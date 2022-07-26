
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"

#include "util/delay.h"

#include "Servo_interface.h"

void main()
{
	PORT_voidInit();
	TIMER1_voidInit();


	while(1)
	{
		/*Channel B does not work well*/
		//Servo_u8ServoRotate(OC1B,55.5);
		Servo_u8ServoRotate(OC1A,55.5);

	}

}
