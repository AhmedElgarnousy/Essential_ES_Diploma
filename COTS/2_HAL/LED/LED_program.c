#include"STD_TYPES.h"
#include"LED_interface.h"
#include"DIO_interface.h"


u8 LED_u8TurnOn(LED_t *Copy_u16Ptr) {
    u8 Local_u8ErrorState = 0;

    if(Copy_u16Ptr != NULL)
    {
        if(Copy_u16Ptr ->ConnType == LED_CONN_SRC)
        {
            DIO_u8SetPinValue(Copy_u16Ptr->Port,Copy_u16Ptr->Pin,DIO_u8PIN_HIGH);
        }
        else
        {
            DIO_u8SetPinValue(Copy_u16Ptr->Port,Copy_u16Ptr->Pin,DIO_u8PIN_LOW);
        }
    }
    else
    {
        Local_u8ErrorState = 1;
    }
    return Local_u8ErrorState;
}
u8 LED_u8TurnOff(LED_t *Copy_u16Ptr) {
    u8 Local_u8ErrorState = 0;

    if(Copy_u16Ptr != NULL)
    {
        if(Copy_u16Ptr ->ConnType == LED_CONN_SRC)
        {
            DIO_u8SetPinValue(Copy_u16Ptr->Port,Copy_u16Ptr->Pin,DIO_u8PIN_LOW);
        }
        else
        {
            DIO_u8SetPinValue(Copy_u16Ptr->Port,Copy_u16Ptr->Pin,DIO_u8PIN_HIGH);
        }
    }
    else
    {
        Local_u8ErrorState = 1;
    }
    return Local_u8ErrorState;
}