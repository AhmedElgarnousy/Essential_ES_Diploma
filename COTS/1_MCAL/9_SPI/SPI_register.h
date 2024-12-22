/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: SPI              *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#define SPDR *((volatile u8 *)0x2F) /* SPI Data Register */

#define SPSR *((volatile u8 *)0x2E) /* SPI Status Register*/
#define SPSR_SPIF 7                 /* SPI interrupt falg */
#define SPSR_WCOL 6
#define SPSR_SPI2X 0 /* Prescaller Bit 2*/

#define SPCR *((volatile u8 *)0x2D) /* SPI Control Register*/
#define SPCR_SSPIE 7
#define SPCR_SPE 6 /* SPI enable*/
#define SPCR_DORD 5
#define SPCR_MSTR 4
#define SPCR_MCPOL 3
#define SPCR_CPHA 2
#define SPCR_SPR1 1 /*Prescaller Bit 1 */
#define SPCR_SPR0 0 /* Prescaller Bit 0*/

#endif