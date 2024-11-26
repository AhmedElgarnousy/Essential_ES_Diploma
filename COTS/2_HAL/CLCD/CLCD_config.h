/***********************************************************************/
/********************  Author : Ahmed Kamal    *************************/
/********************  Layer  : HAL             ************************/
/********************  SWC    :  CLCD           ************************/
/********************  version: 1.00            ************************/
/********************  Data: 17/4/2022          ************************/
/***********************************************************************/

/*preprocessor file guard*/
#ifndef  CLCD_config_H_
#define  CLCD_config_H_


#define CLCD_DATA_PORT   DIO_u8PORTA

#define CLCD_CTRL_PORT   DIO_u8PORTA

#define CLCD_RS_PIN      DIO_u8PIN1
#define CLCD_E_PIN       DIO_u8PIN2
#define CLCD_RW_PIN      DIO_u8PIN0 // farse pcb connected to gnd always write

/*
 * Options:
 * 			4 Bit Mode: Four_Bit_Mode
 * 			8 Bit Mode: Eight_Bit_Mode
*/

#define CLCD_Mode Four_Bit_Mode

/*Configuration for 4 bit Mode Should be in this sequence*/
#define	CLCD_DATA_D7	DIO_u8PIN6
#define	CLCD_DATA_D6	DIO_u8PIN5
#define	CLCD_DATA_D5	DIO_u8PIN4
#define	CLCD_DATA_D4	DIO_u8PIN3

#endif /*CLCD_config_H_*/
