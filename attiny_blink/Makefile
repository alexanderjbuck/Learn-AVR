PROJECT=avr_blink
GCCFLAGS=-g -Os -Wall -mmcu=attiny13
LINKFLAGS=-L lib
AVRDUDEFLAGS=-c usbtiny -p t13
LINKOBJECTS=
INCLUDE=

all:	project-upload

compile:${PROJECT}.c
	avr-gcc -static -I ${INCLUDE} ${GCCFLAGS} ${LINKFLAGS} -o ${PROJECT}.o ${PROJECT}.c ${LINKOBJECTS}
	# Only the text section is copied to make the program smaller
	avr-objcopy -j .text -O ihex ${PROJECT}.o ${PROJECT}.hex
	
${PROJECT}.hex:	compile
	
project-upload:	${PROJECT}.hex
	avrdude ${AVRDUDEFLAGS} -U flash:w:${PROJECT}.hex:a

fuses:
	avrdude ${AVRDUDEFLAGS} -U lfuse:w:0x7A:m -U hfuse:w:0xFF:m

showfuses:
	avrdude ${AVRDUDEFLAGS} -U lfuse:r:-:h -U hfuse:r:-:h

clean:
	rm -f *.o
	rm -f ${PROJECT}.hex
