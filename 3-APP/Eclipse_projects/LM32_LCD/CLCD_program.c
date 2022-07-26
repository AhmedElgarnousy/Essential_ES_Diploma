/*************************************************************************/
/*************************************************************************/
/********************  Author : Ahmed Kamal    ****************************/
/********************  Layer  : HAL             ****************************/
/********************  SWC    :  CLCD              *************************/
/********************  version: 1.00            ****************************/
/********************  Data: 17/4/2022          ****************************/
/*************************************************************************/
/*************************************************************************/

#include<util/delay.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"CLCD_config.h"
#include"CLCD_interface.h"
#include"CLCD_private.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{

#if CLCD_Mode==Eight_Bit_Mode
		/*set RS pin to LOW for command*/
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

		/*set RW pin to HIGH for write*/
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

		/*set command  to Data pins*/
		DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

		/*set E pin to HIGH for Enable*/
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
#endif


#if CLCD_Mode==Four_Bit_Mode
		/*set RS pin to LOW for command*/
				DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

				/*set RW pin to HIGH for write*/
				DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

				//send last bits of command



#endif
}

void CLCD_voidSendData(u8 Copy_u8Data)
{

#if CLCD_Mode==Eight_Bit_Mode

	/*set RS pin to LOW for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*set RW pin to HIGH for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*set COMMAND  to Data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*set E pin to HIGH for Enable*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);



#elif CLCD_Mode==Four_Bit_Mode

#endif

}
void CLCD_voidInit(void)
{

#if CLCD_Mode==Four_Bit_Mode
		_delay_ms(40);

		/*Function Set */

	    CLCD_voidSendCommand(0b00100000);
	    CLCD_voidSendCommand(0b00100000);
	    CLCD_voidSendCommand(0b10000000);

		/*Display ON/OFF Control*/

		CLCD_voidSendCommand(0b00000000);
		CLCD_voidSendCommand(0b11000000);

		/*Display Clear*/
		CLCD_voidSendCommand(0b00000000);
		CLCD_voidSendCommand(0b00010000);
#endif

#if  CLCD_Mode==Eight_Bit_Mode

	/*wait for more than 30ms*/
	_delay_ms(40);

	/*function set command: 2 lines"1", 5*8 Font Size"0"*/
	CLCD_voidSendCommand(0b00111000);

	/*Display ON/OFF control: display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

 	/*Display clear*/
	CLCD_voidSendCommand(0b00000001);

	/*entry mode set
	*/
#endif
}

void CLCD_voidSendString(const char*Copy_pcString )
{
	//any variable carry ASCII value should be char not unsigned or signed
	u8 Local_u8Counter=0;
	while(Copy_pcString[Local_u8Counter]!='\0')
	{
	CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
	Local_u8Counter++;
	}

}

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8ErrorState=0;
	u8 Local_u8Address;
	if(Copy_u8XPos==0)
	{
		/*Location is at first line in CLCD 16*2*/
		Local_u8Address=Copy_u8YPos;
	}
	else if(Copy_u8XPos==1)
	{
		/*Location is at Second line in CLCD 16*2*/
		Local_u8Address=Copy_u8YPos+0x40;
	}
	/*set bit number 7 for set DDRAM Address command then send the command*/
	CLCD_voidSendCommand(Local_u8Address+128);
}

void CLCD_voidWriteSpecialCharacter(u8*Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress=0,Local_u8Iterator;
	/*calculate the CGRAM Address whose each block is 8 bytes */
	Local_u8CGRAMAddress=Copy_u8PatternNumber*8;
	/*send SGRAM Address command to LCD, with setting bit 6,clearing bit 7*/
	CLCD_voidSendCommand(Local_u8CGRAMAddress+64);

	/*write pattern into CGRAM*/
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}
	/*Go back to the DDRAM to display the pattern*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	/*Display the pattern written in the CG RAM
	 * DDRAM treat with the CGRAM with location(block) number from 0 to 7*/
	CLCD_voidSendCommand(Copy_u8PatternNumber);

	/**********/
	/*set E pin to HIGH for Enable*/
}


void CLCD_voidWriteNumber(u32 Copy_u32Number)
{

}


