/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: HAL            *************************/
/*************   SWC: DC Motor         *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/
/***************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "DIO_interface.h"

#include "DCMotor_config.h"
#include "DCMotor_interface.h"
#include "DCMotor_private.h"

void DCMotor_u8RotateCW()
{
	DIO_u8SetPinValue(MOTOR_PORT,M1PIN1,DIO_u8PIN_HIGH);
	
	DIO_u8SetPinValue(MOTOR_PORT,M1PIN2,DIO_u8PIN_LOW);
	
	
}
void DCMotor_u8RotateCCW()
{
	
	DIO_u8SetPinValue(MOTOR_PORT,M1PIN2,DIO_u8PIN_HIGH);
	
	DIO_u8SetPinValue(MOTOR_PORT,M1PIN1,DIO_u8PIN_LOW);
	
	
}
