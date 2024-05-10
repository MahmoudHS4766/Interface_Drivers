/*
 * Button.c
 *
 * Created: 8/22/2023 1:49:49 AM
 *  Author: Mahmoud Hamdy
 */ 

#include "DIO.h"

void Button_Init(unsigned char port,unsigned char pinnum)
{
	DIO_setPIN_dir(port,pinnum,0);
}


unsigned char Button_readStatus(unsigned char port,unsigned char pinnum)
{
	return DIO_u8read(port,pinnum);
}