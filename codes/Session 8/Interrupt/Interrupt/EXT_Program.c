/*
 * EXT_Program.c
 *
 * Created: 1/27/2025 12:48:22 PM
 *  Author: Original
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"

void (*GlobalPtr0)(void)=NULL;	// Global Pointer To a Local Pointer To Function
void (*GlobalPtr1)(void)=NULL;
void (*GlobalPtr2)(void)=NULL;


void EXTI_EnabledOrDisable(u8 IntIdx,u8 IntState)
{
	switch(IntState)
	{
		case ENABLED:
		switch(IntIdx)
		{
			case INT0:
			SET_BIT(GICR,GICR_INT0);
			break;
			case INT1:
			SET_BIT(GICR,GICR_INT1);
			break;
			case INT2:
			SET_BIT(GICR,GICR_INT2);
			break;
		}
		break;
		
		case DISABLED:
		switch(IntIdx)
		{
			case INT0:
			CLR_BIT(GICR,GICR_INT0);
			break;
			case INT1:
			CLR_BIT(GICR,GICR_INT1);
			break;
			case INT2:
			CLR_BIT(GICR,GICR_INT2);
			break;
		}
		break;
	}
}
void EXTI_SetSenseCtrl(u8 IntIdx, u8 IntSense)
{
	switch(IntIdx)
	{
		case INT0:
		switch(IntSense)
		{
			case FALLING_EDGE:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC10);	
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC10);
			break;
			case LOGICAL_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC10);
			break;
			case LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC10);
			break;
		}
		break;
		case INT1:
		switch(IntSense)
		{
			case FALLING_EDGE:
			CLR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
			break;
			case LOGICAL_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
			break;
			case LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
			break;
		}
		break;
		case INT2:
		switch(IntSense)
		{
			case FALLING_EDGE:
			CLR_BIT(MCUSR,MCUSR_ISC2);
			break;
			case RISING_EDGE:
			SET_BIT(MCUSR,MCUSR_ISC2);
			break;
		}
		break;
	}
}

u8 EXTI_SetCallBack(u8 IntIdx,void(*PtrFunc)(void))  // Here The Pointer is a local pointer to function as we need the address of the function that will be written in the main.c
{
	u8 ErrorState=OK;
	if(PtrFunc !=NULL)
	{
		switch(IntIdx)
		{
			case INT0:
			GlobalPtr0=PtrFunc;   // here we move the local pointer to the global pointer 
			break;
			case INT1:
			GlobalPtr1=PtrFunc;
			break;
			case INT2:
			GlobalPtr2=PtrFunc;
			break;
		}
	}
	else
	{
		ErrorState=NOK;	
	}
	return ErrorState;
}

void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
	GlobalPtr0();
}


void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
	GlobalPtr1();
}


void __vector_3(void) __attribute__((signal));

void __vector_3(void)
{
	GlobalPtr2();
}