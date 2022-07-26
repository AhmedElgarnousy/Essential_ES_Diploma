#include"STD_TYPES.h"
#include"util/delay.h"
#include"PORT_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
void INT0_ISR(void);
void INT1_ISR(void);
void main(void)
{
	PORT_voidInit();

	EXTI_voidInt0Init();
    EXTI_voidInt1Init();
	EXTI_u8Int0SetCallBack(INT0_ISR);
	EXTI_u8Int1SetCallBack(INT1_ISR);
	GIE_voidEnable();

	while(1)
	{


	}

}

void INT0_ISR()
{
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
}
void INT1_ISR()
{
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_HIGH);
	_delay_ms(50);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_LOW);
	_delay_ms(50);
}

