/*
 *       Author: Tasneem
 *  Created on: Dec 10, 2023
 */

#include "../STD_Types.h"
#include "../BIT_Math.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_voidInit(void)
{
	DDRA=CONCAT(DIO_PIN_NUM_A7_DIR,DIO_PIN_NUM_A6_DIR,DIO_PIN_NUM_A5_DIR,DIO_PIN_NUM_A4_DIR,DIO_PIN_NUM_A3_DIR,DIO_PIN_NUM_A2_DIR,DIO_PIN_NUM_A1_DIR,DIO_PIN_NUM_A0_DIR);
	DDRB=CONCAT(DIO_PIN_NUM_B7_DIR,DIO_PIN_NUM_B6_DIR,DIO_PIN_NUM_B5_DIR,DIO_PIN_NUM_B4_DIR,DIO_PIN_NUM_B3_DIR,DIO_PIN_NUM_B2_DIR,DIO_PIN_NUM_B1_DIR,DIO_PIN_NUM_B0_DIR);
	DDRC=CONCAT(DIO_PIN_NUM_C7_DIR,DIO_PIN_NUM_C6_DIR,DIO_PIN_NUM_C5_DIR,DIO_PIN_NUM_C4_DIR,DIO_PIN_NUM_C3_DIR,DIO_PIN_NUM_C2_DIR,DIO_PIN_NUM_C1_DIR,DIO_PIN_NUM_C0_DIR);
	DDRD=CONCAT(DIO_PIN_NUM_D7_DIR,DIO_PIN_NUM_D6_DIR,DIO_PIN_NUM_D5_DIR,DIO_PIN_NUM_D4_DIR,DIO_PIN_NUM_D3_DIR,DIO_PIN_NUM_D2_DIR,DIO_PIN_NUM_D1_DIR,DIO_PIN_NUM_D0_DIR);
}
void DIO_voidWritePin(uint8 u8PortCpy, uint8 u8PinCpy, uint8 u8ValueCpy)
{
	switch(u8PortCpy){
	case PORT_A:
		if (u8ValueCpy == DIO_HIGH)
		{
			SET_BIT(PORTA, u8PinCpy);
		}
		else if(u8ValueCpy == DIO_LOW)
		{
			CLR_BIT(PORTA, u8PinCpy);
		}
		break;
	case PORT_B:
		if (u8ValueCpy == DIO_HIGH)
		{
			SET_BIT(PORTB, u8PinCpy);
		}
		else if(u8ValueCpy == DIO_LOW)
		{
			CLR_BIT(PORTB, u8PinCpy);
		}
		break;
	case PORT_C:
		if (u8ValueCpy == DIO_HIGH)
		{
			SET_BIT(PORTC, u8PinCpy);
		}
		else if(u8ValueCpy == DIO_LOW){
			CLR_BIT(PORTC, u8PinCpy);
		}
		break;
	case PORT_D:
		if (u8ValueCpy == DIO_HIGH){
			SET_BIT(PORTD, u8PinCpy);
		}
		else if(u8ValueCpy == DIO_LOW){
			CLR_BIT(PORTD, u8PinCpy);
		}
		break;
		}
}
uint8 DIO_u8ReadPin(uint8 u8PortCpy, uint8 u8PinCpy)
{
	uint8 u8PinVal;
	switch(u8PortCpy)
	{
		case PORT_A:
			u8PinVal=GET_BIT(PINA,u8PinCpy);
			break;
		case PORT_B:
			u8PinVal=GET_BIT(PINB,u8PinCpy);
			break;
		case PORT_C:
			u8PinVal=GET_BIT(PINC,u8PinCpy);
			break;
		case PORT_D:
			u8PinVal=GET_BIT(PIND,u8PinCpy);
			break;
	}
	return u8PinVal;
}

void DIO_voidTogglePin(uint8 u8PortCpy, uint8 u8PinCpy)
{
	switch(u8PortCpy)
	{
		case PORT_A:
			TOG_BIT(PORTA,u8PinCpy);
			break;
		case PORT_B:
			TOG_BIT(PORTB,u8PinCpy);
			break;
		case PORT_C:
			TOG_BIT(PORTC,u8PinCpy);
			break;
		case PORT_D:
			TOG_BIT(PORTD,u8PinCpy);
			break;
	}

}
/* DIO_voidWritePort(PORT_A, 0x20) -> ob0010 0000-----> this means bit 0 will be 0 and bit5 will be 1 */
void DIO_voidWritePort(uint8 u8PortCpy, uint8 u8ValueCpy)
{
	switch(u8PortCpy){
	case PORT_A:
		PORTA = u8ValueCpy;
		break;
	case PORT_B:
		PORTB = u8ValueCpy;
		break;
	case PORT_C:
		PORTC = u8ValueCpy;
		break;
	case PORT_D:
		PORTD = u8ValueCpy;
		break;

	}
}
void DIO_voidPullUpState(uint8 u8PortCpy , uint8 u8PinCpy,uint8 u8State)
{
	uint8 u8Direction ;
	switch(u8PortCpy)
	{
	case PORT_A :
		u8Direction=GET_BIT(DDRA,u8PinCpy);
		break;
	case PORT_B :
		u8Direction=GET_BIT(DDRB,u8PinCpy);
		break;

	case PORT_C :
		u8Direction=GET_BIT(DDRC,u8PinCpy);
		break;

	case PORT_D :
		u8Direction=GET_BIT(DDRD,u8PinCpy);
		break;
	}
	if (u8Direction==DIO_INPUT)			//if zero, write zero in pin
	{
		DIO_voidWritePin(u8PortCpy,u8PinCpy,u8State);
	}
	else
	{
		//do nothing
	}
}
