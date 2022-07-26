#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "ADC_interface.h"

#include "DCMotor_interface.h"
#include "util/delay.h"


s32 map(s32 Copy_s32InputMin,s32 Copy_s32InputMax,s32 Copy_s32OutputMin,s32 Copy_s32OutputMax,s32 Copy_s32InputVal)
{
	s32 Local_s32outputVal;
	Local_s32outputVal=Copy_s32OutputMax-Copy_s32OutputMin;
	 Local_s32outputVal *=(Copy_s32InputVal-Copy_s32InputMin);
	 Local_s32outputVal /=Copy_s32InputMax-Copy_s32InputMin;
	 Local_s32outputVal +=Copy_s32OutputMin;

	return Local_s32outputVal;
	}


void main ()
{
	PORT_voidInit();
	TIMER0_voidInit();

	u8 APP_u8POTReading;
	u16 App_u16ADCReadingVal;

	while(1)
	 {
		/*Get the reading from Potentiometer*/
		DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN1,&APP_u8POTReading);
		ADC_u8StartConversionSynch(SINGLE_ENDED_ADC0,&App_u16ADCReadingVal);

		/**/
		TIMER0_voidSetCompMatchValue(App_u16ADCReadingVal);
	 }
}
