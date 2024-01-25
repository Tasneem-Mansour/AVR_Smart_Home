/*
 * TWI_private.h
 *
 *  Created on: Jan 1, 2024
 *      Author: Tasneem
 */

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define 	TWBR				*((volatile uint8*)0x20)
#define 	TWCR                *((volatile uint8*)0x56)
#define 	TWSR                *((volatile uint8*)0x21)
#define 	TWDR                *((volatile uint8*)0x23)
#define 	TWAR                *((volatile uint8*)0x22)




#define START_CONDITION					0x08
#define REPEATE_START_CONDITION			0x10
#define SLA_WITH_W_NOACK				0x20
#define SLA_WITH_R_NOACK				0x38
#define MASTER_SEND_DATA_NOACK			0x30
#define MASTER_RECEIVE_DATA_NOACK		0x58



#endif /* TWI_PRIVATE_H_ */
