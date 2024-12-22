/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: SPI           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/


#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"SPI_interface.h"
#include"SPI_Config.h"
#include"SPI_private.h"
#include"SPI_register.h"


void SPI_voidInitMaster()
{
	/*Master Initialization*/
	SET_BIT(SPCR, SPCR_MSTR);

	/* Clock Prescaler divide by 16 */
	SET_BIT(SPCR, SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);
	CLR_BIT(SPSR, SPSR_SPI2X);


	/* SPI Enable */
	SET_BIT(SPCR, SPCR_SPE);
}

void SPI_voidInitSlave()
{
	/* Slave Initialization */
	CLR_BIT(SPCR, SPCR_MSTR);

	/* SPI Enable */
	SET_BIT(SPCR, SPCR_SPE);

}

u8 SPI_u8Transceive(u8 Copy_u8Data){
	/*send the data*/
	SPDR = Copy_u8Data;

	// wait until transfer is complete
	while(GET_BIT(SPSR, SPSR_SPIF) == 0);
	// get the exchanged data
	return SPDR;

}
