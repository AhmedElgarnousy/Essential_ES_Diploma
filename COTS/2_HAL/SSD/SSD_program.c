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

	if(Copy_u16Ptr -> COM_Type == COM_CATHODE)
	{
		switch(Copy_u16Ptr->Port)
		{
			case DIO_u8PORTA:
							DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8PORT_OUTPUT);
							DIO_u8SetPortValue(DIO_u8PORTA,Copy_u8Number);
							break;
			case DIO_u8PORTB:
							DIO_u8SetPortDirection(DIO_u8PORTB,DIO_u8PORT_OUTPUT);
							DIO_u8SetPortValue(DIO_u8PORTB,Copy_u8Number);
							break;
			case DIO_u8PORTC:
							DIO_u8SetPortDirection(DIO_u8PORTC,DIO_u8PORT_OUTPUT);
							DIO_u8SetPortValue(DIO_u8PORTC,Copy_u8Number);
							break;
			case DIO_u8PORTD:
							DIO_u8SetPortDirection(DIO_u8PORTD,DIO_u8PORT_OUTPUT);
							DIO_u8SetPortValue(DIO_u8PORTD,Copy_u8Number);
							break;

			default :		Local_u8ErrorState = 1; break;
		}
	}
	else
	{
		switch(Copy_u16Ptr->Port)
		{
			case DIO_u8PORTA:	
							DIO_u8SetPortDirection(DIO_u8PORTA,DIO_u8PORT_OUTPUT);
							DIO_u8SetPortValue(DIO_u8PORTA,~Copy_u8Number);
							break;
			case DIO_u8PORTB:	
							DIO_u8SetPortDirection(DIO_u8PORTB,DIO_u8PORT_OUTPUT);
							DIO_u8SetPortValue(DIO_u8PORTB,~Copy_u8Number);
							break;
			case DIO_u8PORTC:	
							DIO_u8SetPortDirection(DIO_u8PORTC,DIO_u8PORT_OUTPUT);
							DIO_u8SetPortValue(DIO_u8PORTC,~Copy_u8Number);
							break;
			case DIO_u8PORTD:
							DIO_u8SetPortDirection(DIO_u8PORTD,DIO_u8PORT_OUTPUT);
							DIO_u8SetPortValue(DIO_u8PORTD,~Copy_u8Number);
							break;
			
			default :			Local_u8ErrorState = 1; break;
		}
	}
	return Local_u8ErrorState;
}
