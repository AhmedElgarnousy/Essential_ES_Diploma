#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "util/delay.h"

#include"DIO_interface.h"
#include"PORT_interface.h"

#include"CLCD_interface.h"

#define time	80


void main(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	u8 Local_u8Counter;
	u8 Local_u8Counter1;
	u8 Local_u8Counter2;
	u8 Local_u8Counter3;

	/*Location1 in CGRAM For Hamoksha
	 Location2 in CGRAM For BALL
	 */
	u8 Hamoksha[7]={
					0b00001110,
					0b00010001,
					0b00001110,
					0b00000100,
					0b00011111,
					0b00000100,
					0b11111111
								};
	u8 Hamoksha_down[7]={
			0b00001110,
			0b00010001,
			0b00001110,
			0b00000100,
			0b00011111,
			0b00000100,
			0b00011000
						};
	u8 Hamoksha_up[7]={
			0b00001110,
			0b00010001,
			0b00001110,
			0b00000100,
			0b00011111,
			0b00000100,
			0b00000011
						};
	u8 BALL[7]={
								0b00000000,
								0b00000000,
								0b00000000,
								0b00000110,
								0b00000110,
								0b00000000,
								0b00000000,
											};

	u8 BALL_dowm[7]={
								0b00000000,
								0b00000000,
								0b00000000,
								0b00000000,
								0b00000110,
								0b00000110,
								0b00000000,
											};
	u8 BALL_up[8]={
			0b00011000,
			0b00011000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000
						};

	u8 dance1[7]={
					0b00001110,
					0b00010001,
					0b00001110,
					0b00001010,
					0b00001010,
					0b00010011,
					0b00001010
								};
	u8 dance2[7]={
					0b00001110,
					0b00010001,
					0b00001110,
					0b00010101,
					0b00001110,
					0b00010101,
					0b00011011
								};

	u8 gun[7]={
					0b00000000,
					0b00001111,
					0b00001111,
					0b00011000,
					0b00011000,
					0b00011000,
					0b00011000
								};
	u8 bullet[7]={
					0b00000000,
					0b00000000,
					0b00000100,
					0b00001110,
					0b00000100,
					0b00000000,
					0b00000000
								};

	u8 Hamoksha_Died[7]={
							0b00000000,
							0b00001000,
							0b00001010,
							0b00011101,
							0b00001010,
							0b00001000,
							0b00000000
										};


	while(1)
	{
		CLCD_voidSendString("I am Hamoksha");
				CLCD_voidWriteSpecialCharacter(&Hamoksha,0,0,15);
				_delay_ms(1000);

					/*clear The screen*/
				CLCD_voidSendCommand(0b00000001);

				CLCD_voidSendString("I PlayFootball");
				CLCD_voidWriteSpecialCharacter(&Hamoksha,0,0,15);
				CLCD_voidWriteSpecialCharacter(&BALL,1,0,14);
				_delay_ms(1000);

		for(Local_u8Counter=0;Local_u8Counter<10;Local_u8Counter++)
		{
			CLCD_voidWriteSpecialCharacter(&Hamoksha_up,0,0,15);
			CLCD_voidWriteSpecialCharacter(&BALL_up,1,0,14);
				_delay_ms(time);
			CLCD_voidWriteSpecialCharacter(&Hamoksha_down,0,0,15);
			CLCD_voidWriteSpecialCharacter(&BALL_dowm,1,0,14);
				_delay_ms(time);
		}

		CLCD_voidSendCommand(1);
		CLCD_voidSendString("I can run");
		CLCD_voidWriteSpecialCharacter(&Hamoksha,0,0,15);
		_delay_ms(1000);

		for(Local_u8Counter1=15;Local_u8Counter1>1;Local_u8Counter1--)
		{
			CLCD_voidWriteSpecialCharacter(&Hamoksha_down,0,1,Local_u8Counter1);
			_delay_ms(time);
			CLCD_voidSendCommand(1);
			CLCD_voidWriteSpecialCharacter(&Hamoksha_up,0,1,Local_u8Counter1);
			_delay_ms(time);
			CLCD_voidSendCommand(1);
		}

		CLCD_voidSendCommand(1);
		CLCD_voidSendString("I can dance");
		CLCD_voidWriteSpecialCharacter(&Hamoksha,0,0,15);
		_delay_ms(1000);

		for(Local_u8Counter2=0;Local_u8Counter2<10;Local_u8Counter2++)
		{
			CLCD_voidWriteSpecialCharacter(&dance1,0,0,15);
			_delay_ms(110);

			CLCD_voidWriteSpecialCharacter(&dance2,0,0,15);
			_delay_ms(110);
		}

		CLCD_voidSendCommand(1);
		CLCD_voidWriteSpecialCharacter(&gun,0,0,0);
		CLCD_voidWriteSpecialCharacter(&Hamoksha,1,0,15);
		_delay_ms(1000);

		CLCD_voidSendCommand(1);
		CLCD_voidSendString("Do not kill me");
		CLCD_voidWriteSpecialCharacter(&Hamoksha,1,0,15);
		_delay_ms(750);

		CLCD_voidSendCommand(1);
		CLCD_voidWriteSpecialCharacter(&gun,0,0,0);
		CLCD_voidWriteSpecialCharacter(&Hamoksha,1,0,15);

		for(Local_u8Counter3=2;Local_u8Counter3<15;Local_u8Counter3++)
		{
			CLCD_voidWriteSpecialCharacter(&bullet,2,0,Local_u8Counter3);
			_delay_ms(time);
			//CLCD_voidSendCommand(1);
		}

		CLCD_voidSendCommand(1);
		CLCD_voidWriteSpecialCharacter(&gun,0,0,0);
		CLCD_voidWriteSpecialCharacter(&Hamoksha_Died,1,0,15);
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("Hamoksha Died");
		_delay_ms(5000);
		CLCD_voidSendCommand(1);

	}
}
