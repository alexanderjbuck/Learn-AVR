/* ATTINY Blink
 * Alexander Buck
 * 2010-08-10
 */

#include "config.h"

#include <avr/io.h>
#include <avr/delay.h>

/*
	If the delay passed to _delay_ms is a variable, then the
	floating point library will be included.  This will make
	the program larger than will fit in 1k.  To allow for a
	variable delay I added this function.  The overhead of
	repeatedly calling _delay_ms may cause some inaccuracy
	so this could be improved.
*/
void delay_ms(int millis) {
	while (millis > 0) {
		_delay_ms(1);
		millis--;
	}
}

void cycle_led(int delay) {
	PORTB |= (1<<PB0);
	delay_ms(delay);
	PORTB &= ~(1<<PB0);
	delay_ms(delay);
}

int main() {
	DDRB |= (1<<PB0);	//PB0 as output
	DDRB &= ~(1<<PB3);	//PB3 as input

	int delay;

	while (1) {
		/* The blink rate is changed based on the state
		of the switch.
		*/
		if (bit_is_clear(PINB,PB3)) {
			delay = 500;
		} else {
			delay = 100;
		}

		cycle_led(delay);
	}

	return 0;
}
