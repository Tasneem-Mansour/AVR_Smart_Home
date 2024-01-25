/*
 * TWI_interface.h
 *
 *  Created on: Jan 1, 2024
 *      Author: Tasneem
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum{
	NO_ERROR,
	START_CONDITION_ERR,
	REPEAT_START_ERR,
	SLA_W_NOACK_ERR,
	SLA_R_NOACK_ERR,
	MASTER_SEND_DATA_ERR,
	MASTER_RECEIVE_DATA_ERR,
	MAX_ERR,

}TWI_ErrorState_t;

void TWI_voidMasterInit(void);
void TWI_voidSlaveInit(void);

TWI_ErrorState_t TWI_enStartCondition(void);
TWI_ErrorState_t TWI_enRepeatStart(void);
TWI_ErrorState_t TWI_enSetSlaveAddress_Write(uint8 u8SlaveAddressCpy);
TWI_ErrorState_t TWI_enSetSlaveAddress_Read(uint8 u8SlaveAddressCpy);
TWI_ErrorState_t TWI_enMasterWriteData(uint8 u8DataCpy);
TWI_ErrorState_t TWI_enMasterReadData(uint8* u8DataCpy);

void TWI_voidStopCondition(void);



#endif /* TWI_INTERFACE_H_ */
