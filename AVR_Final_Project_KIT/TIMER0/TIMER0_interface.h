/*
 * TIMER0_interface.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Tasneem
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


#define TIMER0_NO_PRESCALER          1
#define TIMER0_PRESCALER_8           2
#define TIMER0_PRESCALER_64          3
#define TIMER0_PRESCALER_256         4
#define TIMER0_PRESCALER_1024        5
#define EXTERNAL_CLOCK_FALLING       6
#define EXTERNAL_CLOCK_RISING        7


void TIMER0_voidInit(void);
void TIMER0_voidEnable(uint8 u8Prescalar);
void TIMER0_voidDisable(void);

void TIMER0_voidEnableOvfInt(void);
void TIMER0_voidDisableOvfInt(void);


void TIMER0_voidEnableComInt(void);
void TIMER0_voidDisableComInt(void);


void TIMER0_voidSetTCNTValue(uint8 u8ValueCpy);

void TIMER0_voidSetOCRValue(uint8 u8ValueCpy);

void TIMER0_voidSetCallBackOvfInt(pf pfOvfcallbackCpy);


void TIMER0_voidSetCallBackComInt(pf pfComcallbackCpy);
uint8 TIMER0_voidReadTCNTReg(void);

#endif /* TIMER0_INTERFACE_H_ */
