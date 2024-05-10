/*
 * I2C_driver.c
 *
 * Created: 2/5/2024 8:12:29 PM
 *  Author: Mahmoud Hamdy
 */ 
#include "I2C_driver.h"
#define prescaler 1 // prescaler : 1, 4, 16, or 64
void I2C_MasterInit(unsigned long SCL_frequency)
{
	TWBR = ((F_CPU/SCL_frequency)-16) / (2*prescaler);
	
	if (prescaler == 1)
	{
		TWSR = 0;
	} 
	else if (prescaler == 4)
	{
		TWSR = 1;
	}
	else if (prescaler == 16)
	{
		TWSR = 2;
	}
	else if (prescaler == 64)
	{
		TWSR = 3;
	}
}


void I2C_StartCondtion(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0xF8) != 0x08);
}

void I2C_RepeatedStart(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while (READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0xF8) != 0x10);
}

void I2C_StopCondtion(void)
{
	TWCR = (1<<TWINT) |(1<<TWEN)| (1<<TWSTO);
}

void I2C_SetAddress(unsigned char address)
{
	TWAR = address;
}

//MASTER transmitter / Slave receiver
void I2C_SLA_plusWrite(unsigned char SLA_W)
{
	TWDR = SLA_W;
	TWCR |= (1<<TWINT);
	while (READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0xF8) != 0x18);	 
}

//MASTER receiver / Slave transmitter
void I2C_SLA_plusRead(unsigned char SLA_R)
{
	TWDR = SLA_R;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0xF8) != 0x40);
}

//MASTER transmitter / Slave receiver
void I2C_WriteData(unsigned char data)
{
	TWDR = data;
	TWCR |= (1<<TWINT);
	while (READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0xF8) != 0x28);
}

//MASTER transmitter / Slave receiver
unsigned char I2C_SlaveRead(void)
{
	TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	while (READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0xF8) != 0x60);	
	TWCR |= (1<<TWINT);
	while (READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0xF8) != 0x80);
	return TWDR;
}

//MASTER receiver / Slave transmitter / receive data respond with ACK
unsigned char I2C_ACK_MasterRead(void)
{
	TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
	while (READ_BIT(TWCR,TWINT)==0);
	while ((TWSR & 0xF8) != 0x50);
	return TWDR;
}

//MASTER receiver / Slave transmitter / receive data respond with NO ACK
unsigned char I2C_NACK_MasterRead(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (READ_BIT(TWCR,TWINT)==0);
	//while ((TWSR & 0xF8) != 0x58);
	return TWDR;	
}



