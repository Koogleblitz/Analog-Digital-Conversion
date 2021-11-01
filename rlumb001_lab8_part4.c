/*	Author: Richard Tobing, rlumb001@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding timer.h or example
 *	code, is my own original work.
	
	Demo Link: 	https://www.youtube.com/watch?v=cgYLxkZsgwg
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif



//-------------------------------------------------ADC------------------------------------------//
void ADC_init() { ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE); }
//-------------------------------------------------/ADC------------------------------------------//







unsigned short x, my_short, halfMin;
unsigned char my_char, my_char_too,C;

unsigned long halfMax;

int main(void) {
	DDRA = 0x00; PORTA = 0xFF;   
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	ADC_init();
	


	while(1){
		if(ADC <= 45){ PORTB = 0; }
		else if(ADC <= 118 ){ PORTB =     1; } 
		else if(ADC <= (118*2)){ PORTB =  1+2; } 
		else if(ADC <= (118*3) ){ PORTB = 1+2+4; } 
		else if(ADC <= (118*4)){ PORTB =  1+2+4+8; } 
		else if(ADC <= (118*5)){ PORTB =  1+2+4+8+16; } 
		else if(ADC <= (118*6)){ PORTB =  1+2+4+8+16+32; } 
		else if(ADC <= (118*7)){ PORTB =  1+2+4+8+16+32+64; } 
		else{ PORTB = 0xFF; }
	}

    return 1;
}

