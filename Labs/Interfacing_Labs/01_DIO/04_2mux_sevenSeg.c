
#include "STD_TYPES.h"
#include <util/delay.h>
#include <avr/io.h>

#define RED PC0
#define GRN PC1
#define BLU PC2
#define SEG1_COM PC6
#define SEG2_COM PC7

void main(void)
{
	DDRA = 0xff;
	DDRC = 0xff;

	DDRC |= (1<< SEG1_COM); // enable BC546 transistor for common cathode pin out (fares pcb)
	DDRC |= (1<< SEG2_COM);

	u8 sevenSegNums[10] = { 0b01111110, 0b00001100, 0b10110110, 0b10011110, 0b11001100, 0b11011010, 0b11111010, 0b00001110, 0b11111110, 0b11011110};

    // display number 20
    while(1)
    {
    	// enable 7-seg2 and disable 7-seg1
    	PORTC &= ~(1<< SEG1_COM); // turn off seg1
    	PORTC |= (1<< SEG2_COM); // turn on seg2
    	PORTA = sevenSegNums[2];
    	_delay_ms(10);

        // enable 7-seg1 and disable  7-seg2
    	PORTC &= ~(1<< SEG2_COM); // turn off seg2
    	PORTC |= (1<< SEG1_COM); // turn on seg1
    	PORTA = sevenSegNums[0];
    	_delay_ms(10);
    }
}
