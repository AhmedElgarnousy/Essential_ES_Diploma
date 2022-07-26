#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SPI_interface.h"

#include"util/delay.h"

void main(void)
{
	PORT_voidInit();
	SPI_voidInitMaster();

	while(1)
	{
		SPI_u8TranSceive(1);
		_delay_ms(10);
	}

}
