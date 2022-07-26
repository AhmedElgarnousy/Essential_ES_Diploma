
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include"ADC_interface.h"
#include "GIE_interface.h"

s32 map(s32 Copy_s32InputMin,s32 Copy_s32InputMax,s32 Copy_s32OutputMin,s32 Copy_s32OutputMax,s32 Copy_s32InputVal)
{
	s32 Local_s32outputVal;
	Local_s32outputVal=Copy_s32OutputMax-Copy_s32OutputMin;
	 Local_s32outputVal *=(Copy_s32InputVal-Copy_s32InputMin);
	 Local_s32outputVal /=Copy_s32InputMax-Copy_s32InputMin;
	 Local_s32outputVal +=Copy_s32OutputMin;

	return Local_s32outputVal;
	}

void PWM(void);

void main(void)
{

	u16 Local_u16PotVal=0;
	s32 x;
	PORT_voidInit();

	/*Initialize TIMER0 to generate PWM (Duty Cycle 25%, Period Time 256usec)*/
	TIMER0_voidInit();
	TIMER0_voidSetCompMatchValue(64);

	TIMER1_voidInit();
	GIE_voidEnable();
	ADC_voidInit();
	while(1)
	{
		/*
			TIMER1_voidSetICR(20000);
			ADC_u8StartConversionSynch(SINGLE_ENDED_ADC0,&Local_u16PotVal);
			x=map(0,255,750,2500,Local_u16PotVal);
			TIMER1_voidSetChannelACompMatch(x);
		 	 */


	}
}


void PWM(void)
{
	static u16 Local_u16Counter=0;
	Local_u16Counter++;

	if(Local_u16Counter==5)
	{
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_LOW);

	}
	else if(Local_u16Counter==10)
	{
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PIN_LOW);
	}

	else if(Local_u16Counter==15)
	{
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN_LOW);
	}
	else if(Local_u16Counter==20)
	{
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN5,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PIN_HIGH);
		Local_u16Counter=0;
	}

}
