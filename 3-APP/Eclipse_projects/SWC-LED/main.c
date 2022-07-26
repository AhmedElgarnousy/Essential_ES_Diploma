/******************************************************************************/
/******************************************************************************/
/*********************       Author :Ahmed Kamal      *************************/
/*********************       Layer :	HALL	      *************************/
/*********************       SWC :Led              *************************/
/*********************       Version : 1.00           *************************/
/******************************************************************************/
/******************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include<util/delay.h>

#include "LED_config.h"#include "LED_config.h"
#include "LED_interface.h"#include "LED_interface.h"
#include"DIO_interface.h"


void main(void)
{
	/*LED_t Led1={DIO_u8PORTA,DIO_u8PIN5,LED_u8Sink};
	LED_t Led2={DIO_u8PORTB,DIO_u8PIN3,LED_u8Sink};*/
	LED_t Led3={DIO_u8PORTC,DIO_u8PIN4,LED_u8Source};
	LED_t Led4={DIO_u8PORTD,DIO_u8PIN7,LED_u8Sink};

		while(1)
		{
				/*LED_u8Turn_On(&Led1);
				_delay_ms(50);
				LED_u8Turn_Off(&Led1);
				_delay_ms(50);

				LED_u8Turn_On(&Led2);
				_delay_ms(50);
				LED_u8Turn_Off(&Led2);
				_delay_ms(50);*/

				LED_u8Turn_On(&Led3);
				_delay_ms(50);
				LED_u8Turn_Off(&Led3);
				_delay_ms(50);

				LED_u8Turn_On(&Led4);
				_delay_ms(50);
				LED_u8Turn_Off(&Led4);
				_delay_ms(50);
		}
}
