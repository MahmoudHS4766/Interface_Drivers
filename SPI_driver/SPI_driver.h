/*
 * SPI_driver.h
 *
 * Created: 1/26/2024 10:41:38 AM
 *  Author: Mahmoud Hamdy
 */ 


#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include <avr/io.h>
#include "DIO.h"
#include "std_macros.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
unsigned char SPI_MasterTransmitChar(unsigned char Data);
unsigned char SPI_SlaveRecieveChar(unsigned char Data);
void SPI_MasterTransmitString(unsigned char *str);


#endif /* SPI_DRIVER_H_ */