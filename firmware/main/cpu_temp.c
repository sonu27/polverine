#include "cpu_temp.h"
#include "driver/temperature_sensor.h"
#include "esp_log.h"

static const char *TAG = "cpu_temp";
static temperature_sensor_handle_t temp_handle = NULL;

esp_err_t cpu_temp_init(void)
{
    temperature_sensor_config_t cfg = TEMPERATURE_SENSOR_CONFIG_DEFAULT(10, 80);
    esp_err_t err = temperature_sensor_install(&cfg, &temp_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Install failed: %s", esp_err_to_name(err));
        return err;
    }
    err = temperature_sensor_enable(temp_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Enable failed: %s", esp_err_to_name(err));
        return err;
    }
    float initial;
    temperature_sensor_get_celsius(temp_handle, &initial);
    ESP_LOGI(TAG, "CPU temperature sensor ready: %.1f C", initial);
    return ESP_OK;
}

float cpu_temp_read(void)
{
    float temp = 0;
    if (temp_handle) {
        temperature_sensor_get_celsius(temp_handle, &temp);
    }
    return temp;
}
