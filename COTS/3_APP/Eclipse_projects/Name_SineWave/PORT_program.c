/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: PORT              *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/

#include"STD_TYPES.h"

#include"PORT_config.h"
#include"PORT_private.h"
#include"PORT_interface.h"
#include"PORT_register.h"


void PORT_voidInit()
{
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;

	PORTA=PORTA_InitVal;
	PORTB=PORTB_InitVal;
	PORTC=PORTC_InitVal;
	PORTD=PORTD_InitVal;
}
