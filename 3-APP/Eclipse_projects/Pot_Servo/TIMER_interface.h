/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: TIMER           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/


#ifndef TIMER_interface_H_
#define TIMER_interface_H_

void TIMER0_voidInit(void);

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);
void TIMER1_voidInit();

void TIMER1_voidSetICR(u16 Copy_u16TopValue);
void TIMER1_voidSetChannelACompMatch(u16 Copy_u16ChannelACompMatch);

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));


#endif
