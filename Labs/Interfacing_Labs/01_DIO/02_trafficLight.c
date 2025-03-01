
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

	DDRC |= (1<< SEG2_COM); // enable BC546 transistor for common cathode pin out (fares pcb)
	PORTC |= (1<< SEG2_COM);

	u8 sevenSegNums[10] = { 0b01111110, 0b00001100, 0b10110110, 0b10011110, 0b11001100, 0b11011010, 0b11111010, 0b00001110, 0b11111110, 0b11011110};

    while(1)
    {
    	PORTC |= (1 << RED);
    	// 1 - 10
    	for(int i = 0; i < 10; i++) {
    		 PORTA = sevenSegNums[i];
    		_delay_ms(1000);
    	}
    	PORTC &= ~(1 << RED);

    	PORTC |= (1 << BLU);
    	 // 1 - 10
    	 for(int i = 0; i < 3; i++) {
    	    PORTA = sevenSegNums[i];
    	    _delay_ms(1000);
    	 }
    	 PORTC &= ~(1 << BLU);

    	 PORTC |= (1 << GRN);
    	  // 1 - 10
    	  for(int i = 0; i < 10; i++) {
    	     PORTA = sevenSegNums[i];
    	     _delay_ms(1000);
    	   }
    	  PORTC &= ~(1 << GRN);
    }
}
