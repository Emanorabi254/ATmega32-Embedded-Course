/*
 * Timer.c
 *
 * Created: 1/29/2025 1:28:55 PM
 * Author : Original
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "util/delay.h"
#include "TIMER0_Interface.h"
#include "GI_Interface.h"

int main(void)
{
	DIO_SetPinDirection(PORT_A,PIN0,PIN_OUTPUT);
	DIO_SetPinDirection(PORT_A,PIN1,PIN_OUTPUT);
	GI_EnabledOrDisabled(ENABLED);
	TIMER_Init();
	
    while (1) 
    {
	 
				DIO_SetPinValue(PORT_A,PIN1,PIN_HIGH);
				_delay_ms(2000);
					DIO_SetPinValue(PORT_A,PIN1,PIN_LOW);
					_delay_ms(2000);
		
	}

}