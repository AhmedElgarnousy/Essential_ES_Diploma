#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
#include "LED_interface.h"
//#include ""

LED_t APP_RedLed = {DIO_u8PORTC, DIO_u8PIN0, LED_CONN_SRC};

void ISR_COMPARE_MATCH_MODE(void);

void main()
{
	PORT_voidInit();
	GIE_voidEnable();
	TIMER0_voidInit();
	TIMER0_voidSetCompMatchValue(125);

	TIMER0_u8SetCallBack(&ISR_COMPARE_MATCH_MODE);

	while(1);

}


void ISR_COMPARE_MATCH_MODE(void)
{
	static u8 counter = 0;
	counter ++;
	if(counter == 5)
	{
		LED_u8TurnOff(&APP_RedLed);
	}
	else if(counter == 20)
	{
		LED_u8TurnOn(&APP_RedLed);
		counter = 0;
	}
}
