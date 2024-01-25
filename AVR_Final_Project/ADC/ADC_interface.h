/*
 * ADC_interface.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Tasneem
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define Channel_A0 0
#define Channel_A1 1
#define Channel_A2 2
#define Channel_A3 3
#define Channel_A4 4
#define Channel_A5 5
#define Channel_A6 6
#define Channel_A7 7

void ADC_Init (void); // ADC Initialization And Enable
uint16 ADC_Read_SYNCH (uint8 Channel); // Read From The ADC Channel


void ADC_Start_ASYNC (uint8 Channel);
uint16 ADC_Read_ASYNC(void);
void ADC_void_SET_CALL_BACK(void (*PTR)(void));

#endif /* ADC_INTERFACE_H_ */
