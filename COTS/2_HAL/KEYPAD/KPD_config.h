/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: HAL            *************************/
/*************   SWC: KPD              *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/


#ifndef KPD_config_H_
#define KPD_config_H_


//#define KPD_PORT   DIO_u8PORTD

#define KPD_ROWS_PORT   DIO_u8PORTB

#define KPD_COLS_PORT   DIO_u8PORTD

#define KPD_COLUMN0_PIN		DIO_u8PIN2
#define KPD_COLUMN1_PIN		DIO_u8PIN3
#define KPD_COLUMN2_PIN		DIO_u8PIN4
#define KPD_COLUMN3_PIN		DIO_u8PIN5

#define KPD_ROW0_PIN		DIO_u8PIN4
#define KPD_ROW1_PIN		DIO_u8PIN5
#define KPD_ROW2_PIN		DIO_u8PIN6
#define KPD_ROW3_PIN		DIO_u8PIN7


//#define KPD_NO_PRESSED_KEY	0xff
#define KPD_ARR_VAL		{{1,2,3,'+'},{4,5,6,'-'},{7,8,9,'*'},{0,'.','=','/'}}

/*
 * sign -> ASCII Code
 '+' -> 43
 '-' -> 45
 '*' -> 42
 '/' -> 47
 '=' -> 61
 '.' -> 46
*/

#endif
