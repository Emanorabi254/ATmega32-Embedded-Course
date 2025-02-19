/*
 * LCD.c
 *
 * Created: 1/25/2025 12:56:18 PM
 * Author : Original
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "CLCD_Interface.h"

void main(void)
{
    DIO_SetPortDirection(PORT_A,PORT_OUTPUT);
	DIO_SetPortDirection(PORT_C,0x07);
	CLCD_Init();
	CLCD_SendString("Eman Orabi *_*");
	CLCD_SetPosition(1,2);
	CLCD_SendString("YOur Fav Eng");
	while (1) 
    {
    }
}

