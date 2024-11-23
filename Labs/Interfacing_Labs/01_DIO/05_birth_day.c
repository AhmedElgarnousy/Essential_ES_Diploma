
#include "STD_TYPES.h"
#include <util/delay.h>
#include <avr/io.h>

#define RED PC0
#define GRN PC1
#define BLU PC2

#define SEG1_COM PC6
#define SEG2_COM PC7

#define SET_BIT(VAR,BIT_NO) (VAR|=(1<<BIT_NO))
#define CLR_BIT(VAR,BIT_NO) (VAR&=~(1<<BIT_NO))
#define TOGGLE_BIT(VAR,BIT_NO) (VAR^=(1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO) ((VAR>>BIT_NO)&1)


void SSD_2Mux_display_num(u8 SSD_port_num, u8 SSD_COM_port, u8 seg1_COM, u8 seg2_COM ,u8 display_num, u8 time) {
	
	if(display_num < 0 | display_num > 99)
		return;

	int first_digit = 0;
	int second_digit = 0;
	int num = display_num;
	u8 sevenSegNums[10] = { 0b01111110, 0b00001100, 0b10110110, 0b10011110, 0b11001100, 0b11011010, 0b11111010, 0b00001110, 0b11111110, 0b11011110};

	second_digit = num % 10; // get last digit
	first_digit = num / 10; // remove last digit


	for (int i = 0 ; i < time ; i++)
	{
		switch(SSD_COM_port)
		{
			case 1:
				switch(SSD_port_num)
				{
					case 1:
						CLR_BIT(PORTA, seg1_COM);  // turn off seg1
						SET_BIT(PORTA, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTA, seg2_COM);; // turn off seg2
						SET_BIT(PORTA, seg1_COM); // turn on seg1
						PORTA = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 2:
						CLR_BIT(PORTA, seg1_COM);  // turn off seg1
						SET_BIT(PORTA, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTA, seg2_COM);; // turn off seg2
						SET_BIT(PORTA, seg1_COM); // turn on seg1
						PORTB = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 3:
						CLR_BIT(PORTA, seg1_COM);  // turn off seg1
						SET_BIT(PORTA, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTA, seg2_COM);; // turn off seg2
						SET_BIT(PORTA, seg1_COM); // turn on seg1
						PORTC = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 4:
						CLR_BIT(PORTA, seg1_COM);  // turn off seg1
						SET_BIT(PORTA, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTA, seg2_COM);; // turn off seg2
						SET_BIT(PORTA, seg1_COM); // turn on seg1
						PORTD = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					default: break;
				}
			case 2:
				switch(SSD_port_num)
				{
					case 1:
						CLR_BIT(PORTB, seg1_COM);  // turn off seg1
						SET_BIT(PORTB, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTB, seg2_COM);; // turn off seg2
						SET_BIT(PORTB, seg1_COM); // turn on seg1
						PORTA = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 2:
						CLR_BIT(PORTB, seg1_COM);  // turn off seg1
						SET_BIT(PORTB, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTB, seg2_COM);; // turn off seg2
						SET_BIT(PORTB, seg1_COM); // turn on seg1
						PORTB = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 3:
						CLR_BIT(PORTB, seg1_COM);  // turn off seg1
						SET_BIT(PORTB, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTB, seg2_COM);; // turn off seg2
						SET_BIT(PORTB, seg1_COM); // turn on seg1
						PORTC = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 4:
						CLR_BIT(PORTB, seg1_COM);  // turn off seg1
						SET_BIT(PORTB, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTB, seg2_COM);; // turn off seg2
						SET_BIT(PORTB, seg1_COM); // turn on seg1
						PORTD = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					default: break;
				}
			case 3:
				switch(SSD_port_num)
				{
					case 1:
						CLR_BIT(PORTC, seg1_COM);  // turn off seg1
						SET_BIT(PORTC, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTC, seg2_COM);; // turn off seg2
						SET_BIT(PORTC, seg1_COM); // turn on seg1
						PORTA = sevenSegNums[second_digit];
						_delay_ms(10);
					break;

					case 2:
						CLR_BIT(PORTC, seg1_COM);  // turn off seg1
						SET_BIT(PORTC, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTC, seg2_COM);; // turn off seg2
						SET_BIT(PORTC, seg1_COM); // turn on seg1
						PORTB = sevenSegNums[second_digit];
						break;
					case 3:
						CLR_BIT(PORTC, seg1_COM);  // turn off seg1
						SET_BIT(PORTC, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTC, seg2_COM);; // turn off seg2
						SET_BIT(PORTC, seg1_COM); // turn on seg1
						PORTC = sevenSegNums[second_digit];
						break;
					case 4:
						CLR_BIT(PORTC, seg1_COM);  // turn off seg1
						SET_BIT(PORTC, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTC, seg2_COM);; // turn off seg2
						SET_BIT(PORTC, seg1_COM); // turn on seg1
						PORTD = sevenSegNums[second_digit];
						break;
					default: break;
				}
			case 4:
				switch(SSD_port_num)
				{
					case 1:
						CLR_BIT(PORTD, seg1_COM);  // turn off seg1
						SET_BIT(PORTD, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTD, seg2_COM);; // turn off seg2
						SET_BIT(PORTD, seg1_COM); // turn on seg1
						PORTA = sevenSegNums[second_digit];
						break;
					case 2:
						CLR_BIT(PORTD, seg1_COM);  // turn off seg1
						SET_BIT(PORTD, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTD, seg2_COM);; // turn off seg2
						SET_BIT(PORTD, seg1_COM); // turn on seg1
						PORTB= sevenSegNums[second_digit];
						break;
					case 3:
						CLR_BIT(PORTD, seg1_COM);  // turn off seg1
						SET_BIT(PORTD, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTD, seg2_COM);; // turn off seg2
						SET_BIT(PORTD, seg1_COM); // turn on seg1
						PORTC = sevenSegNums[second_digit];
						break;
					case 4:
						CLR_BIT(PORTD, seg1_COM);  // turn off seg1
						SET_BIT(PORTD, seg2_COM); // turn on seg2
						PORTA = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTD, seg2_COM);; // turn off seg2
						SET_BIT(PORTD, seg1_COM); // turn on seg1
						PORTD = sevenSegNums[second_digit];
						break;
					default: break;
				}
			default:break;
		} // parent switch
	} // for
} // end


