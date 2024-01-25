/*
 * SPI_program.c
 *
 *  Created on: Dec 26, 2023
 *      Author: Tasneem
 */
#include "../BIT_Math.h"
#include "../STD_Types.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void SPI_voidMasterInit(void){
	/******Select data order*******/						  // default
	CLR_BIT(SPCR, SPCR_DORD);
	/******Select master******/
	SET_BIT(SPCR, SPCR_MSTR);
	/******Clock Polarity -> leading edge -> rising ******/	  // default
	CLR_BIT(SPCR, SPCR_CPOL);
	/******Clock Phase    -> sample first ******/			  // default
	CLR_BIT(SPCR, SPCR_CPHA);
	/******Select SPI clock rate******/
	SET_BIT(SPCR, SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);
	CLR_BIT(SPSR, SPSR_SPI2X);

	/******Enable SPI******/
	SET_BIT(SPCR, SPCR_SPE);
}
void SPI_voidSlaveInit(void){
	/******Select data order******/
	CLR_BIT(SPCR, SPCR_DORD);								  // default
	/******Select slave******/
	CLR_BIT(SPCR, SPCR_MSTR);
	/******Clock Polarity -> leading edge -> rising ******/   // default
	CLR_BIT(SPCR, SPCR_CPOL);
	/******Clock Phase    -> sample first ******/             // default
	CLR_BIT(SPCR, SPCR_CPHA);

	/******Enable SPI******/
	SET_BIT(SPCR, SPCR_SPE);
}

uint8 SPI_u8TransceiverDataSynch(uint8 u8DataCpy){
	/*****Send Data****/
	SPDR = u8DataCpy;
	/*****wait until data received****/
	while(GET_BIT(SPSR, SPSR_SPIF)==0);

	return SPDR;
}
