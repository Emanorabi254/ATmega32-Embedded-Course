/*
 * Timer_Interface.h
 *
 * Created: 1/29/2025 1:30:51 PM
 *  Author: Original
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER_Init();
void TIMER_Start(u8 Prescaler);
void TIMER_Disable();
void TIMER_SetCounterValue(u8 Value);

void TIMER_SetComapreMatchValue(u8 Value);

#endif /* TIMER_INTERFACE_H_ */