/*************************************************************************/
/*************************************************************************/
/********************  Author : Ahmed Kamal    ****************************/
/********************  Layer  : HAL             ****************************/
/********************  SWC    :  CLCD              *************************/
/********************  version: 1.00            ****************************/
/********************  Data: 17/4/2022          ****************************/
/*************************************************************************/
/*************************************************************************/

/*preprocessor file guard*/
#ifndef CLCD_config_H_
#define  CLCD_config_H_


#define CLCD_DATA_PORT   DIO_u8PORTC

#define CLCD_CTRL_PORT   DIO_u8PORTD
#define CLCD_RS_PIN      DIO_u8PIN0
#define CLCD_RW_PIN      DIO_u8PIN1
#define CLCD_E_PIN       DIO_u8PIN2


#define Eight_Bit_Mode 1
#define Four_Bit_Mode 0

#define CLCD_Mode Eight_Bit_Mode


#endif
