idf_component_register(
    SRCS "main.c" "bmv080_task.c" "bme690_task.c" "mqtt.c" "led.c" "cpu_temp.c"
    INCLUDE_DIRS "."
    REQUIRES esp_driver_gpio esp_driver_spi esp_driver_i2c esp_driver_tsens esp_wifi esp_event nvs_flash esp_timer esp_pm
    PRIV_REQUIRES bmv080 bsec bme69x
)
