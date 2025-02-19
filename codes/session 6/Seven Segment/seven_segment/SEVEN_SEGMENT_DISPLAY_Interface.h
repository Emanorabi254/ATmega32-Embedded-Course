/*
 * SEVEN_SEGMENT_DISPLAY_Interface.h
 *
 * Created: 1/25/2025 10:50:48 AM
 *  Author: Original
 */ 


#ifndef SEVEN_SEGMENT_DISPLAY_INTERFACE_H_
#define SEVEN_SEGMENT_DISPLAY_INTERFACE_H_

#include "STD_TYPES.h"

typedef struct{
	u8 PortData;  // For the 7 pins of the seven segment and the decimal point of it
	u8 CtrlPort;   // For the common pin
	u8 CtrlPin;    // for the common pin
	u8 type;       // for the type of 7 segment if it common cathode or common anode 
	} SSD_t;

#define ENABLED          1
#define DISABLED         0

#define COMMON_ANODE     1
#define COMMON_CATHODE   0	

void SSD_EnabeledDisabeled(SSD_t SevenObj, u8 Mode);
void SSD_DisplayNumber (SSD_t SevenObj, u8 Number);


#endif /* SEVEN_SEGMENT_DISPLAY_INTERFACE_H_ */