/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: UART           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/

#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_register.h"
#include "UART_config.h"
#include "UART_private.h"


void USART_Init()
{
	u8 Local_u8UCSRAValue=0;	//We use this Method because u should put the total value at one time
	SET_BIT(Local_u8UCSRAValue,7);
	CLR_BIT(UCSRC,UCSRC_UPM1);
	CLR_BIT(UCSRC,UCSRC_UPM0);

	/*1 Stop bit*/
	CLR_BIT(Local_u8UCSRAValue,UCSRC_USBS);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	/*8 data bits*/
	SET_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);

	UCSRC=Local_u8UCSRAValue;

	/*Baud Rate 9600 bit/sec*/
	UBRRL=51;

	/*Enable Transmitter and Receiver*/
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);

}


void USART_voidSend(u8 Copy_u8Data)
{
	/*wait until transmit data buffer is empty*/
	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);

	UDR=Copy_u8Data;
}

u8 USART_voidReceive()
{
	while(GET_BIT(UCSRA,UCSRA_RXC) == 0);

	return UDR;
}
