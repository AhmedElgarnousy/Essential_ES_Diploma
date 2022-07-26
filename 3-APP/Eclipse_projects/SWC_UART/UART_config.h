/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: UART           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/

#ifndef	UART_config_H_
#define UART_config_H_


/*
 * Options:
 * 			Choose FIVE_BITS: for 5 Bits for data
 * 			Choose SIX_BITS: for 6 Bits for data
 * 			Choose SEVEN_BITS: for 7 Bits for data
 * 			Choose EIGHT_BITS: for 8 Bits for data
 * 			Choose NINE_BITS: for 9 Bits for data
 * 				// you have to handle in the function send and receive and make it u16
 *
 * 			*/
#define DATA_BITS 		EIGHT_BITS


/*
 * Options:
 * 			Choose EVEN_PARITY
 * 			Choose ODD_PARITY
 * 			Choose DISABLED
 * 			*/
#define PARITY_MODE		DISABLED

/*
 * Options:
 * 			Choose	ONE_BIT
 * 			Choose	TWO_BIT
 * 			*/
#define STOP_BIT_SELECT		ONE_BIT


/*
 * Options:
 * 			Choose	ASYNCHRONOUS
 * 			Choose	SYNCHRONOUS
 * 			*/
#define USART_MODE_SELECT	ASYNCHRONOUS



#define BAUD_RATE		9600
#define OSC_FREQ		8000000


#define UART_u32TIMEOUT 		1000
#endif
