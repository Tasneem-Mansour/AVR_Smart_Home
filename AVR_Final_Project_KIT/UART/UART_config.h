/*
 * UART_config.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Tasneem
 */

/******* UCSRB BITS ********/
#define		UCSRB_RXCIE		7
#define		UCSRB_TXCIE		6
#define     UCSRB_UDRIE		5
#define		UCSRB_RXEN		4
#define     UCSRB_TXEN		3
#define     UCSRB_UCSZ2		2
#define     UCSRB_RXB8		1
#define     UCSRB_TXB8		0


/******* UCSRC BITS ********/
#define		UCSRC_URSEL		7
#define		UCSRC_UMSEL		6
#define		UCSRC_UPM1 		5
#define		UCSRC_UPM0 		4
#define		UCSRC_USBS 		3
#define		UCSRC_UCSZ1		2
#define		UCSRC_UCSZ0 	1
#define		UCSRC_UCPOL		0



#define     BAUD_RATE		BAUD_9600
