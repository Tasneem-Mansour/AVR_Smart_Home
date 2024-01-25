/*
 * EXTI_program.c
 *
 *  Created on: Dec 17, 2023
 *      Author: Tasneem
 */

#include "../STD_Types.h"
#include "../BIT_Math.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"

void (*EXTI0_CALLBACK_PTR)(void)=NULL;
void (*EXTI1_CALLBACK_PTR)(void)=NULL;
void (*EXTI2_CALLBACK_PTR)(void)=NULL;


void EXT_INTERRUPT_VID_INIT(void){
#if EXT0_MODE==     LOW_LEVEL
	CLR_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#elif EXT0_MODE==   IOC
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#elif EXT0_MODE==   FALLING_EDGE
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#elif EXT0_MODE==   RISING_EDGE
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#else
#endif

#if EXT1_MODE==     LOW_LEVEL
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif EXT1_MODE==   IOC
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#elif EXT1_MODE==   FALLING_EDGE
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#elif EXT1_MODE==   RISING_EDGE
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#else
#endif

#if EXT2_MODE== FALLING_EDGE
	CLR_BIT(MCUCSR,ISC2);

#elif EXT2_MODE== RISING_EDGE
	SET_BIT(MCUCSR,ISC2);


#else
#endif
}

void EXT_INTERRUPT_VID_ENABLE(uint8 interrupt_number){
	switch(interrupt_number){
	case EXT0:
		SET_BIT(GICR, INT0);
		break;
	case EXT1:
		SET_BIT(GICR, INT1);
		break;
	case EXT2:
		SET_BIT(GICR, INT2);
		break;
	default:
		break;
	}
}

void EXT_INTERRUPT_VID_DISABLE(uint8 interrupt_number){
	switch(interrupt_number){
		case EXT0:
			CLR_BIT(GICR, INT0);
			break;
		case EXT1:
			CLR_BIT(GICR, INT1);
			break;
		case EXT2:
			CLR_BIT(GICR, INT2);
			break;
		default:
			break;
	}
}

	void EXT0_VID_SET_CALL_BACK(void (*PTR)(void)){
		EXTI0_CALLBACK_PTR=PTR;
	}

	void EXT1_VID_SET_CALL_BACK(void (*PTR)(void)){
		EXTI1_CALLBACK_PTR=PTR;
	}

	void EXT2_VID_SET_CALL_BACK(void (*PTR)(void)){
		EXTI2_CALLBACK_PTR=PTR;
	}


	void __vector_1 (void) __attribute__ ((signal,used, externally_visible)) ; \
	void __vector_1 (void){
		EXTI0_CALLBACK_PTR();
	}

	void __vector_2 (void) __attribute__ ((signal,used, externally_visible)) ; \
	void __vector_2 (void){
		EXTI1_CALLBACK_PTR();
	}


	void __vector_3 (void) __attribute__ ((signal,used, externally_visible)) ; \
	void __vector_3 (void){
		EXTI2_CALLBACK_PTR();
	}
