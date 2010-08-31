/* AVR Blink
 * Alexander Buck
 * 2010-07-27
 */

#include "config.h"

#include <stdio.h>
#include <math.h>

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/delay.h>
#include <inttypes.h>

int main() {
	DDRC |= (1<<PC4);

	while (1) {
		PORTC |= (1<<PC4);
		_delay_ms(500);
		PORTC &= ~(1<<PC4);
		_delay_ms(500);
	}

	return 0;
}
