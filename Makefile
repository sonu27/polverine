PORT        ?= /dev/cu.usbmodem2101
DOCKER_RUN  = docker run --rm -v $(CURDIR):/project -w /project/firmware espressif/idf:v5.5.3
ESPTOOL     = .venv/bin/python -m esptool --chip esp32s3 -b 460800 -p $(PORT)

BOOTLOADER  = firmware/build/bootloader/bootloader.bin
PARTITION   = firmware/build/partition_table/partition-table.bin
APP         = firmware/build/polverine.bin

.PHONY: build clean flash erase monitor

build:
	$(DOCKER_RUN) idf.py build

clean:
	$(DOCKER_RUN) bash -c "rm -f sdkconfig && idf.py build"

flash:
	$(ESPTOOL) write-flash --flash-mode dio --flash-size 8MB --flash-freq 80m \
		0x0 $(BOOTLOADER) 0x8000 $(PARTITION) 0x10000 $(APP)

erase:
	$(ESPTOOL) erase-flash

monitor:
	.venv/bin/python3 -c "\
	import serial, time; \
	ser = serial.Serial('$(PORT)', 115200, timeout=1); \
	ser.dtr = False; ser.rts = True; time.sleep(0.1); ser.rts = False; time.sleep(0.5); \
	end = time.time() + 30; \
	[\
	    (lambda d: print(d.decode('utf-8', errors='replace'), end='', flush=True) if d else None)(ser.read(ser.in_waiting or 1)) \
	    for _ in iter(lambda: time.time() < end, False) \
	]; \
	ser.close()"
