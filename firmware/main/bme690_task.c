#include "bme690_task.h"
#include "pins.h"
#include "mqtt.h"
#include "led.h"
#include "config.h"

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c_master.h"
#include "esp_log.h"
#include "esp_timer.h"

#include "bme69x.h"
#include "bsec_interface.h"
#include "bsec_iaq.h"

static const char *TAG = "bme690";

#define BSEC_INSTANCE_SIZE 3272
#define BSEC_TOTAL_HEAT_DUR 140
#define NUM_BSEC_OUTPUTS 14

static i2c_master_bus_handle_t i2c_bus;
static i2c_master_dev_handle_t i2c_dev;
static struct bme69x_dev bme;
static uint8_t bsec_instance[BSEC_INSTANCE_SIZE];

static int64_t get_timestamp_ns(void)
{
    return esp_timer_get_time() * 1000LL;
}

// BME69x I2C read callback
static int8_t bme69x_i2c_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t length, void *intf_ptr)
{
    esp_err_t err = i2c_master_transmit_receive(i2c_dev, &reg_addr, 1, reg_data, length, 1000);
    return (err == ESP_OK) ? BME69X_OK : BME69X_E_COM_FAIL;
}

// BME69x I2C write callback
static int8_t bme69x_i2c_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t length, void *intf_ptr)
{
    uint8_t *buf = malloc(1 + length);
    if (!buf) return BME69X_E_COM_FAIL;
    buf[0] = reg_addr;
    memcpy(buf + 1, reg_data, length);
    esp_err_t err = i2c_master_transmit(i2c_dev, buf, 1 + length, 1000);
    free(buf);
    return (err == ESP_OK) ? BME69X_OK : BME69X_E_COM_FAIL;
}

static void bme69x_delay_us(uint32_t period, void *intf_ptr)
{
    uint32_t ms = (period + 999) / 1000;
    if (ms == 0) ms = 1;
    vTaskDelay(pdMS_TO_TICKS(ms));
}

static esp_err_t i2c_init(void)
{
    i2c_master_bus_config_t bus_cfg = {
        .i2c_port = BME690_I2C_PORT,
        .sda_io_num = BME690_PIN_SDA,
        .scl_io_num = BME690_PIN_SCL,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
    };
    esp_err_t err = i2c_new_master_bus(&bus_cfg, &i2c_bus);
    if (err != ESP_OK) return err;

    i2c_device_config_t dev_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = BME690_I2C_ADDR,
        .scl_speed_hz = BME690_I2C_FREQ_HZ,
    };
    return i2c_master_bus_add_device(i2c_bus, &dev_cfg, &i2c_dev);
}

