/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: 	EXTI           *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/

#ifndef EXTI_config_H_
#define EXTI_config_H_

/* Options:
			1-LOW_LEVEL
			2-ON_CHANGE
			3-FALLING_EDGE
			4-RISING_EDGE
							  */
							  
#define INT0_SENSE			FALLING_EDGE
#define INT1_SENSE			FALLING_EDGE
/* Options:
			1-FALLING_EDGE
			2-RISING_EDGE
							  */
#define INT2_SENSE FALLING_EDGE

/* means that you want to start the code with enabling the interrupt or not*/
/*OPTIONS:
			1-ENABLED
			2-DISABLE
							  */

#define INT0_INITIAL_STATE	ENABLED
#define INT1_INITIAL_STATE  ENABLED
#define INT2_INITIAL_STATE  DISABLE


#endif
