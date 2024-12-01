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
		// move cloclwise
		RELAY_voidActivate(DIO_u8PORTC, DIO_u8PIN4);
		RELAY_voidDeactivate(DIO_u8PORTC, DIO_u8PIN3);
		_delay_ms(5000);

		// STOP
		RELAY_voidDeactivate(DIO_u8PORTC, DIO_u8PIN4);
		RELAY_voidDeactivate(DIO_u8PORTC, DIO_u8PIN3);
		_delay_ms(5000);

		//  move counter cloclwise
		RELAY_voidDeactivate(DIO_u8PORTC, DIO_u8PIN4);
		RELAY_voidActivate(DIO_u8PORTC, DIO_u8PIN3);
		_delay_ms(5000);

		// STOP
		RELAY_voidDeactivate(DIO_u8PORTC, DIO_u8PIN4);
		RELAY_voidDeactivate(DIO_u8PORTC, DIO_u8PIN3);
		_delay_ms(5000);

	}
}
