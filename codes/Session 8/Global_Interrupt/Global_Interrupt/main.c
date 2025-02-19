/*
 * Global_Interrupt.c
 *
 * Created: 1/27/2025 1:29:37 PM
 * Author: Original
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_Interface.h"
#include "LED_Interface.h"
#include "GI_Interface.h"
#include "EXTI_Interface.h"

void Func();
int main(void)
{
	DIO_SetPinDirection(PORT_B,PIN2,PIN_INPUT);
	DIO_SetPinValue(PORT_B,PIN2,PIN_HIGH);
	LED_Init(PORT_A,PIN0);
	GI_EnabledOrDisabled(ENABLED);
	EXTI_EnabledOrDisable(INT2,ENABLED);
	EXTI_SetSenseCtrl(INT2,FALLING_EDGE);
	EXTI_SetCallBack(INT2,Func);
	
    while (1) 
    {
    }
}


/* ISR By Using The Callback  */
void Func(void)
{
	LED_Toggle(PORT_A,PIN0);
}
