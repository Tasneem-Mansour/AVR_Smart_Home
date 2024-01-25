/*
 * UART_interface.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Tasneem
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_



void UART_voidInit(void);
void UART_voidSendDataSynch(const uint8 u8DataCpy);
uint8 UART_u8ReceiveData(void);
void UART_voidSendstring(uint8 *ptr);


#endif /* UART_INTERFACE_H_ */
