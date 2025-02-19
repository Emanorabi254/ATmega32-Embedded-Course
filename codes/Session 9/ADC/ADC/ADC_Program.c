/*
 * ADC_Program.c
 *
 * Created: 1/28/2025 1:18:45 PM
 *  Author: Original
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"


void ADC_Init(void)
{
	//Bits of Control Register
	
	// Polling ->no interrupt,no SIE 
	CLR_BIT(ADCSRA,3);	//ADIE->0
	// Clear ADLAR to Read 10 bit
	CLR_BIT(ADMUX,5);	// ADLAR->0	
	// refrence selection  =AVCC
	SET_BIT(ADMUX,6);   //REFS0
	CLR_BIT(ADMUX,7);	//REFS1
	//Prescaler /64
	CLR_BIT(ADCSRA,0);  //ADPS0
	SET_BIT(ADCSRA,1);	//ADPS1
	SET_BIT(ADCSRA,2);	//ADPS2
	//Enable ADC
	SET_BIT(ADCSRA,7);  //ADEN
	
}
u16 ADC_Convert(u8 ChannelIdx)
{
	// Select Required Channel
	ADMUX &=0b11100000;
	ADMUX|=ChannelIdx; 
	//Start Conversion
	SET_BIT(ADCSRA,6); // ADSC
	//Polling till the flag is rasied
	while(GET_BIT(ADCSRA,4)==0); //ADIF
	//clear Flag
	SET_BIT(ADCSRA,4);  //ADIF--> here is cleares by writing logical 1 on the flag
	return ADC_OUTPUT;
}
