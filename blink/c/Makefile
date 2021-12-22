CFLAGS ?= -Os -DF_APU=16000000UL -mmcu=atmega328p
LDFLAGS ?= -mmcu=atmega328p
# Path where your Arduino Uno is connected to
ARDUINO_USB ?= /dev/ttyACM0

all: blink.hex

blink.hex: blink.exe
	avr-objcopy -O ihex -R .eeprom blink.exe blink.hex

blink.exe: blink.o
	avr-gcc $(LDFLAGS) -o $@ $^

blink.o: blink.c
	avr-gcc $(CFLAGS) -c -o $@ $<

upload: blink.hex
	avrdude -F -V -c arduino -p ATMEGA328p -P ${ARDUINO_USB} -b 115200 -U flash:w:blink.hex  

clean:
	rm -f blink.elf blink.hex blink.o blink.exe
