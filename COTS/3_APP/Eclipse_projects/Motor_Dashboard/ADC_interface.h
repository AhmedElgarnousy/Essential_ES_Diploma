/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: ADC           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/

#ifndef	ADC_interface_H_
#define ADC_interface_H_


void ADC_voidInit(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16 *Copy_pu16Reading);

/*you should enable the GIE Before using this Function*/
u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u16* Copy_pu16Reading,void (*Copy_pvNotificationFunc)(void));

typedef struct
{
	u8 *Channel;
	u8 *Result;
	u8 size;
	void (*pvNotificationFunc)(void);

}ADC_Chain_t;

u8 ADC_u8StartChainAsynch(ADC_Chain_t *Copy_psChain);


#define SINGLE_ENDED_ADC0       0
#define SINGLE_ENDED_ADC1	    1
#define SINGLE_ENDED_ADC2		2
#define	SINGLE_ENDED_ADC3		3
#define SINGLE_ENDED_ADC4		4
#define SINGLE_ENDED_ADC5		5
#define SINGLE_ENDED_ADC6		6
#define SINGLE_ENDED_ADC7		7

#define   POSTIVE_DIFFERENTIAL_ADC1_NEGATIVE_DIFFERENTIAL_ADC0_GAIN_10X		10
#define   POSTIVE_DIFFERENTIAL_ADC1_NEGATIVE_DIFFERENTIAL_ADC0_GAIN_200X	12
#define   POSTIVE_DIFFERENTIAL_ADC3_NEGATIVE_DIFFERENTIAL_ADC2_GAIN_10X		14
#define   POSTIVE_DIFFERENTIAL_ADC3_NEGATIVE_DIFFERENTIAL_ADC2_GAIN_200X	16
#define   POSTIVE_DIFFERENTIAL_ADC0_NEGATIVE_DIFFERENTIAL_ADC1_GAIN_1X		17
#define   POSTIVE_DIFFERENTIAL_ADC2_NEGATIVE_DIFFERENTIAL_ADC1_GAIN_1X		19
#define   POSTIVE_DIFFERENTIAL_ADC3_NEGATIVE_DIFFERENTIAL_ADC1_GAIN_1X		20

#endif
