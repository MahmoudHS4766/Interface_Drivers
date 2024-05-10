/*
 * EEPROM_driver.h
 *
 * Created: 8/28/2023 4:46:02 PM
 *  Author: Mahmoud Hamdy
 */ 


#ifndef EEPROM_DRIVER_H_
#define EEPROM_DRIVER_H_

#include <avr/io.h>
#include "std_macros.h"
/*
Function Description : Write one byte to the given address(10 bit address).
*/
void EEPROM_write(const unsigned char address,unsigned char data);


/*
Function Description : Read one byte to the given address.
*/
char EEPROM_read(const unsigned char address);


#endif /* EEPROM_DRIVER_H_ */