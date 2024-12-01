#ifndef RELAY_INTERFACE_H_
#define RELAY_INTERFACE_H_

// coil pins
// pin1 connected on npn transistor low side driving
// pin2 connected with 5v
void RELAY_voidActivate(u8 Copy_u8PORT, u8 Copy_u8Pin);
void RELAY_voidDeactivate(u8 Copy_u8PORT, u8 Copy_u8Pin);


#endif /* RELAY_INTERFACE_H_ */