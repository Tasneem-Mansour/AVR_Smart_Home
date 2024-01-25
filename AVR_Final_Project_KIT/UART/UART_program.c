/*
 * UART_program.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Tasneem
 */
#include "../STD_Types.h"
#include "../BIT_Math.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"
#include "util/delay.h"

volatile uint8 u8Global_Data;
volatile uint8 u8Global_Receive;

void UART_voidInit(void){
	uint8 u8Local_temp = 0;

	/* enable RXCIE, RX Complete Interrupt Enable */
	SET_BIT(UCSRB, UCSRB_RXCIE);
	/* Enable UDRIE, Data Register Empty Interrupt Enable */
	SET_BIT(UCSRB, UCSRB_UDRIE);

	/* Select 8-bit data (character size) */
	CLR_BIT(UCSRB, UCSRB_UCSZ2);

	/*************** Select UCSRC register ********************/
	SET_BIT(u8Local_temp, UCSRC_URSEL);
	SET_BIT(u8Local_temp, UCSRC_UCSZ0);
	SET_BIT(u8Local_temp, UCSRC_UCSZ1);

	/* Select UART mode */
	CLR_BIT(u8Local_temp, UCSRC_UMSEL);     //Asynchronous Operation
	/* Select parity mode */				//disable parity bits
	CLR_BIT(u8Local_temp, UCSRC_UPM0);
	CLR_BIT(u8Local_temp, UCSRC_UPM1);
	/* Select stop bit */
	CLR_BIT(u8Local_temp, UCSRC_USBS);      //1 stop bit
	/**********************************************************/

	/* Select BaudRate = 9600 */
	UBRRL = BAUD_RATE;

	/* Enable RXEN */
	SET_BIT(UCSRB, UCSRB_RXEN);
	/* Enable TXEN */
	SET_BIT(UCSRB, UCSRB_TXEN);

	/**********************************************************/
	UCSRC = u8Local_temp;
}

void UART_voidSendDataAsynch(const uint8 u8DataCpy){
	u8Global_Data = u8DataCpy;
	//UDR = u8DataCpy
}
void UART_voidSendDataSynch(const uint8 u8DataCpy){
	while ((UCSRA & 0x20) == 0x00);
	UDR = u8DataCpy;
}

uint8 UART_u8ReceiveData(void){

//	uint8 Result;
	// Wait until Reception Complete
	while((UCSRA & 0x80) == 0x00);
//	Result = UDR;
	return UDR;


}
void UART_voidSendstring(uint8 *ptr)
{
	while(*ptr!=0)
	{
		UART_voidSendDataSynch(*ptr);
		ptr++;
		_delay_ms(100);
	}
}



// __attribute__ -> communicate with LINKER, to not to optimize it
//  USART, RXC, Rx Complete
void __vector_13 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_13 (void)
{
	UDR = u8Global_Data;
}

//USART, TXC, Tx Complete
void __vector_15 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_15 (void)
{

}

//USART, UDRE, Data Register Empty
void __vector_14 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_14 (void)
{
	UART_voidSendDataAsynch(u8Global_Data);
}
