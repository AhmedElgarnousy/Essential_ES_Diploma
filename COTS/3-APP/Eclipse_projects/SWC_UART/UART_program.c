/***************************************************************/
/***************************************************************/
/*************   Author: Ahmed Kamal   *************************/
/*************   Layer: MCAL           *************************/
/*************   SWC: UART           ****************************/
/*************   Version: 1.00           ***********************/
/***************************************************************/

#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_register.h"
#include "UART_config.h"
#include "UART_private.h"

static u8 USART_u8BusyState = IDLE;

void (*USART_pvSendCharNotificationFunc)(void) = NULL;
static u8 USART_u8Data;

void (*USART_pvReceiveCharNotificationFunc)(void) = NULL;

u8 *USART_u8RecevedData = NULL;


char* USART_cString ;
void (* USART_pvSendStringNotificationFunc)(void) = NULL;

static u8 USART_u8ISRSource;

void USART_Init()
{
	u8 Local_u8UCSRAValue=0;	//We use this Method because u should put the total value at one time
	u16 Local_u16Baud=0 ;
	/*Accessing the UCSRC Register*/
	SET_BIT(Local_u8UCSRAValue,7);

#if PARITY_MODE == EVEN_PARITY

	SET_BIT(Local_u8UCSRAValue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRAValue,UCSRC_UPM0);

#elif PARITY_MODE == ODD_PARITY

	SET_BIT(Local_u8UCSRAValue,UCSRC_UPM1);
	SET_BIT(Local_u8UCSRAValue,UCSRC_UPM0);

#elif PARITY_MODE == DISABLED
	CLR_BIT(Local_u8UCSRAValue,UCSRC_UPM1);
	CLR_BIT(Local_u8UCSRAValue,UCSRC_UPM0);

#else
#error "Wrong parity Configurations"
#endif


#if STOP_BIT_SELECT ==	ONE_BIT
	/*1 Stop bit*/
	CLR_BIT(Local_u8UCSRAValue,UCSRC_USBS);

#elif	STOP_BIT_SELECT == TWO_BIT

	SET_BIT(Local_u8UCSRAValue,UCSRC_USBS);

#else
#error "Wrong stop bit Configurations"
#endif


#if USART_MODE_SELECT == ASYNCHRONOUS

	CLR_BIT(Local_u8UCSRAValue,UCSRC_UMSEL);

#elif	USART_MODE_SELECT == SYNCHRONOUS

	SET_BIT(Local_u8UCSRAValue,UCSRC_UMSEL);

#else
#error "Wrong USART mode select Configurations"
#endif

#if DATA_BITS == FIVE_BITS

	CLR_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif DATA_BITS == SIX_BITS
	SET_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif DATA_BITS == SEVEN_BITS
	CLR_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif DATA_BITS == EIGHT_BITS
	/*8 data bits*/
	SET_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

#elif DATA_BITS == NINE_BITS
	SET_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRAValue,UCSRC_UCSZ0);
	SET_BIT(UCSRB,UCSRB_UCSZ2);

#else
#error "Wrong Data Bits Configurations"
#endif

	/*Fill UCSRC Value*/
	UCSRC=Local_u8UCSRAValue;

	/*Set Baud Rate*/
	Local_u16Baud = ((u32)(OSC_FREQ) / (u32)(16*(BAUD_RATE)) -1);
	UBRRH = (u8)(Local_u16Baud >> 8); /*Already has 0 in URSEL that Access UBRRH*/
	UBRRL = (u8)Local_u16Baud;

	// support the double speed with the other equation
	/*Baud Rate 9600 bit/sec
	UBRRL=51;*/

	// make a cofiguration to support simplex communication
	/*Enable Transmitter and Receiver*/
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);

}

// time out
void USART_u8SendCharSynch(u8 Copy_u8Data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE) == 0);
	UDR = Copy_u8Data;

}

// time out
//Check  on null pointer
/* char String[] = {};*/
void USART_u8SendStringSynch(const char* Copy_cString)
{
	u8 Local_u8Counter;

	for(Local_u8Counter=0; Local_u8Counter!='\0' ; Local_u8Counter ++ )
	{
		// if this func returns you to receive the return and check if this not ok exit
		USART_u8SendCharSynch(Copy_cString[Local_u8Counter]);

	}

}


