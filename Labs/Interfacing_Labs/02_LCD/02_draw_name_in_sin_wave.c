#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"PORT_interface.h"
#include"CLCD_interface.h"
#include<util/delay.h>

void main()
{
	PORT_voidInit();
	CLCD_voidInit();

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
		CLCD_voidWriteSpecialCharacter(alf_pattern, 0, 0, 15);
		CLCD_voidWriteSpecialCharacter(ha_pattern, 1, 0, 14);
		CLCD_voidWriteSpecialCharacter(mim_pattern, 2, 0, 13);
		CLCD_voidWriteSpecialCharacter(dal_pattern, 3, 0, 12);
		_delay_ms(1500);
		CLCD_voidClearScreen();

		CLCD_voidWriteSpecialCharacter(alf_pattern, 0, 1, 11);
		CLCD_voidWriteSpecialCharacter(ha_pattern, 1, 1, 10);
		CLCD_voidWriteSpecialCharacter(mim_pattern, 2, 1, 9);
		CLCD_voidWriteSpecialCharacter(dal_pattern, 3, 1, 8);
		_delay_ms(1500);
		CLCD_voidClearScreen();

		CLCD_voidWriteSpecialCharacter(alf_pattern, 0, 0, 7);
		CLCD_voidWriteSpecialCharacter(ha_pattern, 1, 0, 6);
		CLCD_voidWriteSpecialCharacter(mim_pattern, 2, 0, 5);
		CLCD_voidWriteSpecialCharacter(dal_pattern, 3, 0, 4);
		_delay_ms(1500);
		CLCD_voidClearScreen();

		CLCD_voidWriteSpecialCharacter(alf_pattern, 0, 1, 3);
		CLCD_voidWriteSpecialCharacter(ha_pattern, 1, 1, 2);
		CLCD_voidWriteSpecialCharacter(mim_pattern, 2, 1, 1);
		CLCD_voidWriteSpecialCharacter(dal_pattern, 3, 1, 0);
		_delay_ms(1500);
		CLCD_voidClearScreen();

	}

}
