# AGENTS.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

Polverine — air quality sensor board: ESP32-S3-MINI-1 + BMV080 PM2.5 + BME690 gas sensor.

## Build & Flash

All commands are in the root `Makefile`. Override serial port with `PORT=/dev/cu.usbmodem1234`.

| Command | Description |
|---|---|
| `make build` | Docker build (ESP-IDF v5.5.3) |
| `make clean` | Clean rebuild (deletes sdkconfig first) |
| `make flash` | Flash bootloader + partition table + app |
| `make erase` | Erase entire flash including NVS |
| `make monitor` | Serial monitor (30s) |

Build runs inside Docker (`espressif/idf:v5.5.3`). Flash/erase/monitor use esptool from `.venv/` (Python venv with `esptool` + `pyserial`). Board must be in flash mode for `flash`/`erase` (hold BOOT, press RESET, release BOOT).

## Config

Credentials live in `firmware/main/config.h` (gitignored). Copy from `config.example.h`.

## Hardware Pin Mapping

Defined in `firmware/main/pins.h`:
- BMV080: SPI2 — MISO=13, MOSI=11, CLK=12, CS=10 @ 1MHz
- BME690: I2C0 — SCL=21, SDA=14, addr=0x76 @ 100kHz
- LEDs: Red=47, Green=48, Blue=38

## Architecture

ESP-IDF v5.5.3, target esp32s3, 80MHz CPU (power management locks to 80MHz).

**Startup flow** (`main.c:app_main`): NVS init → LED init → PM config → WiFi STA connect (blue LED) → CPU temp sensor init → MQTT init → spawn bmv080_task + bme690_task.

**Task coordination**: Both sensor tasks block on `mqtt_event_group` `MQTT_CONNECTED_BIT` before starting measurements. MQTT reconnect is handled by the ESP MQTT client library.

**Sensor tasks**:
- `bmv080_task` — SPI2, polls `bmv080_serve_interrupt()` every 100ms, publishes JSON on data-ready callback
- `bme690_task` — I2C0, BSEC LP mode (3s cycle), dynamic temp offset via CPU die temp, saves BSEC calibration state to NVS every 4 hours

**MQTT**: Topics `polverine/{mac}/bmv080` and `polverine/{mac}/bme690`, QoS 0, JSON payloads.

**LED states**: blue=WiFi connecting, red flash=MQTT publish failure, solid red=fatal error.

## SDK Components

- `components/bmv080/` — headers + precompiled .a from BMV080 SDK v11.2.0
- `components/bsec/` — headers + libalgobsec.a + IAQ config from BSEC v3.2.1.0
- `components/bme69x/` — Bosch BME69x driver C source

SDK source archives in project root (`bmv080-sdk-v11-2-0/`, `bsec_v3-2-1-0/`) — do NOT reference the BlackIoT/Polverine repo code.

## SDK Documentation

Markdown conversions of SDK docs live in `docs/`:

- `docs/bmv080/README.md` — main BMV080 SDK docs
- `docs/bmv080/CHANGELOG.md` — BMV080 version history
- `docs/bmv080/bmv080-api-reference.md` — BMV080 C API reference (converted from Doxygen HTML)
- `docs/bsec/integration-guide.md` — BSEC integration guide (converted from PDF)
- `docs/bsec/release-notes.md` — BSEC 3.2.1.0 release notes (converted from PDF)
- `docs/bsec/binary-size-info.md` — BSEC binary sizes per platform (converted from PDF)
- `docs/bsec/integration-examples.md` — BSEC integration examples

## TIG Stack (Telegraf + TimescaleDB + Grafana)

Dashboard and data pipeline deployed via Portainer on `home.lan` (or your own hostname).

- Compose file: `compose.yaml` (fully self-contained — all configs inline)
- Grafana dashboard: `http://home.lan:3000` → Dashboards → "Polverine"
- MQTT broker: Mosquitto on port 1883
- Database: TimescaleDB (PostgreSQL + time-series extensions)
- Data collector: Telegraf subscribes to MQTT, writes to TimescaleDB

### Data Schema

Two tables, auto-created by Telegraf (one per sensor):
- `bme690` — temperature, humidity, pressure, iaq, static_iaq, co2, voc, gas_percentage, tvoc, iaq_accuracy, tvoc_accuracy, raw_temperature, raw_humidity, raw_gas, cpu_temperature, temp_offset, stabilized, run_in
- `bmv080` — pm1, pm2_5, pm10, pm1_count, pm2_5_count, pm10_count, runtime, obstructed, out_of_range
- Tag tables (`bme690_tag`, `bmv080_tag`) hold device MAC via `tag_id` foreign key

### Dashboard Layout (4 rows)

1. **Climate** — Temperature/Humidity stats + charts, Pressure chart
2. **Air Quality** — IAQ gauge + chart, Static IAQ, CO2, bVOC, tVOC, Gas %
3. **Particulate Matter** — PM Mass (PM1/2.5/10), PM Count
4. **Diagnostics** — IAQ Accuracy, tVOC Accuracy, Raw Sensors, Status table

### Docker Compose Notes

- All config is inline (`content:` blocks) — no external files needed
- `$` must be escaped as `$$` in compose for Grafana query macros (`$$__timeFilter`)
- Named volumes for all services to prevent anonymous volume creation
- TimescaleDB volume at `/var/lib/postgresql` (not `/var/lib/postgresql/data`) to prevent anonymous volume from image VOLUME directive
- Mosquitto needs explicit volumes for `/mosquitto/data` and `/mosquitto/log`
- Dashboard JSON is embedded in the `grafana-dashboard-polverine` config

## Rules

- Docker only for builds — no installing ESP-IDF on host
- Never commit `config.h` (contains WiFi/MQTT secrets)
- Write our own firmware from scratch using official SDKs
- Build after each change to catch errors early
