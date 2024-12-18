#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WatchDog_config.h"
#include "WatchDog_interface.h"
#include "WatchDog_private.h"
#include "WatchDog_register.h"




void WatchDog_voidSleep(u8 Copy_u8SleepTime){
	/* Clear Prescaler Bits */
	WDTCR &= 0b11111000;
	/* Set Required Prescaler*/
	WDTCR |= Copy_u8SleepTime;

}
void WatchDog_voidEnable(void) {
    SET_BIT(WDTCR, WDTCR_WDE);
}
void WatchDog_voidDisable(void) {
	WDTCR |= 0b00011000; // in the same operation(Clock cycle)
	WDTCR = 0;
}
