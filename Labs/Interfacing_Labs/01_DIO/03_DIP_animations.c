#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "SW_interface.h"
#include <util/delay.h>


void APP_voidFlashing_every_500ms(void);
void APP_voidShifting_left_every_250ms(void);
void APP_voidShifting_right_every_250ms(void);
void APP_void2LEDs_converging_every_300ms(void);
void APP_void2LEDs_diverging_every_300ms(void);
void APP_voidPingPongEffect(void);
void APP_voidSnakeEffect(void);
void APP_void2LEDs_con_diverging_every_300ms(void);

static u8 APP_u8LED_nth [8] = {1, 2, 4, 8, 16, 32, 64, 128};
static u8 APP_u82LEDs_nth [4] = {24, 36, 66, 129};

void main(void)
{
	PORT_voidInit();

	u8 *Local_u8SW1State = NULL;
	u8 *Local_u8SW2State = NULL;
	u8 *Local_u8SW3State = NULL;
	u8 Local_u8Mode;

	while(1)
	{
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN2, SW_SELFLOCKING, SW_PULL_UP, Local_u8SW1State);
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN3, SW_SELFLOCKING, SW_PULL_UP, Local_u8SW2State);
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN4, SW_SELFLOCKING, SW_PULL_UP, Local_u8SW3State);

		Local_u8Mode = *Local_u8SW1State + *Local_u8SW2State + *Local_u8SW3State;

		switch (Local_u8Mode) {
			case 0: APP_voidFlashing_every_500ms();		  break;
			case 1: APP_voidShifting_left_every_250ms();  break;
			case 2: APP_voidShifting_right_every_250ms(); break;
			case 3: APP_void2LEDs_converging_every_300ms(); break;
			case 4: APP_void2LEDs_diverging_every_300ms(); break;
			case 5: APP_voidPingPongEffect(); break;
			case 6: APP_voidSnakeEffect(); break;
			case 7: APP_void2LEDs_con_diverging_every_300ms(); break;
			default: break;
		}

	}
}


void APP_voidFlashing_every_500ms(void) {
	DIO_u8SetPortValue(DIO_u8PORTB, 0b11111111);
	_delay_ms(500);
	DIO_u8SetPortValue(DIO_u8PORTB, 0);
	_delay_ms(500);
}

void APP_voidShifting_left_every_250ms(void) {
	for(u8 i= 0; (s8) i < 8; i++)
	{
		DIO_u8SetPortValue(DIO_u8PORTB, APP_u8LED_nth[i]);
		_delay_ms(250);
	}
}

void APP_voidShifting_right_every_250ms(void){
	for(u8 i= 7; (s8) i >= 0; i--)
	{
		DIO_u8SetPortValue(DIO_u8PORTB, APP_u8LED_nth[i]);
		_delay_ms(250);
	}
}

void APP_void2LEDs_converging_every_300ms(void) {
	for(u8 i= 0; (s8) i < 4; i++)
	{
		DIO_u8SetPortValue(DIO_u8PORTB, APP_u82LEDs_nth[i]);
		_delay_ms(300);
	}
}

void APP_void2LEDs_diverging_every_300ms(void){
	for(u8 i= 3; (s8) i >= 0; i--)
	{
		DIO_u8SetPortValue(DIO_u8PORTB, APP_u82LEDs_nth[i]);
		_delay_ms(300);
	}
}

void APP_voidPingPongEffect(void){
	APP_voidShifting_left_every_250ms();
	APP_voidShifting_right_every_250ms();
}

void APP_voidSnakeEffect(void) {
	u8 increment = 0;
	for(u8 i= 0; (s8) i < 8; i++)
	{
		increment += APP_u8LED_nth[i];
		DIO_u8SetPortValue(DIO_u8PORTB, increment);
		_delay_ms(250);
	}
}

void APP_void2LEDs_con_diverging_every_300ms(void) {
	APP_void2LEDs_diverging_every_300ms();
	APP_void2LEDs_converging_every_300ms();
}
