/*
 * Seven_Segment.c
 *
 * Created: 1/23/2025 9:02:11 PM
 * Author : Eman Orabi
 */ 

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "SEVENSEGMENT_Interface.h"

int main(void)
{
    /* Replace with your application code */
	SEVENSEGMENT_Init(PORTA);
	SEVENSEGMENT_Init(PORTC);
    while (1) 
    {
		SEVENSEGMENT_SetCommon(PORTA,COMMON_ANODE,COUNT_INCREASING);
		SEVENSEGMENT_SetCommon(PORTC,COMMON_CATHODE,COUNR_DECREASING);
    }
}

