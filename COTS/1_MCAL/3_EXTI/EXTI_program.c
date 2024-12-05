/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: 	EXTI           *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/


#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"EXTI_interface.h"
#include"EXTI_config.h"
#include"EXTI_register.h"
#include"EXTI_private.h"


void EXTI_voidInt0Init(void)
{
	/*1-(PIF) Check sense Control(The event)*/
#if  INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR, MCUCR_ISC01);
	CLR_BIT(MCUCR, MCUCR_ISC00);

#elif INT0_SENSE ==ON_CHANGE
	SET_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC01);

#elif INT0_SENSE == FALLING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC01);
	CLR_BIT(MCUCR, MCUCR_ISC00);

#elif INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC01);
	SET_BIT(MCUCR, MCUCR_ISC00);

#else
	#error "Wrong INT0_SENSE Configuration Option"
#endif

   /*Check peripheral interrupt enable (PIE) initial state*/
#if INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);

#elif INT0_INITIAL_STATE == DISABLE
	CLR_BIT(GICR,GICR_INT0);
#else
	#error "Wrong INT0_INITIAL_STATE Configuration Option"
#endif

}

void EXTI_voidInt1Init(void)
{
#if INT1_SENSE == LOW_LEVEL

	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
	
#elif INT1_SENSE == ON_CHANGE

	CLR_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SENSE == RISING_EDGE

	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);

#elif INT1_SENSE == FALLING_EDGE

	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);

#else
#error  "Wrong INT1_SENSE Configuration Option"

#endif

	   /*Check peripheral interrupt enable (PIE) initial state*/
#if INT1_INITIAL_STATE ==ENABLED
		SET_BIT(GICR,GICR_INT1);

#elif	INT1_INITIAL_STATE == DISABLE
		CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong INT1_INITIAL_STATE Configuration Option"

#endif

}

void EXTI_voidInt2Init(void)
{
	/*(PIF) Check sense Control*/
#if INT2_SENSE == FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2);

#elif INT2_SENSE == RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#else
	#error "Wrong INT2_SENSE Configuration Option"
#endif

	/*Check peripheral(Specific) interrupt enable (PIE) initial state*/

#if INT2_INITIAL_STATE==DISABLE
	SET_BIT(GICR,GICR_INT2);

#elif INT2_INITIAL_STATE==ENABLED
	SET_BIT(GICR,GICR_INT2);
#else
	#error "Wrong INT2_INITIAL_STATE Configuration Option"
#endif
}


/*	Description: A function to set  the required sense control of INT0 using PostBuild Configuration
 *  Input: Copy_u8Sense, Option are:
 *  								1-LOW_LEVEL
 *  								2-ON_CHANGE
 *  								3-FALLING_EDGE
 *  								4-RISING_EDGE
 *  Output: Error Status with type u8
 *  */
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState=OK;
	switch (Copy_u8Sense)
	{
		case LOW_LEVEL: CLR_BIT(MCUCR,MCUCR_ISC01); CLR_BIT(MCUCR,MCUCR_ISC00); break;
		case ON_CHANGE: SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
		case RISING_EDGE: SET_BIT(MCUCR,MCUCR_ISC01); SET_BIT(MCUCR,MCUCR_ISC00); break;
		case FALLING_EDGE: SET_BIT(MCUCR,MCUCR_ISC01); CLR_BIT(MCUCR,MCUCR_ISC00); break;
		default: Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
/*	Description: A function to set  the required sense control of INT1 using PostBuild Configuration
 *  Input: Copy_u8Sense, Option are:
 *  								1-LOW_LEVEL
 *  								2-ON_CHANGE
 *  								3-FALLING_EDGE
 *  								4-RISING_EDGE
 *  Output: Error Status with type u8
 *  */
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
		switch (Copy_u8Sense)
		{
			case LOW_LEVEL: 	CLR_BIT(MCUCR,MCUCR_ISC11); CLR_BIT(MCUCR,MCUCR_ISC10); break;
			case ON_CHANGE: 	CLR_BIT(MCUCR,MCUCR_ISC11); SET_BIT(MCUCR,MCUCR_ISC10); break;
			case RISING_EDGE: 	SET_BIT(MCUCR,MCUCR_ISC11); SET_BIT(MCUCR,MCUCR_ISC10); break;
			case FALLING_EDGE: 	SET_BIT(MCUCR,MCUCR_ISC11); CLR_BIT(MCUCR,MCUCR_ISC10); break;

			default: Local_u8ErrorState = NOK;
		}
		return Local_u8ErrorState;
}

/*	Description: A function to set  the required sense control of INT2 using PostBuild Configuration
 *  Input: Copy_u8Sense, Option are:
 *  								1-FALLING_EDGE
 *  								2-RISING_EDGE
 *  Output: Error Status with type u8
 *  */
u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
		switch (Copy_u8Sense)
		{
			case RISING_EDGE:	SET_BIT(MCUCSR,MCUCSR_ISC2); break;
			case FALLING_EDGE: 	CLR_BIT(MCUCSR,MCUCSR_ISC2); break;
			default: Local_u8ErrorState = NOK;
		}
		return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState = OK;
		switch(Copy_u8Int)
		{
			case INT0: SET_BIT(GICR,GICR_INT0); break;
			case INT1: SET_BIT(GICR,GICR_INT1); break;
			case INT2: SET_BIT(GICR,GICR_INT2); break;
			default: Local_u8ErrorState = NOK;
		}
	return Local_u8ErrorState;
}

u8 EXTI_u8IntDisable(u8 Copy_u8Int)
{
	u8 Local_u8ErrorState = OK;
		switch(Copy_u8Int)
		{
			case INT0: CLR_BIT(GICR,GICR_INT0); break;
			case INT1: CLR_BIT(GICR,GICR_INT1); break;
			case INT2: CLR_BIT(GICR,GICR_INT2); break;
			default: Local_u8ErrorState = NOK;
		}
	return Local_u8ErrorState;
}
/*create Global Pointer to function to hold INT0 ISR Address*/
void (*EXTI_pvInt0Func)(void) = NULL;

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func=Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}

/*ISR of INT0 */
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/*Do nothing*/
	}
}

/*create Global Pointer to function to hold INT1 ISR Address*/
void (*EXTI_pvInt1Func)(void) = NULL;
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func = Copy_pvInt1Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}

/*ISR of INT1 */
void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func();
	}
	else
	{
		/*Do nothing*/
	}
}

/*create Global Pointer to function to hold INT2 ISR Address*/
void (*EXTI_pvInt2Func)(void) = NULL;
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func = Copy_pvInt2Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

/*ISR of INT2 */
void __vector_3 (void)  __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func();
	}
	else
	{
		/*Do nothing*/
	}
}
