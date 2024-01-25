/*
 * Password.c
 *
 *  Created on: Jan 12, 2024
 *      Author: Tasneem
 */
#include "../BIT_Math.h"
#include "../STD_Types.h"
#include "Password_interface.h"
#include "../KeyPad/KPD_interface.h"

uint8 u8key[5];


uint8* PASS_u8Setup(void){
//	while(KPD_u8GetKey() == 0);

	for(uint8 i=0; i<5; i++){
		u8key[i] = KPD_u8GetKey();
	}
	return u8key;
}

uint8 PASS_u8ComparePassword(uint8 key1, uint8 key2 ){
	uint8 u8Error = 0;
	if(key1 == key2){
		u8Error = 0;
	}
	else{
		u8Error = 1;
	}
	return u8Error;
}
//uint8 PASS_u8ErrorDetection(uint8 *current_password){
//	uint8 u8Check = 0;
//
//	uint8 u8Error = 0;
//
//	for (uint8 i=0;i<5;i++){
//		input_password[i]=PASS_voidSetup();
//		//Gotoxy(1,i);
//		//LCD_voidWriteCharctr("*");
//		u8Check = PASS_u8ComparePassword(input_password[i],current_password[i]);
//	}
//	if(u8Check == 0){
//		u8Error = 0;
//	}
//	else{
//		u8Error = 1;
//	}
//	return u8Error;
//}
