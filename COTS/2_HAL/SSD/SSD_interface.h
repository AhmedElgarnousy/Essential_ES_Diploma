/*************************************************************************/
/*************************************************************************/
/********************  Author : Ahmed Kamal    ****************************/
/********************  Layer  : HALL           ****************************/
/********************  SWC    : SSD               *************************/
/********************  version: 1.00          ****************************/
/*************************************************************************/
/*************************************************************************/

#ifndef SSD_interface_H_
#define SSD_interface_H_

#define SSD_COM_CATHODE 0
#define SSD_COM_ANODE 1

// number may differ depend on hw connections
#define SSD_u8_ZERO  0b01111111  
#define SSD_u8_ONE  0b00001100   
#define SSD_u8_TWO  0b10110110   
#define SSD_u8_THREE  0b10011110 
#define SSD_u8_FOUR  0b01100110  
#define SSD_u8_FIVE  0b11001100  
#define SSD_u8_SIX  0b11111010  
#define SSD_u8_SEVEN  0b00001110 
#define SSD_u8_EIGHT  0b11111110 
#define SSD_u8_NINE  0b11011110  

typedef struct
{
	u8 COM_Type;
	u8 Port;
	u8 EnablePort; // Port of COM pin
	u8 EnablePin; // COM pin
}SSD_t;


/*make Function for enable and disable the 7_seg to used for multiplexing */
u8 SSD_u8Enable_SDD(SSD_t * Copy_u16Ptr);
u8 SSD_u8Disable_SDD(SSD_t * Copy_u16Ptr);
u8 SSD_u8SetNumber(u8 Copy_u8Number, SSD_t*Copy_u16Ptr);

void SSD_void2Mux_display_num(SSD_t * Copy_u16Ptr1, SSD_t * Copy_u16Ptr2, u8 Copy_u8DisplayNum, u8 Copy_u8SEETimeInSeconds);

#endif
