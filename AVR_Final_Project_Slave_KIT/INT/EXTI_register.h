/*
 * EXTI_register.h
 *
 *  Created on: Dec 17, 2023
 *      Author: Tasneem
 */

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define MCUCR     	*((volatile uint8*)(0x55))			//MCU Control Register
#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0


#define MCUCSR    	*((volatile uint8*)(0x54))			//MCU Control Status Register
#define ISC2 6


#define GIFR     	*((volatile uint8*)(0x5A))
#define INTF1 7
#define INTF0 6
#define INTF2 5


#define GICR      	*((volatile uint8*)(0x5B))			//General Interrupt Control Register
#define INT1 7
#define INT0 6
#define INT2 5


#endif /* EXTI_REGISTER_H_ */
