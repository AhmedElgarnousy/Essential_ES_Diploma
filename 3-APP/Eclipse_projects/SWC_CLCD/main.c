#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "util/delay.h"

#include"DIO_interface.h"
#include"PORT_interface.h"

#include"CLCD_interface.h"

#define time	80


void main(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	u8 Local_u8Counter;

	/*Location1 in CGRAM For Hamoksha
	 Location2 in CGRAM For BALL
	 */
	u8 Hamoksha[8]={
					0b00001110,
					0b00010001,
					0b00001110,
					0b00000100,
					0b00011111,
					0b00000100,
					0b11111111
								};

	CLCD_voidSendData('b');
	CLCD_voidWriteSpecialCharacter(&Hamoksha,0,1,0);

	while(1)
	{

	}
}
