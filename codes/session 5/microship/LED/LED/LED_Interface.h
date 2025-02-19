/*
 * LED_Interface.h
 *
 * Created: 1/27/2025 4:04:47 PM
 *  Author: Original
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_ON     1
#define LED_OFF    0

void LED_Init(u8 PortLed,u8 PinLed);

void LED_On_Off(u8 PortLed,u8 PinLed,u8 LedState);
void LED_Toggle(u8 PortLed,u8 PinLed);

#endif /* LED_INTERFACE_H_ */