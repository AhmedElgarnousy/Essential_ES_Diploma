#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"SW_interface.h"

#include <util/delay.h>

u8 SW_u8GetState(
    u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8SelfLocking,
    u8 Copy_u8PullType, 
    u8* Copy_pu8Value)
    {
        u8 Local_u8ErrorStatus = 0;

        if(Copy_pu8Value == NULL)
        {
            Local_u8ErrorStatus = 1;
        }

        DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,Copy_pu8Value);

        if(*Copy_pu8Value == 0)
        {
            if (Copy_u8PullType == SW_PULL_UP)
            {
                *Copy_pu8Value = SW_PRESSED;
            }
            else
            {
                *Copy_pu8Value = SW_NOT_PRESSED;
            }
        }
        else
        {
            if (Copy_u8PullType == SW_PULL_UP)
            {
                *Copy_pu8Value = SW_NOT_PRESSED;
            }
            else
            {
                *Copy_pu8Value = SW_PRESSED;
            }
        }

        if(Copy_u8SelfLocking == SW_SELFLOCKING)
        {
            // handle debouncing
            _delay_ms(250); // utils/delay.h
        }
        return Local_u8ErrorStatus;
    }
