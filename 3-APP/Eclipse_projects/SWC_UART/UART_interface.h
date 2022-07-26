/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: UART             *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/

#ifndef	UART_interface_H_
#define UART_interface_H_


void USART_Init(); /*Done*/

void USART_voidSendCharSynch(u8 Copy_u8Data); /*Done*/

/*PreCondtion:
 * 			You have to open GIE Before Calling
 *  */
u8 USART_u8SendCharAsynch(u8 Copy_u8Data , void (*Copy_pvSendCharNotificationFunc)(void)); /*Done*/

void USART_u8SendStringSynch(char* Copy_cString); /*Done*/

u8 USART_u8SendStringAsynch(char* Copy_cString , void (* Copy_pvSendStringNotificationFunc)(void)); /*Done*/


u8 USART_u8ReceiveCharSynch(u8*Copy_u8Reading); /*DONE*/

/*PreCondtion:
 * 			You have to open GIE Before Calling The Function
 *  */
u8 USART_u8ReceiveCharAsynch(u8 *Copy_u8RecevedData , void (*Copy_pvReceiveCharNotificationFunc)(void)); /*Done*/

u8 USART_u8ReceiveBufferSynch(u8 * Buffer , u8 BufferSize);

u8 USART_u8ReceiveBufferAsynch(u8 * Buffer , u8 BufferSize , void (*Copy_pvReceiveBufferNotificationFunc)(void));

#endif
