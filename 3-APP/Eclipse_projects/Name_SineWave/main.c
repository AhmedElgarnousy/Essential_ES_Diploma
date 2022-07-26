#include"STD_TYPES.h"
#include  "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"

#include "util/delay.h"

#define time 60

void main()
{


	PORT_voidInit();
	CLCD_voidInit();

	u8 alf_pattern[7]={
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
	u8 i,j;
	while(1)
	{

		CLCD_voidWriteSpecialCharacter(&alf_pattern,0,1,15);

		CLCD_voidWriteSpecialCharacter(&ha_pattern,1,1,14);

		CLCD_voidWriteSpecialCharacter(&mim_pattern,2,1,13);

		CLCD_voidWriteSpecialCharacter(&dal_pattern,3,1,12);
		_delay_ms(time);
		CLCD_voidSendCommand(1);

		CLCD_voidWriteSpecialCharacter(&alf_pattern,0,0,11);

		CLCD_voidWriteSpecialCharacter(&ha_pattern,1,0,10);

		CLCD_voidWriteSpecialCharacter(&mim_pattern,2,0,9);

		CLCD_voidWriteSpecialCharacter(&dal_pattern,3,0,8);
		_delay_ms(time);
		CLCD_voidSendCommand(1);

			CLCD_voidWriteSpecialCharacter(&alf_pattern,0,1,7);

			CLCD_voidWriteSpecialCharacter(&ha_pattern,1,1,6);

			CLCD_voidWriteSpecialCharacter(&mim_pattern,2,1,5);

			CLCD_voidWriteSpecialCharacter(&dal_pattern,3,1,4);

			_delay_ms(time);

			CLCD_voidSendCommand(1);

				CLCD_voidWriteSpecialCharacter(&alf_pattern,0,0,3);

				CLCD_voidWriteSpecialCharacter(&ha_pattern,1,0,2);

				CLCD_voidWriteSpecialCharacter(&mim_pattern,2,0,1);

				CLCD_voidWriteSpecialCharacter(&dal_pattern,3,0,0);
				_delay_ms(time);

	}
}

