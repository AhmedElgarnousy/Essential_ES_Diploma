/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: DIO              *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/

/*preprocessor file guard*/


#ifndef DIO_register_H
#define DIO_register_H

#define DIO_u8PIN_HIGH       1
#define DIO_u8PIN_LOW        0

#define DIO_u8PORTA        0
#define DIO_u8PORTB        1
#define DIO_u8PORTC        3
#define DIO_u8PORTD        4

#define DIO_u8PORT_HIGH       0xFF
#define DIO_u8PORT_LOW        0

#define DIO_u8PIN0         0
#define DIO_u8PIN1         1
#define DIO_u8PIN2         2
#define DIO_u8PIN3         3
#define DIO_u8PIN4         4
#define DIO_u8PIN5         5
#define DIO_u8PIN6         6
#define DIO_u8PIN7         7


u8 DIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);

u8 DIO_u8SetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);

u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8* Copy_pu8Value);

u8 DIO_u8TogglePinValue(u8 Copy_u8Port,u8 Copy_u8Pin);

#endif

