/*
 * main.c
 *
 *  Created on: Jan 12, 2024
 *      Author: Tasneem
 */
#include "STD_Types.h"
#include "BIT_Math.h"
#include "util/delay.h"
#include "DIO/DIO_interface.h"
#include "ADC/ADC_interface.h"
#include "EEPROM/TWI_interface.h"
#include "EEPROM/EEPROM_interface.h"
#include "DC_Motor/DC_Motor_interface.h"
#include "KeyPad/KPD_interface.h"
#include "UART/UART_interface.h"
#include "Password/Password_interface.h"
#include "LCD/LCD_interface.h"
#include "INT/EXTI_interface.h"
#include "INT/Global_Interrupt_interface.h"
#include "SPI_Protocol/SPI_interface.h"
#include "TIMER0/TIMER0_interface.h"
#include "TIMER1_Servo/TIMER1_interface.h"

#define ARRAY_SIZE				5
#define REFERNCE_VOLTAGE		5000
#define ADC_RESOLUTION			1024
#define LM1300_CONVERSION		10
#define EEPROM_START_ADDRESS	0X00

uint16 u16ServoCounter=0;
volatile uint32 u32Light_ISR;
uint8 u8key[ARRAY_SIZE];
uint8 u8InputPassword[ARRAY_SIZE];
uint8 u8EEPROMData [ARRAY_SIZE];
uint8 u8Error[5];
uint8 u8WelcomeInFlag;

uint8 u8FirstVar;
uint8 u8SecondVar;


void ArrivalButton(void);
void EntranceButton(void);

