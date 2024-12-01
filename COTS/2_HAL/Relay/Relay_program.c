#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "Relay_config.h"
#include "Relay_interface.h"
#include "Relay_private.h"




void RELAY_voidActivate(u8 Copy_u8PORT, u8 Copy_u8Pin)
{
    DIO_u8SetPinValue(Copy_u8PORT, Copy_u8Pin, DIO_u8PIN_HIGH);
}
void RELAY_voidDeactivate(u8 Copy_u8PORT, u8 Copy_u8Pin)
{
    DIO_u8SetPinValue(Copy_u8PORT, Copy_u8Pin, DIO_u8PIN_LOW);
}