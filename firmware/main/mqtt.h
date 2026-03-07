#ifndef MQTT_H
#define MQTT_H

#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

#define MQTT_CONNECTED_BIT BIT0

extern EventGroupHandle_t mqtt_event_group;

esp_err_t mqtt_init(void);
esp_err_t mqtt_publish(const char *topic, const char *data);
void mqtt_get_device_id(char *buf, size_t len);

#endif