u8 USART_u8SendCharAsynch(u8 Copy_u8Data , void (*Copy_pvSendCharNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;

	if(USART_u8BusyState == IDLE)
	{
		/*Check that pointer not equal null*/
			if(Copy_pvSendCharNotificationFunc == NULL)
			{
				Local_u8ErrorState = NULL_POINTER;
			}
			else
			{
				/*Make Function Busy */
				USART_u8BusyState = BUSY;

				/*Init ISR Source*/
				USART_u8ISRSource = CHAR_ASYCH;

				/*make it globally*/

				/*Initialize the call back notification function globally */
				USART_pvSendCharNotificationFunc = Copy_pvSendCharNotificationFunc;

				/*Initialize the data globally */
				USART_u8Data = Copy_u8Data;

				/*Enable Data Register Empty Interrupt */
				SET_BIT(UCSRB,UCSRB_UDRIE);
			}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}

return Local_u8ErrorState;
}


u8 USART_u8SendStringAsynch(const char* Copy_cString , void (* Copy_pvSendStringNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;

	if(USART_u8BusyState == IDLE)
	{
		/*Check on pointers*/
		if(Copy_cString == NULL && Copy_pvSendStringNotificationFunc == NULL)
			{
				Local_u8ErrorState = NULL_POINTER;
			}
			else
			{
				/*Make Function Busy */
				USART_u8BusyState = BUSY;

				/*Init ISR Source*/
				USART_u8ISRSource = STRING_ASYCH;

				/*Init String Globally*/
				USART_cString = Copy_cString;

				/*Init CallBack Notification Function */
				USART_pvSendStringNotificationFunc = Copy_pvSendStringNotificationFunc;

				/*Enable Interrupt*/
				SET_BIT(UCSRB,UCSRB_UDRIE);
			}

	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState;
}



u8 USART_u8ReceiveCharSynch(u8 *Copy_u8Reading)
{
	u8 Local_u8ErrorState = OK;
	u32 Local_u32Counter=0;

	/* Polling with Time out Mechanism*/
	while( GET_BIT(UCSRA,UCSRA_RXC) == 0 && Local_u32Counter != UART_u32TIMEOUT)
	{
		Local_u32Counter++;
	}

	if(Local_u32Counter == UART_u32TIMEOUT)
	{
		/*Loop is broken due to time out reached*/

		Local_u8ErrorState = NOK;
	}
	else
	{
		/*Loop is broken due to flag*/
		*Copy_u8Reading = UDR;
	}

	return Local_u8ErrorState;
}

u8 USART_u8ReceiveCharAsynch(u8 *Copy_u8RecevedData , void (*Copy_pvReceiveCharNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;

	if(USART_u8BusyState == IDLE)
	{
		 /*Check pointer not equal NULL*/
			if( Copy_pvReceiveCharNotificationFunc == NULL || Copy_u8RecevedData == NULL )
			{
				Local_u8ErrorState = NULL_POINTER;
			}
			else
			{
				// 	ISRSource
				/*Make Function Busy */
				USART_u8BusyState = BUSY;

				/*Init The callback notification function Globally*/
				USART_pvReceiveCharNotificationFunc = Copy_pvReceiveCharNotificationFunc;

				/*Init The send data Globally*/
				USART_u8RecevedData = Copy_u8RecevedData;

				/*Enable RX Complete Interrupt*/
				SET_BIT(UCSRB,UCSRB_RXCIE);

			}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}

return Local_u8ErrorState;
}

/*ISR of USART, RX Complete*/
void __vector_13(void)__attribute__((signal));
void __vector_13(void)
{
	/*Receiving the data*/
	*USART_u8RecevedData = UDR;

	/*Disable Interrupt*/
	CLR_BIT(UCSRB,UCSRB_RXCIE);

	/*Call the notification Function*/
	USART_pvReceiveCharNotificationFunc();


}

/*ISR of USART Data Register Empty UDRE */
void __vector_14(void)__attribute__((signal));
void __vector_14(void)
{
	u8 Local_u8Counter;
	/*check ISR Source*/
	if(USART_u8ISRSource == CHAR_ASYCH)
	{
		/*Sending the data*/
		UDR = USART_u8Data;


		/*Make Function Idle
		 * Donot make it idle while sending
		 * may be come another interrupt and call this function(UART-Send)
		 * or
		 * may be notification functions call this Function*/
		USART_u8BusyState = IDLE;

		/*Invoke the callback notification Function*/
		USART_pvSendCharNotificationFunc();

		/*Disable interrupt*/
		CLR_BIT(UCSRB,UCSRB_UDRIE);
	}

	else if(USART_u8ISRSource == STRING_ASYCH)
	{

		for(Local_u8Counter=0; Local_u8Counter !='\0'; Local_u8Counter++ )
		{
			UDR = USART_cString[Local_u8Counter];
		}

		/*Make Function Idle*/
		USART_u8BusyState = IDLE;

		/*Disable Interrupt*/
		CLR_BIT(UCSRB,UCSRB_UDRIE);

		/*call the notification Function*/
		//Make the notification function the lastest thing in ISR
		USART_pvSendStringNotificationFunc();

	}


}

/*ISR of USART, TX Complete*/
//Not used for us
void __vector_15(void)__attribute__((signal));
void __vector_15(void)
{

}



