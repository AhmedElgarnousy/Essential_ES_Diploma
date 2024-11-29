/*************************************************************************/
/*************************************************************************/
/********************  Author : Ahmed Kamal    ****************************/
/********************  Layer  : HAL             ****************************/
/********************  SWC    :  CLCD              *************************/
/********************  version: 1.00            ****************************/
/********************  Data: 17/4/2022          ****************************/
/********************  version: 2.00            ****************************/
/********************  Data: 24/7/2024          ****************************/
/*************************************************************************/
/*************************************************************************/

#ifndef CLCD_interface_H_
#define CLCD_interface_H_


void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSendString(const char* Copy_pcString );

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);

void CLCD_voidWriteSpecialCharacter(u8*Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos);

void CLCD_voidWriteNumber(u32 Copy_u32Number);

void CLCD_voidWriteNumber_v2(u32 Copy_u32Number);

void CLCD_voidClearScreen();

#endif /*CLCD_interface_H_*/
