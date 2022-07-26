#include<util/delay.h>

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"PORT_interface.h"
#include"DIO_interface.h"


void main()
{
	PORT_voidInit();
	while (1)
	{
		for(u8 i=0;i<25;i++)
		{
			//step1
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			_delay_ms(20);
			//step2
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			_delay_ms(20);
			//step3
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			_delay_ms(20);
			//step4
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
			_delay_ms(20);
		}


		/*
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_LOW);
		_delay_ms(50);

		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		_delay_ms(50);
		*/

	}

}
