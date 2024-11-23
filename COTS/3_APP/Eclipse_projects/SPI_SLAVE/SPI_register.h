/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: SPI              *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/


#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_


#define SPDR					*((volatile u8*)0x2f)				/*SPI data Register*/

#define SPSR					*((volatile u8*)0x2E)				/*SPI Status Register*/
#define SPSR_SPIF				7									/*SPI Interrupt Flag*/
#define SPSR_SPI2X				0									/*Prescalar bit 2*/


#define SPCR					*((volatile u8*)0x2D)				/*SPI Control Register*/
#define SPCR_SPE				6									/*SPI Enable*/
#define SPCR_MSTR				4									/*Master bit*/
#define SPCR_SPR1				1									/*Prescaler Bit 1*/
#define SPCR_SPR0				0									/*Prescaler Bit 0*/


#endif
