/*************************************************************************/
/*************************************************************************/
/********************  Author : Ahmed Kamal    ****************************/
/********************  Layer  : HALL           ****************************/
/********************  SWC    : SSD               *************************/
/********************  version: 1.00          ****************************/
/*************************************************************************/
/*************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"
#include"SSD_interface.h"
#include"SSD_config.h"
#include"SSD_private.h"
#include<util/delay.h>

// Number should be in Binary Format
u8 SSD_u8SetNumber(u8 Copy_u8Number,SSD_t*Copy_u16Ptr)
{
	u8 Local_u8ErrorState=0;

	if(Copy_u16Ptr -> COM_Type == SSD_COM_CATHODE)
	{
		DIO_u8SetPortValue(Copy_u16Ptr->Port, Copy_u8Number);
	}
	else
	{
		DIO_u8SetPortValue(Copy_u16Ptr->Port, ~Copy_u8Number);
	}
	return Local_u8ErrorState;
}

u8 SSD_u8Enable_SDD(SSD_t * Copy_u16Ptr) {
	u8 Local_u8ErrorStatus = 0;
	
	if(Copy_u16Ptr == NULL)
	{
		Local_u8ErrorStatus = 1;
	}
	
	if(Copy_u16Ptr->COM_Type == SSD_COM_ANODE)
	{
		DIO_u8SetPinValue(Copy_u16Ptr->EnablePort,Copy_u16Ptr->EnablePin,DIO_u8PIN_HIGH);
	}
	else if(Copy_u16Ptr->COM_Type == SSD_COM_CATHODE)
	{ //
		DIO_u8SetPinValue(Copy_u16Ptr->EnablePort,Copy_u16Ptr->EnablePin,DIO_u8PIN_HIGH); // LOW but i have transistor
	}
	else
	{
		Local_u8ErrorStatus =1;
	}
	
	return Local_u8ErrorStatus;
}

u8 SSD_u8Disable_SDD(SSD_t * Copy_u16Ptr) {
	u8 Local_u8ErrorStatus = 0;
	
	if(Copy_u16Ptr == NULL)
	{
		Local_u8ErrorStatus = 1;
	}
	
	if(Copy_u16Ptr->COM_Type == SSD_COM_ANODE)
	{
		DIO_u8SetPinValue(Copy_u16Ptr->EnablePort,Copy_u16Ptr->EnablePin,DIO_u8PIN_LOW);
	}
	else if(Copy_u16Ptr->COM_Type == SSD_COM_CATHODE)
	{ //
		DIO_u8SetPinValue(Copy_u16Ptr->EnablePort,Copy_u16Ptr->EnablePin,DIO_u8PIN_LOW); // HIGH but i have trasistor
	}
	else
	{
		Local_u8ErrorStatus =1;
	}
	
	return Local_u8ErrorStatus;
}



void SSD_void2Mux_display_num(SSD_t * Copy_u16Ptr1, SSD_t * Copy_u16Ptr2, u8 Copy_u8DisplayNum, u8 Copy_u8SEETimeInSeconds) {
	if((Copy_u8DisplayNum < 0) || (Copy_u8DisplayNum > 99))
		return;

	u8 first_digit = 0;
	u8 second_digit = 0;
	u8 num = Copy_u8DisplayNum;
	u8 sevenSegNums[10] = { 0b01111110, 0b00001100, 0b10110110, 0b10011110, 0b11001100, 0b11011010, 0b11111010, 0b00001110, 0b11111110, 0b11011110};

	second_digit = num % 10; // get last digit
	first_digit = num / 10; // remove last digit

	for(u8 i = 0; i <= Copy_u8SEETimeInSeconds*50; i++)
	{
		SSD_u8Disable_SDD(Copy_u16Ptr1);
		SSD_u8Enable_SDD(Copy_u16Ptr2);
		SSD_u8SetNumber( sevenSegNums[first_digit], Copy_u16Ptr2);
		_delay_ms(10);

		SSD_u8Disable_SDD(Copy_u16Ptr2);
		SSD_u8Enable_SDD(Copy_u16Ptr1);
		SSD_u8SetNumber(sevenSegNums[second_digit], Copy_u16Ptr1);
		_delay_ms(10);
	}
}
