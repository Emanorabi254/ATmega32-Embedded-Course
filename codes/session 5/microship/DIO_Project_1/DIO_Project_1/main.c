/*
 * DIO_Project_1.c
 *
 * Created: 1/23/2025 10:32:01 AM
 * Author : Eman Orabi
 */ 

#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO_Interface.h"

int main(void)
{
	DIO_SetPinDirection(PORT_A,PIN0,PIN_OUTPUT);

    while (1) 
    {
		DIO_SetPinValue(PORT_A,PIN0,PIN_HIGH);
		_delay_ms(1000);
		DIO_SetPinValue(PORT_A,PIN0,PIN_LOW);
		_delay_ms(1000);
		
    }
}

