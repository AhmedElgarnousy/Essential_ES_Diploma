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
	SET_BIT(Local_u8UCSRAValue,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	// No Parity
	CLR_BIT(Local_u8UCSRAValue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRAValue,UCSRC_UPM0);

	/*1 Stop bit*/
	CLR_BIT(Local_u8UCSRAValue,UCSRC_USBS);

	UCSRC = Local_u8UCSRAValue; // Load UCSRC value

	/*Baud Rate 9600 bit/sec*/
	// if value bigger than 255 use high register also
	UBRRL = 51;
	UBRRH = 51>>8; // 0

	/*Enable Transmitter and Receiver*/
	SET_BIT(UCSRB, UCSRB_RXEN);
	SET_BIT(UCSRB, UCSRB_TXEN);
}

u8 USART_u8SendCharSynch(u8 Copy_u8Data)
{
	/* wait until transmit data buffer is empty(flag raised) or time out finsihed */
	u16 Local_u8ErrorState = OK;
	u32 Local_u32Timeout = 0;

	while((GET_BIT(UCSRA, UCSRA_UDRE) == 0) && (Local_u32Timeout < USART_u32TIME_OUT))
	{
		Local_u32Timeout ++;
	}

	if(Local_u32Timeout >= USART_u32TIME_OUT)
	{
		/*Loop is broken because the timeout is reached*/
		Local_u8ErrorState = ERR_TIME_OUT;
	}
	else
	{
		UDR = Copy_u8Data;
	}
	return Local_u8ErrorState;
}

u8 USART_u8ReceiveCharSynch(u8 * Copy_pu8ReceivedChar)
{
	u8 Local_u8ErrorState = OK;

	if(Copy_pu8ReceivedChar == NULL)
	{
		Local_u8ErrorState = NULL_POINTER;
	}
	// WE add TIMEout because we wait here user input or add time out for receive if needed
	while( GET_BIT(UCSRA,UCSRA_RXC) == 0);
		*Copy_pu8ReceivedChar = UDR;

	return Local_u8ErrorState;
}

void USART_voidSendStringSynch(char *string){
	u8 Local_u8Counter = 0;

	while(string[Local_u8Counter] != '\0')
	{
		USART_u8SendCharSynch(string[Local_u8Counter]);
		Local_u8Counter++;
	}
}

u8 USART_u8ReceivedBufferSynch(u8 * Copy_pu8Buffer, u8 Copy_u8BufferSize)
{
	u8 Local_u8ErrorState = OK;

	// check pointer is Null or not
	for(u8 Local_u8Counter = 0;  Local_u8Counter < Copy_u8BufferSize; Local_u8Counter++)
	{
		USART_u8ReceiveCharSynch(&Copy_pu8Buffer[Local_u8Counter]);
	}
	return Local_u8ErrorState;
}



// Asynchronous
// you have to enable GIE before use thes functions
void USART_voidSendCharAsynch(u8 Copy_u8Data, void (*Copy_pvNotificationFunc)(void))
{

}

// -------------------------------------ISRs------------------------------------

//  USART, Rx Complete
void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{

}

// USART Data Register Empty
void __vector_14(void) __attribute__((signal));
void __vector_14(void)
{

}

//USART, Tx Complete
void __vector_15(void) __attribute__((signal));
void __vector_15(void)
{

}