int main(void){
	uint16 u16Temperature   = 0;
	uint16 u16TempAnalogSignal=0;
	uint16 u16LightAnalogSignal=0;

	DIO_voidInit();
	ADC_Init();
	KPD_voidInit();
	UART_voidInit();
	LCD_voidInit_4bitMode();
	TWI_voidMasterInit();
	EXT_INTERRUPT_VID_INIT();



	DIO_voidWritePin(PORT_D, DIO_PIN_NUM_D7, DIO_LOW);
	DIO_voidWritePin(PORT_B, DIO_PIN_NUM_B3, DIO_LOW);

	DIO_voidWritePin(PORT_B, DIO_PIN_NUM_B2, ENABLE_PULLUP);
	DIO_voidWritePin(PORT_D, DIO_PIN_NUM_D3, ENABLE_PULLUP);

	//**************************************
//	DIO_voidWritePin(PORT_D, DIO_PIN_NUM_D0, ENABLE_PULLUP);
//	DIO_voidWritePin(PORT_B, DIO_PIN_NUM_B0, DIO_LOW);

//	if(GET_BIT(PORT_D, DIO_PIN_NUM_D0) ==0){
//		DIO_voidWritePin(PORT_B, DIO_PIN_NUM_B0, DIO_HIGH);
//	}
//
//	else {
//		DIO_voidWritePin(PORT_B, DIO_PIN_NUM_B0, DIO_LOW);
//
//	}

	//*******************************************s
	// Ask owner to set password
	LCD_voidWriteString_4bitMode("Set Password:", 13);

	// Set password on keypad
	uint8 u8PasswordSize = sizeof(u8key)/sizeof(u8key[0]);
	for(uint8 i=0;i<u8PasswordSize; ){
		u8key[i] = KPD_u8GetKey();								//get password from user
		LCD_voidDisplayKeys(u8key, &i);							//print password on LCD
		_delay_ms(200);
	}

	//save the password in EEPROM
	for(uint8 i=0;i<u8PasswordSize;i++){
		EEPROM_voidWrite(EEPROM_START_ADDRESS+i,u8key[i]);
	}
	// Print House Number
	LCD_voidSendCommand_4bitMode(lcd_Clear);
	LCD_voidGotoxy_4bitMode(6,LineOne);
	LCD_voidWriteString_4bitMode("22B1", 4);
	LCD_voidGotoxy_4bitMode(5,LineTwo);
	LCD_voidWriteString_4bitMode("------", 6);

	_delay_ms(100);
	//Fire an interrupt if the renter pressed the arrival button
	EXT_INTERRUPT_VID_ENABLE(EXT2);
	EXT2_VID_SET_CALL_BACK(ArrivalButton);

	//fire an interrupt if the renter pressed the entrance button
	EXT_INTERRUPT_VID_ENABLE(EXT1);
	EXT1_VID_SET_CALL_BACK(EntranceButton);

	Global_Interrupt_Enable();

	while(1){
		if(u8WelcomeInFlag){
			//VENTILATION SYSTEM
			//--------------------
			//	ADC_Start_ASYNC(Channel_A1);
			u16TempAnalogSignal = ((uint32)(ADC_Read_SYNCH(Channel_A1))*(REFERNCE_VOLTAGE))/(ADC_RESOLUTION);
			u16Temperature = u16TempAnalogSignal / LM1300_CONVERSION;

			// Turn On the Fan in case the potentiometer (Temperature) > 25c
			if(u16Temperature>= 250){
				DCM_voidRotateCCW();		//DC motor using PWM ON (fan)
			}
			else{
				DCM_voidStop();				//shut the fan off in case of working
			}

			//LIGHTNING SYSTEM
			//--------------------
			u16LightAnalogSignal = ((uint32)(ADC_Read_SYNCH(Channel_A0))*(REFERNCE_VOLTAGE))/(ADC_RESOLUTION);
			u16LightAnalogSignal = ((uint32)(u16LightAnalogSignal) * (255)) / (REFERNCE_VOLTAGE);
			TIMER0_voidSetOCRValue(u16LightAnalogSignal);
		}
		else{
			//do nth
		}
	}
}
void ArrivalButton(){
	uint8 u8ErrorDetected=0;
	uint8 u8PasswordSize = sizeof(u8InputPassword)/sizeof(u8InputPassword[0]);

	//Enable timer0 to save power
	TIM1_voidInit();
	TIM1_voidSetIcuRegValue(20000);
	TIM1_voidEnable(TIMER1_PRESCALER_8);

	//welcome message then ask renter to enter password
	LCD_voidSendCommand_4bitMode(lcd_Clear);
	LCD_voidGotoxy_4bitMode(5, LineOne);
	LCD_voidWriteString_4bitMode("WELCOME", 7);
	_delay_ms(1500);

	while(u8ErrorDetected <2){
		LCD_voidSendCommand_4bitMode(lcd_Clear);
		LCD_voidWriteString_4bitMode("Enter Password:", 15);
		LCD_voidGotoxy_4bitMode(0,LineTwo);

		// Enter password on keypad
		for(uint8 i=0;i<u8PasswordSize;){
			LCD_voidGotoxy_4bitMode(i, LineTwo);
			u8InputPassword[i] = KPD_u8GetKey();
			LCD_voidDisplayKeys(u8InputPassword, &i);  				//print password on LCD
			_delay_ms(200);
		}

		//error detection
		for(uint8 i=0; i<u8PasswordSize; i++){
			EEPROM_voidRead(EEPROM_START_ADDRESS+i, &u8EEPROMData[i]);
			u8Error[i] = PASS_u8ComparePassword(u8EEPROMData[i], u8InputPassword[i]);
		}



		//incorrect passwordu8EEPROMData
		for(uint8 i =0; i<5;i++){
			if(u8Error[i]==1){
				u8ErrorDetected++;
				break;
			}
			else {
				u8ErrorDetected=0;
			}
		}
		if(u8ErrorDetected){
			LCD_voidSendCommand_4bitMode(lcd_Clear);
			LCD_voidGotoxy_4bitMode(0, LineOne);
			LCD_voidWriteString_4bitMode("Wrong! Try Again", 16);
			UART_voidSendDataSynch(5);					// Count number of trials up
			_delay_ms(500);
		}

		else{
			LCD_voidSendCommand_4bitMode(lcd_Clear);
			LCD_voidGotoxy_4bitMode(0, LineOne);
			LCD_voidWriteString_4bitMode("****CORRECT****", 16);
			_delay_ms(500);
			//u8ErrorCounts=0
			UART_voidSendDataSynch(10);
			LCD_voidSendCommand_4bitMode(lcd_Clear);
			LCD_voidGotoxy_4bitMode(3, LineOne);
			LCD_voidWriteString_4bitMode("WELCOME IN", 11);
			u8WelcomeInFlag =1;

			for (u16ServoCounter = 750 ; u16ServoCounter<1624; u16ServoCounter++)		// Open the door
			{
				TIM1_voidSetCmpARegValue(u16ServoCounter);           //OCR1A
				_delay_ms(10);
			}
			DIO_voidWritePin(PORT_D, DIO_PIN_NUM_D7, DIO_HIGH);  						//Turn On the lights
			DIO_voidWritePin(PORT_B, DIO_PIN_NUM_B3, DIO_HIGH);
			break;
		}
	}

	if(u8ErrorDetected>=2){
		UART_voidSendDataSynch(3);
		LCD_voidSendCommand_4bitMode(lcd_Clear);
		LCD_voidGotoxy_4bitMode(4, LineOne);
		LCD_voidWriteString_4bitMode("INTRUDER", 8);
		_delay_ms(5000);

	}
	else{

	}
	//Enable timer0 to save power
	TIMER0_voidInit();
	TIMER0_voidEnable(TIMER0_PRESCALER_8);

}


void EntranceButton(void){
	for (u16ServoCounter =1624; u16ServoCounter>750;u16ServoCounter--)			// Close the door
	{
		TIM1_voidSetCmpARegValue(u16ServoCounter);
		_delay_ms(10);
	}
}

