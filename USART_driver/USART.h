/*
 * USART.h
 *
 * Created: 10/11/2023 11:43:23 AM
 *  Author: Mahmoud Hamdy
 */ 


#ifndef USART_H_
#define USART_H_

#include <avr/io.h>
#include "std_macros.h"
#define F_CPU 8000000ul
#include <avr/delay.h>

/*Function description: Initialize USART in Asynchrounous mode*/
void UART_Init(unsigned short baud_rate);
/*Function description: Transmit u8data through Tx*/
void UART_SendData(char data);
/*Function description: Recieve u8data through Rx*/
char UART_ReceiveData(void);
/*Function description: Transmit string of data through Tx*/
void UART_SendString(char *ptr);


#endif /* USART_H_ */