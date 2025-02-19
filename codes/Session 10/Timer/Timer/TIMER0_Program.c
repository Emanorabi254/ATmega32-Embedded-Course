/*
 * TIMER0_Program.c
 *
 * Created: 1/29/2025 1:34:17 PM
 *  Author: Original
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "TIMER0_Private.h"
#include "TIMER0_Interface.h"

void TIMER_Init()
{
	//set mode-->normal ,set clock ---> prescaler
	CLR_BIT(TCCR0,3);  // WGMO1
	CLR_BIT(TCCR0,6);  // WGM00
	//set prescaler --> /8
	CLR_BIT(TCCR0,0); //CS00
	SET_BIT(TCCR0,1); //CS01
	CLR_BIT(TCCR0,2); //CS02
	// Enable Interrupt overflow
	SET_BIT(TIMSK,0);
	// Enable Interrupt Compare Match
	SET_BIT(TIMSK,1);
}
void TIMER_Start(u8 Prescaler)
{
	TCCR0 &=0xFC;
	TCCR0 |=Prescaler;
}
void TIMER_Disable()
{
	CLR_BIT(TCCR0,0); //CS00
	CLR_BIT(TCCR0,1); //CS01
	CLR_BIT(TCCR0,2); //CS02
}
void TIMER_SetCounterValue(u8 Value)
{
	TCNT0=Value;
}
void TIMER_SetComapreMatchValue(u8 Value)
{
	OCR0=Value;
}










//compare match
void __vector__10 (void)   __attribute__ ((signal));
void __vector__10 (void)
{
	
}
// overflow
void __vector__11 (void)   __attribute__ ((signal));
void __vector__11 (void)
{
	static u8 Flag=0;
	static u16 Counter=0;
	if(Flag==0)
	{
		if(Counter == 3921)
		{
			DIO_SetPinValue(PORT_A,PIN0,PIN_HIGH);
			Counter=0;
			Flag=1;
		}
	}
	else if(Flag==1)
	{
		if(Counter == 3921)
		{
			DIO_SetPinValue(PORT_A,PIN0,PIN_LOW);
			Counter=0;
			Flag=0;
		}
	}
			
		
		Counter++;
}