/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: SPI           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/
#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_register.h"
#include "SPI_config.h"
#include "SPI_private.h"


void SPI_voidInitMaster(void)
{
	/* master initialization*/
	SET_BIT(SPCR,SPCR_MSTR);

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);

	/*Clock prescaler: divide by 16*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);

}

void SPI_voidInitSlave(void)
{
	/*master initialization*/
	CLR_BIT(SPCR,SPCR_MSTR);

	/*SPI Enable*/
	SET_BIT(SPCR,SPCR_SPE);

}

u8 SPI_u8TranSceive(u8 Copy_u8Data)
{
	/*Send the data*/
	SPDR = Copy_u8Data;

	/*Wait (Busy Waiting ) until transfer is complete*/
	while(GET_BIT(SPSR,SPSR_SPIF) == 0);

	/*Get the exchanged data*/
	return SPDR;
}
