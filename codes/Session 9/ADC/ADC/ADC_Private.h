/*
 * ADC_Private.h
 *
 * Created: 1/28/2025 1:21:36 PM
 *  Author: Original
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define		ADMUX	 *((volatile u8*)0x27)
#define		ADMUX_ADLAR   5
#define		ADMUX_REFS0	  6
#define		ADMUX_REFS1   7


#define		ADCSRA	 *((volatile u8*)0x26)
#define		ADCSRA_ADPS0	0
#define		ADCSRA_ADPS0	1
#define		ADCSRA_ADPS0	2
#define		ADCSRA_ADIE		3

#define		ADC_OUTPUT		 *((volatile u16*)0x24)

#endif /* ADC_PRIVATE_H_ */