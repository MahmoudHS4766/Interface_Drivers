/*
 * ADC_driver.h
 *
 * Created: 9/19/2023 7:04:23 PM
 *  Author: Mahmoud Hamdy
 */ 


#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <avr/io.h>
#include "std_macros.h"

void ADC_Init();
unsigned short ADC_u16Read(void);


#endif /* ADC_DRIVER_H_ */