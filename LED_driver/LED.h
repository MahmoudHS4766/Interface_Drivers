/*
 * LED.h
 *
 * Created: 8/21/2023 5:30:49 PM
 *  Author: Mahmoud Hamdy
 */ 


#ifndef LED_H_
#define LED_H_

/*
Function Description : Initialize the pin as an output
pin to connect the led.
*/
void LED_Init(unsigned char port,unsigned char pinnum);


/*
Function Description : Turn on the led connected
to the given pin and port.
*/
void LED_turnON(unsigned char port,unsigned char pinnum);


/*
Function Description : Turn off the led connected
to the given pin and port.
*/
void LED_turnOFF(unsigned char port,unsigned char pinnum);


/*
Function Description : Toggle the led connected
to the given pin and port.
*/
void LED_toggle(unsigned char port,unsigned char pinnum);


/*
Function Description : Read the status of the led connected
to the given pin and port.
*/
unsigned char LED_readStatus(unsigned char port,unsigned char pinnum);

#endif /* LED_H_ */