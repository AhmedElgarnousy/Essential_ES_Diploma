#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"
#include "LED_interface.h"
//#include ""

LED_t APP_Led1 = {DIO_u8PORTB, DIO_u8PIN0, LED_CONN_SRC};
LED_t APP_Led2 = {DIO_u8PORTB, DIO_u8PIN1, LED_CONN_SRC};
LED_t APP_Led3 = {DIO_u8PORTB, DIO_u8PIN2, LED_CONN_SRC};


void ISR_COMPARE_MATCH_MODE(void);

int main(void)
{
	PORT_voidInit();
	GIE_voidEnable();
	TIMER0_voidInit();
	TIMER0_voidSetCompMatchValue(125);

	TIMER0_u8SetCallBack(ISR_COMPARE_MATCH_MODE);

//	while(1);
	while(1){}

	return 0;
}

// 3 PWM signal
void ISR_COMPARE_MATCH_MODE(void)
{
	static u8 counter = 0;
	counter ++;
	if(counter == 5)
	{
		LED_u8TurnOff(&APP_Led1);
	}
	else if(counter == 10)
	{
		LED_u8TurnOff(&APP_Led2);
	}
	else if(counter == 15)
	{
		LED_u8TurnOff(&APP_Led3);
	}
	else if(counter == 20)
	{
		LED_u8TurnOn(&APP_Led1);
		LED_u8TurnOn(&APP_Led2);
		LED_u8TurnOn(&APP_Led3);
		counter = 0;
	}

}
