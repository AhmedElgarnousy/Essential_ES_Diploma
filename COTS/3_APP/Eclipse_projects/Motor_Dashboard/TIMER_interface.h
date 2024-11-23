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



#define ICU_RISING_EDGE		1
#define ICU_FALLING_EDGE	0

void TIMER0_voidInit(void);

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);
void TIMER1_voidInit();

void TIMER1_voidSetICR(u16 Copy_u16TopValue);
void TIMER1_voidSetChannelACompMatch(u16 Copy_u16ChannelACompMatch);

void TIMER1_voidSetTimerValue(u16 Copy_u16Value);
u16 TIMER1_u16ReadTimerValue();


void TIMER1_voidSetChannelBCompMatch(u16 Copy_u16ChannelBCompMatch);

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));


void ICU_voidInit();
u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge);
u16 ICU_u16ReadInputCaputure();
void ICU_voidDisableInterrupt();
u8 ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));



/*:::::::::::::::::::::::Assignment:::::::::::::::::::::::*/

/*
 * Options:
 * 			1-TIMER0_OVF
 * 			2-TIMER0_COMP
 * 			3-TIMER1_OVF
 * 			4-TIMER1_CAPT
 * 			5-TIMER1_COMPA
 * 			6-TIMER1_COMPB
 * 			7-TIMER2_OVF
 * 			8-TIMER2_COMP
 * 							*/

u8 TIMER_voidEnable(u8 Copy_u8InterruptSource);
u8 TIMER_voidDisable(u8 Copy_u8InterruptSource);

u8 TIMER_voidSetCallBack(void (*Copy_pvCallBackFunc)(void),u8 Copy_u8InterruptSourceNo);

#endif
