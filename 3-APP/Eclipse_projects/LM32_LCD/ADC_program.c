/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: ADC           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/


#include"STD_TYPES.h"
#include"BIT_MATH.h"



#include"ADC_interface.h"
#include"ADC_config.h"
#include"ADC_register.h"
#include"ADC_private.h"

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
	ADCSRA &=ADC_PRESCALER_MASK;
	ADCSRA |=ADC_PRESCALER_SELECT;

	/*Enable peripheral */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u16 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
	u16 Local_u8ADCReading;
	/*Clear the MUX bits in ADMUX register*/
	ADMUX &=ADC_MULTIPLEXER_MASK;
	/*set the required channel into the MUX bits*/
	ADMUX |=Copy_u8Channel;

	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

/*set conversion mode: single conversion or auto trigger*/
#if ADC_TRIGGER_MODE==DISABLE

	/*Polling (busy waiting) until the conversion complete flag is set*/
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);

	/*clear the conversion complete flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);


#elif ADC_TRIGGER_MODE==ENABLE
	/*Set ADC auto trigger Enable bit*/
	SET_BIT(ADCSRA,ADCSRA_ADATA);
	/*set interrupt enable*/
	SET_BIT(ADCSRA,ADCSRA_ADIE);

	/*Select ADC Auto Trigger Source*/
	SFIOR &=ADC_AUTO_TRIGGER_SOURCE_MASK;
	SFIOR |=ADC_AUTO_TRIGGER_SOURCE;

	/*Start First Auto trigger source*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
#else
#error "Wrong Auto Trigger Mode Configuration"
#endif

	/*Return the reading*/
#if ADC_RESOLUTION == EIGHT_BIT_RESOLUTION
	Local_u8ADCReading=ADCH;
			return Local_u8ADCReading;

#elif	ADC_RESOLUTION == TEN_BIT_RESOLUTION

	Local_u8ADCReading=ADC;
	return Local_u8ADCReading;

#else
#error "Wrong Resolution Selection"
#endif
}
