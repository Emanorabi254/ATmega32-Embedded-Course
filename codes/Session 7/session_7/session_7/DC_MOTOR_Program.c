/*
 * DC_MOTOR_Program.c
 *
 * Created: 1/26/2025 3:47:58 PM
 *  Author: Original
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "DC_MOTOR_Config.h"
#include "DC_MOTOR_interface.h"

void DCM_Init(void)
{
	DIO_SetPinDirection(DCM_PORT,DCM_PIN0,PIN_OUTPUT);
	DIO_SetPinDirection(DCM_PORT,DCM_PIN1,PIN_OUTPUT);
}
void DCM_RotateCW(void)
{
	DIO_SetPinValue(DCM_PORT,DCM_PIN0,PIN_LOW);
	DIO_SetPinValue(DCM_PORT,DCM_PIN1,PIN_HIGH);
}
void DCM_RotateCCW(void)
{
	DIO_SetPinValue(DCM_PORT,DCM_PIN0,PIN_HIGH);
	DIO_SetPinValue(DCM_PORT,DCM_PIN1,PIN_LOW);
}
void DCM_Stop(void)
{
	DIO_SetPinValue(DCM_PORT,DCM_PIN0,PIN_LOW);
	DIO_SetPinValue(DCM_PORT,DCM_PIN1,PIN_LOW);	
}