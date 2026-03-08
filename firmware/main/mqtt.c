#include "mqtt.h"
#include "config.h"

#include <string.h>
#include "esp_log.h"
#include "esp_mac.h"
#include "mqtt_client.h"

static const char *TAG = "mqtt";

EventGroupHandle_t mqtt_event_group;
static esp_mqtt_client_handle_t mqtt_client;
static char device_id[13];

static void mqtt_event_handler(void *arg, esp_event_base_t base, int32_t event_id, void *event_data)
{
    esp_mqtt_event_handle_t event = event_data;
    switch (event->event_id) {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG, "Connected to broker");
        xEventGroupSetBits(mqtt_event_group, MQTT_CONNECTED_BIT);
        break;
    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGW(TAG, "Disconnected from broker");
        xEventGroupClearBits(mqtt_event_group, MQTT_CONNECTED_BIT);
        break;
    case MQTT_EVENT_ERROR:
        ESP_LOGE(TAG, "MQTT error type=%d", event->error_handle->error_type);
        break;
    default:
        break;
    }
}

void mqtt_get_device_id(char *buf, size_t len)
{
    strncpy(buf, device_id, len);
    buf[len - 1] = '\0';
}

esp_err_t mqtt_init(void)
{
    mqtt_event_group = xEventGroupCreate();

    uint8_t mac[6];
    esp_read_mac(mac, ESP_MAC_WIFI_STA);
    snprintf(device_id, sizeof(device_id), "%02x%02x%02x%02x%02x%02x",
             mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    ESP_LOGI(TAG, "Device ID: %s", device_id);

    const esp_mqtt_client_config_t mqtt_cfg = {
        .broker.address.uri = MQTT_BROKER_URL,
    };

    mqtt_client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(mqtt_client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);
    return esp_mqtt_client_start(mqtt_client);
}

esp_err_t mqtt_publish(const char *topic, const char *data)
{
    if (!(xEventGroupGetBits(mqtt_event_group) & MQTT_CONNECTED_BIT)) {
        return ESP_ERR_INVALID_STATE;
    }
    int msg_id = esp_mqtt_client_publish(mqtt_client, topic, data, 0, 0, 0);
    return (msg_id >= 0) ? ESP_OK : ESP_FAIL;
}
