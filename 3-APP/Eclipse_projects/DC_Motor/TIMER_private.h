/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: TIMER          ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/


#ifndef TIMER_private_H_
#define TIMER_private_H_


#define NORMAL				1
#define PWM_PHASE_CORRECT	2
#define CTC					3
#define FAST_PWM			4



#define NON_INVERTING_MODE	6
#define INVERTING_MODE		7


#define TOGGLE							2
#define CLEAR							3
#define SET								4

#define NON_INVERTING	9
#define INVERTING		4



#define DIVIDE_BY_8			2
#define DIVIDE_BY_64		3
#define DIVIDE_BY_256		4
#define DIVIDE_BY_1024		5

#define TIMER_PRESC_MASK	0b11111000


#define 	TIMER0_OVF			0
#define 	TIMER0_COMP			1

#define 	TIMER1_OVF			2
#define 	TIMER1_COMPA		3
#define 	TIMER1_COMPB		4
#define 	TIMER1_CAPT			5

#define 	TIMER2_OVF			6
#define 	TIMER2_COMP			7

#endif
