/***************************************************/
/***************************************************/
/*********	Author :Ahmed Kamal				********/
/*********	Layer :LIB						********/
/*********	SWC : Standard Types			********/
/*********	Version :1.00					********/
/***************************************************/
/***************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef signed short s16;

typedef unsigned long int u32;
typedef signed long int s32;

typedef float f32;
typedef double f64;

#define NULL  0

#define OK    0
#define NOK	  1

#define NULL_POINTER	1 // Error State

#define BUSY_FUNC	1 // Error State

#define IDLE	0
#define BUSY	1

#define ERR_TIME_OUT	1 // Error State

#endif /* STD_TYPES_H_ */
