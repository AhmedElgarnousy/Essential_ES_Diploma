/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: WATCHDOG              *************************/
/*************   Version: 1.00         *************************/
/***************************************************************/
/***************************************************************/

#ifndef WATCHDOG_INTERFACE_H_
#define WATCHDOG_INTERFACE_H_


// you have to enable GIE

//#define WDT_SLEEP_TIME  WDT_1_sec
/*
 * Options:
 * 		1- */
#define WDT_1_sec 0b1111000

void WatchDog_voidSleep(u8 Copy_u8SleepTime);
void WatchDog_voidEnable(void);
void WatchDog_voidDisable(void);

#endif /*WATCHDOG_INTERFACE_H_*/
