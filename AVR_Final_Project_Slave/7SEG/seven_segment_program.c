/*
 * seven_segment_program.h
 *
 *  Created on: Dec 11, 2023
 *      Author: Tasneem
 */

#include "../STD_Types.h"
#include "../BIT_Math.h"
#include "../DIO/DIO_interface.h"
#include "seven_segment_interface.h"
#include "seven_segment_config.h"
/*  common cathode*/		    /* 0    1    2   3     4    5    6   7    8    9  */
uint8 Seven_SegmentPattern_1[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
/*0x3F = ob01111111  -> represents number 0 on seven-segment*/

uint8 Seven_SegmentPattern_2[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void SevSeg_voidDisplay(uint8 u8NumberCpy)
{	if(u8NumberCpy<10){
		#if COMMON_TYPE == COMMON_CATHODE
			DIO_voidWritePort(SEVEN_PORT_NAME_1,Seven_SegmentPattern_1[u8NumberCpy]);
		#elif COMMON_TYPE == COMMON_ANODE
			DIO_voidWritePort(SEVEN_PORT_NAME_1,~Seven_SegmentPattern_1[u8NumberCpy]);

		#endif
	}

	else if	(u8NumberCpy>=10 && u8NumberCpy<99){
		#if COMMON_TYPE == COMMON_CATHODE
			DIO_voidWritePort(SEVEN_PORT_NAME_1,Seven_SegmentPattern_1[u8NumberCpy%10]);
			DIO_voidWritePort(SEVEN_PORT_NAME_2,Seven_SegmentPattern_2[u8NumberCpy/10]);
		#elif COMMON_TYPE == COMMON_ANODE
			DIO_voidWritePort(SEVEN_PORT_NAME_1,Seven_SegmentPattern_1[u8NumberCpy%10]);
			DIO_voidWritePort(SEVEN_PORT_NAME_2,~Seven_SegmentPattern_2[u8NumberCpy/10]);

		#endif

	}



}
