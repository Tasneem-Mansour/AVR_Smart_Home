/*
 * LCD_interface.h
 *
 *  Created on: Dec 12, 2023
 *      Author: Tasneem
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/************* Commands ************/
#define lcd_Clear           0x01          /* replace all characters with ASCII 'space' */
#define lcd_Home            0x02          /* return cursor to first position on first line */
#define lcd_EntryMode       0x06          /* shift cursor from left to right on read/write */
#define lcd_DisplayOff      0x08          /* turn display off */
#define lcd_DisplayOn       0x0C          /* display on, cursor off, don't blink character */
#define lcd_FunctionReset   0x30          /* reset the LCD */

#define lcd_Func4bitInit 	0x32		  /* Send for 4 bit initialization of LCD  */
#define lcd_Func4bitInit1   0x33
#define lcd_FunctionSet4bit 0x28		  /* 2-line, 5*7 matrix in 4-bit mode */

#define lcd_FunctionSet8bit 0x38          /* 8-bit data, 2-line display, 5 x 7 font */
#define lcd_SetCursor       0x80          /* set cursor position */

/*************** LCD DIO ****************/
#define lcd_DATAPORT        PORT_D
#define lcd_CONTROLPORT     PORT_C
#define lcd_RSPIN           DIO_PIN_NUM_C2
//#define lcd_RWPIN         DIO_PIN_NUM_C5
#define lcd_EPIN            DIO_PIN_NUM_C3

#define LineOneStart        0x80			//128
#define LineTwoStart		0xC0			//192

#define LineOne				1
#define LineTwo				2
/********** Function Definition ************/
void LCD_voidInit(void);
void LCD_voidInit_4bitMode(void);

void LCD_voidSendCommand(uint8 u8CmdCpy);
void LCD_voidSendCommand_4bitMode(uint8 u8CmdCpy);

void LCD_voidWriteCharctr(uint8 u8DataCpy);
void LCD_voidWriteCharctr_4bitMode(uint8 u8DataCpy);

void LCD_voidWriteString(uint8 *pu8StringCpy, uint8 u8Index);
void LCD_voidWriteString_4bitMode(uint8 *pu8StringCpy, uint8 u8Index);

void Gotoxy(uint8 X, uint8 Y);		// x = columns  y = rows
void LCD_voidGotoxy_4bitMode(uint8 x, uint8 y);
void LCD_voidWriteExtraChar(uint8 Y, uint8 X);

void LCD_voidDisplayKeys(uint8 *u8key, uint8 *index);

#endif /* LCD_INTERFACE_H_ */
