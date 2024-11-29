#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"PORT_interface.h"
#include"CLCD_interface.h"
#include<util/delay.h>


void main()
{
	PORT_voidInit();
	CLCD_voidInit();

	CLCD_voidGoToXY(1,1);
	CLCD_voidSendString("Ahmed");

	u8 alf_pattern[7] = {
				0b00001111,
				0b00001000,
				0b00011110,
				0b00000100,
				0b00000100,
				0b00000100,
				0b00000100
	};
	u8 ha_pattern[7]={
				0b00010000,
				0b00001000,
				0b00000100,
				0b00000010,
				0b00011111,
				0b00000000,
				0b00000000
	};
	u8 mim_pattern[7]={
				0b00000000,
				0b00000000,
				0b00000000,
				0b00001110,
				0b00010011,
				0b00001100,
				0b00000000
	};
	u8 dal_pattern[7]={
				0b00000001,
				0b00000001,
				0b00000001,
				0b00011111,
				0b00000000,
				0b00000000,
				0b00000000
	};

	while(1)
	{

	}
}
