/*************************************************************************/
/*************************************************************************/
/********************  Author : Ahmed Kamal    ****************************/
/********************  Layer  : HALL           ****************************/
/********************  SWC    : SSD               *************************/
/********************  version: 1.00          ****************************/
/*************************************************************************/
/*************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"
#include"SSD_interface.h"
#include"SSD_config.h"
#include"SSD_private.h"

u8 SSD_u8SetNumber(u8 Copy_u8Number,SSD_t*Copy_u16Ptr)
{
	u8 Local_u8ErrorState=0;

	if(Copy_u16Ptr -> COM_Type == SSD_COM_CATHODE)
	{
		DIO_u8SetPortValue(Copy_u16Ptr->Port, Copy_u8Number);
	}
	else
	{
		DIO_u8SetPortValue(Copy_u16Ptr->Port, ~Copy_u8Number);
	}
	return Local_u8ErrorState;
}

u8 SSD_u8Enable_SDD(SSD_t * Copy_u16Ptr) {
	u8 Local_u8ErrorStatus = 0;
	
	if(Copy_u16Ptr == NULL)
	{
		Local_u8ErrorStatus = 1;
	}
	
	if(Copy_u16Ptr->COM_Type == SSD_COM_ANODE)
	{
		DIO_u8SetPinValue(Copy_u16Ptr->EnablePort,Copy_u16Ptr->EnablePin,DIO_u8PIN_HIGH);
	}
	else if(Copy_u16Ptr->COM_Type == SSD_COM_CATHODE)
	{ //
		DIO_u8SetPinValue(Copy_u16Ptr->EnablePort,Copy_u16Ptr->EnablePin,DIO_u8PIN_HIGH); // LOW but i have transistor
	}
	else
	{
		Local_u8ErrorStatus =1;
	}
	
	return Local_u8ErrorStatus;
}

u8 SSD_u8Disable_SDD(SSD_t * Copy_u16Ptr) {
	u8 Local_u8ErrorStatus = 0;
	
	if(Copy_u16Ptr == NULL)
	{
		Local_u8ErrorStatus = 1;
	}
	
	if(Copy_u16Ptr->COM_Type == SSD_COM_ANODE)
	{
		DIO_u8SetPinValue(Copy_u16Ptr->EnablePort,Copy_u16Ptr->EnablePin,DIO_u8PIN_LOW);
	}
	else if(Copy_u16Ptr->COM_Type == SSD_COM_CATHODE)
	{ //
		DIO_u8SetPinValue(Copy_u16Ptr->EnablePort,Copy_u16Ptr->EnablePin,DIO_u8PIN_LOW); // HIGH but i have trasistor
	}
	else
	{
		Local_u8ErrorStatus =1;
	}
	
	return Local_u8ErrorStatus;
}


/*

void SSD_2Mux_display_num(u8 SSD_port_num, u8 SSD_COM_port, 
			u8 seg1_COM, u8 seg2_COM ,u8 display_num, u8 time) {

	if(display_num < 0 | display_num > 99)
		return;

	int first_digit = 0;
	int second_digit = 0;
	int num = display_num;
	u8 sevenSegNums[10] = { 0b01111110, 0b00001100, 0b10110110, 0b10011110, 0b11001100, 0b11011010, 0b11111010, 0b00001110, 0b11111110, 0b11011110};

	second_digit = num % 10; // get last digit
	first_digit = num / 10; // remove last digit


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
						PORTB = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTA, seg2_COM);; // turn off seg2
						SET_BIT(PORTA, seg1_COM); // turn on seg1
						PORTB = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 3:
						CLR_BIT(PORTA, seg1_COM);  // turn off seg1
						SET_BIT(PORTA, seg2_COM); // turn on seg2
						PORTC = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTA, seg2_COM);; // turn off seg2
						SET_BIT(PORTA, seg1_COM); // turn on seg1
						PORTC = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 4:
						CLR_BIT(PORTA, seg1_COM);  // turn off seg1
						SET_BIT(PORTA, seg2_COM); // turn on seg2
						PORTD = sevenSegNums[first_digit];
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
						PORTB = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTB, seg2_COM);; // turn off seg2
						SET_BIT(PORTB, seg1_COM); // turn on seg1
						PORTB = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 3:
						CLR_BIT(PORTB, seg1_COM);  // turn off seg1
						SET_BIT(PORTB, seg2_COM); // turn on seg2
						PORTC = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTB, seg2_COM);; // turn off seg2
						SET_BIT(PORTB, seg1_COM); // turn on seg1
						PORTC = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 4:
						CLR_BIT(PORTB, seg1_COM);  // turn off seg1
						SET_BIT(PORTB, seg2_COM); // turn on seg2
						PORTD = sevenSegNums[first_digit];
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
						for (int i = 0 ; i < time ; i++)
						{
							CLR_BIT(PORTC, seg1_COM);  // turn off seg1
							SET_BIT(PORTC, seg2_COM); // turn on seg2
							PORTA = sevenSegNums[first_digit];
							_delay_ms(10);

							CLR_BIT(PORTC, seg2_COM);; // turn off seg2
							SET_BIT(PORTC, seg1_COM); // turn on seg1
							PORTA = sevenSegNums[second_digit];
							_delay_ms(10);
						}
						break;

					case 2:
						CLR_BIT(PORTC, seg1_COM);  // turn off seg1
						SET_BIT(PORTC, seg2_COM); // turn on seg2
						PORTB = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTC, seg2_COM);; // turn off seg2
						SET_BIT(PORTC, seg1_COM); // turn on seg1
						PORTB = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 3:
						CLR_BIT(PORTC, seg1_COM);  // turn off seg1
						SET_BIT(PORTC, seg2_COM); // turn on seg2
						PORTC = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTC, seg2_COM);; // turn off seg2
						SET_BIT(PORTC, seg1_COM); // turn on seg1
						PORTC = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 4:
						CLR_BIT(PORTC, seg1_COM);  // turn off seg1
						SET_BIT(PORTC, seg2_COM); // turn on seg2
						PORTD = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTC, seg2_COM);; // turn off seg2
						SET_BIT(PORTC, seg1_COM); // turn on seg1
						PORTD = sevenSegNums[second_digit];
						_delay_ms(10);
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
						_delay_ms(10);
						break;
					case 2:
						CLR_BIT(PORTD, seg1_COM);  // turn off seg1
						SET_BIT(PORTD, seg2_COM); // turn on seg2
						PORTB = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTD, seg2_COM);; // turn off seg2
						SET_BIT(PORTD, seg1_COM); // turn on seg1
						PORTB= sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 3:
						CLR_BIT(PORTD, seg1_COM);  // turn off seg1
						SET_BIT(PORTD, seg2_COM); // turn on seg2
						PORTC = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTD, seg2_COM);; // turn off seg2
						SET_BIT(PORTD, seg1_COM); // turn on seg1
						PORTC = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					case 4:
						CLR_BIT(PORTD, seg1_COM);  // turn off seg1
						SET_BIT(PORTD, seg2_COM); // turn on seg2
						PORTD = sevenSegNums[first_digit];
						_delay_ms(10);

						CLR_BIT(PORTD, seg2_COM);; // turn off seg2
						SET_BIT(PORTD, seg1_COM); // turn on seg1
						PORTD = sevenSegNums[second_digit];
						_delay_ms(10);
						break;
					default: break;
				}
			default:break;
		} // parent switch
} // end
*/