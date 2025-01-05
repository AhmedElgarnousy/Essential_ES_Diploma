
#include "STD_TYPES.h"
//#include "B"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "RTOS_interface.h"


LED_t led1 = {DIO_u8PORTC, DIO_u8PIN0, LED_CONN_SRC};
LED_t led2 = {DIO_u8PORTC, DIO_u8PIN1, LED_CONN_SRC};
LED_t led3 = {DIO_u8PORTC, DIO_u8PIN2, LED_CONN_SRC};

void LED1(void);
void LED2(void);
void LED3(void);

int main()
{
	PORT_voidInit();
	RTOS_voidCreateTask(0, 1000, &LED1);
	RTOS_voidCreateTask(1, 3000, &LED3);
	RTOS_voidCreateTask(2, 2000, &LED2);

	RTOS_voidStart();

	while(1)
	{

	}
}

void LED1(void){
	LED_u8Toggle(&led1);
}
void LED2(void){
	LED_u8Toggle(&led2);

}
void LED3(void){
	LED_u8Toggle(&led3);

}