static void publish_bsec_outputs(bsec_output_t *outputs, uint8_t n_outputs)
{
    float temperature = 0, humidity = 0, pressure = 0;
    float iaq = 0, static_iaq = 0, co2 = 0, voc = 0;
    float gas_pct = 0, tvoc = 0;
    float raw_temp = 0, raw_hum = 0, raw_gas = 0;
    uint8_t iaq_accuracy = 0, tvoc_accuracy = 0;
    bool stabilized = false, run_in = false;

    for (uint8_t i = 0; i < n_outputs; i++) {
        switch (outputs[i].sensor_id) {
        case BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_TEMPERATURE:
            temperature = outputs[i].signal;
            break;
        case BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_HUMIDITY:
            humidity = outputs[i].signal;
            break;
        case BSEC_OUTPUT_RAW_PRESSURE:
            pressure = outputs[i].signal;
            break;
        case BSEC_OUTPUT_IAQ:
            iaq = outputs[i].signal;
            iaq_accuracy = outputs[i].accuracy;
            break;
        case BSEC_OUTPUT_STATIC_IAQ:
            static_iaq = outputs[i].signal;
            break;
        case BSEC_OUTPUT_CO2_EQUIVALENT:
            co2 = outputs[i].signal;
            break;
        case BSEC_OUTPUT_BREATH_VOC_EQUIVALENT:
            voc = outputs[i].signal;
            break;
        case BSEC_OUTPUT_GAS_PERCENTAGE:
            gas_pct = outputs[i].signal;
            break;
        case BSEC_OUTPUT_TVOC_EQUIVALENT:
            tvoc = outputs[i].signal;
            tvoc_accuracy = outputs[i].accuracy;
            break;
        case BSEC_OUTPUT_RAW_TEMPERATURE:
            raw_temp = outputs[i].signal;
            break;
        case BSEC_OUTPUT_RAW_HUMIDITY:
            raw_hum = outputs[i].signal;
            break;
        case BSEC_OUTPUT_RAW_GAS:
            raw_gas = outputs[i].signal;
            break;
        case BSEC_OUTPUT_STABILIZATION_STATUS:
            stabilized = outputs[i].signal > 0.5f;
            break;
        case BSEC_OUTPUT_RUN_IN_STATUS:
            run_in = outputs[i].signal > 0.5f;
            break;
        }
    }

    char topic[64];
    char payload[768];
    char device_id[13];

    mqtt_get_device_id(device_id, sizeof(device_id));
    snprintf(topic, sizeof(topic), "polverine/%s/bme690", device_id);

    snprintf(payload, sizeof(payload),
        "{\"temperature\":%.1f,\"humidity\":%.1f,\"pressure\":%.0f,"
        "\"iaq\":%.0f,\"iaq_accuracy\":%u,"
        "\"static_iaq\":%.0f,"
        "\"co2\":%.0f,\"voc\":%.2f,"
        "\"gas_percentage\":%.1f,"
        "\"tvoc\":%.0f,\"tvoc_accuracy\":%u,"
        "\"raw_temperature\":%.1f,\"raw_humidity\":%.1f,\"raw_gas\":%.0f,"
        "\"stabilized\":%s,\"run_in\":%s}",
        temperature, humidity, pressure,
        iaq, iaq_accuracy,
        static_iaq,
        co2, voc,
        gas_pct,
        tvoc, tvoc_accuracy,
        raw_temp, raw_hum, raw_gas,
        stabilized ? "true" : "false",
        run_in ? "true" : "false");

    printf("%s\n", payload);
    mqtt_publish(topic, payload);
}

