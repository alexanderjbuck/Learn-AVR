PROJECT=avr_blink
GCCFLAGS=-g -Os -Wall -mmcu=atmega328p
LINKFLAGS=-L lib -Wl,-u,vfprintf -lprintf_flt -Wl,-u,vfscanf -lscanf_flt -lm
AVRDUDEFLAGS=-c usbtiny -p m328p
LINKOBJECTS=
INCLUDE=

all:	project-upload

compile:${PROJECT}.c
	avr-gcc -static -I ${INCLUDE} ${GCCFLAGS} ${LINKFLAGS} -o ${PROJECT}.o ${PROJECT}.c ${LINKOBJECTS}
	avr-objcopy -j .text -j .data -O ihex ${PROJECT}.o ${PROJECT}.hex
	
${PROJECT}.hex:	compile
	
project-upload:	${PROJECT}.hex
	avrdude ${AVRDUDEFLAGS} -U flash:w:${PROJECT}.hex:a

fuses:
	avrdude ${AVRDUDEFLAGS} -U lfuse:w:0xd6:m -U hfuse:w:0xd9:m

showfuses:
	avrdude ${AVRDUDEFLAGS} -U lfuse:r:-:h

clean:
	rm -f *.o
	rm -f ${PROJECT}.hex
