/*
 * Timer.c
 *
 * Created: 9/25/2023 10:08:50 PM
 *  Author: Mahmoud Hamdy
 */ 
#include "Timer.h"

void TIMER0_CTC_Init_interrupt(void)
{
	//configure waveform generation mode
	SET_BIT(TCCR0,WGM01);
	
	//set OCR0 Value
	OCR0 = 80;
	
	//Configure prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//Enable interrupt 
	sei();
	SET_BIT(TIMSK,OCIE0);
	 
}

void TIMER0_wave_nonPWM(void)
{
	//set pin OC0 as output
	SET_BIT(DDRB,3);
	
	//configure waveform generation mode
	SET_BIT(TCCR0,WGM01);
	
	//configure OCn
	SET_BIT(TCCR0,COM00);
	
	//Configure prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//set OCRn value
	OCR0 = 64;
}

void TIMER0_wave_fastPWM(void)
{
	//set pin OC0 as output
	SET_BIT(DDRB,3);
	
	//configure waveform generation mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	//configure OCn, clear on compare match, set at bottom(OVF)
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
	//Configure prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//set OCRn value
	OCR0 = 64;	
}

void TIMER0_wave_phasecorrectPWM(void)
{
	//set pin OC0 as output
	SET_BIT(DDRB,3);
	
	//configure waveform generation mode
	SET_BIT(TCCR0,WGM00);
	
	//configure OCn, clear on compare match up-counting, set at compare match down-counting
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
	//Configure prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//set OCRn value
	OCR0 = 64;	
}

void TIMER2_OVERFLOW_Init_interrupt(void)
{
	//configure input clock, external oscillator 32.768kHz crystal
	SET_BIT(ASSR,AS2);
	
	//Configure prescaler
	SET_BIT(TCCR2,CS22);
	SET_BIT(TCCR2,CS20);
	
	//Enable interrupt
	sei();
	SET_BIT(TIMSK,TOIE2);
}

void TIMER1_wave_fastPWM(double m_sec)
{
	SET_BIT(DDRD,5);//set pin OCR1A as output
	
	//set wave generation mode / mode: 14, TOP: ICR1
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	
	ICR1 = 19999; //20ms TOP
	OCR1A = m_sec*1000;// changes ms to us
	
	//set clock select / prescaler:/8, 1000count:1ms
	SET_BIT(TCCR1B,CS11);
	
	//set compare output mode / Clear OCR1A on compare match, Set OCR1A at BOTTOM(non inverting mode)
	SET_BIT(TCCR1A,COM1A1);
}