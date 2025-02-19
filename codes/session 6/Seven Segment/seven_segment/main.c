/*
 * Session_6.c
 *
 * Created: 1/25/2025 10:15:57 AM
 * Author : Original
 */ 

#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "SEVEN_SEGMENT_DISPLAY_Interface.h"

u8 main(void)
{

//create Obj from SSD_t as the configuration.

SSD_t MySSD={PORT_A,PORT_C,PIN0,COMMON_CATHODE};
	
//Direction of dataport and ctrlport --->output	
	DIO_SetPortDirection(PORT_A,PORT_OUTPUT);
	DIO_SetPinDirection(PORT_C,PIN0,PIN_OUTPUT);
	
	SSD_EnabeledDisabeled(MySSD,ENABLED);
    while (1) 
    {
		for(u8 i=0;i<10;i++)
		{
			SSD_DisplayNumber(MySSD,i);
			_delay_ms(1000);
		}
    }
}

