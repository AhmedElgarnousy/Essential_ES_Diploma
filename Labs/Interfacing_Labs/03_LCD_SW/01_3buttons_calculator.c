#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"PORT_interface.h"
#include"SW_interface.h"
#include"CLCD_interface.h"
#include"LED_interface.h"
#include<util/delay.h>


	u8 Local_u8Up = SW_NOT_PRESSED;
	u8 Local_u8Down = SW_NOT_PRESSED;
	u8 Local_u8Enter = SW_NOT_PRESSED;

	u8 Local_u8Num1 = 1;
	u8 Local_u8Num2 = 1;
	u8 Local_u8NextIdx = 0;
	char Local_u8Operations[4] = {'+', '-', '*', '/'};

	LED_t REDLed  = {DIO_u8PORTC, DIO_u8PIN0, LED_CONN_SRC};

	u8 Local_u8Arrow [8] = {0b00000100, 0b00001110, 0b00010101, 0b00000100, 0b00000100, 0b00000100, 0b00000100, 0b00000100};
	u8 Local_u8Clear [8] = { 0b00000000 };


void CALC_voidInitState() {
	// initial state 1 + 1
	CLCD_voidClearScreen();
	CLCD_voidSendString("welcome");
	_delay_ms(1000);
	CLCD_voidClearScreen();

	CLCD_voidWriteNumber(1);
	CLCD_voidSendData('+');
	CLCD_voidWriteNumber(1);
}

void CALC_voidSelectDigit1(){
	// choose digit1 option
	do
	{
		CLCD_voidGoToXY(1,9);
		CLCD_voidSendString("OP1");
		CLCD_voidWriteSpecialCharacter(Local_u8Arrow, 1, 1, 0);
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN2, SW_SELFLOCKING, SW_PULL_UP, &Local_u8Up);
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN3, SW_SELFLOCKING, SW_PULL_UP, &Local_u8Down);
		SW_u8GetState(DIO_u8PORTD, DIO_u8PIN4, SW_SELFLOCKING, SW_PULL_UP, &Local_u8Enter);

		if (Local_u8Up == SW_PRESSED)
		{
			LED_u8TurnOn(&REDLed);
			_delay_ms(500);
			LED_u8TurnOff(&REDLed);
			_delay_ms(500);

			Local_u8Num1++;
			CLCD_voidGoToXY(0,0);
			CLCD_voidWriteNumber(Local_u8Num1);
		}
		if (Local_u8Down == SW_PRESSED)
		{
			Local_u8Num1--;
			CLCD_voidGoToXY(0,0);
			CLCD_voidWriteNumber(Local_u8Num1);
		}
	}while(Local_u8Enter == SW_NOT_PRESSED);

}

void CALC_voidSelectOperation(){
	do
		{
			CLCD_voidGoToXY(1,9);
			CLCD_voidSendString("OP2");

			CLCD_voidWriteSpecialCharacter(Local_u8Clear, 0, 1, 0);
			CLCD_voidWriteSpecialCharacter(Local_u8Arrow, 1, 1, 1);
			SW_u8GetState(DIO_u8PORTD, DIO_u8PIN2, SW_SELFLOCKING, SW_PULL_UP, &Local_u8Up);
			SW_u8GetState(DIO_u8PORTD, DIO_u8PIN3, SW_SELFLOCKING, SW_PULL_UP, &Local_u8Down);
			SW_u8GetState(DIO_u8PORTD, DIO_u8PIN4, SW_SELFLOCKING, SW_PULL_UP, &Local_u8Enter);

			if (Local_u8Up == SW_PRESSED)
			{
				Local_u8NextIdx++;
				if(Local_u8NextIdx == 4)
				{
					Local_u8NextIdx = 0;
				}
				CLCD_voidGoToXY(0,1);
				CLCD_voidSendData(Local_u8Operations[Local_u8NextIdx]);
			}
			if (Local_u8Down == SW_PRESSED)
			{
				Local_u8NextIdx--;
				if(Local_u8NextIdx == (u8)-1)
				{
					Local_u8NextIdx = 3;
				}
				CLCD_voidGoToXY(0,1);
				CLCD_voidSendData(Local_u8Operations[Local_u8NextIdx]);
			}
		}while(Local_u8Enter == SW_NOT_PRESSED);

}

void CALC_voidSelectDigit2(){
	// choose digit2 option
		do
		{
			CLCD_voidGoToXY(1,9);
			CLCD_voidSendString("OP3");
			CLCD_voidWriteSpecialCharacter(Local_u8Clear, 0, 1, 1);
			CLCD_voidWriteSpecialCharacter(Local_u8Arrow, 1, 1, 2);
			SW_u8GetState(DIO_u8PORTD, DIO_u8PIN2, SW_SELFLOCKING, SW_PULL_UP, &Local_u8Up);
			SW_u8GetState(DIO_u8PORTD, DIO_u8PIN3, SW_SELFLOCKING, SW_PULL_UP, &Local_u8Down);
			SW_u8GetState(DIO_u8PORTD, DIO_u8PIN4, SW_SELFLOCKING, SW_PULL_UP, &Local_u8Enter);

			if (Local_u8Up == SW_PRESSED)
			{
				Local_u8Num2++;
				CLCD_voidGoToXY(0,2);
				CLCD_voidWriteNumber(Local_u8Num2);
			}
			if (Local_u8Down == SW_PRESSED)
			{
				Local_u8Num2--;
				CLCD_voidGoToXY(0,2);
				CLCD_voidWriteNumber(Local_u8Num2);
			}
		}while(Local_u8Enter == SW_NOT_PRESSED);
}

void CALC_voidResult(){
	// result
	CLCD_voidWriteSpecialCharacter(Local_u8Clear, 0, 1, 2); // delete previous arrow
	CLCD_voidWriteSpecialCharacter(Local_u8Arrow, 1, 1, 4);
	CLCD_voidGoToXY(0,3);
	CLCD_voidSendData('=');

	if(Local_u8Operations[Local_u8NextIdx] == '+')
	{
		CLCD_voidWriteNumber(Local_u8Num1 + Local_u8Num2);
	}
	else if(Local_u8Operations[Local_u8NextIdx] == '-')
	{
		CLCD_voidWriteNumber(Local_u8Num1 - Local_u8Num2);
	}
	else if(Local_u8Operations[Local_u8NextIdx] == '*')
	{
		CLCD_voidWriteNumber(Local_u8Num1 * Local_u8Num2);
	}
	else if(Local_u8Operations[Local_u8NextIdx] == '/')
	{
		CLCD_voidWriteNumber(Local_u8Num1 / Local_u8Num2);
	}
}



void main(void)
{
	PORT_voidInit();
	CLCD_voidInit();

	while(1)
	{

		CALC_voidInitState();

		CALC_voidSelectDigit1();
		CALC_voidSelectOperation();
		CALC_voidSelectDigit2();
		CALC_voidResult();

		do
		{
			SW_u8GetState(DIO_u8PORTD, DIO_u8PIN4, SW_SELFLOCKING, SW_PULL_UP, &Local_u8Enter);

		}while(Local_u8Enter == SW_NOT_PRESSED);

		CLCD_voidClearScreen();
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Start Again");
		_delay_ms(2000);
		Local_u8Num1 = 1;
		Local_u8Num2 = 1;
		Local_u8NextIdx = 0;

	}
}
