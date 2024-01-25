/*
 * SPI_config.h
 *
 *  Created on: Dec 26, 2023
 *      Author: Tasneem
 */



/******** SPCR BITS  ********/
#define  	SPCR_SPIE		7
#define  	SPCR_SPE		6
#define 	SPCR_DORD		5
#define 	SPCR_MSTR		4
#define 	SPCR_CPOL		3
#define  	SPCR_CPHA		2
#define 	SPCR_SPR1		1
#define  	SPCR_SPR0		0



/******** SPSR BITS  ********/
#define 	SPSR_SPIF		7
#define		SPSR_WCOL		6
#define 	SPSR_SPI2X		0



/******** SPDR BITS  ********/
#define 	SPDR_MSB		7
#define  	SPDR_LSB		0
