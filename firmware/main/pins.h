#ifndef PINS_H
#define PINS_H

// BMV080 PM2.5 Sensor (SPI)
#define BMV080_SPI_HOST     SPI2_HOST
#define BMV080_PIN_MISO     13
#define BMV080_PIN_MOSI     11
#define BMV080_PIN_CLK      12
#define BMV080_PIN_CS       10
#define BMV080_SPI_FREQ_HZ  1000000

// BME690 Gas/Env Sensor (I2C)
#define BME690_I2C_PORT     I2C_NUM_0
#define BME690_PIN_SCL      21
#define BME690_PIN_SDA      14
#define BME690_I2C_ADDR     0x76
#define BME690_I2C_FREQ_HZ  100000

// RGB LEDs
#define LED_RED_PIN         47
#define LED_GREEN_PIN       48
#define LED_BLUE_PIN        38

#endif
