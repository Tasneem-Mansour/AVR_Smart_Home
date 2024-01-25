/*
 * KPD_interface.h
 *
 *  Created on: Dec 12, 2023
 *      Author: Tasneem
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_


#define KPD_ROW_PORT        	PORT_B
#define KPD_COLUMN_PORT         PORT_C

#define ROW_START       		DIO_PIN_NUM_B4
#define ROW_END         		DIO_PIN_NUM_B7
#define COLUMN_START   			DIO_PIN_NUM_C4
#define COLUMN_END     			DIO_PIN_NUM_C7

#define NoPressedKey    0xFF


void KPD_voidInit(void);
uint8 KPD_u8GetKey(void);

#endif /* KPD_INTERFACE_H_ */
