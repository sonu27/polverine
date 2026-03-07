#ifndef CONFIG_H
#define CONFIG_H

#define WIFI_SSID       "your-ssid"
#define WIFI_PASSWORD   "your-password"
#define MQTT_BROKER_URL "mqtt://your-broker:1883"

// BME690 dynamic temperature offset: offset = BASE + SCALE * cpu_temp
// Tune by comparing against a reference thermometer.
#define BME690_TEMP_OFFSET_BASE   12.5f
#define BME690_TEMP_OFFSET_SCALE  0.25f

#endif
