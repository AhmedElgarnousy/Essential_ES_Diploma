#include<avr/io.h>
#include<util/delay.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
//Assignment1
void main()
{

   DDRA=0b00000111;
  /*set first three bits of port A is output& next three bits are input for switchs
   A0 for green, A1 for yellow, A2 for red*/
   DDRB=0b11111111;/*first seven segment (common cathode) to display*/
   DDRC=0b11111111;/*second seven segment (common cathode)*/

   u16 SevSegArr_1[]={0b01101101,0b01100110,0b01001111,0b01011011,0b00000110,0b00111111,
      	0b01101111,0b01111111,0b01001111,0b01111101,
  		0b01101101,0b01100110, 0b01001111,0b01011011,
  		0b00000110,0b00111111};


      	 u16 SevSegArr_2[]={0b00000110,0b00000110,0b00000110,0b00000110,0b00000110,0b00000110,
      			 0b00111111,0b00111111,0b00111111
      			 ,0b00111111,0b00111111,0b00111111
  				 ,0b00111111,0b00111111,0b00111111,
  				 0b00111111};
      	u8 i;/* COUNTER */

	while(1)
	{

    	 //turn on green led for 15 seconds
    	 SET_BIT(PORTA,0);


     //count down from 15 to 0 on 2 sev_segemnts
		 for( i=0;i<=15;i++)
		 {
			PORTB=SevSegArr_1[i];
			PORTC=SevSegArr_2[i];
			_delay_ms(100);
         }
		 //turn off green led
		 CLR_BIT(PORTA,0);



		 //turn on yellow led for 3 seconds
		 SET_BIT(PORTA,1);

	     //count down from 3 to 0 on 2 sev_segemnts
		 for( i=2;i<=4;i++)
				 {
					PORTB=SevSegArr_1[i];
					PORTC=SevSegArr_2[7];
					_delay_ms(100);
		         }

		 //turn off yellow led
		 CLR_BIT(PORTA,1);




		 //turn on RED led for 15 seconds
		 SET_BIT(PORTA,2);
		 //count down from 15 to 0 on 2 sev_segemnts
		 for( i=0;i<=15;i++)
		 		 {
		 			PORTB=SevSegArr_1[i];
		 			PORTC=SevSegArr_2[i];
		 			_delay_ms(100);
		          }

		 //turn off RED led
				 CLR_BIT(PORTA,2);


     }


	}




