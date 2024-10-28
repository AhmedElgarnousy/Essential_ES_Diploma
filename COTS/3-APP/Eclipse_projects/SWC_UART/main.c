#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "UART_interface.h"


void main()
{
	PORT_voidInit();
	USART_Init();

	u8 APP_u8Data=0;
	while(1)
	{
		/*
		APP_u8Data=USART_voidReceive();

		if( APP_u8Data=='1' )
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
		else if(APP_u8Data=='2')
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		}

		USART_voidSend('D');*/
	}



}
