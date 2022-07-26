
#include "util/delay.h"
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"

void main()
{
	PORT_voidInit();

	while(1)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		_delay_us(50);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		_delay_us(50);


	}


}

