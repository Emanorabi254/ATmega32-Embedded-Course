/*
 * SEVENSEGMENT_Program.c
 *
 * Created: 1/23/2025 9:05:01 PM
 *  Author: Original
 */ 

#include "util/delay.h"
#include "SEVENSEGMENT_Interface.h"
#include "DIO_Interface.h"
#include "STD_TYPES.h"


void SEVENSEGMENT_Init(u8 Portname)
{
	DIO_SetPortDirection(Portname,PORT_OUTPUT);
}

void SEVENSEGMENT_SetCommon(u8 Portname,u8 CommonChosen,u8 CountingChosen)
{
	u8 COMMON_ANODE_Value[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
	u8 COMMON_CATHODE_Value[]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
		
	while(1)
	{	
		if (CountingChosen==COUNT_INCREASING)
		{		
			for(u8 LoopIndex=0;LoopIndex<10;LoopIndex++)
			{
				if (CommonChosen == COMMON_ANODE)
				{
					DIO_SetPortValue(Portname, COMMON_ANODE_Value[LoopIndex]);
				}
				else if (CommonChosen == COMMON_CATHODE)
				{
					DIO_SetPortValue(Portname, COMMON_CATHODE_Value[LoopIndex]);
				}

				_delay_ms(500);
			}
		}
		else if(CountingChosen==COUNR_DECREASING)
		{
			for(u8 LoopIndex=9;LoopIndex>=0;LoopIndex--)
			{
				if (CommonChosen == COMMON_ANODE)
				{
					DIO_SetPortValue(Portname, COMMON_ANODE_Value[LoopIndex]);
				}
				else if (CommonChosen == COMMON_CATHODE)
				{
					DIO_SetPortValue(Portname, COMMON_CATHODE_Value[LoopIndex]);
				}

				_delay_ms(500);
			}
		}
	}
}