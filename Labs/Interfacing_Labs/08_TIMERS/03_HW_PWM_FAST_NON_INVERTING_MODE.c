#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "LED_interface.h"

#include <util/delay.h>

void main()
{
	PORT_voidInit();
	TIMER0_voidInit();
	while(1)
	{
	for (u8 i = 0; i < 255; i++)
	{
		TIMER0_voidSetCompMatchValue(i);
		_delay_ms(30);
	}
	}
}
