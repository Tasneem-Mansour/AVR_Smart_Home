/*
 * UART_private.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Tasneem
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define 	UDR          *( (volatile  uint8*) 0x2C)
#define		UCSRA		 *( (volatile  uint8*) 0x2B)
#define		UCSRB		 *( (volatile  uint8*) 0x2A)
#define		UCSRC		 *( (volatile  uint8*) 0x40)
#define     UBRRL		 *( (volatile  uint8*) 0x29)
#define		UBRRH		 *( (volatile  uint8*) 0x40)			// Fcpu=8MHZ won't need UBRRH

#define 	BAUD_9600	 51

#endif /* UART_PRIVATE_H_ */
