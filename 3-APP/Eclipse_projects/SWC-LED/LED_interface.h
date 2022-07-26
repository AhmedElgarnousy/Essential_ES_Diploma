#ifndef LED_interface_H_
#define LED_interface_H_


#define LED_u8Source 1
#define LED_u8Sink 0

typedef struct
{
	u8 port;
	u8 pin;
	u8 connType;

}LED_t;


LED_u8Turn_Off(LED_t*Copy_u8Ptr);
LED_u8Turn_On(LED_t*Copy_u8Ptr);




#endif
