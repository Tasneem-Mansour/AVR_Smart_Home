/*
 * DC_Motor_program.c
 *
 *  Created on: Dec 14, 2023
 *      Author: Tasneem
 */
#include "../STD_Types.h"
#include "../BIT_Math.h"
#include "DC_Motor_config.h"
#include "DC_Motor_interface.h"
#include "../DIO/DIO_interface.h"


void DCM_voidRotateCW(void){
	DIO_voidWritePin(DCM_PORT, DCM_PIN0, DIO_LOW);
	DIO_voidWritePin(DCM_PORT, DCM_PIN1, DIO_HIGH);
}
void DCM_voidRotateCCW(void){
	DIO_voidWritePin(DCM_PORT, DCM_PIN0, DIO_HIGH);
	DIO_voidWritePin(DCM_PORT, DCM_PIN1, DIO_LOW);
}
void DCM_voidStop(void){
	DIO_voidWritePin(DCM_PORT, DCM_PIN0, DIO_LOW);
	DIO_voidWritePin(DCM_PORT, DCM_PIN1, DIO_LOW);
}

