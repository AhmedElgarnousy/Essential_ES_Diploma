/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: UART           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/

#ifndef	UART_interface_H_
#define UART_interface_H_


void USART_voidInit(void);

u8 USART_u8SendCharSynch(u8 Copy_u8Data); // done

void USART_voidSendCharAsynch(u8 Copy_u8Data, void (*Copy_pvNotificationFunc)(void));

void USART_voidSendStringAsynch(char * string, void (*Copy_pvNotificationFunc)(void));

void USART_voidSendStringSynch(char * string); // done

u8 USART_u8ReceiveCharSynch(u8 * Copy_pu8ReceivedChar); //done

u8 USART_u8ReceiveCharAsynch(u8 * Copy_pu8ReceivedChar, void (*Copy_pvNotificationFunc)(void));

u8 USART_u8ReceivedBufferSynch(u8 * Copy_pu8Buffer, u8 Copy_u8BufferSize); //done

u8 USART_u8ReceivedBufferAsynch(u8 * Copy_pu8Buffer, u8 Copy_u8BufferSize, void (*Copy_pvNotificationFunc)(void));

#endif
