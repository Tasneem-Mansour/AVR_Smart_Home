/*
 * Global_Interrupt_program.c
 *
 *  Created on: Dec 17, 2023
 *      Author: Tasneem
 */

#include "../STD_Types.h"
#include "../BIT_Math.h"
#include "Global_Interrupt_register.h"
#include "Global_Interrupt_interface.h"

void Global_Interrupt_Enable(void)
{
	SET_BIT(SREG,I);
}
void Global_Interrupt_Disable(void)
{
	CLR_BIT(SREG,I);
}
