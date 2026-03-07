#ifndef LED_H
#define LED_H

#include <stdbool.h>

void led_init(void);
void led_set_blue(bool on);
void led_set_green(bool on);
void led_set_red(bool on);
void led_flash_green(void);
void led_flash_red(void);

#endif
