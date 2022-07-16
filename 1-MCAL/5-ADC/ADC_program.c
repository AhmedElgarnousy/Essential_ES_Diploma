/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: ADC              *************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/


#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"ADC_interface.h"
#include"ADC_config.h"
#include"ADC_register.h"
#include"ADC_private.h"

u8 ADC_flag;

static u16 *ADC_pu16Reading=NULL;
static void (*ADC_pvCallBackNotificationFunc)(void)=NULL;


static u8* ADC_pu8ChainChannelArr=NULL;		/*Global variable to carry chain array*/
static u8 ADC_u8ChainSize;					/*Global variable to carry number of channels*/
static u16* ADC_pu16ChainResultArr=NULL;	/*Global variable to carry chain result*/
static u8 ADC_u8ChainConversionIndex=0;		/*Global Variable to carry the current conversion index*/

static u8 ADC_u8ISRSource;

u8 ADC_u8BusyState=IDLE;

void ADC_voidInit(void)
{
	/*set the reference voltage*/
#if  ADC_REFERENCE_VOLTAGE==AREF

	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif ADC_REFERENCE_VOLTAGE==AVCC

	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	
#elif ADC_REFERENCE_VOLTAGE	== INTERNAL

	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);

#else
#error "Wrong Voltage Reference Selection"
#endif

	/*set the adjust result left adjust 8bit resolution right adjust 10bit resolution*/
#if ADC_ADJUST_RESULT==LEFT_ADJUST_RESULT

	SET_BIT(ADMUX,ADMUX_ADLAR);

#elif ADJUST_RESULT==RIGHT_ADJUST_RESULT

	CLR_BIT(ADMUX,ADMUX_ADLAR);

