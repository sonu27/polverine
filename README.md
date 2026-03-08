# Polverine

Air quality sensor firmware for the Polverine board — an ESP32-S3 mikroBUS board with a Bosch BMV080 particulate matter sensor and BME690 environmental sensor.

## What It Measures

| Sensor | Measurements |
|---|---|
| **BMV080** | PM1, PM2.5, PM10 (mass & count) |
| **BME690** (via BSEC) | Temperature, humidity, pressure, IAQ, static IAQ, CO2, bVOC, tVOC, gas % |

Sensor data is published over MQTT as JSON and can be visualized with the included Grafana dashboard.

## Prerequisites

- [Docker](https://www.docker.com/) (for building firmware)
- Python 3 with a venv (for flashing)

No ESP-IDF installation required — builds run inside the `espressif/idf:v5.5.3` Docker image.

## Quick Start

### 1. Set up the Python venv (one-time)

```sh
python3 -m venv .venv
.venv/bin/pip install esptool pyserial
```

### 2. Configure

```sh
cp firmware/main/config.example.h firmware/main/config.h
```

Edit `firmware/main/config.h` with your WiFi and MQTT credentials:

```c
#define WIFI_SSID       "your-ssid"
#define WIFI_PASSWORD   "your-password"
#define MQTT_BROKER_URL "mqtt://your-broker:1883"
```

### 3. Build

```sh
make build
```

### 4. Flash

Put the board into flash mode (hold BOOT, press RESET, release BOOT), then:

```sh
make flash
```

If your serial port isn't `/dev/cu.usbmodem2101`, override it:

```sh
make flash PORT=/dev/cu.usbmodem1234
```

### 5. Monitor

```sh
make monitor
```

## Makefile Commands

| Command | Description |
|---|---|
| `make build` | Build firmware in Docker |
| `make clean` | Delete sdkconfig and rebuild from scratch |
| `make flash` | Flash bootloader + partition table + app |
| `make erase` | Erase entire flash (including NVS calibration data) |
| `make monitor` | Serial monitor (30 seconds) |

## How It Works

On boot the firmware connects to WiFi, then MQTT, then starts two FreeRTOS tasks:

- **bmv080_task** — reads the BMV080 particulate matter sensor over SPI, publishes every ~10 seconds
- **bme690_task** — reads the BME690 gas sensor over I2C through the Bosch BSEC library (LP mode, 3-second cycle), publishes every ~3 seconds

Data is published as JSON to MQTT topics `polverine/{mac}/bmv080` and `polverine/{mac}/bme690`, where `{mac}` is the device's WiFi MAC address.

### LED Indicators

| LED | Meaning |
|---|---|
| Blue (solid) | Connecting to WiFi |
| Green (flash) | Data published successfully |
| Red (flash) | MQTT publish failed |
| Red (solid) | Fatal error (sensor init failed, etc.) |

### Temperature Compensation

The ESP32's self-heating raises the BME690 temperature reading well above ambient. The firmware uses the ESP32's internal CPU temperature sensor to compute a dynamic offset fed to BSEC via `BSEC_INPUT_HEATSOURCE`. Tune the constants in `config.h` (`BME690_TEMP_OFFSET_BASE`, `BME690_TEMP_OFFSET_SCALE`) by comparing against a reference thermometer.

### BSEC Calibration State

BSEC calibration state is saved to NVS flash every 4 hours and restored on boot. The IAQ accuracy field indicates calibration progress (0 = uncalibrated, 3 = fully calibrated). Use `make erase` to reset calibration if needed.

## Dashboard

The `compose.yaml` file contains a self-contained Docker Compose stack (Mosquitto + Telegraf + TimescaleDB + Grafana) with a pre-configured Grafana dashboard. Deploy it with Portainer or `docker compose up -d`.

## Project Structure

```
firmware/
  main/           Firmware source (main.c, sensor tasks, MQTT, LED, config)
  components/     Bosch SDK libraries (BMV080, BSEC, BME69x)
compose.yaml      TIG stack (Telegraf + TimescaleDB + Grafana + Mosquitto)
docs/             SDK documentation (converted to Markdown)
Makefile          Build, flash, and monitor commands
```

## License

Bosch SDK components under `firmware/components/` and `docs/` are subject to their respective licenses. See the SDK archives for details.
