/*
 * DIO_Interface.h
 *
 *  Created on: Apr 4, 2022
 *      Author: mhmdr
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "Std_Types.h"
#include "DIO_Registers.h"
#include "DIO_Config.h"
#include "Common_Macros.h"

void DIO_SetPortDir(uint8 Port , uint8 Dir);
void DIO_SetPinDir(uint8 Port , uint8 Pin , uint8 Dir);

void DIO_SetPortVal(uint8 Port , uint8 Val);
void DIO_SetPinVal(uint8 Port , uint8 Pin , uint8 Val);

void DIO_ReadPort(uint8 Port , uint8* Val);
void DIO_ReadPin(uint8 Port , uint8 Pin , uint8* Val);
void DIO_PullUp_PIN(uint8 Port , uint8 Pin);
void DIO_TogglePin(uint8 Port , uint8 Pin);



#endif /* DIO_INTERFACE_H_ */
