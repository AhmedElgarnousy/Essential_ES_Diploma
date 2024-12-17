#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "GIE_interface.h"

#include "TIMER_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>

void ICU_HW_ISR(void);

u16 App_u16PeriodTime = 0;
u16 App_u16ONTime = 0;

int main(void)
{
	PORT_voidInit();

	CLCD_voidInit();

	// Counter
//	ICU_u8SetCallBack(&ICU_HW_ISR);
	TIMER_voidSetCallBack(&ICU_HW_ISR,5); // 5 is TIMER1_CAPT
	ICU_voidInit();

	TIMER1_voidInit();

	// generate PWM Signal
	TIMER0_voidInit();
	TIMER0_voidSetCompMatchValue(64);
	GIE_voidEnable();

	while(1)
	{
		// wait until signal captured(period time, on time measured)
//		while(App_u16PeriodTime == 0 && App_u16ONTime == 0);
		while(App_u16PeriodTime == 0);

		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Period:");
		CLCD_voidWriteNumber(App_u16PeriodTime);
		CLCD_voidSendString("us");

		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("ON Time: ");
		CLCD_voidWriteNumber(App_u16ONTime);
		CLCD_voidSendString("us");
	}
}

// notification or callback
void ICU_HW_ISR(void)
{
	static u8 Local_u8Counter = 0;
	static u16 Reading1, Reading2, Reading3;
	static u16 Local_u16PeriodTicks, Local_u16OnTicks;
	Local_u8Counter++;

	if(Local_u8Counter == 1)
	{
		Reading1 =  ICU_u16ReadInputCaputure();
	}
	else if(Local_u8Counter == 2)
	{
		Reading2 =  ICU_u16ReadInputCaputure();
		Local_u16PeriodTicks = Reading2 - Reading1;
		ICU_u8SetTriggerEdge(ICU_FALLING_EDGE);
		App_u16PeriodTime = Local_u16PeriodTicks * 1; // 1us is tick time
	}
	else if(Local_u8Counter == 3)
	{
		Reading3 =  ICU_u16ReadInputCaputure();
		Local_u16OnTicks = Reading3 - Reading2;
		App_u16ONTime = Local_u16OnTicks * 1; // 1us is tick time
		// disable interrupt
		ICU_voidDisableInterrupt();
	}
}
