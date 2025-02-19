/*
 * ADC.c
 *
 * Created: 1/28/2025 12:59:42 PM
 * Author : Original
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "CLCD_Interface.h"

int main(void)
{
	u16 DigReading;
	u16 AnalogValue;
	u8 TempValue;
	//Configure The PA0 Input For Analog value(ADC)
	DIO_SetPinDirection(PORT_A,PIN0,PIN_INPUT);
	// Configure LCD Pins ->output
	DIO_SetPortDirection(PORT_D,PORT_OUTPUT);
	// LCD bits Control
	DIO_SetPortDirection(PORT_C,0b00000111);
	ADC_Init();
	CLCD_Init();
    while (1) 
    {
		
		DigReading=ADC_Convert(0);
		AnalogValue=((u32)DigReading*5000)/1024;
		TempValue=AnalogValue/10;
		CLCD_SetPosition(0,0);
		CLCD_SendString("Temp is: ");
		CLCD_SetPosition(1,0);
	    CLCD_SendNumber(TempValue);
    }
}