#else
#error "Wrong Adjust Result "
#endif

	/*Set prescaler(Bit Masking) */
	ADCSRA &=ADC_PRESCALER_MASK;/*to make the first three bits equal zeros*/
	ADCSRA |=ADC_PRESCALER_SELECT;

	/*Enable peripheral */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16 *Copy_pu16Reading)
{
	u32 Local_u32Counter=0;
	u8 Local_u8ErrorState=OK;

	if(ADC_u8BusyState==IDLE)
	{
		ADC_u8BusyState=BUSY;

		/*Clear the MUX bits in ADMUX register*/
		ADMUX &=ADC_MULTIPLEXER_MASK;

		/*set the required channel into the MUX bits*/
		ADMUX |=Copy_u8Channel;

		/*start conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*Polling (busy waiting) until the conversion complete flag is set or counter reached timeout*/
		while( (GET_BIT(ADCSRA,ADCSRA_ADIF)==0) && (Local_u32Counter!=ADC_u32TIMEOUT) )
		{
			Local_u32Counter++;
		}
		if(Local_u32Counter==ADC_u32TIMEOUT)
		{
			/*Loop is broken because the timeout is reached*/
			Local_u8ErrorState=NOK;
		}
		else
		{
			/*Loop is broken because flag is raised */
			 /*clear the conversion complete flag*/
			 SET_BIT(ADCSRA,ADCSRA_ADIF);

			#if ADC_RESOLUTION == EIGHT_BIT_RESOLUTION
					*Copy_pu16Reading=ADCH;

					/*ADC finished return it to idle*/
					ADC_u8BusyState=IDLE;

			#elif	ADC_RESOLUTION == TEN_BIT_RESOLUTION
					*Copy_pu16Reading=ADC;

					/*ADC finished return it to idle*/
					ADC_u8BusyState=IDLE;
			#else
			#error "Wrong Resolution Selection"
			#endif
		}
	}
	else
	{
		ADC_u8BusyState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u16* Copy_pu16Reading,void (*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if(ADC_u8BusyState==IDLE)
	{

		if(Copy_pvNotificationFunc == NULL || Copy_pu16Reading == NULL)
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		else
		{
			/*make ADC busy in order not to work until being idle */
			ADC_u8BusyState=BUSY;

			/*Make ISR Source single channel asynchronous*/
			ADC_u8ISRSource=SINGLE_CHANNEL_ASYNCH;

			/*Initialize the reading variable globally*/
			ADC_pu16Reading=Copy_pu16Reading;

			/*Initialize the call back notification function globally*/
			ADC_pvCallBackNotificationFunc=Copy_pvNotificationFunc;

			/*Clear the MUX bits in ADMUX register*/
				ADMUX &=ADC_MULTIPLEXER_MASK;

				/*set the required channel into the MUX bits*/
				ADMUX |=Copy_u8Channel;

				/*start conversion*/
				SET_BIT(ADCSRA,ADCSRA_ADSC);

				/*ADC interrupt enable */
				SET_BIT(ADCSRA,ADCSRA_ADIE);

				/*Set flag to indicate the ISR from where it comes*/
				SET_BIT(ADC_flag,0);
		 }
	}
	else
	{
		Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}




u8 ADC_u8StartChainAsynch(ADC_Chain_t *Copy_psChain)
{
	u8 Local_u8ErrorState=OK;
		/*Check NULL Pointer*/
		if(Copy_psChain == NULL)
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		else
		{
			/*Check ADC State*/
			if(ADC_u8BusyState==IDLE)
			{
				/*Make ADC Busy*/
				ADC_u8BusyState=BUSY;

				/*Make ISR Source Chain  asynchronous*/
				 ADC_u8ISRSource=CHAIN_ASYNCH;

				/*Initialize chain channel array*/
				ADC_pu8ChainChannelArr=Copy_psChain->Channel;

				/*Initialize Result  array*/
				ADC_pu16ChainResultArr=Copy_psChain->Result;

				/*Initialize size  */
				ADC_u8ChainSize=Copy_psChain->size;

				/*Initialize chain channel array*/
				ADC_pvCallBackNotificationFunc=Copy_psChain->pvNotificationFunc;

				/*Initialize current conversion index*/
				ADC_u8ChainConversionIndex=0;

				/*Clear the MUX bits in ADMUX register*/
				ADMUX &=ADC_MULTIPLEXER_MASK;

				/*set the required channel into the MUX bits*/
				ADMUX |=ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];

				//start conversion of 1st channel
				SET_BIT(ADCSRA,ADCSRA_ADSC);

				//enable interrupt
				SET_BIT(ADCSRA,ADCSRA_ADIE);

			}
			else
			{
				Local_u8ErrorState=BUSY_FUNC;
			}
		}


return Local_u8ErrorState;
}


void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	if(ADC_u8ISRSource == SINGLE_CHANNEL_ASYNCH)
	{
			/*Read ADC Result */
			#if ADC_RESOLUTION == EIGHT_BIT_RESOLUTION
					*ADC_pu16Reading=ADCH;

			#elif	ADC_RESOLUTION == TEN_BIT_RESOLUTION
							*ADC_pu16Reading=ADC;
			#else
			#error "Wrong Resolution Selection"
			#endif

				/*Make ADC state be IDLE because it finished*/
					ADC_u8BusyState=IDLE;

				/*Invoke the call back notification*/
				ADC_pvCallBackNotificationFunc();

				/*Disable the ADC Conversion complete interrupt*/
				CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}

	else if(ADC_u8ISRSource==CHAIN_ASYNCH)
	{
			/*Read the current conversion*/
			#if ADC_RESOLUTION == EIGHT_BIT_RESOLUTION
					ADC_pu16ChainResultArr[ADC_u8ChainConversionIndex]=ADCH;

			#elif	ADC_RESOLUTION == TEN_BIT_RESOLUTION
					ADC_pu16ChainResultArr[ADC_u8ChainConversionIndex]=ADC;
			#else
			#error "Wrong Resolution Selection"
			#endif

			/*increment chain index*/
					ADC_u8ChainConversionIndex++;

			/*Check the size */
			if(ADC_u8ChainConversionIndex==ADC_u8ChainSize)
			{
				/*ADC is now idle*/
				ADC_u8BusyState=IDLE;

				/*invoke the call back  notification Function*/
				ADC_pvCallBackNotificationFunc();

				/*Disable ADC conversion complete interrupt*/
				CLR_BIT(ADCSRA,ADCSRA_ADIE);

			}
			else
			{
				/*Chain is not finished*/
				/*Set the new required channel */
				ADMUX &=ADC_MULTIPLEXER_MASK;
				ADMUX |=ADC_pu8ChainChannelArr[ADC_u8ChainConversionIndex];

				/*Start the conversion*/
				SET_BIT(ADCSRA,ADCSRA_ADIE);
			}
	}

}


