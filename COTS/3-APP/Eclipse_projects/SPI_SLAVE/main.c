#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SPI_interface.h"

#include"util/delay.h"

void main(void)
{
	u8 Local_u8ReceiveData;
	PORT_voidInit();
	SPI_voidInitSlave();

	while(1)
	{
		Local_u8ReceiveData = SPI_u8TranSceive(10);
		_delay_ms(10);
		if(Local_u8ReceiveData == 1)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
	}

}