void main(void)
{
	DDRA = 0xff;
	DDRC = 0xff;

	DDRC |= (1<< SEG1_COM); // enable BC546 transistor for common cathode pin out (fares pcb)
	DDRC |= (1<< SEG2_COM);


	u8 sevenSegNums[10] = { 0b01111110, 0b00001100, 0b10110110, 0b10011110, 0b11001100, 0b11011010, 0b11111010, 0b00001110, 0b11111110, 0b11011110};

    while(1)
    {
    	// 04
    	for(int i = 0; i < 100; i++) {
			// enable seven seg 2 and disable seg1
			PORTC &= ~(1<< SEG1_COM); // turn off seg1
			PORTC |= (1<< SEG2_COM); // turn on seg2
			PORTA = sevenSegNums[0];
			_delay_ms(10);

			PORTC &= ~(1<< SEG2_COM); // turn off seg2
			PORTC |= (1<< SEG1_COM); // turn on seg1
			PORTA = sevenSegNums[4];
			_delay_ms(10);
    	}

    	//_delay_ms(1000);

    	// 08
    	for(int i = 0; i < 100; i++) {
			// enable seven seg 2 and disable seg1
			PORTC &= ~(1<< SEG1_COM); // turn off seg1
			PORTC |= (1<< SEG2_COM); // turn on seg2
			PORTA = sevenSegNums[0];
			_delay_ms(10);

			PORTC &= ~(1<< SEG2_COM); // turn off seg2
			PORTC |= (1<< SEG1_COM); // turn on seg1
			PORTA = sevenSegNums[8];
			_delay_ms(10);
    	}

    	// 20
    	for(int i = 0; i < 100; i++) {
			// enable seven seg 2 and disable seg1
			PORTC &= ~(1<< SEG1_COM); // turn off seg1
			PORTC |= (1<< SEG2_COM); // turn on seg2
			PORTA = sevenSegNums[2];
			_delay_ms(10);

			PORTC &= ~(1<< SEG2_COM); // turn off seg2
			PORTC |= (1<< SEG1_COM); // turn on seg1
			PORTA = sevenSegNums[0];
			_delay_ms(10);
    	}

    	for(int i = 0; i < 100; i++) {
			// 01
			PORTC &= ~(1<< SEG1_COM); // turn off seg1
			PORTC |= (1<< SEG2_COM); // turn on seg2
			PORTA = sevenSegNums[0];
			_delay_ms(10);

			PORTC &= ~(1<< SEG2_COM); // turn off seg2
			PORTC |= (1<< SEG1_COM); // turn on seg1
			PORTA = sevenSegNums[1];
			_delay_ms(10);
    	}
    }
}
