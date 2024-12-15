#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>
#include "ADC_register.h"
#include "BIT_MATH.h"

u8 ADC_u8GetReading(u8 Copy_u8Channel) {
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
	CLCD_voidInit();
	ADC_voidInit();

//	u16 * Local_pu8digitalVal = NULL;
	u16 Local_u8digitalVal ;

	while(1)
	{
		// doesn't work correctly
//		ADC_u8StartConversionSynch(SINGLE_ENDED_ADC0, Local_pu8digitalVal);
//		u16 miliVolt = (u16)(( (u32)(*Local_pu8digitalVal) * 5000UL) / 256UL);

		ADC_u8StartConversionSynch(SINGLE_ENDED_ADC0, &Local_u8digitalVal);
		u16 miliVolt = (u16)(((u32)Local_u8digitalVal * 5000UL) / 256UL);

//		Local_u8digitalVal = ADC_u8GetReading(SINGLE_ENDED_ADC0);
//		u16 miliVolt = (u16)(((u32)Local_u8digitalVal * 5000UL) / 256UL);

		u8 temp = miliVolt / 10;

		CLCD_voidWriteNumber(temp);
		CLCD_voidSendString(" Celisus");
		_delay_ms(200);
		CLCD_voidClearScreen();
	}
}
