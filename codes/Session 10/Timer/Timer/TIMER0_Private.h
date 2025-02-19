/*
 * TIMER0_Private.h
 *
 * Created: 1/29/2025 1:33:52 PM
 *  Author: Original
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0       *((volatile  u8*) 0x53)
#define TCNT0       *((volatile  u8*) 0x52)
#define OCR0        *((volatile  u8*) 0x5C)
#define TIMSK       *((volatile  u8*) 0x59)
#define TIFR        *((volatile  u8*) 0x58)



#endif /* TIMER0_PRIVATE_H_ */