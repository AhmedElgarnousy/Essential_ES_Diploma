/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: TWI              *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_register.h"
#include "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"


/*Pass 0 in the SlaveAddress argument if master will not be addressed*/
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	/*Set Clock Frequency to 400bps*/
	/*Set TWDR to 2*/
	TWDR= 2;

	/*Clear the 2 bits of TWPS*/
	CLR_BIT(TWSR,TWSR_TWPS1);
	CLR_BIT(TWSR,TWSR_TWPS0);

	/*Initialize the node address*/
	if(Copy_u8SlaveAddress != 0)
	{
		/*6 bit MSBs For address*/
		TWAR = Copy_u8SlaveAddress << 1;
	}

	/*Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*Initialize the node address*/
	TWAR = Copy_u8SlaveAddress << 1;

	/*Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);

}


TWI_ErrorStatus TWI_SendStartCondtionStart(void)
{
	TWI_ErrorStatus Local_ErrorStatus = NoError;

	/*Send start condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*CLear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	if( (TWSR & 1111000) != START_ACK)
	{
		Local_ErrorStatus = StartCondtionError;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrorStatus Local_ErrorStatus = NoError;

	/*Send start condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTA);

	/*CLear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	if( (TWSR & 1111000) != REP_START_ACK)
	{
		Local_ErrorStatus = RepeatedStartError;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_ErrorStatus;
}

TWI_ErrorStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus Local_ErrorState = NoError;

	/*Clear the start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Set the slave address in the 7 MSB in the data register*/
	TWDR = Copy_u8SlaveAddress << 1;
	CLR_BIT(TWDR,0); 		// for write request

	/*CLear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	if( (TWSR & 1111000) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorState = SlaveAddressWithWriteErr;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_ErrorState;
}



TWI_ErrorStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorStatus Local_ErrorState = NoError;

	/*Clear the start condition bit*/
	CLR_BIT(TWCR,TWCR_TWSTA);

	/*Set the slave address in the 7 MSB in the data register*/
	TWDR = Copy_u8SlaveAddress << 1;
	CLR_BIT(TWDR,1); 		// for write request


	/*CLear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/*Check on the operation status in the status register*/
	if( (TWSR & 1111000) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrorState = SlaveAddressWithReadErr;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_ErrorState;
}


TWI_ErrorStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrorStatus Local_ErrorState = NoError;

	/*write the data byte*/
	TWDR = Copy_u8DataByte;

	/*CLear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/*Check on the operation status in the status register*/
	if( (TWSR & 1111000) != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterWriteByteErr;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_ErrorState;
}

TWI_ErrorStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
	TWI_ErrorStatus Local_ErrorState = NoError;

	/*Enable master generating ack bit*/
	SET_BIT(TWCR,TWCR_TWEA);

	/*CLear the interrupt flag to start the slave sending data*/
	SET_BIT(TWCR,TWCR_TWINT);

	/*Wait until the interrupt flag is raised again and the previous operation is complete*/
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	/*Check on the operation status in the status register*/
	if( (TWSR & 1111000) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrorState = MasterReadByteErr;
	}
	else
	{
		/*Read the receiving data*/
		*Copy_pu8DataByte = TWDR;
	}

	return Local_ErrorState;
}


void TWI_SendStopCondition(void)
{
	/*Generate stop condition on the bus*/
	SET_BIT(TWCR,TWCR_TWSTO);

	/*CLear the interrupt flag to start the slave sending data*/
	CLR_BIT(TWCR,TWCR_TWINT);

}
