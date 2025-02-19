/*
 * session_7.c
 *
 * Created: 1/26/2025 1:59:38 PM
 * Author : Original
 */ 

#include "DC_MOTOR_interface.h"
#include "util/delay.h"

int main(void)
{
DCM_Init();
    while (1) 
    {
		DCM_RotateCW();
		_delay_ms(2000);
		DCM_RotateCCW();
		_delay_ms(2000);
		DCM_Stop();
		_delay_ms(2000);
    }
}

