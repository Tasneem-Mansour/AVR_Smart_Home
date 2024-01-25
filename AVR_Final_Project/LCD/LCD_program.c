/*
 * LCD_program.c
 *
 *  Created on: Dec 12, 2023
 *      Author: Tasneem
 */

#include "../STD_Types.h"
#include "../BIT_Math.h"
#include "../DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "../Password/Password_interface.h"
#include "util/delay.h"

void LCD_voidInit(void){
	/* Pin Direction*/
	DIO_voidWritePort(lcd_DATAPORT   , DIO_OUTPUT);
	DIO_voidWritePin (lcd_CONTROLPORT, lcd_RSPIN, DIO_OUTPUT);
	//DIO_voidWritePin (lcd_CONTROLPORT, lcd_RWPIN, DIO_OUTPUT);
	DIO_voidWritePin (lcd_CONTROLPORT, lcd_EPIN , DIO_OUTPUT);
	/* Make Enable Low*/
	DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_LOW);

	_delay_ms(30);
	LCD_voidSendCommand(lcd_Home);
	_delay_ms(5);
	LCD_voidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(5);
	LCD_voidSendCommand(lcd_DisplayOn);
	_delay_ms(5);
	LCD_voidSendCommand(lcd_Clear);
	_delay_ms(5);
	LCD_voidSendCommand(lcd_EntryMode);
	_delay_ms(5);
}
void LCD_voidInit_4bitMode(void){
	/* Pin Direction*/
//	DIO_voidWritePort(lcd_DATAPORT, DIO_OUTPUT);
	DIO_voidWritePin (lcd_DATAPORT, DIO_PIN_NUM_A4, DIO_OUTPUT);
	DIO_voidWritePin (lcd_DATAPORT, DIO_PIN_NUM_A5, DIO_OUTPUT);
	DIO_voidWritePin (lcd_DATAPORT, DIO_PIN_NUM_A6, DIO_OUTPUT);
	DIO_voidWritePin (lcd_DATAPORT, DIO_PIN_NUM_A7, DIO_OUTPUT);

	DIO_voidWritePin (lcd_CONTROLPORT, lcd_RSPIN, DIO_OUTPUT);
	//DIO_voidWritePin (lcd_CONTROLPORT, lcd_RWPIN, DIO_OUTPUT);
	DIO_voidWritePin (lcd_CONTROLPORT, lcd_EPIN , DIO_OUTPUT);
	/* Make Enable Low*/
	DIO_voidWritePin (lcd_CONTROLPORT, lcd_EPIN , DIO_LOW);

	_delay_ms(50);
	LCD_voidSendCommand_4bitMode(lcd_Home);
	_delay_ms(5);
	LCD_voidSendCommand_4bitMode(lcd_FunctionSet4bit);
	_delay_ms(5);
	LCD_voidSendCommand_4bitMode(lcd_DisplayOn);
	_delay_ms(5);
	LCD_voidSendCommand_4bitMode(lcd_Clear);
	_delay_ms(5);
	LCD_voidSendCommand_4bitMode(lcd_EntryMode);
	_delay_ms(5);
}
void LCD_voidSendCommand(uint8 u8CmdCpy){
	/* Command(0) or Data(1) */
	DIO_voidWritePin(lcd_CONTROLPORT, lcd_RSPIN, DIO_LOW);
	/* Read(1) or Write(0) */
	//DIO_voidWritePin(lcd_CONTROLPORT, lcd_RWPIN, DIO_LOW);
	/* Write Commands on Data Pins*/
	DIO_voidWritePort(lcd_DATAPORT, u8CmdCpy);
	/* Enable Sequence */
	DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_HIGH);
	_delay_ms(5);
	DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_LOW);
}

void LCD_voidSendCommand_4bitMode(uint8 u8CmdCpy){
    /* Send Higher nibble of command */
    DIO_voidWritePort(lcd_DATAPORT, (lcd_DATAPORT & 0x0F) | (u8CmdCpy & 0xF0));
    /* Command(0) or Data(1) */
    DIO_voidWritePin(lcd_CONTROLPORT, lcd_RSPIN, DIO_LOW);
    /* Read(1) or Write(0) */
    //DIO_voidWritePin(lcd_CONTROLPORT, lcd_RWPIN, DIO_LOW);

    /* Enable Sequence */
    DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_HIGH);
    _delay_us(5);
    DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_LOW);
    _delay_us(200);

    /* Send Lower nibble of command */
    DIO_voidWritePort(lcd_DATAPORT, (lcd_DATAPORT & 0x0F) | (u8CmdCpy <<4));
    /* Enable Sequence */
    DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_HIGH);
    _delay_us(5);
    DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_LOW);
    _delay_us(5);
}


