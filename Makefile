km = default

BUILD = ../../.build/sighol56_$(km).uf2
TARGET = /volumes/RPI-RP2

build:
	qmk compile -km $(km)

flash: build
	bash -c 'while [[ ! -f $(TARGET)/INDEX.HTM ]]; do printf "Waiting...\n"; sleep 1; done; printf "Mounted...\n"; sleep 2'
	cp $(BUILD) $(TARGET)

.PHONY: build flash
