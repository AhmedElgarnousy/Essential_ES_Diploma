/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: RTOS Stack     *************************/
/*************   SWC: RTOS             *************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
/***************************************************************/

#include"STD_TYPES.h"

#include"TIMER_interface.h"
#include"GIE_interface.h"

#include"RTOS_private.h"
#include"RTOS_interface.h"
#include"RTOS_config.h"


Task_t SystemTasks[TASK_NUM] = {{NULL}};

void RTOS_voidStart(void)
{
	/**/
	TIMER0_u8SetCallBack(&voidScheduler);
	GIE_voidEnable();
	TIMER0_voidInit();
}

void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void(*Copy_pvTaskFunc)(void))
{
	SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
	SystemTasks[Copy_u8Priority].TaskFunc = Copy_pvTaskFunc;

}

static void voidScheduler(void)
{
	static u16 Local_u16TickCounter=0;
	u8 Local_u8TaskCounter;

	Local_u16TickCounter++;

	/*Loop on all tasks to check their periodicity*/
	for(Local_u8TaskCounter=0; Local_u8TaskCounter < TASK_NUM; Local_u8TaskCounter++)
	{
		if((Local_u16TickCounter % SystemTasks[Local_u8TaskCounter].Periodicity) == 0)
		{
			/*Invoke the task function*/
		    if(SystemTasks[Local_u8TaskCounter].TaskFunc != NULL)
			{
				SystemTasks[Local_u8TaskCounter].TaskFunc();
			}
			else
			{
				/*Do nothing*/
			}
		}
	}
}





