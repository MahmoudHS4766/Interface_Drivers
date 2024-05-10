/*
 * USART.c
 *
 * Created: 10/11/2023 11:42:57 AM
 *  Author: Mahmoud Hamdy
 */ 

#include "USART.h"

void UART_Init(unsigned short baud_rate)
{
	unsigned short UBRR;
	UBRR = (F_CPU/(16*baud_rate))-1;
	UBRRH = (unsigned char)UBRR>>8;
	UBRRL = (unsigned char)UBRR;
	
	UCSRB = (1<<RXEN) | (1<<TXEN);//Receiver enable, Transmitter enable
	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);//Enable UCSRC address, character size
}

void UART_SendData(char data)
{
	while(READ_BIT(UCSRA,UDRE)==0);//Wait for UDR transmit buffer to be empty
	UDR = data;//Put data in transmit buffer
}

char UART_ReceiveData(void)
{
	while(READ_BIT(UCSRA,RXC)==0);//Wait for UDR receive buffer to be filled with data
	//Return data available in receiver buffer
	return UDR;
}

void UART_SendString(char *ptr)
{
	while (*ptr != 0)
	{
		UART_SendData(*ptr);
		ptr++;
		_delay_ms(100);
	}
}

