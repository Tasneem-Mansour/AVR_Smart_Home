/*
 * SPI_interface.h
 *
 *  Created on: Dec 26, 2023
 *      Author: Tasneem
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_




void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);

uint8 SPI_u8TransceiverDataSynch(uint8 u8DataCpy);

#endif /* SPI_INTERFACE_H_ */
