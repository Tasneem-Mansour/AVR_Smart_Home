/*
 * Password_interface.h
 *
 *  Created on: Jan 12, 2024
 *      Author: Tasneem
 */

#ifndef PASSWORD_PASSWORD_INTERFACE_H_
#define PASSWORD_PASSWORD_INTERFACE_H_

//extern uint8 u8key[5];

uint8 input_password[5];
uint8 current_password[5];

uint8* PASS_u8Setup(void);
uint8 PASS_u8ComparePassword(uint8 key1, uint8 key2 );
uint8 PASS_u8ErrorDetection(uint8 *current_password);



#endif /* PASSWORD_PASSWORD_INTERFACE_H_ */
