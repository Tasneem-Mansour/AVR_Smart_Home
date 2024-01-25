/*
 * DIO_interface.h
 *
 *  Created on: Dec 10, 2023
 *      Author: Tasneem
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define ENABLE_PULLUP 	1
#define DISABLE_PULLUP 	0

#define DIO_INPUT		0
#define DIO_OUTPUT		1

#define DIO_HIGH		1
#define DIO_LOW  		0

#define PORT_A   		1
#define PORT_B  		2
#define PORT_C 			3
#define PORT_D 	    	4

/* the next pins can be defined only one time for all ports ex. DIO_PIN_NUM0   0   */
/* PORT A pins */
#define DIO_PIN_NUM_A0      0
#define DIO_PIN_NUM_A1      1
#define DIO_PIN_NUM_A2      2
#define DIO_PIN_NUM_A3      3
#define DIO_PIN_NUM_A4      4
#define DIO_PIN_NUM_A5      5
#define DIO_PIN_NUM_A6      6
#define DIO_PIN_NUM_A7      7

/* PORT B pins */
#define DIO_PIN_NUM_B0      0
#define DIO_PIN_NUM_B1      1
#define DIO_PIN_NUM_B2      2
#define DIO_PIN_NUM_B3      3
#define DIO_PIN_NUM_B4      4
#define DIO_PIN_NUM_B5      5
#define DIO_PIN_NUM_B6      6
#define DIO_PIN_NUM_B7      7

/* PORT C pins */
#define DIO_PIN_NUM_C0      0
#define DIO_PIN_NUM_C1      1
#define DIO_PIN_NUM_C2      2
#define DIO_PIN_NUM_C3      3
#define DIO_PIN_NUM_C4      4
#define DIO_PIN_NUM_C5      5
#define DIO_PIN_NUM_C6      6
#define DIO_PIN_NUM_C7      7

/* PORT D pins */
#define DIO_PIN_NUM_D0      0
#define DIO_PIN_NUM_D1      1
#define DIO_PIN_NUM_D2      2
#define DIO_PIN_NUM_D3      3
#define DIO_PIN_NUM_D4      4
#define DIO_PIN_NUM_D5      5
#define DIO_PIN_NUM_D6      6
#define DIO_PIN_NUM_D7      7

void DIO_voidInit(void);

void DIO_voidWritePin(uint8 u8PortCpy , uint8 u8PinCpy,uint8 u8ValueCpy);

uint8 DIO_u8ReadPin(uint8 u8PortCpy , uint8 u8PinCpy);

void DIO_voidTogglePin(uint8 u8PortCpy , uint8 u8PinCpy);

void DIO_voidWritePort(uint8 u8PortCpy ,uint8 u8ValueCpy );

void DIO_voidPullUpState(uint8 u8PortCpy , uint8 u8PinCpy,uint8 u8ValueCpy);
#endif /* DIO_INTERFACE_H_ */
