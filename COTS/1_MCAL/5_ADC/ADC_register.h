/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: ADC           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/

#ifndef	ADC_register_H_
#define ADC_register_H_


#define ADMUX           *( (volatile u8* ) 0x27)    /*ADC Multiplexer Selection Register*/
#define ADMUX_REFS1		7					        /*Reference Selection Bit1*/
#define ADMUX_REFS0		6					        /*Reference Selection Bit0*/
#define ADMUX_ADLAR		5					        /*ADC Left Adjust Result*/



#define ADCSRA   	    *( (volatile u8* ) 0x26)	/*ADC Control and Status Register*/
#define ADCSRA_ADEN		7                           /*ADC Enable*/
#define ADCSRA_ADSC		6                           /*Start Conversion*/
#define ADCSRA_ADATA	5                           /*Auto trigger Enable*/
#define ADCSRA_ADIF		4                           /*Interrupt Flag*/
#define ADCSRA_ADIE		3                           /*Interrupt Enable*/
#define ADCSRA_ADPS2	2                           /*Prescaler Bit2*/
#define ADCSRA_ADPS1	1                           /*Prescaler Bit1*/
#define ADCSRA_ADPS0	0                           /*Prescaler Bit0*/

#define ADCH   			*( (volatile u8*) 0x25)	    /*ADC High Register*/
#define ADCL   		    *( (volatile u8*) 0x24)     /*ADC Low Register*/

#define SFIOR			*( ( volatile u8* ) 0x50)
#define SFIOR_ADTS2		7
#define SFIOR_ADTS1		6
#define SFIOR_ADTS0		5

#define ADC   		    *( (volatile u16* ) 0x24)

#endif
