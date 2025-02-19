/*
 * LED_Program.c
 *
 * Created: 1/27/2025 4:05:24 PM
 *  Author: Original
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "LED_Config.h"
#include "LED_Interface.h"
#include "util/delay.h"

void LED_Init(u8 PortLed,u8 PinLed)
{
	DIO_SetPinDirection(PortLed,PinLed,PIN_OUTPUT);
}
void LED_On_Off(u8 PortLed,u8 PinLed,u8 LedState)
{
	switch(LedState)
	{
		case LED_ON:
		DIO_SetPinValue(PortLed,PinLed,PIN_HIGH);
		break;
		case LED_OFF:
		DIO_SetPinValue(PortLed,PinLed,PIN_LOW);
		break;
	}
}
void LED_Toggle(u8 PortLed,u8 PinLed)
{
	DIO_SetPinValue(PortLed,PinLed,PIN_HIGH);
	_delay_ms(2000);
	DIO_SetPinValue(PortLed,PinLed,PIN_LOW);
}