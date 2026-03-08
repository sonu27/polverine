#include "bmv080_task.h"
#include "pins.h"
#include "mqtt.h"
#include "led.h"

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"
#include "esp_log.h"
#include "esp_heap_caps.h"

#include "bmv080.h"
#include "bmv080_defs.h"

static const char *TAG = "bmv080";

static spi_device_handle_t spi_handle;

// SPI read callback for BMV080 - 16-bit word transfers, MSB first
static int8_t bmv080_spi_read(bmv080_sercom_handle_t handle, uint16_t header,
                               uint16_t *payload, uint16_t payload_length)
{
    spi_transaction_ext_t t = {
        .base = {
            .flags = SPI_TRANS_VARIABLE_ADDR | SPI_TRANS_VARIABLE_CMD,
            .addr = header,
            .length = payload_length * 16,
            .rxlength = payload_length * 16,
            .tx_buffer = NULL,
            .rx_buffer = payload,
        },
        .command_bits = 0,
        .address_bits = 16,
    };

    esp_err_t err = spi_device_polling_transmit((spi_device_handle_t)handle,
                                                 (spi_transaction_t *)&t);

    // Convert from big endian to little endian
    for (int i = 0; i < payload_length; i++) {
        payload[i] = __builtin_bswap16(payload[i]);
    }

    return (int8_t)err;
}

// SPI write callback for BMV080 - 16-bit word transfers, MSB first
static int8_t bmv080_spi_write(bmv080_sercom_handle_t handle, uint16_t header,
                                const uint16_t *payload, uint16_t payload_length)
{
    // Convert to big endian using heap buffer (DMA-capable)
    uint16_t *swapped = heap_caps_malloc(payload_length * sizeof(uint16_t), MALLOC_CAP_DMA);
    if (!swapped) return -1;
    for (int i = 0; i < payload_length; i++) {
        swapped[i] = __builtin_bswap16(payload[i]);
    }

    spi_transaction_ext_t t = {
        .base = {
            .flags = SPI_TRANS_VARIABLE_ADDR | SPI_TRANS_VARIABLE_CMD,
            .addr = header,
            .length = payload_length * 16,
            .tx_buffer = swapped,
            .rx_buffer = NULL,
        },
        .command_bits = 0,
        .address_bits = 16,
    };

    esp_err_t err = spi_device_transmit((spi_device_handle_t)handle,
                                         (spi_transaction_t *)&t);
    free(swapped);
    return (int8_t)err;
}

static int8_t bmv080_delay(uint32_t ms)
{
    vTaskDelay(pdMS_TO_TICKS(ms));
    return 0;
}

static void bmv080_data_ready(bmv080_output_t output, void *param)
{
    char topic[64];
    char payload[512];
    char device_id[13];

    mqtt_get_device_id(device_id, sizeof(device_id));
    snprintf(topic, sizeof(topic), "polverine/%s/bmv080", device_id);

    snprintf(payload, sizeof(payload),
        "{\"runtime\":%.1f,"
        "\"pm1\":%.1f,\"pm2_5\":%.1f,\"pm10\":%.1f,"
        "\"pm1_count\":%.1f,\"pm2_5_count\":%.1f,\"pm10_count\":%.1f,"
        "\"obstructed\":%s,\"out_of_range\":%s}",
        output.runtime_in_sec,
        output.pm1_mass_concentration,
        output.pm2_5_mass_concentration,
        output.pm10_mass_concentration,
        output.pm1_number_concentration,
        output.pm2_5_number_concentration,
        output.pm10_number_concentration,
        output.is_obstructed ? "true" : "false",
        output.is_outside_measurement_range ? "true" : "false");

    ESP_LOGI(TAG, "%s", payload);
    if (mqtt_publish(topic, payload) != ESP_OK) {
        led_flash_red();
    }
}

static esp_err_t bmv080_spi_init(void)
{
    spi_bus_config_t bus_cfg = {
        .miso_io_num = BMV080_PIN_MISO,
        .mosi_io_num = BMV080_PIN_MOSI,
        .sclk_io_num = BMV080_PIN_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
    };

    esp_err_t err = spi_bus_initialize(BMV080_SPI_HOST, &bus_cfg, SPI_DMA_CH_AUTO);
    if (err != ESP_OK) return err;

    spi_device_interface_config_t dev_cfg = {
        .address_bits = 16,
        .clock_speed_hz = BMV080_SPI_FREQ_HZ,
        .mode = 0,
        .spics_io_num = BMV080_PIN_CS,
        .queue_size = 1,
    };

    return spi_bus_add_device(BMV080_SPI_HOST, &dev_cfg, &spi_handle);
}

void bmv080_task(void *param)
{
    ESP_LOGI(TAG, "Initializing BMV080...");

    // Wait for MQTT connection
    xEventGroupWaitBits(mqtt_event_group, MQTT_CONNECTED_BIT, false, true, portMAX_DELAY);

    // Init SPI
    esp_err_t err = bmv080_spi_init();
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "SPI init failed: %s", esp_err_to_name(err));
        led_set_red(true);
        vTaskDelete(NULL);
        return;
    }

    // Print driver version
    uint16_t major, minor, patch;
    char git_hash[12];
    int32_t commits_ahead;
    bmv080_status_code_t status = bmv080_get_driver_version(&major, &minor, &patch, git_hash, &commits_ahead);
    if (status == E_BMV080_OK) {
        ESP_LOGI(TAG, "Driver version: %d.%d.%d", major, minor, patch);
    }

    // Open sensor
    bmv080_handle_t handle = NULL;
    status = bmv080_open(&handle, (bmv080_sercom_handle_t)spi_handle,
                         bmv080_spi_read, bmv080_spi_write, bmv080_delay);
    if (status != E_BMV080_OK) {
        ESP_LOGE(TAG, "bmv080_open failed: %d", status);
        led_set_red(true);
        vTaskDelete(NULL);
        return;
    }

    // Reset sensor
    status = bmv080_reset(handle);
    if (status != E_BMV080_OK) {
        ESP_LOGE(TAG, "bmv080_reset failed: %d", status);
    }

    // Get sensor ID
    char sensor_id[13];
    status = bmv080_get_sensor_id(handle, sensor_id);
    if (status == E_BMV080_OK) {
        ESP_LOGI(TAG, "Sensor ID: %s", sensor_id);
    }

    // Set measurement algorithm to HIGH_PRECISION
    bmv080_measurement_algorithm_t algo = E_BMV080_MEASUREMENT_ALGORITHM_HIGH_PRECISION;
    status = bmv080_set_parameter(handle, "measurement_algorithm", &algo);
    if (status != E_BMV080_OK) {
        ESP_LOGW(TAG, "set measurement_algorithm failed: %d", status);
    }

    // Start continuous measurement
    status = bmv080_start_continuous_measurement(handle);
    if (status != E_BMV080_OK) {
        ESP_LOGE(TAG, "start_continuous_measurement failed: %d", status);
        bmv080_close(&handle);
        vTaskDelete(NULL);
        return;
    }

    ESP_LOGI(TAG, "Continuous measurement started");

    // Poll serve_interrupt every 100ms
    while (1) {
        status = bmv080_serve_interrupt(handle, bmv080_data_ready, NULL);
        if (status != E_BMV080_OK
            && status != E_BMV080_WARNING_FIFO_EVENTS_OVERFLOW
            && status != E_BMV080_WARNING_FIFO_SW_BUFFER_SIZE
            && status != E_BMV080_WARNING_FIFO_HW_BUFFER_SIZE) {
            ESP_LOGW(TAG, "serve_interrupt status: %d", status);
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
