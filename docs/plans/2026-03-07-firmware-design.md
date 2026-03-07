# Polverine Firmware Design

## Overview
ESP-IDF v5.5.3 firmware for the Polverine air quality sensor board. Reads BMV080 (PM2.5) over SPI and BME690 (gas/env) over I2C via BSEC library. Outputs JSON over USB serial and MQTT over WiFi.

## Architecture
Three FreeRTOS tasks:
1. **BMV080 Task** — SPI, continuous measurement, HIGH_PRECISION, poll every 100ms, output ~1s
2. **BME690/BSEC Task** — I2C, BSEC LP mode 3s, config bme690_iaq_33v_3s_28d, all IAQ outputs
3. **Main/WiFi Task** — NVS, WiFi STA, MQTT client. Other tasks wait for MQTT ready.

## MQTT
- Topics: `polverine/{mac_id}/bmv080`, `polverine/{mac_id}/bme690`
- All sensor fields included in JSON payloads
- WiFi/MQTT credentials via compile-time `config.h` (gitignored)

## Power
- CPU 80MHz max, light sleep enabled
- BSEC temperature offset configurable for self-heating compensation

## Build
- Docker only: `espressif/idf:v5.5.3`
- No host toolchain installation required
