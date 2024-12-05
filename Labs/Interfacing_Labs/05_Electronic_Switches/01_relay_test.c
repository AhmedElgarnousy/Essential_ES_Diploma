#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "Relay_interface.h"
#include <util/delay.h>



void main()
{
	PORT_voidInit();
	while(1)
	{
		RELAY_voidActivate(DIO_u8PORTC, DIO_u8PIN4);
		_delay_ms(5000);
		RELAY_voidDeactivate(DIO_u8PORTC, DIO_u8PIN4);
		_delay_ms(5000);

	}
}
