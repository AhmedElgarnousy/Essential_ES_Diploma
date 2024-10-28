/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: TWI              *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_


/*Status Register*/

#define START_ACK						0x08		/*Start has been sent*/
#define REP_START_ACK					0x10		/*Repeated Start*/
#define SLAVE_ADD_AND_WR_ACK			0x18		/*Master transmit (slave address + write request) ACK*/
#define SLAVE_ADD_AND_RD_ACK			0x40		/*Master transmit (slave address + read request) ACK*/
#define MSTR_WR_BYTE_ACK				0x28		/*Master transmit data ACK*/
#define MSTR_RD_BYTE_WITH_ACK			0x50		/*Master Recevied Data with ACK*/
#define MSTR_RD_BYTE_WITH_NACK			0x58		/*Master Recevied Data with not ACK*/
#define SLAVE_ADD_RCVD_RD_REQ			0xA8		/*Means that slave adddress is received with read request*/
#define SLAVE_ADD_RCVD_WR_REQ			0x60		/*Means that slave adddress is received with write request*/
#define SLAVE_DATA_RECEIVED			    0x80		/*Means that a byte is received*/
#define SLAVE_BYTE_TRANSMITTED			0xB8		/*Means that the written byte is transmitted*/



#endif 
