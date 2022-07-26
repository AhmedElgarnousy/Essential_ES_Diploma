
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"
#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"#include "LED_interface.h"


LED_u8Turn_On(LED_t*Copy_u8Ptr)
{
	u8 Local_u8ErrorState=0;

	if(Copy_u8Ptr->connType==LED_u8Source)
	{
		DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_HIGH);
	}
	else
	{
		DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_LOW);
	}
	return Local_u8ErrorState=1;
}
/*********************************************************/
LED_u8Turn_Off(LED_t*Copy_u8Ptr)
{
	u8 Local_u8ErrorState=0;

		if(Copy_u8Ptr->connType==LED_u8Source)
		{
			DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_OUTPUT);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_LOW);
		}
		else
		{
			DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_OUTPUT);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN5,DIO_u8PIN_HIGH);
		}
}
