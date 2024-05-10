/*
 * LED.c
 *
 * Created: 8/21/2023 5:30:11 PM
 *  Author: Mahmoud Hamdy
 */ 

#include "DIO.h"

void LED_Init(unsigned char port,unsigned char pinnum)
{
	DIO_setPIN_dir(port,pinnum,1);
}

void LED_turnON(unsigned char port,unsigned char pinnum) 
{
	DIO_writePIN(port,pinnum,1);
}

void LED_turnOFF(unsigned char port,unsigned char pinnum)
{
	DIO_writePIN(port,pinnum,0);
}

void LED_toggle(unsigned char port,unsigned char pinnum)
{
	DIO_togglePIN(port,pinnum);
}

unsigned char LED_readStatus(unsigned char port,unsigned char pinnum)
{
	return DIO_u8read(port,pinnum);
}
