
#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "ADC_interface.h"
#include "TIMER_interface.h"

s32 map(s32 Copy_s32InputMin,s32 Copy_s32InputMax,s32 Copy_s32OutputMin,s32 Copy_s32OutputMax,s32 Copy_s32InputVal)
{
	s32 Local_s32outputVal;
	Local_s32outputVal=Copy_s32OutputMax-Copy_s32OutputMin;
	 Local_s32outputVal *=(Copy_s32InputVal-Copy_s32InputMin);
	 Local_s32outputVal /=Copy_s32InputMax-Copy_s32InputMin;
	 Local_s32outputVal +=Copy_s32OutputMin;

	return Local_s32outputVal;
	}

void main()
{
	u16 Local_u8PotReading;
	s32 Local_s32ServoMapVal;
	PORT_voidInit();
	ADC_voidInit();
	TIMER1_voidInit();
	GIE_voidEnable();

	/*Set the Period time of Servo Motor*/
	TIMER1_voidSetICR(20000);


	while(1)
	{


	    ADC_u8StartConversionSynch(SINGLE_ENDED_ADC0,&Local_u8PotReading);
	    Local_s32ServoMapVal=map(0,255,1000,2000,Local_u8PotReading);

		TIMER1_voidSetChannelACompMatch(Local_s32ServoMapVal);

	}


}
