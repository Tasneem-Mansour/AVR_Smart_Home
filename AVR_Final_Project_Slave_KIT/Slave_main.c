/*
 * main.c
 *
 *  Created on: Jan 14, 2024
 *      Author: Tasneem
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "util/delay.h"
#include "DIO/DIO_interface.h"
#include "UART/UART_interface.h"
#include "7SEG/seven_segment_interface.h"

int main(void){
	DIO_voidInit();
	UART_voidInit();
	DIO_voidWritePin(PORT_B, DIO_PIN_NUM_B0, DIO_LOW);
	uint8 u8ErrorCounts=0;
	while(1){
		//-------------MCU2----------------
		// start counting no. of trials on the 7SEG
		//if no. of trials exceeded 3
		//turn the siren ON (buzzer)
		uint8 u8WrongPass = UART_u8ReceiveData();

		if(u8WrongPass == 5){
			if(u8ErrorCounts<2){
				u8ErrorCounts++;
				SevSeg_voidDisplay(u8ErrorCounts);
				_delay_ms(20);
			}
			else{
				//do nth
			}
		}
		else if(u8WrongPass == 3){
			DIO_voidWritePin(PORT_B, DIO_PIN_NUM_B0, DIO_HIGH);		//buzzer ON
			_delay_ms(5000);
//			DIO_voidWritePin(PORT_B, DIO_PIN_NUM_B0, DIO_LOW);
		}
		else {
			u8ErrorCounts=0;
			SevSeg_voidDisplay(u8ErrorCounts);
		}
	}
}
