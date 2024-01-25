/*
 * KPD_program.c
 *
 *  Created on: Dec 12, 2023
 *      Author: Tasneem
 */
#include "../STD_Types.h"
#include "../BIT_Math.h"
#include "../DIO/DIO_interface.h"
#include "KPD_interface.h"
#include "util/delay.h"
uint8 KPD_arr[4][4]={{ '1', '2', '3', 'A'},
					 { '4', '5', '6', 'B'},
					 { '7', '8', '9', 'C'},
					 { '*', '0', '#', 'D'}};


void KPD_voidInit(void){
	uint8 i;
	for(i=ROW_START; i<=ROW_END; i++){
		//make all rows input pull up
		DIO_voidPullUpState(KPD_PORT,i, ENABLE_PULLUP);
	}
	for(i=COLUMN_START; i<=COLUMN_END; i++){
		//make all column pins high
		//DIO_voidWritePin(KPD_PORT,i, DIO_INPUT);
		DIO_voidWritePin(KPD_PORT,i, DIO_HIGH);
		}
}

uint8 KPD_u8GetKey(void){
	uint8 key = NoPressedKey;
	uint8 i, j, k;
	uint8 result, exitflag = DIO_LOW;
	for(i=0;i<4;i++){			//loop over columns
		//set all columns high
		for(k=COLUMN_START; k<=COLUMN_END;k++){
			DIO_voidWritePin(KPD_PORT,k, DIO_HIGH);
		}
		//set column low
		DIO_voidWritePin(KPD_PORT,(COLUMN_START+i), DIO_LOW);

		for(j=0;j<4;j++){		//loop over rows
			result = DIO_u8ReadPin(KPD_PORT, (ROW_START+j));
			_delay_ms(20);
			if(result == DIO_LOW){
				key = KPD_arr[j][i];
				exitflag = DIO_HIGH;
				if(exitflag ==DIO_HIGH){
					break;
				}
			}
		}
		if(exitflag == DIO_HIGH){
			break;
		}
	}
	return key;
}


