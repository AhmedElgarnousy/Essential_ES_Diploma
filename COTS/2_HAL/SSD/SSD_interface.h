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

#define COM_CATHODE 0
#define COM_ANODE 1

#define SSD_u8_ZERO  0b01111111
#define SSD_u8_ONE  0b00000110
#define SSD_u8_TWO  0b01011011
#define SSD_u8_THREE  0b01001111
#define SSD_u8_FOUR  0b01100110
#define SSD_u8_FIVE  0b01101101
#define SSD_u8_SIX  0b01111101
#define SSD_u8_SEVEN  0b01000111
#define SSD_u8_EIGHT  0b01111111
#define SSD_u8_NINE  0b01101111

typedef struct
{
	u8 COM_Type;
	u8 Port;
	u8 EnablePort;
	u8 EnablePin; // COM pin
}SSD_t;


/*make Function for enable and disable the 7_seg to used for multiplexing */
// u8 SSD_u8Enable_SDD(SSD_t * Copy_u16Ptr);
// u8 SSD_u8Disable_SDD(SSD_t * Copy_u16Ptr);
u8 SSD_u8SetNumber(u8 Copy_u8Number,SSD_t*Copy_u16Ptr);


#endif
