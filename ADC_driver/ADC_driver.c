/*
 * ADC_driver.c
 *
 * Created: 9/19/2023 7:04:02 PM
 *  Author: Mahmoud Hamdy
 */ 

#include "ADC_driver.h"

void ADC_Init()
{
	SET_BIT(ADMUX,REFS0);//configure VREF
	SET_BIT(ADCSRA,ADSC);//enable ADC
	/*
	select pin for MUX
	SET_BIT(ADMUX,MUX0);
	SET_BIT(ADMUX,MUX1);
	SET_BIT(ADMUX,MUX2);
	*/
	
	//Adjust ADC clock
	SET_BIT(ADMUX,ADPS1);
	SET_BIT(ADMUX,ADPS2);
}

unsigned short ADC_u16Read(void)
{
	unsigned short return_val;
	
	SET_BIT(ADCSRA,ADSC);//enable ADC
	while(READ_BIT(ADCSRA,ADSC)==1);//wait for conversion

	return_val = ADCL;
	return_val |= ADCH<<8;
	return return_val;
	
}