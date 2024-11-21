
#include "STD_TYPES.h" 
// #include <util/delay.h>
// #include <avr/io.h>

void main(void)
{
	DDRA = 0xff;

	DDRC |= (1<< 7); // enable BC546 transistor for common cathode pin out
	PORTC |= (1<< 7);

	u8 sevenSegNums[10] =
    {
        0b01111110,
        0b00001100,
        0b10110110,
        0b10011110,
        0b11001100,
        0b11011010,
        0b11111010,
        0b00001110,
        0b11111110,
        0b11011110,
        };

    while(1)
    {
    	for(int i = 0; i < 10; i++) {
    		 PORTA = sevenSegNums[i];
    		_delay_ms(1000);

    	}
    }
}
