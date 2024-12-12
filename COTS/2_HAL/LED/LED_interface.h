#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


#define LED_CONN_SRC  1
#define LED_CONN_SINK  0

typedef struct{
  u8 Port;
  u8 Pin;
  u8 ConnType; // src, sink
} LED_t;

u8 LED_u8TurnOn(LED_t *Copy_u16Ptr);

u8 LED_u8TurnOff(LED_t *Copy_u16Ptr);

u8 LED_u8Toggle(LED_t *Copy_u16Ptr);


#endif /* LED_INTERFACE_H_ */

