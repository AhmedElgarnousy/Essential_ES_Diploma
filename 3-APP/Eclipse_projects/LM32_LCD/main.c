#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"
#include"PORT_interface.h"
#include"ADC_interface.h"

#include"CLCD_interface.h"




void main()
{
  PORT_voidInit();
  CLCD_voidInit();
  ADC_voidInit();
	while(1)
	{
            u16 digital=ADC_u8GetChannelReading(SINGLE_ENDED_ADC0);
			u16 MilliVolt=((u32)(digital*5000UL))/256UL;
			CLCD_voidGoToXY(0,0);
			CLCD_voidWriteNumber(MilliVolt/10);
			CLCD_voidSendString("C");
			_delay_ms(200);
			CLCD_voidSendCommand(0b00000001);
	}



}
