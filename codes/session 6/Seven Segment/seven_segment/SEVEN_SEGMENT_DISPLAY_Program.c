/*
 * SEVEN_SEGMENT_DISPLAY_Program.c
 *
 * Created: 1/25/2025 10:51:29 AM
 *  Author: Original
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "SEVEN_SEGMENT_DISPLAY_Interface.h"

void SSD_EnabeledDisabeled(SSD_t SevenObj, u8 Mode)
{
	if (SevenObj.type == COMMON_CATHODE)
	{
		if(Mode == ENABLED)
		{
			DIO_SetPinValue(SevenObj.CtrlPort,SevenObj.CtrlPin,PIN_LOW);
		}
		else if(Mode == DISABLED)
		{
			DIO_SetPinValue(SevenObj.CtrlPort,SevenObj.CtrlPin,PIN_HIGH);
		}
	}
	else if (SevenObj.type == COMMON_ANODE)
	{
		if(Mode == ENABLED)
		{
			DIO_SetPinValue(SevenObj.CtrlPort,SevenObj.CtrlPin,PIN_HIGH);
		}
		else if(Mode == DISABLED)
		{
			DIO_SetPinValue(SevenObj.CtrlPort,SevenObj.CtrlPin,PIN_LOW);
		}
	}
}

void SSD_DisplayNumber (SSD_t SevenObj, u8 Number)
{
	u8 SSD_arr[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	if (SevenObj.type == COMMON_CATHODE)
	{
		DIO_SetPortValue(SevenObj.PortData,SSD_arr[Number]);
	}
	else if (SevenObj.type == COMMON_ANODE)
	{
		DIO_SetPortValue(SevenObj.PortData,~SSD_arr[Number]);
	}
}