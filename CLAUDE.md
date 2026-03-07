# Polverine Firmware

Air quality sensor board: ESP32-S3-MINI-1 + BMV080 PM2.5 + BME690 gas sensor.

## Makefile

All common commands are in the root `Makefile`. Override serial port with `PORT=/dev/cu.usbmodem1234`.

| Command | Description |
|---|---|
| `make build` | Docker build (ESP-IDF v5.5.3) |
| `make clean` | Clean rebuild (deletes sdkconfig first) |
| `make flash` | Flash bootloader + partition table + app |
| `make erase` | Erase entire flash including NVS |
| `make monitor` | Serial monitor (30s) |
| `make nodered-push` | Deploy local flow to Node-RED server |
| `make nodered-pull` | Pull server flow to local |

Board must be in flash mode for `flash`/`erase` (hold BOOT, press RESET, release BOOT).

## Config

Credentials live in `firmware/main/config.h` (gitignored). Copy from `config.example.h`.

## Hardware Pin Mapping

Defined in `firmware/main/pins.h`:
- BMV080: SPI2 — MISO=13, MOSI=11, CLK=12, CS=10 @ 1MHz
- BME690: I2C0 — SCL=21, SDA=14, addr=0x76 @ 100kHz
- LEDs: Red=47, Green=48, Blue=38

## Architecture

- ESP-IDF v5.5.3, target esp32s3, 80MHz CPU
- FreeRTOS tasks: bmv080_task (SPI, 100ms poll), bme690_task (I2C, BSEC LP 3s)
- WiFi STA → MQTT → sensor tasks start
- MQTT topics: `polverine/{mac}/bmv080`, `polverine/{mac}/bme690`
- LED states: blue=WiFi connecting, green flash=data published, red=error

## SDK Components

- `components/bmv080/` — headers + precompiled .a from BMV080 SDK v11.2.0
- `components/bsec/` — headers + libalgobsec.a + IAQ config from BSEC v3.2.1.0
- `components/bme69x/` — Bosch BME69x driver C source

SDK source archives in project root (`bmv080-sdk-v11-2-0/`, `bsec_v3-2-1-0/`) — do NOT reference the BlackIoT/Polverine repo code.

## Node-RED Dashboard

Dashboard v2 using `@flowfuse/node-red-dashboard` on `home.lan:1880`.

- Flow JSON: `nodered/polverine-v2-flow.json`
- Dashboard URL: `http://home.lan:1880/dashboard/polverine`
- Server: Docker compose via `node-red-compose.yml` (container: `iaq-node-red-1`)
- MQTT broker: `home.lan:1883` (Mosquitto in same compose)
- Deployed flows live in container volume `myNodeREDdata` at `/data/flows.json`

### Push local flow to server

```bash
scp nodered/polverine-v2-flow.json home.lan:/tmp/flows.json
ssh home.lan "docker cp /tmp/flows.json iaq-node-red-1:/data/flows.json && docker restart iaq-node-red-1"
```

### Pull server flow to local

```bash
ssh home.lan "docker exec iaq-node-red-1 cat /data/flows.json" > nodered/polverine-v2-flow.json
```

### Dashboard 2.0 gotchas

- `ui-group` `width`/`height` must be **integers**, not strings
- `ui-group` needs `visible: "true"`, `disabled: "false"`, `groupType: "default"`
- `ui-page` needs `breakpoints` array for responsive layout
- Only one `ui-base` per Node-RED instance — pages share it (path `/dashboard`)
- Node-RED regenerates widget IDs on import but keeps config node IDs

## Rules

- Docker only for builds — no installing ESP-IDF on host
- Never commit `config.h` (contains WiFi/MQTT secrets)
- Write our own firmware from scratch using official SDKs
- Build after each change to catch errors early
