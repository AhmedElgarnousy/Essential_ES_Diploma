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
