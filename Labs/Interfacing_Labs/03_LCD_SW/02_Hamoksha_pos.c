#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "SW_interface.h"


void main()
{
	PORT_voidInit();
	CLCD_voidInit();

	u8 Local_Swstate1 = SW_NOT_PRESSED; // up
	u8 Local_Swstate2 = SW_NOT_PRESSED; // down
	u8 Local_Swstate3 = SW_NOT_PRESSED; // right
	u8 Local_Swstate4 = SW_NOT_PRESSED; // left

	u8 x_pos = 0;
	u8 y_pos = 0;

	u8 Hamoksha[8] = { 0b00001110, 0b00010001, 0b00001110, 0b00000100, 0b00011111, 0b00000100, 0b11111111, 0b00000100 };

	CLCD_voidWriteSpecialCharacter(Hamoksha, 1, x_pos, y_pos);

	while(1)
	{
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN2, SW_SELFLOCKING, SW_PULL_UP, &Local_Swstate1);
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN3, SW_SELFLOCKING, SW_PULL_UP, &Local_Swstate2);
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN4, SW_SELFLOCKING, SW_PULL_UP, &Local_Swstate3);
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN5, SW_SELFLOCKING, SW_PULL_UP, &Local_Swstate4);

		if(Local_Swstate1 == SW_PRESSED) // up
		{
			if(x_pos == 1)
			{
				x_pos = 0;
				CLCD_voidClearScreen();
				CLCD_voidWriteSpecialCharacter(Hamoksha, 1, x_pos, y_pos);
			}
		}

		if(Local_Swstate2 == SW_PRESSED) // down
		{
			if(x_pos == 0)
			{
				x_pos = 1;
				CLCD_voidClearScreen();
				CLCD_voidWriteSpecialCharacter(Hamoksha, 1, x_pos, y_pos);
			}
		}

		if(Local_Swstate3 == SW_PRESSED) // right
		{
			if(y_pos <= 15)
			{
				y_pos ++;
				CLCD_voidClearScreen();
				CLCD_voidWriteSpecialCharacter(Hamoksha, 1, x_pos, y_pos);
			}
		}

		if(Local_Swstate4 == SW_PRESSED) // left
		{
			if(y_pos > 0)
			{
				y_pos --;
				CLCD_voidClearScreen();
				CLCD_voidWriteSpecialCharacter(Hamoksha, 1, x_pos, y_pos);
			}
		}
	}
}
