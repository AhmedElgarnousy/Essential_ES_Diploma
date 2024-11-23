/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: RTOS Stack     *************************/
/*************   SWC: TIMER0           *************************/
/*************   SWC: TIMER0           *************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/


#ifndef TIMER_register_H_
#define TIMER_register_H_


#define OCR0			*((volatile u8*)0x5C)		/*Output Compare Register 0*/

#define TCCR0			*((volatile u8*)0x53)		/*Timer0 Control register*/
#define TCCR0_WGM00		6                           /*Waveform generation Mode bit0*/
#define TCCR0_COM01		5
#define TCCR0_COM00		4
#define TCCR0_WGM01		3                           /*Waveform generation Mode bit1*/
#define TCCR0_CS02		2                           /*Prescaler bit2*/
#define TCCR0_CS01		1                           /*Prescaler bit1*/
#define TCCR0_CS00		0                           /*Prescaler bit0*/

#define TIMSK			*((volatile u8*)0x59)		/*Timer Mask*/
#define TIMSK_TOIE0		0
#define TIMSK_OCIE0		1							/*Output Compare interrupt Enable*/
#define TIMSK_TOIE1		2
#define TIMSK_OCIE1B		3
#define TIMSK_OCIE1A		4
#define TIMSK_TICIE1	5							/*Timer1 input caputure interrupt enable*/
#define TIMSK_TOIE2		6
#define TIMSK_OCIE2		7

#define TCCR1A 		*((volatile u8*)0x4F)

#define TCCR1A_WGM10	0
#define TCCR1A_WGM11	1
#define TCCR1A_COM1A0	6
#define TCCR1A_COM1A1	7




#define TCCR1B 		*((volatile u8*)0x4E)		/*TIMER1 Control Register B*/

#define	TCCR1B_ICES1	6						/*input Capature edge select*/
#define TCCR1B_WGM12	3
#define TCCR1B_WGM13	4


#define ICR1 		*((volatile u16*)0x46)

#define OCR1A 		*((volatile u16*)0x4A)

#define OCR1B		*((volatile u16*)0x48)

#define TCNT1	*((volatile u16*)0x4C)


#endif
