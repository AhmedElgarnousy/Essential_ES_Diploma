/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: RTOS Stack     *************************/
/*************   SWC: TIMER0           *************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"TIMER_interface.h"
#include"TIMER_register.h"
#include"TIMER_private.h"
#include"TIMER_config.h"



static void (*TIMER0_pvCallBackFunc)(void)=NULL;

/*Global Array of PointerToFunc
static void (*TIMER_pvCallBackFunc[8])(void)={NULL};*/

void TIMER0_voidInit(void)
{
	/*choose CTC Mode*/
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
	
	/*set the required compare  Match Value*/
	OCR0 = TIMER0_u8COMP_MATCH_VAL;

	/*Set prescaler(Bit Masking) */
	TCCR0 &=TIMER_PRESC_MASK;
	TCCR0 |=CLK_PRESCALER;

	/*Output Compare Match Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);
}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	
	if(Copy_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}



/*::::::::::::TIMER0 COMP::::::::::::*/
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}

