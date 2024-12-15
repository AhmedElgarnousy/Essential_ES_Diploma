#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>


void APP_voidADCNotification(void);

u16 APP_u8digitalVal ;

void main()
{
	PORT_voidInit();
	CLCD_voidInit();
	GIE_voidEnable();
	ADC_voidInit();

	while(1)
	{
		// doesn't work correctly
//		ADC_u8StartConversionSynch(SINGLE_ENDED_ADC0, Local_pu8digitalVal);
//		u16 miliVolt = (u16)(( (u32)(*Local_pu8digitalVal) * 5000UL) / 256UL);

		ADC_u8StartConversionAsynch(SINGLE_ENDED_ADC0, &APP_u8digitalVal, APP_voidADCNotification);
	}
}


void APP_voidADCNotification(void) {
	u16 miliVolt = (u16)(((u32)APP_u8digitalVal * 5000UL) / 256UL);
	u8 temp = miliVolt / 10;

	CLCD_voidWriteNumber(temp);
	CLCD_voidSendString(" C by Asynch");
	_delay_ms(200);
	CLCD_voidClearScreen();
}
