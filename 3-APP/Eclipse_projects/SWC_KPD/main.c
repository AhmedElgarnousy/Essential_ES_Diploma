
#include"STD_TYPES.h"

#include"PORT_interface.h"
#include"CLCD_interface.h"
#include"KPD_interface.h"


void main(void)
{
	u8 Local_u8Key;
	PORT_voidInit();
	CLCD_voidInit();

	while(1)
	{

		do
		{
			Local_u8Key=KPD_u8GetPressedKey();
		}while(Local_u8Key == KPD_NO_PRESSED_KEY);

		CLCD_voidSendData(Local_u8Key+'0');

	}
}
