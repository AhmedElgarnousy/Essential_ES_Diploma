
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "ADC_interface.h"
#include "GIE_interface.h"
#include "util/delay.h"


void ADC_voidCallback(void);

void main()
{
	u16 Local_u16PotReadig;
	PORT_voidInit();
	ADC_voidInit();
	GIE_voidEnable();

	u8 Local_u8MapVal;
	while(1)
	{
		//ADC_u8StartConversionSynch(SINGLE_ENDED_ADC0,&Local_u16PotReadig);
		GIE_voidEnable();
		//ADC_u8StartConversionAsynch(SINGLE_ENDED_ADC0,&Local_u16PotReadig,ADC_voidCallback);
		ADC_u8StartConversionSynch(SINGLE_ENDED_ADC0,&Local_u16PotReadig);

		DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,Local_u16PotReadig);


	}

}
void ADC_voidCallback(void)
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
	_delay_ms(10);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
	_delay_ms(10);
}
