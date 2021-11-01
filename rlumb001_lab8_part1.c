/*	Author: Richard Tobing, rlumb001@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding timer.h or example
 *	code, is my own original work.
	
	Demo Link: https://www.youtube.com/watch?v=GqK4LcCik08
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif



//-------------------------------------------------ADC------------------------------------------//
void ADC_init() {
ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}
//-------------------------------------------------/ADC------------------------------------------//
unsigned short x, my_short;
unsigned char my_char, my_char_too;



int main(void) {
	DDRA = 0x00; PORTA = 0xFF;   
	DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;
	ADC_init();



	while(1){
		x = ADC;
		my_char = (char)x;
		my_char_too = (char)(x >> 8);
		PORTB = my_char;
		PORTD = my_char_too;

	}

    return 1;
}
