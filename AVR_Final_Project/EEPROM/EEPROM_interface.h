/*
 * EEPROM_interface.h
 *
 *  Created on: Jan 2, 2024
 *      Author: Tasneem
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidRead(uint8 u8LocationAddressCpy , uint8* pu8DataCpy);

void EEPROM_voidWrite(uint8 u8LocationAddressCpy , uint8 u8DataCpy);
void EEPROM_voidWritePage(uint8 u8LocationAddressCpy , uint8* pu8DataCpy, uint8 length);

#endif /* EEPROM_INTERFACE_H_ */
