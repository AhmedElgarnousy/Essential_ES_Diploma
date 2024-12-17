/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: TIMER          ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/


#ifndef TIMER_config_H_
#define TIMER_config_H_

/*
 * Options: For Timer 0
 * 			1- NORMAL: Normal mode(overflow mode)
 * 			2- PWM_PHASE_CORRECT
 * 			3- CTC: Clear Timer on Compare Match
 * 			4- FAST_PWM
 * */
#define WAVE_GENERATION_MODE	FAST_PWM

/*
 * Options:
 * 			1- TOGGLE: Toggle OC0 on compare match
 * 			2- CLEAR: Clear OC0 on compare match
 * 			3-SET: Set OC0 on compare match
 * */
#define COMP_OUT_MODE_NON_PWM	SET

/*
 * Options:
 * 			1- NON_INVERTING_MODE: Clear OC0 on compare match, set OC0 at Top,
 * 			2- INVERTING_MODE: Set OC0 on compare match, clear OC0 at Top,
 * */
#define COMP_OUT_MODE	NON_INVERTING_MODE

/*
 * Options:
 * 	1- NON_INVERTING:
 * 			Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
 * 	2- INVERTING:
 * 		Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.
 * */
#define COMP_OUT_MODE_PHASE_CORRECT	NON_INVERTING


/*
 * Options:
 * 			1- DIVIDE_BY_8: clkI/O/8 (From prescaler)
 * 			2- DIVIDE_BY_64:
 * 			3- DIVIDE_BY_256:
 * 			4- DIVIDE_BY_1024:
 * */

#define CLK_PRESCALER	DIVIDE_BY_8


#endif
