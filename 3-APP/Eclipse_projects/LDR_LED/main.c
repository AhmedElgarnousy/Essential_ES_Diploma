#include"STD_TYPES.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"


void main()
{
	PORT_voidInit();
	ADC_voidInit();
	while(1)
	{
		u8 MAX_READING;
		u8 READING;
		u8 MIN_READING;
		u8 Step=(MAX_READING+MAX_READING)/8;
		READING=ADC_u8GetChannelReading(SINGLE_ENDED_ADC0);
		DIO_u8SetPortValue(DIO_u8PORTC,DIO_u8PORT_HIGH);

		for()
		{

		}
	}


}
