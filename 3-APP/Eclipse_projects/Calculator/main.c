
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"


void main()
{
	PORT_voidInit();
	CLCD_voidInit();

	 u8 KPD;

	while(1)
	{
		do
		{
			KPD_u8GetPressedKey();

		}while(KPD_u8GetPressedKey() == KPD_NO_PRESSED_KEY);

		KPD = KPD_u8GetPressedKey();
		CLCD_voidWriteNumber(KPD);


	}

}
