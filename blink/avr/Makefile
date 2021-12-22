EXEC = blink.s
ARDUINO_USB ?= /dev/ttyACM0

all: compile

compile:
	avra $(EXEC)

upload: compile
	avrdude -F -V -c arduino -p ATMEGA328p -P ${ARDUINO_USB} -b 115200 -U flash:w:$(EXEC).hex

clean:
	rm $(EXEC).hex $(EXEC).cof $(EXEC).eep.hex $(EXEC).obj
