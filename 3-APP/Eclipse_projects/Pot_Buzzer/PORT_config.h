/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: PORT             *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/


#ifndef PORT_config_H_
#define PORT_config_H_

/*Choose : 0 for input 
		   1 for output 		 */
		   
 #define   PORTA_PIN0_DIR       0
 #define   PORTA_PIN1_DIR       0
 #define   PORTA_PIN2_DIR       0
 #define   PORTA_PIN3_DIR       0
 #define   PORTA_PIN4_DIR       0
 #define   PORTA_PIN5_DIR       0
 #define   PORTA_PIN6_DIR       0
 #define   PORTA_PIN7_DIR       0

 
 #define   PORTB_PIN0_DIR       0
 #define   PORTB_PIN1_DIR       0
 #define   PORTB_PIN2_DIR       0
 #define   PORTB_PIN3_DIR       1
 #define   PORTB_PIN4_DIR       1
 #define   PORTB_PIN5_DIR       1
 #define   PORTB_PIN6_DIR       0
 #define   PORTB_PIN7_DIR       0

 
 #define   PORTC_PIN0_DIR       1
 #define   PORTC_PIN1_DIR       1
 #define   PORTC_PIN2_DIR       1
 #define   PORTC_PIN3_DIR       0
 #define   PORTC_PIN4_DIR       0
 #define   PORTC_PIN5_DIR       0
 #define   PORTC_PIN6_DIR       1
 #define   PORTC_PIN7_DIR       0

 
 #define   PORTD_PIN0_DIR       0
 #define   PORTD_PIN1_DIR       0
 #define   PORTD_PIN2_DIR       0
 #define   PORTD_PIN3_DIR       0
 #define   PORTD_PIN4_DIR       0
 #define   PORTD_PIN5_DIR       1
 #define   PORTD_PIN6_DIR       0
 #define   PORTD_PIN7_DIR       0


/*for DIR:0
 * choose 1: for pulled up
 * 		  0: for FLOATING
 *
 * for DIR:1
 * choose 1:for High
 * 		  0:for Low
 * */
#define 	PORTA_PIN0_InitVal	0
#define 	PORTA_PIN1_InitVal	0
#define 	PORTA_PIN2_InitVal	0
#define 	PORTA_PIN3_InitVal	0
#define 	PORTA_PIN4_InitVal	0
#define 	PORTA_PIN5_InitVal	0
#define 	PORTA_PIN6_InitVal	0
#define 	PORTA_PIN7_InitVal	0


#define 	PORTB_PIN0_InitVal	0
#define 	PORTB_PIN1_InitVal	0
#define 	PORTB_PIN2_InitVal	0
#define 	PORTB_PIN3_InitVal	1
#define 	PORTB_PIN4_InitVal	1
#define 	PORTB_PIN5_InitVal	1
#define 	PORTB_PIN6_InitVal	0
#define 	PORTB_PIN7_InitVal	0

#define 	PORTC_PIN0_InitVal	0
#define 	PORTC_PIN1_InitVal	0
#define 	PORTC_PIN2_InitVal	0
#define 	PORTC_PIN3_InitVal	0
#define 	PORTC_PIN4_InitVal	0
#define 	PORTC_PIN5_InitVal	1
#define 	PORTC_PIN6_InitVal	0
#define 	PORTC_PIN7_InitVal	0


#define 	PORTD_PIN0_InitVal	0
#define 	PORTD_PIN1_InitVal	0
#define 	PORTD_PIN2_InitVal	0
#define 	PORTD_PIN3_InitVal	0
#define 	PORTD_PIN4_InitVal	0
#define 	PORTD_PIN5_InitVal	1
#define 	PORTD_PIN6_InitVal	0
#define 	PORTD_PIN7_InitVal	0


#endif
