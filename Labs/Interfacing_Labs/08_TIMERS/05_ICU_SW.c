#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "TIMER_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>

void ICU_SW_ISR_INT0(void);

u16 App_u16PeriodTime = 0;
u16 App_u16ONTime = 0;

void main(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	GIE_voidEnable();

	EXTI_voidInt0Init();
	EXTI_u8Int0SetCallBack(&ICU_SW_ISR_INT0);

	TIMER1_voidInit();
	TIMER0_voidInit();
	TIMER0_voidSetCompMatchValue(64);

	while(1)
	{
		// wait until signal captured(period time, on time measured)
		while(App_u16PeriodTime == 0);
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Period Time:");
		CLCD_voidWriteNumber(App_u16PeriodTime);
		CLCD_voidSendString("us");

		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("ON Time: ");
		CLCD_voidWriteNumber(App_u16ONTime);
		CLCD_voidSendString("us");
	}
}

// notification or callback
void ICU_SW_ISR_INT0(void)
{
	static u8 Local_u8Counter = 0;
	static 	u16 Local_u16PeriodTicks;
	static 	u16 Local_u16OnTimeTicks;

	Local_u8Counter++;
	if(Local_u8Counter == 1)
	{
		// clear timer
		TIMER1_voidSetTimerValue(0);
	}
	else if(Local_u8Counter == 2)
	{
		Local_u16PeriodTicks = TIMER1_u16ReadTimerValue();
		App_u16PeriodTime =Local_u16PeriodTicks * 1 ; // 1us is tick time
		EXTI_u8Int0SetSenseControl(FALLING_EDGE);
	}
	else if(Local_u8Counter == 3)
	{
		Local_u16OnTimeTicks = TIMER1_u16ReadTimerValue() - Local_u16PeriodTicks;
		App_u16ONTime = Local_u16OnTimeTicks * 1;

		// disable Interrupt
		EXTI_u8IntDisable(INT0);
	}
}
