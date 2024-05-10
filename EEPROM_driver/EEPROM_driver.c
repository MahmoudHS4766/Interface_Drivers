/*
 * EEPROM_driver.c
 *
 * Created: 8/28/2023 4:45:45 PM
 *  Author: Mahmoud Hamdy
 */ 


#include "EEPROM_driver.h"

void EEPROM_write(const unsigned char address,unsigned char data)
{
	/*set up address register (can be EEAR=address)*/
	EEARL = (char) address;
	EEARH = (char) (address>>8);
	
	/*set up data register*/
	EEDR = data;
	
	SET_BIT(EECR,EEMWE);/*EEMWE=2*/
	
	SET_BIT(EECR,EEWE);/*EEWE=1*/
	
	/* wait for completion of write operation */
	while (READ_BIT(EECR,EEWE)==1);
}

unsigned char EEPROM_read(const unsigned char address)
{
	EEARL = (char) address;
	EEARH = (char) (address>>8);

	SET_BIT(EECR,EERE);/*EERE=0*/
	
	/*return data from data register*/
	return EEDR;	
}





