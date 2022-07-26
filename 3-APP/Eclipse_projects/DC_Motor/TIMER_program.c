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

static void (*ICU_pvCallBackFunc)(void)=NULL;


/*Global Array of PointerToFunc*/
static void (*TIMER_pvCallBackFunc[8])(void)={NULL};

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



		//Waveform generation mode , Fast PWM
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		SET_BIT(TCCR1B,TCCR1B_WGM13);

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


void ICU_voidInit()
{
	/*Set trigGer source to rising edge initially */
	SET_BIT(TCCR1B,TCCR1B_ICES1);

	/*Enable input capture interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}


u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge)
{
	u8 Local_u8ErrorState=OK;

	if(Copy_u8Edge==ICU_RISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);

	}
	else if(Copy_u8Edge==ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

void ICU_voidDisableInterrupt()
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}


u16 ICU_u16ReadInputCaputure()
{
	return ICR1;
}

u8 ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;

	if(Copy_pvCallBackFunc !=NULL)
	{
		ICU_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}



/*::::::::::::::::::::::Assignments one function contains nearly same at MCU::::::::::::::::::::::*/

u8 TIMER_voidEnable(u8 Copy_u8InterruptSource)
{
	u8 Local_u8ErrorState=OK;

	switch(Copy_u8InterruptSource)
	{
		case TIMER0_OVF: CLR_BIT(TIMSK,TIMSK_OCIE0); break;
		case TIMER0_COMP:CLR_BIT(TIMSK,TIMSK_TOIE0); break;
		case TIMER1_OVF: CLR_BIT(TIMSK,TIMSK_TOIE1); break;
		case TIMER1_COMPA:CLR_BIT(TIMSK,TIMSK_OCIE1A); break;
		case TIMER1_COMPB:CLR_BIT(TIMSK,TIMSK_OCIE1B); break;
		case TIMER1_CAPT: CLR_BIT(TIMSK,TIMSK_TICIE1); break;
		case TIMER2_OVF: CLR_BIT(TIMSK,TIMSK_TOIE2);  break;
		case TIMER2_COMP:CLR_BIT(TIMSK,TIMSK_OCIE2);  break;

		default :Local_u8ErrorState=NOK;   break;

	}

return	Local_u8ErrorState;
}



u8 TIMER_voidDisable(u8 Copy_u8InterruptSource)
{
	u8 Local_u8ErrorState=OK;

	switch(Copy_u8InterruptSource)
	{
		case TIMER0_OVF: SET_BIT(TIMSK,TIMSK_OCIE0); break;
		case TIMER0_COMP:SET_BIT(TIMSK,TIMSK_TOIE0); break;
		case TIMER1_OVF: SET_BIT(TIMSK,TIMSK_TOIE1); break;
		case TIMER1_COMPA:SET_BIT(TIMSK,TIMSK_OCIE1A); break;
		case TIMER1_COMPB:SET_BIT(TIMSK,TIMSK_OCIE1B); break;
		case TIMER1_CAPT: SET_BIT(TIMSK,TIMSK_TICIE1); break;
		case TIMER2_OVF: SET_BIT(TIMSK,TIMSK_TOIE2);  break;
		case TIMER2_COMP:SET_BIT(TIMSK,TIMSK_OCIE2);  break;

		default :Local_u8ErrorState=NOK;   break;

	}

return	Local_u8ErrorState;
}




u8 TIMER_voidSetCallBack(void (*Copy_pvCallBackFunc)(void),u8 Copy_u8InterruptSourceNo)
{
	u8 Local_u8ErrorState=OK;

	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER_pvCallBackFunc[Copy_u8InterruptSourceNo] = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}

/*::::::::::::TIMER0 OVF::::::::::::*/
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(TIMER_pvCallBackFunc[TIMER0_OVF] != NULL)
	{
		TIMER_pvCallBackFunc[TIMER0_OVF]();
	}

}


/*::::::::::::TIMER0 COMP::::::::::::*/
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER_pvCallBackFunc[TIMER0_COMP] != NULL)
	{
		TIMER_pvCallBackFunc[TIMER0_COMP]();
	}
}


/*::::::::::::TIMER1 OVF::::::::::::*/
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	if(TIMER_pvCallBackFunc[TIMER1_OVF] != NULL)
	{
		TIMER_pvCallBackFunc[TIMER1_OVF]();
	}
}



/*::::::::::::TIMER1 COMPB::::::::::::*/
void __vector_8 (void) __attribute__((signal));
void __vector_8 (void)
{
	if(TIMER_pvCallBackFunc[TIMER1_COMPB] != NULL)
	{
		TIMER_pvCallBackFunc[TIMER1_COMPB]();
	}

}

/*::::::::::::TIMER1 COMPA::::::::::::*/
void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	if(TIMER_pvCallBackFunc[TIMER1_COMPA] != NULL)
	{
		TIMER_pvCallBackFunc[TIMER1_COMPA]();
	}

}


/*::::::::::::TIMER1 CAPT::::::::::::*/
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(TIMER_pvCallBackFunc[TIMER1_CAPT] != NULL)
	{
		TIMER_pvCallBackFunc[TIMER1_CAPT]();
	}

}


/*::::::::::::TIMER2 OVF::::::::::::*/
void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
{
	if(TIMER_pvCallBackFunc[TIMER2_OVF] != NULL)
	{
		TIMER_pvCallBackFunc[TIMER2_OVF]();
	}

}


/*::::::::::::TIMER2 COMP::::::::::::*/
void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	if(TIMER_pvCallBackFunc[TIMER2_COMP] != NULL)
	{
		TIMER_pvCallBackFunc[TIMER2_COMP]();
	}

}
