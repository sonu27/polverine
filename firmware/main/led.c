#include "led.h"
#include "pins.h"

#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void led_init(void)
{
    gpio_config_t cfg = {
        .pin_bit_mask = (1ULL << LED_RED_PIN) | (1ULL << LED_GREEN_PIN) | (1ULL << LED_BLUE_PIN),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&cfg);
    gpio_set_level(LED_RED_PIN, 0);
    gpio_set_level(LED_GREEN_PIN, 0);
    gpio_set_level(LED_BLUE_PIN, 0);
}

void led_set_blue(bool on)  { gpio_set_level(LED_BLUE_PIN, on); }
void led_set_green(bool on) { gpio_set_level(LED_GREEN_PIN, on); }
void led_set_red(bool on)   { gpio_set_level(LED_RED_PIN, on); }

void led_flash_green(void)
{
    gpio_set_level(LED_GREEN_PIN, 1);
    vTaskDelay(pdMS_TO_TICKS(50));
    gpio_set_level(LED_GREEN_PIN, 0);
}

void led_flash_red(void)
{
    gpio_set_level(LED_RED_PIN, 1);
    vTaskDelay(pdMS_TO_TICKS(50));
    gpio_set_level(LED_RED_PIN, 0);
}
