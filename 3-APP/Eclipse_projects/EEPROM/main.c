#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TWI_interface.h"
#include "PORT_interface.h"

#include "EEPROM_interface.h"

#include "util/delay.h"

void main(void)
{
	u8 App_u8Var;

	PORT_voidInit();
	TWI_voidMasterInit(0);

	EEPROM_voidSendDataByte(0,0x44);
	_delay_ms(10);
	EEPROM_voidReadDataByte(0,&App_u8Var);
	DIO_u8SetPortValue(DIO_u8PORTA,App_u8Var);

	while(1)
	{



	}

}
