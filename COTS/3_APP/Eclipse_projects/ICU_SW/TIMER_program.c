/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: TIMER           ****************************/
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

void TIMER0_voidInit(void)
{
#if WAVE_GENERATION_MODE == NORMAL

	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

#elif 	WAVE_GENERATION_MODE == CTC

	/*choose CTC Mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);


		#if COMP_OUT_MODE_NON_PWM==TOGGLE
			/*Toggle OC0 on Compare Match*/
			CLR_BIT(TCCR0,TCCR0_COM01);
			SET_BIT(TCCR0,TCCR0_COM00);

		#elif	COMP_OUT_MODE_NON_PWM==CLEAR
			/*Clear OC0 on Compare Match*/
			SET_BIT(TCCR0,TCCR0_COM01);
			CLR_BIT(TCCR0,TCCR0_COM00);

		#elif 	COMP_OUT_MODE_NON_PWM==SET
			/*Set OC0 on Compare Match*/
			SET_BIT(TCCR0,TCCR0_COM01);
			SET_BIT(TCCR0,TCCR0_COM00);

		#else
		#error"Wrong Compare Output Mode,Non PWM  Configuration "
		#endif

			/*Output Compare Match Interrupt Enable*/
			SET_BIT(TIMSK,TIMSK_OCIE0);

#elif	WAVE_GENERATION_MODE == FAST_PWM

	/*choose fastPWM Mode*/
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

		#if COMP_OUT_MODE	== INVERTING_MODE

			/* Choose Inverting Mode*/
		SET_BIT(TCCR0,TCCR0_COM01);
		SET_BIT(TCCR0,TCCR0_COM00);

		#elif COMP_OUT_MODE == NON_INVERTING_MODE

		/*Choose Non_Inverting mode*/
		SET_BIT(TCCR0,TCCR0_COM01);
		CLR_BIT(TCCR0,TCCR0_COM00);

		#else
		#error "Wrong Compare output mode Configuration"
		#endif



#elif	WAVE_GENERATION_MODE	PWM_PHASE_CORRECT

	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

		#if COMP_OUT_MODE_PHASE_CORRECT	== INVERTING

			/* Choose Inverting Mode*/
		SET_BIT(TCCR0,TCCR0_COM01);
		SET_BIT(TCCR0,TCCR0_COM00);

		#elif COMP_OUT_MODE_PHASE_CORRECT == NON_INVERTING

		/*Choose Non_Inverting mode*/
		SET_BIT(TCCR0,TCCR0_COM01);
		CLR_BIT(TCCR0,TCCR0_COM00);

		#else
		#error "Wrong Compare output mode,Phase Correct PWM Configuration"
		#endif

#else
#error "Wrong Configuration of Waveform Generation"
#endif



		/*Set prescaler(Bit Masking) */
		TCCR0 &=TIMER_PRESC_MASK;
		TCCR0 |=CLK_PRESCALER;


}

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value)
{
	OCR0=Copy_u8Value;
}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	
	if(Copy_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}


void TIMER1_voidInit()

{
	/*Compare Output Mode, fast PWM, non inverted
		SET_BIT(TCCR1A,TCCR1A_COM1A1);
		CLR_BIT(TCCR1A,TCCR1A_COM1A0);*/

	/*Initialize TIMER1 normal Mode
	 * By default is normal*/



		/*Waveform generation mode , Fast PWM
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		SET_BIT(TCCR1B,TCCR1B_WGM13);*/

		/*Prescaler */
		TCCR1B &=TIMER_PRESC_MASK;
		TCCR1B |= DIVIDE_BY_8;
}

void TIMER1_voidSetTimerValue(u16 Copy_u16Value)
{
	TCNT1=Copy_u16Value;
}

u16 TIMER1_u16ReadTimerValue()
{
	return TCNT1;
}



void TIMER1_voidSetICR(u16 Copy_u16TopValue)
{
	ICR1=Copy_u16TopValue;

}
void TIMER1_voidSetChannelACompMatch(u16 Copy_u16ChannelACompMatch)
{
	OCR1A=Copy_u16ChannelACompMatch;
}

void TIMER1_voidSetChannelBCompMatch(u16 Copy_u16ChannelBCompMatch)
{
	OCR1B=Copy_u16ChannelBCompMatch;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}

}
