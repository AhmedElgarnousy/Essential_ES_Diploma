#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "DIO_interface.h"

#include "util/delay.h"


#define WDTCR 		*((volatile u8*)0x41)
#define WDTCR_WDTOE			4
#define WDTCR_WDE			3
#define WDTCR_WDP2			2
#define WDTCR_WDP1			1
#define WDTCR_WDP0			0


void WDT_voidSleep(u8 Copy_u8SleepTime);
void WDT_voidEnable();
void WDT_voidDisable();

void main()
{
	PORT_voidInit();
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);

	WDT_voidEnable();
	/*Watch DoG Sleep After 1 second*/
	WDT_voidSleep(6);
	WDT_voidDisable();

	while(1)
	{


	}

}

/*Make it Configurable with BitMasking*/
void WDT_voidSleep(u8 Copy_u8SleepTime)
{
	/*Clear Prescaller Bits*/
	WDTCR &=0b11111000;

	/*Set the required prescaller*/
	WDTCR |=Copy_u8SleepTime;
}
void WDT_voidEnable()
{

	SET_BIT(WDTCR,WDTCR_WDE);

}
void WDT_voidDisable()
{
	WDTCR |=0b00011000;

	WDTCR =0;


}
