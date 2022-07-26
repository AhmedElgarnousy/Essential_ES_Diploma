#include<avr/io.h>
#include<util/delay.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"

void main(void)
{

DDRC=0xff;
u8 i;
u8 j;
DDRD=0b00000011;

u16 SevSegArr_1[]={0b0111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b01001111,0b01111111,0b01101111};
u16 SevSegArr_2[]={0b0111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b01001111,0b01111111,0b01101111};
		while(1)
		{


			for(i=0,j=9;i<10,j>=0;i++,j--)
			{
				 CLR_BIT(PORTD,0);
		        SET_BIT(PORTD,1);
				 PORTC=SevSegArr_1[i];
				 _delay_ms(1);
				 SET_BIT(PORTD,0);
				CLR_BIT(PORTD,1);
				 PORTC=SevSegArr_2[j];
				 _delay_ms(1);
			}




		}


}
