
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"util/delay.h"

#include"DIO_interface.h"
#include"PORT_interface.h"




void main()
{
	PORT_voidInit();

	while(1)
	{
u8 Local_u8Iterator;
		for(Local_u8Iterator=0;Local_u8Iterator<255;Local_u8Iterator++)
		{
			DIO_u8SetPortValue(DIO_u8PORTA,Local_u8Iterator);
			_delay_ms(5);
		}
		for(Local_u8Iterator=0;Local_u8Iterator<255;Local_u8Iterator++)
				{
					DIO_u8SetPortValue(DIO_u8PORTA,255-Local_u8Iterator);
					_delay_ms(5);
				}


	}



}

