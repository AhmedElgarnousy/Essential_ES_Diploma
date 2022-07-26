/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: ADC           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/

#ifndef	ADC_config_H_
#define ADC_config_H_

/*
 * Options:
 *		1-AREF:Takes AREF as reference , Internal Vref turned off
 *		2-AVCC: Takes AVCC as reference , External Capacitor at AREF Pin
 *		3-INTERNAL: 2.56V Voltage Reference with External Capacitor at AREF Pin
 * 												*/
#define ADC_REFERENCE_VOLTAGE		AVCC

/*
 * Options:
 *		1-LEFT_ADJUST_RESULT
 *		2-RIGHT_ADJUST_RESULT
 * 								*/
#define ADC_ADJUST_RESULT		LEFT_ADJUST_RESULT

/*
 * Options:
 *		1-DIVIDE_BY_2
 *		2-DIVIDE_BY_4
 *		3-DIVIDE_BY_8
 *		4-DIVIDE_BY_16
 *		5-DIVIDE_BY_32
 *		6-DIVIDE_BY_64
 *		7-DIVIDE_BY_128
 * 								*/
#define ADC_PRESCALER_SELECT	DIVIDE_BY_64
		/***************************************************/
/*
 * Options:
 * 		1-EIGHT_BIT_RESOLUTION
 * 		2-TEN_BIT_RESOLUTION
                              */
#define ADC_RESOLUTION		EIGHT_BIT_RESOLUTION

/*
 * Options:
 * 		1-ENABLE
 * 		2-DISABLE (Single conversion)
                              */
#define  ADC_TRIGGER_MODE			DISABLE
/*
 *Options:
 *		1-FREE_RUNNING_MODE
 *		2-ANALOG_COMPARATOR
 *		3-EXTERNAL_INTERRUPT_REQUEST0
 *		4-TIMER_COUNTER0_COMPARE_MATCH
 *		5-TIMER_COUNTER0_OVERFLOW
 *		6-TIMER_COUNTER1_COMPARE_MATCHB
 *		7-TIMER_COUNTER1_OVERFLOW
 *		8-TIMER_COUNTER1_CAPTURE_EVENT
 	 	 	 	 	 	 	 	 	 	 */
#define ADC_AUTO_TRIGGER_SOURCE		FREE_RUNNING_MODE


#endif
