/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: HAL           *************************/
/*************   SWC: SERVO           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "TIMER_interface.h"

#include "Servo_interface.h"
#include "Servo_config.h"
#include "Servo_private.h"


s32 map(s32 Copy_s32InputMin,s32 Copy_s32InputMax,s32 Copy_s32OutputMin,s32 Copy_s32OutputMax,s32 Copy_s32InputVal)
{
	s32 Local_s32outputVal;
	Local_s32outputVal = Copy_s32OutputMax - Copy_s32OutputMin;
	Local_s32outputVal *= ( Copy_s32InputVal - Copy_s32InputMin);
	Local_s32outputVal /= Copy_s32InputMax - Copy_s32InputMin;
	Local_s32outputVal += Copy_s32OutputMin;

	return Local_s32outputVal;
}



u8 Servo_u8ServoRotate(u8 Copy_u8ChannalID, u8 Copy_u8Degree)
{
	u8 Local_u8ErrorState=OK;
	u16 Local_u16CompMatchChannelA,Local_u16CompMatchChannelB;
	
	if(Copy_u8Degree >= 0 && Copy_u8Degree <= 180)
	{
		switch(Copy_u8ChannalID )
		{
		case OC1A:	Local_u16CompMatchChannelA = map(0,180,750,2500,Copy_u8Degree);
					TIMER1_voidSetChannelACompMatch(Local_u16CompMatchChannelA);
					TIMER1_voidSetICR(20000); break;

		case OC1B:	Local_u16CompMatchChannelB = map(0,180,750,2500,Copy_u8Degree);
					TIMER1_voidSetChannelBCompMatch(Local_u16CompMatchChannelB);
					TIMER1_voidSetICR(20000); break;

		default : Local_u8ErrorState=NOK; break;
		}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	
	return Local_u8ErrorState;
	
}
