#ifndef  FREERTOS_CONFIG_H
#define  FREERTOS_CONFIG_H



//these are the minimum configuration to run the FreeRTOS
#define configCPU_CLOCK_HZ              	16000000UL
#define configUSE_TICKLESS_IDLE         	0
#define configTICK_RATE_HZ              	( ( TickType_t ) 1000 )
#define configUSE_PREEMPTION            	1
#define configUSE_IDLE_HOOK             	0
#define configUSE_TICK_HOOK             	0
#define configMAX_PRIORITIES            	( 5 )			 // system priorities are from 0-4 and 4 is the highest
#define configMINIMAL_STACK_SIZE        	( ( unsigned short ) 100 )
#define configTOTAL_HEAP_SIZE           	( ( size_t ) ( 4096 ) )
#define configMAX_TASK_NAME_LEN         	( 10 )
#define configUSE_16_BIT_TICKS          	0			// for 16-bit or 8-bit machines put this 1 
/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY         	( 7 << 5 )    	/* Priority 7, or 0xE0 as only the top three bits are implemented. 
						This is the lowest priority. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY     	( 5 << 5 )  	/* Priority 5, or 0xA0 as only the top three bits are implemented. */


//task APIs
#define INCLUDE_vTaskDelay           1 
#define INCLUDE_vTaskDelayUntil      1 
#define configUSE_TRACE_FACILITY     1

#endif  //FREERTOS_CONFIG_H