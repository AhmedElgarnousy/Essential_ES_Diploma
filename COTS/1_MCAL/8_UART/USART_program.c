/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: UART           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/

#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_interface.h"
#include "USART_register.h"
#include "USART_config.h"
#include "USART_private.h"

void USART_voidInit()
{
	u8 Local_u8UCSRAValue = 0; 	// We use this Method because u should put the total value at one time


	SET_BIT(Local_u8UCSRAValue,UCSRC_URSEL); // UCSRC_URSEL, select UCSRC

	// Asynchronous Mode
	CLR_BIT(Local_u8UCSRAValue,UCSRC_UMSEL);

	/*8 data bits*/
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRAValue,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);

	// Disable Parity
	CLR_BIT(Local_u8UCSRAValue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRAValue,UCSRC_UPM0);

	/*1 Stop bit*/
	CLR_BIT(Local_u8UCSRAValue,UCSRC_USBS);

	UCSRC = Local_u8UCSRAValue;

	/*Baud Rate 9600 bit/sec*/
	// if value bigger than 255 use high register also
	UBRRL = 51;

	/*Enable Transmitter and Receiver*/
	SET_BIT(UCSRB, UCSRB_TXEN);
	SET_BIT(UCSRB, UCSRB_RXEN);
}


void USART_voidSend(u8 Copy_u8Data)
{
	/*wait until transmit data buffer is empty*/
	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);
	UDR = Copy_u8Data;
}

u8 USART_voidReceive()
{
	while(GET_BIT(UCSRA,UCSRA_RXC) == 0);
	return UDR;
}
