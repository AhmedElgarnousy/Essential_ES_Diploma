/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: UART           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/

#ifndef	UART_register_H_
#define UART_register_H_


#define UDR	*((volatile u8*)0x2C) 		/* UART DATA Register */


#define UCSRA	*((volatile u8*)0x2B) 	/* UART Control and Status Register A */
#define UCSRA_RXC		7               /* USART Receive Complete Flag 		  */
#define UCSRA_TXC		6				/* USART Transmit Complete Flag 	  */
#define UCSRA_UDRE		5				/* USART Data Register Empty Flag	  */
#define UCSRA_FE		4
#define UCSRA_DOR		3
#define UCSRA_PE		2
#define UCSRA_U2X		1
#define UCSRA_MPCM		0

#define UCSRB		*((volatile u8*)0x2A) 	/* UART Control and Status Register B  		  */
#define UCSRB_RXCIE		7					/* RX Complete Interrupt Enable 	   		  */
#define UCSRB_TXCIE		6					/* TX Complete Interrupt Enable 	   		  */
#define UCSRB_UDRIE		5					/* USART Data Register Empty Interrupt Enable */
#define UCSRB_RXEN		4
#define UCSRB_TXEN		3
#define UCSRB_UCSZ2		2					/* Character Size Bit 2 */
#define UCSRB_RXB8		1					/* Receive Data Bit 8   */
#define UCSRB_TXB8		0					/* Transmit Data Bit 8  */

#define UBRRL	*((volatile u8*)0x29) 		/* USART Baud Rate Registers LOW */

#define UCSRC 		*((volatile u8*) 0x40) 	/* UART Control and Status Register C  */
#define UCSRC_URSEL		7 					/* Register Select   	*/
#define UCSRC_UMSEL		6					/* USART Mode Select 	*/
#define UCSRC_UPM1		5					/* Parity Mode Bit 1 	*/
#define UCSRC_UPM0		4					/* Parity Mode Bit 0 	*/
#define UCSRC_USBS		3					/* Stop Bit Select   	*/
#define UCSRC_UCSZ1		2					/* Character Size Bit 1	*/
#define UCSRC_UCSZ0		1					/* Character Size Bit 0	*/
#define UCSRC_UCPOL		0


#define UBRRH		*((volatile u8*) 0x40)  /*USART Baud Rate Registers HIGH*/

#endif
