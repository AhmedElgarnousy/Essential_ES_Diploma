/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: ADC           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/

#ifndef	ADC_private_H_
#define ADC_private_H_

#define IDLE	0
#define BUSY	1

#define SINGLE_CHANNEL_ASYNCH		0
#define CHAIN_ASYNCH				1


#define AREF	       1
#define AVCC		   2
#define INTERNAL	   3


#define    LEFT_ADJUST_RESULT		1
#define    RIGHT_ADJUST_RESULT		2

#define ADC_PRESCALER_MASK			0b11111000
#define 	DIVIDE_BY_2				1
#define     DIVIDE_BY_4				2
#define  	DIVIDE_BY_8				3
#define		DIVIDE_BY_16			4
#define		DIVIDE_BY_32			5
#define		DIVIDE_BY_64			6
#define		DIVIDE_BY_128			7

#define ADC_MULTIPLEXER_MASK		0b11100000
#define ADC_AUTO_TRIGGER_SOURCE_MASK  0b00011111


#define EIGHT_BIT_RESOLUTION	0
#define TEN_BIT_RESOLUTION		1


#define ENABLE		1
#define DISABLE		0


/*bit masking*/
#define FREE_RUNNING_MODE					0
#define	ANALOG_COMPARATOR					1
#define	EXTERNAL_INTERRUPT_REQUEST0			2
#define	TIMER_COUNTER0_COMPARE_MATCH		3
#define	TIMER_COUNTER0_OVERFLOW				4
#define	TIMER_COUNTER1_COMPARE_MATCHB		5
#define	TIMER_COUNTER1_OVERFLOW				6
#define	TIMER_COUNTER1_CAPTURE_EVENT		7




#endif
