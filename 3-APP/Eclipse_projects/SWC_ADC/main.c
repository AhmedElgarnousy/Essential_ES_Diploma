#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"PORT_interface.h"
#include"DIO_interface.h"
#include"ADC_interface.h"
#include"GIE_interface.h"

void ADC_voidNotification (void);//prototype
void APP_voidNotificationChain (void);//prototype

u16 App_u16ADCReading;

/*
u8* Channel;
u8* Result;
u8 Size;
*/

u8 APP_u8ChainSynchChannelArr[]={SINGLE_ENDED_ADC0,SINGLE_ENDED_ADC1,SINGLE_ENDED_ADC2};
u8 APP_u8ChainSynchResultArr[];

ADC_ChainSynch_t Chain1={APP_u8ChainSynchChannelArr,APP_u8ChainSynchResultArr,3};

void main()
{
	PORT_voidInit();
	ADC_voidInit();

	while(1)
	{
		GIE_voidEnable();
		/*
		ADC_u8StartConversionAsynch(SINGLE_ENDED_ADC0,&App_u16ADCReading,APP_voidNotificationSingle);
		*/
	}


}

void APP_voidNotificationSingle (void)
{

	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,App_u16ADCReading);
}

void APP_voidNotificationChain (void)
{
	//DIO_u8SetPortValue(DIO_u8PORTA,App_u16ADCReading);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,App_u16ADCReading);
}

