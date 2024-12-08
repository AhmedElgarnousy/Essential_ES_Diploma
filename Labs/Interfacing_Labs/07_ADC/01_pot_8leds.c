
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "GIE_interface.h"
#include "ADC_interface.h"
#include "LED_interface.h"

#include "ADC_register.h"
#include "BIT_MATH.h"


u8 ADC_u8GetReading(u8 Copy_u8Channel){
	ADMUX &= 0b11111000; // clear bits
	ADMUX |= Copy_u8Channel; // select the channel
	// start conversion
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	// Polling until flag raised
	while(GET_BIT(ADCSRA, ADCSRA_ADIF) == 0);

	// clear flag
	SET_BIT(ADCSRA, ADCSRA_ADIF);

	// return reading
	return ADCH;

}
void main()
{
	PORT_voidInit();
	ADC_voidInit();

	u8 PotValue ;
	while(1)
	{
		PotValue = ADC_u8GetReading(SINGLE_ENDED_ADC0);
		DIO_u8SetPortValue(DIO_u8PORTB, PotValue);
	}
}
