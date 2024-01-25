/*
 * TWI_program.c
 *
 *  Created on: Jan 1, 2024
 *      Author: Tasneem
 */
#include "../STD_Types.h"
#include "../BIT_Math.h"
#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"

void TWI_voidMasterInit(void){
	/* Set Clock configuration  TWBR = 2 */
	TWBR = 2;
	CLR_BIT(TWSR , TWSR_TWPS0);
	CLR_BIT(TWSR , TWSR_TWPS1);

	/* Enable Acknowledge bit */
	SET_BIT(TWCR , TWCR_TWEA);
	/* Set my own Address */
	TWAR = MASTER_ADDRESS << 1;
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);

}
void TWI_voidSlaveInit(void){
	/* Enable Acknowledge bit */
	SET_BIT(TWCR , TWCR_TWEA);
	/* Set my own Address */
	TWAR = SLAVE_ADDRESS << 1;
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);
}

TWI_ErrorState_t TWI_enStartCondition(void){
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;
	/* enable start condition */
	SET_BIT(TWCR , TWCR_TWSTA);
	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);

	/*Wait until the interrupt flag us raised again  */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if((TWSR & 0XF8) != START_CONDITION)
	{
		Local_ErrorState = START_CONDITION_ERR;
	}
	else
	{
		/* Do Nothing */
	}

	return Local_ErrorState;


}
TWI_ErrorState_t TWI_enRepeatStart(void){
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;
	/* enable start condition */
	SET_BIT(TWCR , TWCR_TWSTA);
	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);

	/*Wait until the interrupt flag us raised again  */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if((TWSR & 0XF8) != REPEATE_START_CONDITION)
	{
		Local_ErrorState = REPEAT_START_ERR;
	}
	else
	{
		/* Do Nothing */
	}

	return Local_ErrorState;
}
TWI_ErrorState_t TWI_enSetSlaveAddress_Write(uint8 u8SlaveAddressCpy){
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;

	/* Set Slave address in TWDR register */
	TWDR = u8SlaveAddressCpy;

	/* Clear the start condition bit */
	CLR_BIT(TWCR , TWCR_TWSTA);
	/* Clear bit 0 to make write operation */
	CLR_BIT(TWDR , TWDR_TWD0);

	/*************************************************/
	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);
	/*Wait until the interrupt flag us raised again  */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if((TWSR & 0XF8) == SLA_WITH_W_NOACK)
	{
		Local_ErrorState = SLA_W_NOACK_ERR;
	}
	else
	{
		/* Do Nothing */
	}
	return Local_ErrorState;
}
TWI_ErrorState_t TWI_enSetSlaveAddress_Read(uint8 u8SlaveAddressCpy){
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;

	/* Set Slave address in TWDR register */
	TWDR = u8SlaveAddressCpy | 1;   //first bit will be 1

	/* Clear the start condition bit */
	CLR_BIT(TWCR , TWCR_TWSTA);
	/* Set bit 0 to make Read operation */
	//SET_BIT(TWDR , TWDR_TWD0);		//already is set to 1

	/*************************************************/
	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);
	/*Wait until the interrupt flag us raised again  */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if((TWSR & 0XF8) == SLA_WITH_R_NOACK)
	{
		Local_ErrorState = SLA_R_NOACK_ERR;
	}
	else
	{
		/* Do Nothing */
	}
	return Local_ErrorState;
}
TWI_ErrorState_t TWI_enMasterWriteData(uint8 u8DataCpy){
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;
	/* Write data to TWDR */
	TWDR = u8DataCpy;

	/*************************************************/
	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);
	/*Wait until the interrupt flag us raised again  */
	while(GET_BIT(TWCR , TWCR_TWINT) == 0);

	if((TWSR & 0XF8) == MASTER_SEND_DATA_NOACK)
	{
		Local_ErrorState = MASTER_SEND_DATA_ERR;
	}
	else
	{
		/* Do Nothing */
	}

	return Local_ErrorState;

}
TWI_ErrorState_t TWI_enMasterReadData(uint8* u8DataCpy){
	TWI_ErrorState_t Local_ErrorState = NO_ERROR;

		/* Clear interrupt flag to start the operation */
		SET_BIT(TWCR , TWCR_TWINT);
		/* Enable TWI */
		SET_BIT(TWCR , TWCR_TWEN);
		CLR_BIT(TWCR, TWCR_TWEA);
		/*Wait until the interrupt flag us raised again  */
		while(GET_BIT(TWCR , TWCR_TWINT) == 0);

		if((TWSR & 0XF8) == MASTER_RECEIVE_DATA_NOACK)
		{
			Local_ErrorState = MASTER_RECEIVE_DATA_ERR;
		}
		else
		{
		}
			*u8DataCpy = TWDR;

		return Local_ErrorState;

}

void TWI_voidStopCondition(void){
	/* Set bit TWSTO to make stop condition */
	SET_BIT(TWCR , TWCR_TWSTO);

	/************************************************/
	/* Clear interrupt flag to start the operation */
	SET_BIT(TWCR , TWCR_TWINT);
	/* Enable TWI */
	SET_BIT(TWCR , TWCR_TWEN);
}
