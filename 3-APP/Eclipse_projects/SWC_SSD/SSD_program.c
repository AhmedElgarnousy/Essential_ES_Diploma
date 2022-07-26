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


/*make Function for enable and disable the 7_seg for multiplexing */
u8 SSD_u8Enable_SDD(SSD_t*Copy_u16Ptr)
{
	u8 LocalErrorState=0;
	if(Copy_u16Ptr->COM_Type==COM_CATHODE)
	{
		DIO_u8SetPinDirection(Copy_u16Ptr->EnablePort,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
		CLR_BIT(Copy_u16Ptr->EnablePort,Copy_u16Ptr->EnablePin);
	}
	else
	{
		CLR_BIT(Copy_u16Ptr->EnablePort,Copy_u16Ptr->EnablePin);

	}

	return LocalErrorState;
}
				/*****************************************************************/
u8 SSD_u8Disable_SDD(SSD_t*Copy_u16Ptr){

}

				/*****************************************************************/
u8 SSD_u8SetNumber(u8 Copy_u8Number,SSD_t*Copy_u16Ptr)
{
	u8 Local_u8ErrorState=0;

	if(Copy_u16Ptr->COM_Type==COM_CATHODE)
	{
		//CLR_BIT(Copy_u16Ptr->Port,DIO_u8PIN7);
		DIO_u8SetPortDirection(Copy_u16Ptr->Port,DIO_u8PORT_OUTPUT);
		DIO_u8SetPortValue(Copy_u16Ptr->Port,Copy_u8Number);


	}
	else
	{
		//SET_BIT(Copy_u16Ptr->Port,DIO_u8PIN7);
		DIO_u8SetPortDirection(Copy_u16Ptr->Port,DIO_u8PORT_OUTPUT);
		DIO_u8SetPortValue(Copy_u16Ptr->Port,~(Copy_u8Number));
	}
	return Local_u8ErrorState;
}
