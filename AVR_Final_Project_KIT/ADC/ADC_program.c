/*
 * ADC_program.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Tasneem
 */
#include "../BIT_Math.h"
#include "../STD_Types.h"
#include "ADC_interface.h"
#include "ADC_register.h"

void (*ADC_CALLBACK_PTR)(void) = NULL;


void ADC_Init (void){
	CLR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);

	CLR_BIT(ADMUX, ADLAR);

	//clock
	SET_BIT(ADCSRA, ADPS0);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);

	SET_BIT(ADCSRA, ADEN);

}


uint16 ADC_Read_SYNCH (uint8 Channel){
	//bit masking   ADMUX = (111 00000 & 010 10101) | 000 01010 = 010 01010
	ADMUX=(ADMUX&0b11100000) | (Channel);

	SET_BIT(ADCSRA, ADSC);				//start conversion

	while(GET_BIT(ADCSRA, ADIF) == 0);

	SET_BIT(ADCSRA, ADIF); 				//set flag
	return ADC_Reg;
}
//-------------------------------------------------------------------------------
void ADC_Start_ASYNC (uint8 Channel)
{
	if (GET_BIT(ADCSRA, ADSC) == 0)
	{
		ADMUX = ((ADMUX & 0b11100000)|(Channel));
		SET_BIT(ADCSRA, ADSC);
	}
}
uint16 ADC_Read_ASYNC(void)
{
	return ADC_Reg;
}
void ADC_void_SET_CALL_BACK(void (*ptr)(void))
{
	ADC_CALLBACK_PTR = ptr;
}

void __vector_16 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_16 (void){
	ADC_CALLBACK_PTR();
}

