#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "ADC_interface.h"
#include "Servo_interface.h"
#include <util/delay.h>


void main(void)
{
	PORT_voidInit();
	TIMER1_voidInit();
	ADC_voidInit();
	TIMER1_voidSetICR(20000);

	u8 Local_u8Angle = 0;
	u16 Local_u16ADCReading;
	u16 Local_u16ONTime = 1000;

	while(1)
	{
		ADC_u8StartConversionSynch(SINGLE_ENDED_ADC0, &Local_u16ADCReading);
//		Local_u8Angle = map2(0, 255, 0, 180, Local_u16ADCReading);
//		Local_u16ONTime = map2(0, 180, 750, 2500, Local_u8Angle);

		// or
		Local_u16ONTime = map(0, 255, 750, 2500, Local_u16ADCReading);

		TIMER1_voidSetChannelACompMatch(Local_u16ONTime);

	}
}
