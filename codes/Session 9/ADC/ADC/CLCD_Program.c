/*
 * CLCD_Program.c
 *
 * Created: 1/25/2025 12:58:06 PM
 *  Author: Eman Orabi
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "util/delay.h"
#include "CLCD_Config.h"
#include "CLCD_Interface.h"

void CLCD_SendData(u8 Data)
{

	// RS -> HIGH
	DIO_SetPinValue(CTRL_PORT,RS,PIN_HIGH);
	// RW -> LOW
	DIO_SetPinValue(CTRL_PORT,RW,PIN_LOW);
	// DATA -> DATA_PORT
	DIO_SetPortValue(DATA_PORT,Data);
	// EN-> HIGH TO LOW
	DIO_SetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(CTRL_PORT,EN,PIN_LOW);	
}
void CLCD_SendCommond(u8 Command)
{
	
	// RS -> LOW
	DIO_SetPinValue(CTRL_PORT,RS,PIN_LOW);
	// RW -> LOW
	DIO_SetPinValue(CTRL_PORT,RW,PIN_LOW);
	// DATA -> DATA_PORT
	DIO_SetPortValue(DATA_PORT,Command);
	// EN-> HIGH TO LOW
	DIO_SetPinValue(CTRL_PORT,EN,PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(CTRL_PORT,EN,PIN_LOW);
}

void CLCD_Init(void)
{
	_delay_ms(40);
	CLCD_SendCommond(0x38);
	_delay_ms(1);
	CLCD_SendCommond(0x0F);
	_delay_ms(1);
	CLCD_SendCommond(0x01);  // Clear Screan;
	_delay_ms(2);
}

void CLCD_Clear(void)
{
	CLCD_SendCommond(0x01);  // Clear Screan;
	_delay_ms(2);
}
void CLCD_SendString(u8 *PtrToString)
{
	u8 i=0;	
	while(PtrToString[i] !='\0')
	{
		CLCD_SendData(PtrToString[i]);
		i++;
	}
}


void CLCD_SetPosition(u8 xPos, u8 yPos)
{
	u8 Location;
	switch(xPos)
	{
		case 0: Location= yPos;break;
		case 1: Location=yPos+0x40;break;
	}
	CLCD_SendCommond(Location+128);
}
void CLCD_SendNumber(u8 Num)
{
	char buffer[10]; 
	int i = 0;

	if (Num < 0) {
		CLCD_SendData('-');  // Send the negative sign 
		Num = -Num;          // Convert the negative into positive
	}
	// Convert the number into ascii
	do {
		buffer[i++] = (Num % 10) + '0'; // Convert the last digit into Ascii
		Num /= 10; 
	} while (Num > 0);
	// Print numbers in reverse order
	for (int j = i - 1; j >= 0; j--) {
		CLCD_SendData(buffer[j]);
	}
	
}
