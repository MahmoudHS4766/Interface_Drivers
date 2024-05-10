/*
 * I2C_driver.h
 *
 * Created: 2/5/2024 8:12:41 PM
 *  Author: mahmo
 */ 


#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include <avr/io.h>
#include "DIO.h"
#include "std_macros.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

void I2C_MasterInit(unsigned long SCL_frequency);
void I2C_StartCondtion(void);
void I2C_StopCondtion(void);
void I2C_RepeatedStart(void);

/*MASTER transmitter / Slave receiver
*MS 7 bits are address, bit0 --> 0 for write operation
*receive ACK*/
void I2C_SLA_plusWrite(unsigned char SLA_W);

/*MASTER receiver / Slave transmitter
*MS 7 bits are address, bit0 --> 1 for read operation
*receive ACK*/
void I2C_SLA_plusRead(unsigned char SLA_R);

/*MASTER transmitter / Slave receiver
*Transmit 8bit data
*receive ACK*/
void I2C_WriteData(unsigned char data);

/*Each chip defined by given Address*/
void I2C_SetAddress(unsigned char address);

/*MASTER transmitter / Slave receiver
*Receive 8bit data
*respond ACK*/
unsigned char I2C_SlaveRead(void);

/*MASTER receiver / Slave transmitter
*Receive 8 bit data
*respond ACK*/
unsigned char I2C_ACK_MasterRead(void);

/*MASTER receiver / Slave transmitter
*Receive 8 bit data
*respond NON ACK*/
unsigned char I2C_NACK_MasterRead(void);


#endif /* I2C_DRIVER_H_ */