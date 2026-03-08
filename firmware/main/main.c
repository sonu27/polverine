#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_pm.h"
#include "esp_timer.h"
#include "nvs_flash.h"

#include "config.h"
#include "mqtt.h"
#include "bmv080_task.h"
#include "bme690_task.h"
#include "led.h"
#include "cpu_temp.h"

static const char *TAG = "main";

#define WIFI_CONNECTED_BIT      BIT0
#define WIFI_BACKOFF_INIT_MS    1000
#define WIFI_BACKOFF_MAX_MS     30000

static EventGroupHandle_t wifi_event_group;
static int wifi_backoff_ms = WIFI_BACKOFF_INIT_MS;
static esp_timer_handle_t wifi_retry_timer;

static void wifi_retry_cb(void *arg)
{
    ESP_LOGI(TAG, "WiFi reconnecting...");
    esp_wifi_connect();
}

static void wifi_event_handler(void *arg, esp_event_base_t base, int32_t id, void *data)
{
    if (base == WIFI_EVENT && id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (base == WIFI_EVENT && id == WIFI_EVENT_STA_DISCONNECTED) {
        led_set_blue(true);
        ESP_LOGW(TAG, "WiFi disconnected, retrying in %dms", wifi_backoff_ms);
        esp_timer_stop(wifi_retry_timer);   // no-op if not running
        esp_timer_start_once(wifi_retry_timer, wifi_backoff_ms * 1000ULL);
        wifi_backoff_ms *= 2;
        if (wifi_backoff_ms > WIFI_BACKOFF_MAX_MS) {
            wifi_backoff_ms = WIFI_BACKOFF_MAX_MS;
        }
    } else if (base == IP_EVENT && id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)data;
        ESP_LOGI(TAG, "Got IP: " IPSTR, IP2STR(&event->ip_info.ip));
        wifi_backoff_ms = WIFI_BACKOFF_INIT_MS;
        led_set_blue(false);
        xEventGroupSetBits(wifi_event_group, WIFI_CONNECTED_BIT);
    }
}

static void wifi_init(void)
{
    wifi_event_group = xEventGroupCreate();

    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID,
                                                         wifi_event_handler, NULL, NULL));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP,
                                                         wifi_event_handler, NULL, NULL));

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = WIFI_SSID,
            .password = WIFI_PASSWORD,
            .threshold.authmode = WIFI_AUTH_WPA2_PSK,
        },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));

    const esp_timer_create_args_t timer_args = {
        .callback = wifi_retry_cb,
        .name = "wifi_retry",
    };
    ESP_ERROR_CHECK(esp_timer_create(&timer_args, &wifi_retry_timer));

    ESP_ERROR_CHECK(esp_wifi_start());

    xEventGroupWaitBits(wifi_event_group, WIFI_CONNECTED_BIT, pdFALSE, pdFALSE, portMAX_DELAY);
    ESP_LOGI(TAG, "WiFi connected to %s", WIFI_SSID);
}

static void configure_power_management(void)
{
    esp_pm_config_t pm_config = {
        .max_freq_mhz = 80,
        .min_freq_mhz = 80,
        .light_sleep_enable = false,
    };
    esp_err_t err = esp_pm_configure(&pm_config);
    if (err != ESP_OK) {
        ESP_LOGW(TAG, "PM config failed: %s (non-fatal)", esp_err_to_name(err));
    }
}

void app_main(void)
{
    ESP_LOGI(TAG, "Polverine firmware starting...");

    // Init NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // Init LEDs
    led_init();

    // Configure power management
    configure_power_management();

    // Blue LED while connecting WiFi
    led_set_blue(true);
    wifi_init();  // blocks until connected

    // Init CPU temperature sensor
    cpu_temp_init();

    // Start MQTT
    ESP_ERROR_CHECK(mqtt_init());

    // Launch sensor tasks
    if (xTaskCreate(bmv080_task, "bmv080", 32768, NULL, 5, NULL) != pdPASS) {
        ESP_LOGE(TAG, "Failed to create bmv080 task");
        led_set_red(true);
    }
    if (xTaskCreate(bme690_task, "bme690", 16384, NULL, 5, NULL) != pdPASS) {
        ESP_LOGE(TAG, "Failed to create bme690 task");
        led_set_red(true);
    }
}
