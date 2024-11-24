#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

/*  0 means Temporary Switch
    1 means Maintained Switch*/
#define SW_SELFLOCKING 0
#define SW_LOCKING 1

#define SW_PRESSED 1
#define SW_NOT_PRESSED 0

#define SW_PULL_UP 1
#define SW_PULL_DOWN 0

u8 SW_u8GetState(
    u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8SelfLocking, u8 Copy_u8PullType,
    u8 *Copy_pu8Value);

// return : pressed or not

#endif /* SW_INTERFACE_H_ */
