#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"


/*Requirements
 *
 *button for reset
 * */

void main(void)
{
	u8 Local_u8button;

	u8 Local_u8Arrow[8] = {0b00000100,
			0b00001110,
			0b00010101,
			0b00000100,
			0b00000100,
			0b00000100,
			0b00000100,
			0b00000100};

	u8 Local_u8DeleteArrow[8] = {0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000};

	u8 Local_u8DigitPos = 0;

	u8 Local_u8Operation[4] = {'+','-','*','/'};
	u8 index = 0;

	u8 Local_u8Numbers2[9] = {1,2,3,4,5,6,7,8,9};

	u8 Local_u8Numbers1[9] = {1,2,3,4,5,6,7,8,9};

	PORT_voidInit();
	CLCD_voidInit();


	/*Display the Initial Form 1+1*/
	/*Display first Digit*/
	CLCD_voidGoToXY(0,0);
	CLCD_voidWriteNumber(Local_u8Numbers1[0]);

	/*Display the arrow on the 1st digit*/
	CLCD_voidWriteSpecialCharacter(&Local_u8Arrow,0,1,0);

	/*Display the initial operation*/
	CLCD_voidGoToXY(0,1);
	CLCD_voidSendData(Local_u8Operation[0]);

	/*Display the second digit*/
	CLCD_voidGoToXY(0,2);
	CLCD_voidWriteNumber(Local_u8Numbers2[0]);


	while(1)
	{
		/*1st digit Pos*/
		//	CLCD_voidGoToXY(0,0);
		/*read the button and store the return*/
		do
		{
			Local_u8button = KPD_u8GetPressedKey();

		}while(Local_u8button == KPD_NO_PRESSED_KEY);

		/*check which digit we are*/
		if(Local_u8DigitPos == 0)
		{
			/*check which Button is pressed*/
			//up button
			if(Local_u8button == '+')
			{
				CLCD_voidGoToXY(0,Local_u8DigitPos);
				Local_u8Numbers1[index] ++;
				CLCD_voidWriteNumber(Local_u8Numbers1[index]);

				/* Limits the numbers to 9*/
				if(Local_u8Numbers1[index] == 9)
				{
					//index = 0;
					Local_u8Numbers1[index] -=9;
				}

			}

			//down button
			else if(Local_u8button == '-')
			{
				CLCD_voidGoToXY(0,Local_u8DigitPos);

				/*handle  the numbers if we clicked down*/
				if(Local_u8Numbers1[index] == 1)
				{
					Local_u8Numbers1[index] = 1;
				}
				else
				{
					Local_u8Numbers1[index] --;
					CLCD_voidWriteNumber(Local_u8Numbers1[index]);
				}

			}
			/*Enter button*/
			else if(Local_u8button == '.')
			{
				Local_u8DigitPos ++;

				if(Local_u8DigitPos == 3)
				{
					Local_u8DigitPos = 0;
				}

				/* delete the arrow */
				CLCD_voidWriteSpecialCharacter(&Local_u8DeleteArrow,1,1,0);

				CLCD_voidGoToXY(1,Local_u8DigitPos);
				CLCD_voidWriteSpecialCharacter(&Local_u8Arrow,0,1,Local_u8DigitPos);

			}
		}

		else if(Local_u8DigitPos == 1)
		{
			/* up button */
			if(Local_u8button == '+')
			{
				CLCD_voidGoToXY(0,1);
				index ++;
				CLCD_voidSendData(Local_u8Operation[index]);

				/* limits the operation */
				if(Local_u8Operation[index] == '/' )
				{
					index -= 4;
					// tip: Local_u8Operation[index] -=3;
				}
			}
			/* down button */
			else if(Local_u8button == '-')
			{
				CLCD_voidGoToXY(0,1);

				/*handle the operation if we clicked down*/
				if(Local_u8Operation[index] == '-' )
				{
					//index += 4;
					Local_u8Operation[index] = '+';

				}

				index --;
				CLCD_voidSendData(Local_u8Operation[index]);
			}
			/*Enter button*/
			else if(Local_u8button == '.')
			{
				Local_u8DigitPos ++;

				if(Local_u8DigitPos == 3)
				{
					Local_u8DigitPos = 0;
				}

				/* delete the arrow */
				CLCD_voidWriteSpecialCharacter(&Local_u8DeleteArrow,1,1,1);

				CLCD_voidGoToXY(1,Local_u8DigitPos);
				CLCD_voidWriteSpecialCharacter(&Local_u8Arrow,0,1,Local_u8DigitPos);
			}
		}

		else if(Local_u8DigitPos == 2)
		{
			//result button
			if(Local_u8button == '=')
			{
				CLCD_voidGoToXY(0,3);
				CLCD_voidSendData('=');
				CLCD_voidGoToXY(0,4);

				/*calculte the expersion and show it */

				switch(Local_u8Operation[index])
				{
				case '+': CLCD_voidWriteNumber(Local_u8Numbers1[index] + Local_u8Numbers2[index]); break;
				case '-':
					/*handle  the negative */
					if(Local_u8Numbers1[index] < Local_u8Numbers2[index])
					{
						CLCD_voidSendData('-');
						CLCD_voidWriteNumber(Local_u8Numbers2[index] - Local_u8Numbers1[index]); break;
					}
					else
					{
						CLCD_voidWriteNumber(Local_u8Numbers1[index] - Local_u8Numbers2[index]); break;
					}

				case '*': CLCD_voidWriteNumber(Local_u8Numbers1[index] * Local_u8Numbers2[index]); break;
				case '/':
					/*handle  the negative and floating numbers*/

					CLCD_voidWriteNumber(Local_u8Numbers1[index] / Local_u8Numbers2[index]); break;
				}
			}

			//up button
			else if(Local_u8button == '+')
			{
				CLCD_voidGoToXY(0,Local_u8DigitPos);
				Local_u8Numbers2[index] ++;
				CLCD_voidWriteNumber(Local_u8Numbers2[index]);

				/* Limits the numbers to 9*/
				if(Local_u8Numbers2[index] == 9)
				{
					//index = 0;
					Local_u8Numbers2[index] -=9;
				}
			}

			//down button
			else if(Local_u8button == '-')
			{
				CLCD_voidGoToXY(0,Local_u8DigitPos);
				Local_u8Numbers2[index] --;
				CLCD_voidWriteNumber(Local_u8Numbers2[index]);
			}

		}



		else if(Local_u8button == '5')
		{
			/*Reset button*/
			/*Display first Digit*/
			CLCD_voidGoToXY(0,Local_u8DigitPos);
			CLCD_voidWriteNumber(Local_u8Numbers1[0]);

			/*Display the arrow on the first digit*/
			CLCD_voidWriteSpecialCharacter(&Local_u8Arrow,0,1,0);

			/*Display the initial operation*/
			CLCD_voidGoToXY(0,1);
			CLCD_voidSendData('+');

			/*Display the second digit*/
			CLCD_voidGoToXY(0,2);
			CLCD_voidWriteNumber(Local_u8Numbers2[0]);

		}

	}
}
