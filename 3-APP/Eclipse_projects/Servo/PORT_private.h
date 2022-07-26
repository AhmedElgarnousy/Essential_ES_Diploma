/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: PORT             *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/


#ifndef PORT_private_H_
#define PORT_private_H_

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)	0b##b7##b6##b5##b4##b3##b2##b1##b0

#define PORTA_DIR			CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR )
#define PORTB_DIR			CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR )
#define PORTC_DIR			CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR )
#define PORTD_DIR			CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR )

#define PORTA_InitVal		CONC(PORTA_PIN7_InitVal,PORTA_PIN6_InitVal,PORTA_PIN5_InitVal,PORTA_PIN4_InitVal,PORTA_PIN3_InitVal,PORTA_PIN2_InitVal,PORTA_PIN1_InitVal,PORTA_PIN0_InitVal)
#define PORTB_InitVal		CONC(PORTB_PIN7_InitVal,PORTB_PIN6_InitVal,PORTB_PIN5_InitVal,PORTB_PIN4_InitVal,PORTB_PIN3_InitVal,PORTB_PIN2_InitVal,PORTB_PIN1_InitVal,PORTB_PIN0_InitVal)
#define PORTC_InitVal		CONC(PORTC_PIN7_InitVal,PORTC_PIN6_InitVal,PORTC_PIN5_InitVal,PORTC_PIN4_InitVal,PORTC_PIN3_InitVal,PORTC_PIN2_InitVal,PORTC_PIN1_InitVal,PORTC_PIN0_InitVal)
#define PORTD_InitVal		CONC(PORTD_PIN7_InitVal,PORTD_PIN6_InitVal,PORTD_PIN5_InitVal,PORTD_PIN4_InitVal,PORTD_PIN3_InitVal,PORTD_PIN2_InitVal,PORTD_PIN1_InitVal,PORTD_PIN0_InitVal)

#endif
