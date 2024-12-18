#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "WatchDog_interface.h"
#include "GIE_interface.h"
#include "LED_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>


void main()
{
	PORT_voidInit();
	CLCD_voidInit();

	LED_t Led1 = {DIO_u8PORTC, DIO_u8PIN0, LED_CONN_SRC};
	CLCD_voidGoToXY(0,0);
	CLCD_voidSendString("Watch Dog");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("Reset each 1sec");

	LED_u8TurnOn(&Led1);
	_delay_ms(1000);
	LED_u8TurnOff(&Led1);
	_delay_ms(1000);

	GIE_voidEnable();
	WatchDog_voidSleep(WDT_1_sec);
//	WatchDog_voidDisable();

	while(1);
}
