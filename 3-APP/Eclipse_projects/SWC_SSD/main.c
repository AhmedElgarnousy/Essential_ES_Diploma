/*************************************************************************/
/*************************************************************************/
/********************  Author : Ahmed Kamal    ****************************/
/********************  Layer  : HALL           ****************************/
/********************  SWC    : SSD               *************************/
/********************  version: 1.00          ****************************/
/*************************************************************************/
/*************************************************************************/

#include<avr/delay.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"
#include"SSD_interface.h"
#include"SSD_config.h"
#include"SSD_private.h"


SSD_t SSD1={COM_CATHODE,DIO_u8PORTA,DIO_u8PORTB,DIO_u8PIN0};


void main(void)
{


	while(1)
	{
u8 arr[]={SSD_u8_EIGHT,SSD_u8_SEVEN,SSD_u8_SIX,SSD_u8_FIVE,SSD_u8_FOUR,SSD_u8_THREE,SSD_u8_TWO,SSD_u8_ONE,SSD_u8_ZERO};

u8 counter;
for(counter=0;counter<9;counter++){
	SSD_u8SetNumber(arr[counter],&SSD1);
	_delay_ms(50);


}
SSD_t SSD2={COM_CATHODE,DIO_u8PORTA,DIO_u8PORTB,DIO_u8PIN0};
SSD_u8Enable_SDD(&SSD2);
_delay_ms(100);



	}





}
