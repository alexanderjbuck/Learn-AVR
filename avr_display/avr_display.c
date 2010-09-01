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

#include "lcd.h"

int main() {
	DDRC |= (1<<PC4);
	_delay_ms(100);
	lcd_init();
	FILE lcd_stream = FDEV_SETUP_STREAM(lcd_putchar, 0,_FDEV_SETUP_WRITE);
	int i = 0;
	
	lcd_clear_and_home();
	lcd_write_string(PSTR("Alex + Christina"));

	while (1) {
		lcd_line_two();
		if (i) {
			lcd_write_string(PSTR("NY, CA 2010"));
		} else {
			lcd_write_string(PSTR("           "));
		}
		i = (i+1) % 2;
		_delay_ms(1000);
	}
	

	return 0;
}
