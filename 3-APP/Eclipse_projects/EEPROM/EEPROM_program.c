/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: HALL           *************************/
/*************   SWC: EEPROM           *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "TWI_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"


void EEPROM_voidSendDataByte(u16 Copy_u16Address, u8 Copy_u8DataByte)
{
	/*Send Start Condition*/
	TWI_SendStartCondtionStart();

	/*Send SLave Address with write*/
	TWI_SendSlaveAddressWithWrite(0b01010000 |1<<2 | Copy_u16Address>>8);

	/*Master write Data Byte*/
	TWI_MasterWriteDataByte((u8) Copy_u16Address);

	/*Master Write Data Byte*/
	TWI_MasterWriteDataByte(Copy_u8DataByte);

	/*Send Stop Condition*/
	TWI_SendStopCondition();

}

void EEPROM_voidReadDataByte(u16 Copy_u16Address, u8* Copy_pu8DataByte)
{
	/*Send Start Condition*/
	TWI_SendStartCondtionStart();

	/*Send SLave Address with write*/
	TWI_SendSlaveAddressWithWrite(0b01010000 |1<<2 | Copy_u16Address>>8);

	/*Master write Data Byte*/
	TWI_MasterWriteDataByte((u8) Copy_u16Address);

	/*Send Repeated Start*/
	TWI_SendRepeatedStart();

	/*Send SLave Address with Read*/
	TWI_SendSlaveAddressWithRead(0b01010000 | 1<<2 | Copy_u16Address>>8);

	/*Master Read Data Byte*/
	TWI_MasterReadDataByte(Copy_pu8DataByte);

	/*Send Stop Condition*/
	TWI_SendStopCondition();
}
