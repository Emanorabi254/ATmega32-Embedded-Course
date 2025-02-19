/*
 * CLCD_Interface.h
 *
 * Created: 1/25/2025 12:57:43 PM
 *  Author: Original
 */ 


#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_SendData(u8 Data);
void CLCD_SendCommond(u8 Command);
void CLCD_Init(void);
void CLCD_Clear(void);
void CLCD_SendString(u8 *PtrToString);
void CLCD_SetPosition(u8 xPos, u8 yPos);
void CLCD_SendNumber(u8 Num);

#endif /* CLCD_INTERFACE_H_ */