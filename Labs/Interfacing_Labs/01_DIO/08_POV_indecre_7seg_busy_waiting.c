#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SSD_interface.h"
#include "SW_interface.h"
#include <util/delay.h>

void main(void)
{
	PORT_voidInit();
	SSD_t SSD1 = {SSD_COM_CATHODE, DIO_u8PORTA, DIO_u8PORTC, DIO_u8PIN6};
	SSD_t SSD2 = {SSD_COM_CATHODE, DIO_u8PORTA, DIO_u8PORTC, DIO_u8PIN7};

	u8 Local_u8CurrentNum = 50;
	u8 Local_u8SW1State = SW_NOT_PRESSED;
	u8 Local_u8SW2State = SW_NOT_PRESSED;

	while(1)
	{
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN2, SW_SELFLOCKING, SW_PULL_UP, &Local_u8SW1State);
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN3, SW_SELFLOCKING, SW_PULL_UP, &Local_u8SW2State);

		if(Local_u8SW1State == SW_PRESSED)
		{
			Local_u8CurrentNum++;
		}
		if(Local_u8SW2State == SW_PRESSED)
		{
			Local_u8CurrentNum--;
		}
		SSD_void2Mux_display_num(&SSD1, &SSD2, Local_u8CurrentNum, 1);
		/*
		SSD_u8Enable_SDD(&SSD1);
		SSD_u8Disable_SDD(&SSD2);
		SSD_u8SetNumber(sevenSegNums[0], &SSD1);
		_delay_ms(10);

		SSD_u8Enable_SDD(&SSD2);
		SSD_u8Disable_SDD(&SSD1);
		SSD_u8SetNumber(sevenSegNums[2], &SSD2);
		_delay_ms(10);
		 */
	}

}
