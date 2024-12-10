
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "GIE_interface.h"
#include "ADC_interface.h"
#include "LED_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>


void ADC_voidNotification(void) ;

u8 App_pu16ADCReading;

void main(void)
{
	PORT_voidInit();
	ADC_voidInit();
	GIE_voidEnable();
	CLCD_voidInit();

	while(1)
	{
		ADC_u8StartConversionAsynch (SINGLE_ENDED_ADC0, &App_pu16ADCReading, &ADC_voidNotification);
	}
}


void ADC_voidNotification(void) {
	DIO_u8SetPortValue(DIO_u8PORTB, App_pu16ADCReading );
	CLCD_voidGoToXY(1,4);
	CLCD_voidWriteNumber(App_pu16ADCReading);
	_delay_ms(2000);
	CLCD_voidClearScreen();

}
