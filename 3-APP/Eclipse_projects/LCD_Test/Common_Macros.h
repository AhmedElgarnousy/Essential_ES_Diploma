/*
 * Common_Macros.h
 *
 *  Created on: Apr 4, 2022
 *      Author: mhmdr
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)

#endif /* COMMON_MACROS_H_ */
