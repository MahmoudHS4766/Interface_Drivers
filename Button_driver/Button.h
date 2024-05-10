/*
 * Button.h
 *
 * Created: 8/22/2023 1:54:31 AM
 *  Author: Mahmoud Hamdy
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


/*
Function Description : define the given pin in the given port as input pin
*/
void Button_Init(unsigned char port,unsigned char pinnum);


/*
Function Description : Returns 0 or 1 depend on the status of the button(pressed or not)
and the type of connection (pull up or pull down)
*/
unsigned char Button_readStatus(unsigned char port,unsigned char pinnum);


#endif /* BUTTON_H_ */