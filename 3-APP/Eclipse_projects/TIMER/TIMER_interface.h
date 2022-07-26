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

void TIMER1_voidSetTimerValue(u16 Copy_u16Value);
u16 TIMER1_u16ReadTimerValue(u16 Copy_u16Value);

/*::::::::::::::::::::::::::::::::::::::Assignments::::::::::::::::::::::::::::::::::::::::::::::::*/










void TIMER1_voidSetChannelBCompMatch(u16 Copy_u16ChannelBCompMatch);

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));


#endif
