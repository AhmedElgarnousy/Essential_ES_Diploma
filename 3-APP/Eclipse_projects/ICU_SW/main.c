#include "STD_TYPES.h"


#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"

#include "CLCD_interface.h"


static u16 App_u16PeriodTicks=0;
static u16 App_u16OnTicks=0;

void ICU_SW();

void main()
{

	PORT_voidInit();

	EXTI_u8Int0SetCallBack(ICU_SW);
	EXTI_voidInt0Init();

	TIMER0_voidSetCompMatchValue(64);
	TIMER1_voidInit();

	CLCD_voidInit();
	TIMER0_voidInit();
	GIE_voidEnable();


	while(1)
	{
		/*Wait until period time and on ticks are measured*/
		while((App_u16PeriodTicks == 0) && (App_u16OnTicks == 0));

		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("PTime = ");
		CLCD_voidWriteNumber(App_u16PeriodTicks);

		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("On Ticks = ");
		CLCD_voidWriteNumber(App_u16OnTicks);
	}

}

/*The function that will run inside the INT0_ISR*/

void ICU_SW()
{
	static u8 Local_u8Counter=0;
	//u16 App_u16PeriodTicks, App_u16OnTicks;

	Local_u8Counter++;

	if(Local_u8Counter==1)
	{
		/*First Rising Edge*/
		TIMER1_voidSetTimerValue(0);
	}
	else if(Local_u8Counter==2)
	{
		/*Second Rising Edge*/
		App_u16PeriodTicks=TIMER1_u16ReadTimerValue();

		/*Change Trigger to falling Edge*/
		EXTI_u8Int0SetSenseControl(FALLING_EDGE);

	}
	else if(Local_u8Counter==3)
	{
		/*Timer reading now is period ticks + on ticks*/
		App_u16OnTicks=TIMER1_u16ReadTimerValue();
		App_u16OnTicks -=App_u16PeriodTicks;

		/*Disable INT0 interrupt*/
		EXTI_u8IntDisable(INT0);

	}
}