void bme690_task(void *param)
{
    ESP_LOGI(TAG, "Initializing BME690 + BSEC...");

    // Wait for MQTT connection
    xEventGroupWaitBits(mqtt_event_group, MQTT_CONNECTED_BIT, false, true, portMAX_DELAY);

    // Init I2C
    esp_err_t err = i2c_init();
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "I2C init failed: %s", esp_err_to_name(err));
        led_set_red(true);
        vTaskDelete(NULL);
        return;
    }

    // Init BME69x driver
    bme.intf = BME69X_I2C_INTF;
    bme.read = bme69x_i2c_read;
    bme.write = bme69x_i2c_write;
    bme.delay_us = bme69x_delay_us;
    bme.intf_ptr = NULL;
    bme.amb_temp = 25;

    int8_t rslt = bme69x_init(&bme);
    if (rslt != BME69X_OK) {
        ESP_LOGE(TAG, "bme69x_init failed: %d", rslt);
        led_set_red(true);
        vTaskDelete(NULL);
        return;
    }
    ESP_LOGI(TAG, "BME69x chip_id=0x%02x variant=0x%02x", bme.chip_id, (unsigned)bme.variant_id);

    // Init BSEC
    bsec_library_return_t bsec_status = bsec_init(bsec_instance);
    if (bsec_status != BSEC_OK) {
        ESP_LOGE(TAG, "bsec_init failed: %d", bsec_status);
        vTaskDelete(NULL);
        return;
    }

    bsec_version_t version;
    bsec_get_version(bsec_instance, &version);
    ESP_LOGI(TAG, "BSEC version: %d.%d.%d.%d", version.major, version.minor,
             version.major_bugfix, version.minor_bugfix);

    // Load BSEC config
    uint8_t work_buffer[BSEC_MAX_WORKBUFFER_SIZE];
    bsec_status = bsec_set_configuration(bsec_instance, bsec_config_iaq,
                                          sizeof(bsec_config_iaq), work_buffer,
                                          sizeof(work_buffer));
    if (bsec_status != BSEC_OK) {
        ESP_LOGE(TAG, "bsec_set_configuration failed: %d", bsec_status);
    }

    // Subscribe to BSEC outputs at LP rate (3s)
    bsec_sensor_configuration_t requested[NUM_BSEC_OUTPUTS] = {
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_IAQ },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_STATIC_IAQ },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_CO2_EQUIVALENT },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_BREATH_VOC_EQUIVALENT },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_TEMPERATURE },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_HUMIDITY },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_RAW_PRESSURE },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_RAW_TEMPERATURE },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_RAW_HUMIDITY },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_RAW_GAS },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_STABILIZATION_STATUS },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_RUN_IN_STATUS },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_GAS_PERCENTAGE },
        { BSEC_SAMPLE_RATE_LP, BSEC_OUTPUT_TVOC_EQUIVALENT },
    };

    bsec_sensor_configuration_t required_settings[BSEC_MAX_PHYSICAL_SENSOR];
    uint8_t n_required = BSEC_MAX_PHYSICAL_SENSOR;

    bsec_status = bsec_update_subscription(bsec_instance, requested, NUM_BSEC_OUTPUTS,
                                            required_settings, &n_required);
    if (bsec_status != BSEC_OK) {
        ESP_LOGE(TAG, "bsec_update_subscription failed: %d", bsec_status);
        vTaskDelete(NULL);
        return;
    }

    ESP_LOGI(TAG, "BSEC ready, entering measurement loop");

    // Main BSEC loop
    struct bme69x_conf conf;
    struct bme69x_heatr_conf heatr_conf;
    struct bme69x_data sensor_data[3];
    uint8_t n_fields;
    uint8_t last_op_mode = BME69X_SLEEP_MODE;

    while (1) {
        int64_t timestamp_ns = get_timestamp_ns();

        bsec_bme_settings_t sensor_settings;
        bsec_status = bsec_sensor_control(bsec_instance, timestamp_ns, &sensor_settings);
        if (bsec_status != BSEC_OK) {
            ESP_LOGW(TAG, "bsec_sensor_control: %d", bsec_status);
        }

        if (sensor_settings.trigger_measurement) {
            // Configure BME690 based on BSEC instructions
            conf.os_hum = sensor_settings.humidity_oversampling;
            conf.os_temp = sensor_settings.temperature_oversampling;
            conf.os_pres = sensor_settings.pressure_oversampling;
            conf.filter = BME69X_FILTER_OFF;
            conf.odr = BME69X_ODR_NONE;
            bme69x_set_conf(&conf, &bme);

            if (sensor_settings.op_mode == BME69X_FORCED_MODE) {
                heatr_conf.enable = BME69X_ENABLE;
                heatr_conf.heatr_temp = sensor_settings.heater_temperature;
                heatr_conf.heatr_dur = sensor_settings.heater_duration;
                bme69x_set_heatr_conf(BME69X_FORCED_MODE, &heatr_conf, &bme);
                bme69x_set_op_mode(BME69X_FORCED_MODE, &bme);
                last_op_mode = BME69X_FORCED_MODE;

                // Wait for measurement
                uint32_t meas_dur = bme69x_get_meas_dur(BME69X_FORCED_MODE, &conf, &bme);
                bme69x_delay_us(meas_dur + (sensor_settings.heater_duration * 1000), NULL);

                rslt = bme69x_get_data(BME69X_FORCED_MODE, sensor_data, &n_fields, &bme);
                if (rslt == BME69X_OK && n_fields > 0) {
                    bsec_input_t inputs[BSEC_MAX_PHYSICAL_SENSOR];
                    uint8_t n_inputs = 0;

                    if (sensor_settings.process_data & BSEC_PROCESS_TEMPERATURE) {
                        inputs[n_inputs].sensor_id = BSEC_INPUT_TEMPERATURE;
                        inputs[n_inputs].signal = sensor_data[0].temperature;
                        inputs[n_inputs].time_stamp = timestamp_ns;
                        inputs[n_inputs].signal_dimensions = 1;
                        n_inputs++;
                    }
                    if (sensor_settings.process_data & BSEC_PROCESS_HUMIDITY) {
                        inputs[n_inputs].sensor_id = BSEC_INPUT_HUMIDITY;
                        inputs[n_inputs].signal = sensor_data[0].humidity;
                        inputs[n_inputs].time_stamp = timestamp_ns;
                        inputs[n_inputs].signal_dimensions = 1;
                        n_inputs++;
                    }
                    if (sensor_settings.process_data & BSEC_PROCESS_PRESSURE) {
                        inputs[n_inputs].sensor_id = BSEC_INPUT_PRESSURE;
                        inputs[n_inputs].signal = sensor_data[0].pressure;
                        inputs[n_inputs].time_stamp = timestamp_ns;
                        inputs[n_inputs].signal_dimensions = 1;
                        n_inputs++;
                    }
                    if (sensor_settings.process_data & BSEC_PROCESS_GAS) {
                        if (sensor_data[0].status & BME69X_GASM_VALID_MSK) {
                            inputs[n_inputs].sensor_id = BSEC_INPUT_GASRESISTOR;
                            inputs[n_inputs].signal = sensor_data[0].gas_resistance;
                            inputs[n_inputs].time_stamp = timestamp_ns;
                            inputs[n_inputs].signal_dimensions = 1;
                            n_inputs++;
                        }
                    }

                    // Temperature offset for self-heating compensation
                    inputs[n_inputs].sensor_id = BSEC_INPUT_HEATSOURCE;
                    inputs[n_inputs].signal = BME690_TEMP_OFFSET;
                    inputs[n_inputs].time_stamp = timestamp_ns;
                    inputs[n_inputs].signal_dimensions = 1;
                    n_inputs++;

                    bsec_output_t bsec_outputs[BSEC_NUMBER_OUTPUTS];
                    uint8_t n_bsec_outputs = BSEC_NUMBER_OUTPUTS;

                    bsec_status = bsec_do_steps(bsec_instance, inputs, n_inputs,
                                                 bsec_outputs, &n_bsec_outputs);
                    if (bsec_status == BSEC_OK && n_bsec_outputs > 0) {
                        publish_bsec_outputs(bsec_outputs, n_bsec_outputs);
                    } else if (bsec_status != BSEC_OK) {
                        ESP_LOGW(TAG, "bsec_do_steps: %d", bsec_status);
                    }
                }
            } else if (sensor_settings.op_mode == BME69X_SLEEP_MODE) {
                if (last_op_mode != BME69X_SLEEP_MODE) {
                    bme69x_set_op_mode(BME69X_SLEEP_MODE, &bme);
                    last_op_mode = BME69X_SLEEP_MODE;
                }
            }
        }

        // Sleep until next BSEC call
        int64_t next_call_ns = sensor_settings.next_call;
        int64_t now_ns = get_timestamp_ns();
        int64_t sleep_ms = (next_call_ns - now_ns) / 1000000LL;
        if (sleep_ms > 0) {
            vTaskDelay(pdMS_TO_TICKS((uint32_t)sleep_ms));
        } else {
            vTaskDelay(pdMS_TO_TICKS(100));
        }
    }
}
