/*
 * ADC_Interface.h
 *
 * Created: 1/28/2025 1:19:04 PM
 *  Author: Original
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



void ADC_Init(void);
u16 ADC_Convert(u8 ChannelIdx); // u16 ->For Returning 10bit Resolution


#endif /* ADC_INTERFACE_H_ */