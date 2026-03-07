# Polverine Firmware

Air quality sensor board: ESP32-S3-MINI-1 + BMV080 PM2.5 + BME690 gas sensor.

## Build

All builds via Docker — no host toolchain installs.

```bash
docker run --rm -v $(pwd):/project -w /project/firmware espressif/idf:v5.5.3 idf.py build
```

Or use `firmware/build.sh`.

### Clean rebuild (needed after sdkconfig.defaults changes)

```bash
docker run --rm -v $(pwd):/project -w /project/firmware espressif/idf:v5.5.3 bash -c "rm -f sdkconfig && idf.py build"
```

## Flash

Uses esptool from a Python venv (`.venv/`):

```bash
.venv/bin/python -m esptool --chip esp32s3 -b 460800 -p /dev/cu.usbmodem2101 write-flash --flash-mode dio --flash-size 8MB --flash-freq 80m 0x0 firmware/build/bootloader/bootloader.bin 0x8000 firmware/build/partition_table/partition-table.bin 0x10000 firmware/build/polverine.bin
```

Board must be in flash mode (hold BOOT, press RESET, release BOOT).

## Serial Monitor

```bash
.venv/bin/python3 -c "
import serial, time
ser = serial.Serial('/dev/cu.usbmodem2101', 115200, timeout=1)
ser.dtr = False; ser.rts = True; time.sleep(0.1); ser.rts = False; time.sleep(0.5)
end = time.time() + 30
while time.time() < end:
    data = ser.read(ser.in_waiting or 1)
    if data: print(data.decode('utf-8', errors='replace'), end='', flush=True)
ser.close()
"
```

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

## Rules

- Docker only for builds — no installing ESP-IDF on host
- Never commit `config.h` (contains WiFi/MQTT secrets)
- Write our own firmware from scratch using official SDKs
- Build after each change to catch errors early
