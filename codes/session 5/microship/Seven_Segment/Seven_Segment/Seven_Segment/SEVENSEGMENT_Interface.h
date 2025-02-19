/*
 * SEVEN_SEGMENT.h
 *
 * Created: 1/23/2025 9:03:54 PM
 *  Author: Original
 */ 
#include "STD_TYPES.h"

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

void SEVENSEGMENT_Init(u8 Portname);
void SEVENSEGMENT_SetCommon(u8 Portname,u8 CommonChosen,u8 CountingChosen);

#define COMMON_ANODE       1
#define COMMON_CATHODE     0

#define COUNT_INCREASING   1
#define COUNR_DECREASING   0


#endif /* SEVEN_SEGMENT_H_ */