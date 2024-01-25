/*
 * EEPROM_program.c
 *
 *  Created on: Jan 2, 2024
 *      Author: Tasneem
 */

#include "../STD_Types.h"
#include "../BIT_Math.h"
#include <util/delay.h>

#include "TWI_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"



void EEPROM_voidRead(uint8 u8LocationAddressCpy , uint8* pu8DataCpy)
{
	/* Start condition  */
	TWI_enStartCondition();
	/* Send SLA With Write */
	TWI_enSetSlaveAddress_Write(SLAVE_ADDRESS_WRITE);
	/* Send Memory location */
	TWI_enMasterWriteData(u8LocationAddressCpy);
	/* Repeat Start to change Write operation to Read operation */
	TWI_enRepeatStart();
	//	TWI_enSetSlaveAddress_Write(SLAVE_ADDRESS_READ);   //will be also read successfully
	TWI_enSetSlaveAddress_Read(SLAVE_ADDRESS_WRITE);
	/* Master Receive Data*/
	TWI_enMasterReadData(pu8DataCpy);
	TWI_voidStopCondition();

}

void EEPROM_voidWrite(uint8 u8LocationAddressCpy , uint8 u8DataCpy){

	/* Start condition  */
	TWI_enStartCondition();
	/* Send SLA With Write */
	TWI_enSetSlaveAddress_Write(SLAVE_ADDRESS_WRITE);
	/* Send Memory location */
	TWI_enMasterWriteData(u8LocationAddressCpy);
	TWI_enMasterWriteData(u8DataCpy);
	TWI_voidStopCondition();
	_delay_ms(200);

}

void EEPROM_voidWritePage(uint8 u8LocationAddressCpy , uint8* pu8DataCpy, uint8 length){

	/* Start condition  */
	TWI_enStartCondition();
	/* Send SLA With Write */
	TWI_enSetSlaveAddress_Write(SLAVE_ADDRESS_WRITE);
	/* Send Memory location */
	TWI_enMasterWriteData(u8LocationAddressCpy);
	for(uint8 i=0; i<length; i++){
		TWI_enMasterWriteData(pu8DataCpy[i]);
		_delay_ms(5);

	}

	TWI_voidStopCondition();

}
