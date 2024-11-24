#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "LED_interface.h"
#include "SW_interface.h"



void main(void)
{
	PORT_voidInit();

	u8 sw_status = 0;

	LED_t red_led = {DIO_u8PORTC, DIO_u8PIN1, LED_CONN_SRC};

	while(1)
	{
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN2, SW_SELFLOCKING, SW_PULL_UP, &sw_status);

		if(sw_status == SW_PRESSED)
		{
			LED_u8TurnOn(&red_led);
		}
		else
		{
			LED_u8TurnOff(&red_led);
		}
	}
}
