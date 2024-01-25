/*
 * TIMER1_interface.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Tasneem
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_


#define TIMER1_NO_PRESCALER          1
#define TIMER1_PRESCALER_8           2
#define TIMER1_PRESCALER_64          3
#define TIMER1_PRESCALER_256         4
#define TIMER1_PRESCALER_1024        5
#define EXTERNAL_CLOCK_FALLING       6
#define EXTERNAL_CLOCK_RISING        7

void TIM1_voidInit(void);
void TIM1_voidEnable(uint8 u8PrescalValCpy);
void TIM1_voidDisable(void);
void TIM1_voidEnableOvfInt(void);
void TIM1_voidDisableOvfInt(void);
void TIM1_voidEnableCmpAInt(void);
void TIM1_voidDisableCmpAInt(void);
void TIM1_voidEnableCmpBInt(void);
void TIM1_voidDisableCmpBInt(void);
void TIM1_voidEnableIcuInt(void);
void TIM1_voidDisableIcuInt(void);
void TIM1_voidSetCallbackOvfInt(pf pfOvfCalbckCpy);
void TIM1_voidSetCallbackCompAInt(pf pfCompACalbckCpy);
void TIM1_voidSetCallbackCompBInt(pf pfCompBCalbckCpy);
void TIM1_voidSetCallbackIcuInt(pf pfIcuCalbckCpy);
void TIM1_voidSetTimerValue(uint16 u16TimValCpy);    //TCNT1
void TIM1_voidSetCmpARegValue(uint16 u16CmpAValCpy); //OCR1A
void TIM1_voidSetCmpBRegValue(uint16 u16CmpBValCpy); //OCR1B
void TIM1_voidSetIcuRegValue(uint16 u16IcuValCpy);   //ICR1
uint16 TIM1_u8ReadTimerValue(void);                  //TCNT1
uint16 TIM1_u16GetIcuValue (void);


void ICU_voidRisingEdge(void);
void ICU_voidFallenEdge(void);

#endif /* TIMER1_INTERFACE_H_ */
