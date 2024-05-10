/*
 * SPI_driver.c
 *
 * Created: 1/26/2024 10:41:19 AM
 *  Author: Mahmoud Hamdy
 */ 

#include "SPI_driver.h"

void SPI_MasterInit(void)
{
	DIO_setPINdir('B',4,1);//SS
	DIO_setPINdir('B',5,1);//MOSI
	DIO_setPINdir('B',7,1);//SCK
	
	SET_BIT(SPCR,MSTR);
	SET_BIT(SPCR,SPR0);//Fosc/16
	SET_BIT(SPCR,SPE);
	
	DIO_writePIN('B',4,1);//slave is not activated
}

void SPI_SlaveInit(void)
{
	DIO_setPINdir('B',6,1);//MISO
	
	SET_BIT(SPCR,SPE);
}

unsigned char SPI_MasterTransmitChar(unsigned char Data)
{
	DIO_writePIN('B',4,0);//activate slave
	
	SPDR = Data;
	while (READ_BIT(SPSR,SPIF)==0);
	
	return SPDR;
}

unsigned char SPI_SlaveRecieveChar(unsigned char Data)
{
	SPDR = Data;
	while (READ_BIT(SPSR,SPIF)==0);
	
	return SPDR;	
}

void SPI_MasterTransmitString(unsigned char *str)
{
	DIO_writePIN('B',4,0);//activate slave
	while (*str!=0)
	{
		SPI_MasterTransmitChar(*str);
		_delay_ms(300);
		str++; 
	}
}


