/*
 * DIO_private.h
 *
 *  Created on: Dec 10, 2023
 *      Author: Tasneem
 */
/* Access Denied, User!*/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define  CONCAT(b7,b6,b5,b4,b3,b2,b1,b0)       CONCAT_2(b7,b6,b5,b4,b3,b2,b1,b0)	//to prevent adding A7A6A5A4A3A2A1A0
#define  CONCAT_2(b7,b6,b5,b4,b3,b2,b1,b0)     0b##b7##b6##b5##b4##b3##b2##b1##b0	//instead their values will be added




/* input or output */
#define DDRA      *( (volatile  uint8*) 0x3A)
#define DDRB      *( (volatile  uint8*) 0x37)
#define DDRC      *( (volatile  uint8*) 0x34)
#define DDRD      *( (volatile  uint8*) 0x31)
/* write high or low output */
#define PORTA     *( (volatile  uint8*) 0x3B)
#define PORTB     *( (volatile  uint8*) 0x38)
#define PORTC     *( (volatile  uint8*) 0x35)
#define PORTD     *( (volatile  uint8*) 0x32)
/* read high or low input */
#define PINA      *( (volatile  uint8*) 0x39)
#define PINB      *( (volatile  uint8*) 0x36)
#define PINC      *( (volatile  uint8*) 0x33)
#define PIND      *( (volatile  uint8*) 0x30)








#endif /* DIO_PRIVATE_H_ */
