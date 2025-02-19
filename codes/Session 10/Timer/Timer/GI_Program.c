/*
 * GI_Program.c
 *
 * Created: 1/27/2025 1:30:14 PM
 *  Author: Original
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GI_Interface.h"
#include "GI_Private.h"

void GI_EnabledOrDisabled(u8 GI_State)
{
	switch(GI_State)
	{
		case ENABLED:
		SET_BIT(SREG,SREG_I);
		break;
		
		case DISABLED:
		CLR_BIT(SREG,SREG_I);
		break;
	}
}