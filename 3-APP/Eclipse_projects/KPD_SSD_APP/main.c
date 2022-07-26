#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"PORT_interface.h"
#include"DIO_interface.h"

#include"SSD_config.h"
#include"SSD_private.h"
#include"SSD_interface.h"

#include"KPD_config.h"
#include"KPD_private.h"
#include"KPD_interface.h"





void main(void)
{

	PORT_voidInit();
	u8 Local_u8Key;
	SSD_t SSD={COM_ANODE,DIO_u8PORTC,DIO_u8PORTD,DIO_u8PIN0};

	while(1)
	{
		u8 x=KPD_u8GetPressedKey();
		if(x)
		{
			SSD_u8SetNumber(SSD_u8_THREE,&SSD);
		}


	}



}
