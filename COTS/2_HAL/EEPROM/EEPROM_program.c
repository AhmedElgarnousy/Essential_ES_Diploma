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

#include "TWI_interface.h"
#include "TWI_config.h"
#include "TWI_private.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"


void EEPROM_SendDataByte(u8 Copy_u8DataByte, u16 Copy_u16Address)
{
	TWI_SendStartCondtionStart();
	TWI_SendSlaveAddressWithWrite( (0b1010<<4) | (A2 << 2) | (Copy_u16Address >> 8) );
	TWI_MasterWriteDataByte((u8)Copy_u16Address);
	TWI_MasterWriteDataByte(Copy_u8DataByte);
	TWI_SendStopCondition();
}
void EEPROM_ReadDataByte(u16 Copy_u16Address, u8 *Copy_pu8DataByte)
{
	TWI_SendStartCondtionStart();
	TWI_SendSlaveAddressWithWrite((0b1010<<4) | (A2 << 2) | (Copy_u16Address >> 8) );
	TWI_MasterWriteDataByte((u8)Copy_u16Address);
	TWI_SendRepeatedStart();
	TWI_SendSlaveAddressWithRead(0b1010<<4 | A2 << 2 | Copy_u16Address >> 8);
	TWI_MasterReadDataByte(Copy_pu8DataByte);
	TWI_SendStopCondition();
}
