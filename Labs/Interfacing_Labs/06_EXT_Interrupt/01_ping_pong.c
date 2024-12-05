#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include <util/delay.h>


void INT0_ISR(void); // SW1
void INT1_ISR(void); // SW2

u8 Ball [8] = {0b00000000, 0b00000000, 0b00001110, 0b00010001, 0b00010001, 0b00001110, 0b00000000, 0b00000000, 0b00000000};
u8 TennisRacket1 [8] = { 0b00011100, 0b00011100, 0b00011000, 0b00011000, 0b00011000, 0b00011000, 0b00011000, 0b00011100, 0b00000000};
u8 TennisRacket2 [8] = { 0b00000111, 0b00000111, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000011, 0b00000111, 0b00000000};
u8 DeleteRacket [8] = {0b00000000};

u8 App_Rocket1Pos = 0; // defend
u8 App_Rocket2Pos = 0; // defend

#define TABLE_LENGTH  14

void main(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	GIE_voidEnable();
	EXTI_voidInt0Init();
	EXTI_voidInt1Init();
	EXTI_u8Int0SetCallBack(INT0_ISR);
	EXTI_u8Int1SetCallBack(INT1_ISR);


	// void App_voidPingPongStart(void) {}
	CLCD_voidClearScreen();
//	CLCD_voidWriteSpecialCharacter(TennisRacket1, 1, 0, 0);
//	CLCD_voidWriteSpecialCharacter(TennisRacket2, 2, 0, 15);
	CLCD_voidGoToXY(1,2);
	CLCD_voidSendString("game start");
	_delay_ms(3000);
	CLCD_voidClearScreen();

	while(1)
	{
		// move ball right
		// void App_voidKickBallRight(){}
		for(u8 i= 0; i < TABLE_LENGTH; i++)
		{
			CLCD_voidWriteSpecialCharacter(Ball, 0, 0, i);
			CLCD_voidWriteSpecialCharacter(TennisRacket1, 1, 0, 0);
			CLCD_voidWriteSpecialCharacter(TennisRacket2, 2, 0, 15);
			_delay_ms(150);
			CLCD_voidClearScreen();
		}

		// check racket 1 is defend or kicked
		if(App_Rocket2Pos == 1)
		{
			CLCD_voidClearScreen();
			CLCD_voidGoToXY(1,1);
			CLCD_voidSendString("Player 1 wins");
			_delay_ms(2000);
			App_Rocket2Pos = 0;
		}

//		void App_voidKickBallLeft(){}
		for(u8 i = TABLE_LENGTH; i > 0; i--)
		{
			CLCD_voidWriteSpecialCharacter(Ball, 0, 0, i);
			CLCD_voidWriteSpecialCharacter(TennisRacket1, 1, 0, 0);
			CLCD_voidWriteSpecialCharacter(TennisRacket2, 2, 0, 15);
			_delay_ms(150);
			CLCD_voidClearScreen();
		}

		// check racket 2 is defend or kicked
		if(App_Rocket1Pos == 1)
		{
			CLCD_voidClearScreen();
			CLCD_voidGoToXY(1,1);
			CLCD_voidSendString("Player 2 wins");
			_delay_ms(2000);
			App_Rocket1Pos = 0;
		}
	}
}


void INT0_ISR(void) {
	CLCD_voidWriteSpecialCharacter(DeleteRacket, 3, 0, 0);
	CLCD_voidWriteSpecialCharacter(TennisRacket1, 4, 1, 0);
	App_Rocket1Pos = 1;
}

void INT1_ISR(void) {
	CLCD_voidWriteSpecialCharacter(DeleteRacket, 5, 0, 15);
	CLCD_voidWriteSpecialCharacter(TennisRacket2, 6, 1, 15);
	App_Rocket2Pos = 1;
}
