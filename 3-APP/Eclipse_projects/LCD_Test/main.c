

#include"DIO_Interface.h"
#include"LCD_Interface.h"

void main()
{
    DIO_SetPortDir(DIO_PORTA,DIO_PORT_OUTPUT);
    DIO_SetPortDir(DIO_PORTB,DIO_PORT_OUTPUT);

	void LCD_Init(void);
	LCD_WriteChar('1');
	while(1)
	{




	}


}


