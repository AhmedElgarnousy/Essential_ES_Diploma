/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: TWI              *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


typedef enum
{
	NoError,
	StartCondtionError,
	RepeatedStartError,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,

}TWI_ErrorStatus;

/*Pass 0 in the SlaveAddress argument if master will not be addressed or
 * slaveAddress if master can be receiver*/
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus TWI_SendStartCondtionStart(void);

TWI_ErrorStatus TWI_SendRepeatedStart(void);

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrorStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte);

void TWI_SendStopCondition(void);

#endif