void LCD_voidWriteCharctr(uint8 u8DataCpy){		//LCD_voidWriteCharctr('A')
	/* Command(0) or Data(1) */
	DIO_voidWritePin(lcd_CONTROLPORT, lcd_RSPIN, DIO_HIGH);
	/* Read(1) or Write(0) */
	//DIO_voidWritePin(lcd_CONTROLPORT, lcd_RWPIN, DIO_LOW);
	/* Write Data on Data Pins*/
	DIO_voidWritePort(lcd_DATAPORT, u8DataCpy);
	/* Enable Sequence */
	DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_HIGH);
	_delay_ms(5);
	DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_LOW);

}
void LCD_voidWriteCharctr_4bitMode(uint8 u8DataCpy){		//LCD_voidWriteCharctr('A')
	/* Command(0) or Data(1) */
	DIO_voidWritePin(lcd_CONTROLPORT, lcd_RSPIN, DIO_HIGH);
	/* Read(1) or Write(0) */
	//DIO_voidWritePin(lcd_CONTROLPORT, lcd_RWPIN, DIO_LOW);
	/* Write Data on Data Pins, sending upper nibble*/
	DIO_voidWritePort(lcd_DATAPORT, (lcd_DATAPORT & 0x0F) | (u8DataCpy & 0xF0));
	/* Enable Sequence */
	DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_HIGH);
	_delay_us(5);
	DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_LOW);
	_delay_us(200);

	/* Write Data on Data Pins, sending lower nibble*/
	DIO_voidWritePort(lcd_DATAPORT, (lcd_DATAPORT & 0x0F) | (u8DataCpy <<4));
	/* Enable Sequence */
	DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_HIGH);
	_delay_us(5);
	DIO_voidWritePin(lcd_CONTROLPORT, lcd_EPIN , DIO_LOW);
	_delay_us(200);

}
void LCD_voidWriteString(uint8 *pu8StringCpy, uint8 u8Index){	//LCD_voidWriteString('Tasneem')
	/*uint8 i=0;
	 *while(pu8StringCpy[i] != '\0'){
	 *		LCD_voidWriteCharctr(pu8StringCpy[i]);
	 *		i++;
	 *}*/
	for(uint8 i=0; i<u8Index; i++){
		LCD_voidWriteCharctr(pu8StringCpy[i]);
	}
}
void LCD_voidWriteString_4bitMode(uint8 *pu8StringCpy, uint8 u8Index){	//LCD_voidWriteString('Tasneem')
	for(uint8 i=0; i<u8Index; i++){
		LCD_voidWriteCharctr_4bitMode(pu8StringCpy[i]);
	}
}
void Gotoxy(uint8 x, uint8 y){
	if(x>=0 && x<16)
	{
		switch(y){
		case LineOne:
			LCD_voidSendCommand(LineOneStart+x);	//set DDRAM address
			break;
		case LineTwo:
			LCD_voidSendCommand(LineTwoStart+x);	//set DDRAM address
			break;
		default:
			break;
		}
	}
	else
	{
		//do nothing
	}
}

void LCD_voidGotoxy_4bitMode(uint8 x, uint8 y){
	if(x>=0 && x<16)
	{
		switch(y){
		case LineOne:
			LCD_voidSendCommand_4bitMode(LineOneStart+x);	//set DDRAM address
			break;
		case LineTwo:
			LCD_voidSendCommand_4bitMode(LineTwoStart+x);	//set DDRAM address
			break;
		default:
			break;
		}
	}
	else
	{
		//do nothing
	}
}
void LCD_voidWriteExtraChar(uint8 Y, uint8 X){

}

void LCD_voidDisplayKeys(uint8 *u8key, uint8 *index){
	LCD_voidGotoxy_4bitMode(*index, LineTwo);
	if ((u8key[*index] >= '0' && u8key[*index] <= '9') || (u8key[*index] >= 'A' && u8key[*index] <= 'D') || (u8key[*index] =='*')||(u8key[*index] =='#')) {
		LCD_voidWriteCharctr_4bitMode(u8key[*index]);
		LCD_voidGotoxy_4bitMode(*index, LineTwo);
		_delay_ms(200);
		LCD_voidWriteCharctr_4bitMode('*');
		_delay_ms(100);
		(*index)++;
	}
}
