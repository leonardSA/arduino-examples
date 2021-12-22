CFLAGS ?= -Os -DF_APU=16000000UL -mmcu=atmega328p
LDFLAGS ?= -mmcu=atmega328p
# Path where your Arduino Uno is connected to
ARDUINO_USB ?= /dev/ttyACM0
PROG=blink-interrupt

all: $(PROG).hex

$(PROG).hex: $(PROG).exe
	avr-objcopy -O ihex -R .eeprom $(PROG).exe $(PROG).hex

$(PROG).exe: $(PROG).o
	avr-gcc $(LDFLAGS) -o $@ $^

$(PROG).o: $(PROG).c
	avr-gcc $(CFLAGS) -c -o $@ $<

upload: $(PROG).hex
	avrdude -F -V -c arduino -p ATMEGA328p -P ${ARDUINO_USB} -b 115200 -U flash:w:$(PROG).hex  

clean:
	rm -f $(PROG).elf $(PROG).hex $(PROG).o $(PROG).exe
