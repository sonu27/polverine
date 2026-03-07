idf_component_register(
    SRCS "main.c" "bmv080_task.c" "bme690_task.c" "mqtt.c" "led.c" "cpu_temp.c"
    INCLUDE_DIRS "."
    REQUIRES driver esp_wifi esp_event nvs_flash mqtt esp_timer esp_pm
    PRIV_REQUIRES bmv080 bsec bme69x
)
