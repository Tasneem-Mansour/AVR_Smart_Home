/*
 * TIMER0_private.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Tasneem
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_


#define NORMAL_MODE         1
#define CTC_MODE            2
#define FAST_PWM            3
#define PHASE_COEERCT_PWM   4

#define CLEAR_OC0           5
#define SET_OC0             6
#define TOGGLE_OC0          7


#define INVERTING_FAST_PWM                       1
#define NON_INVERTING_FAST_PWM                   2
#define INVERTING_PHASE_CORRECT_PWM              3
#define NON_INVERTING_PHASE_CORRECT_PWM          4

#define DISCONNECT_OC0                           0



#define TCCR0       *((volatile  uint8*) 0x53)
#define TCNT0       *((volatile  uint8*) 0x52)
#define OCR0        *((volatile  uint8*) 0x5C)
#define TIMSK       *((volatile  uint8*) 0x59)
#define TIFR        *((volatile  uint8*) 0x58)


#endif /* TIMER0_PRIVATE_H_ */
