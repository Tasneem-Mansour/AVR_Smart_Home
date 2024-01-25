/*
 * TIMER0_program.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Tasneem
 */

#include "../STD_Types.h"
#include "../BIT_Math.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

pf TIMER0_pfOVFCallBack = NULL_PTR;
pf TIMER0_pfComCallBack = NULL_PTR;

void TIMER0_voidInit(void)
{
#if TIMER0_MODE == NORMAL_MODE
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
#elif TIMER0_MODE == CTC_MODE
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
#elif TIMER0_MODE == FAST_PWM
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
#elif TIMER0_MODE == PHASE_COEERCT_PWM
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	/*
	 * SET NORMAL MODE IF NO SELECTION*/
#else
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
#endif

#if  TIMER0_OC0_PWM == TOGGLE_OC0
	SET_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
#elif TIMER0_OC0_PWM == CLEAR_OC0
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif TIMER0_OC0_PWM == SET_OC0
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif TIMER0_OC0_PWM == INVERTING_FAST_PWM
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif TIMER0_OC0_PWM == NON_INVERTING_FAST_PWM
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif TIMER0_OC0_PWM == INVERTING_PHASE_CORRECT_PWM
	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif TIMER0_OC0_PWM == NON_INVERTING_PHASE_CORRECT_PWM
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
	/*DEFAULT OC0 is disconnected*/
#else
	CLR_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
#endif

//	/*PRESCALAR CONFIG*/
//	TCCR0 = TCCR0 & 0b11111000;
//	TCCR0 |=TIMER0_PRESCALER;

}

//used to enable and update prescalar
void TIMER0_voidEnable(uint8 u8Prescalar)
{
	/*PRESCALAR CONFIG*/
	TCCR0 = TCCR0 & 0b11111000;
	TCCR0 |=u8Prescalar;
}
void TIMER0_voidDisable(void)
{
	TCCR0 = TCCR0 & 0b11111000;
}

void TIMER0_voidEnableOvfInt(void)
{
	SET_BIT(TIMSK,0);
}
void TIMER0_voidDisableOvfInt(void)
{
	CLR_BIT(TIMSK,0);
}


void TIMER0_voidEnableComInt(void)
{
	SET_BIT(TIMSK,1);
}
void TIMER0_voidDisableComInt(void)
{
	CLR_BIT(TIMSK,1);
}


void TIMER0_voidSetTCNTValue(uint8 u8ValueCpy)
{
	TCNT0 = u8ValueCpy;
}

void TIMER0_voidSetOCRValue(uint8 u8ValueCpy)
{
	OCR0 = u8ValueCpy;
}

uint8 TIMER0_voidReadTCNTReg(void)
{
	return TCNT0;
}

void TIMER0_voidSetCallBackOvfInt(pf pfOvfcallbackCpy)
{
	TIMER0_pfOVFCallBack = pfOvfcallbackCpy;
}


void TIMER0_voidSetCallBackComInt(pf pfComcallbackCpy)
{
	TIMER0_pfComCallBack = pfComcallbackCpy;
}

//__attribute__ means -> compiler  do not optimize			//12-1=11
void __vector_11 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_11 (void)
{
	if(TIMER0_pfOVFCallBack!= NULL_PTR)
	{
		TIMER0_pfOVFCallBack();
	}
	else
	{
		//do nothing
	}
}

void __vector_10 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_10 (void)
{
	if(TIMER0_pfComCallBack!= NULL_PTR)
	{
		TIMER0_pfComCallBack();
	}
	else
	{
		//do nothing
	}
}

