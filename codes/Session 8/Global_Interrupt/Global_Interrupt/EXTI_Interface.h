/*
 * EXTI_Interface.h
 *
 * Created: 1/27/2025 12:47:31 PM
 *  Author: Original
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define		INT0			0
#define		INT1			1
#define		INT2			2

#define		ENABLED			1
#define		DISABLED		0

#define     FALLING_EDGE    0
#define		RISING_EDGE		1
#define		LOGICAL_CHANGE  2
#define		LOW_LEVEL		3

void EXTI_EnabledOrDisable(u8 IntIdx,u8 IntState);
void EXTI_SetSenseCtrl(u8 IntIdx, u8 IntSense);

u8 EXTI_SetCallBack(u8 IntIdx,void(*PtrFunc)(void));


#endif /* EXTI_INTERFACE_H_ */