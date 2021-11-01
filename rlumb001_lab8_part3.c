/*	Author: Richard Tobing, rlumb001@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding timer.h or example
 *	code, is my own original work.
	
	Demo Link: 	https://www.youtube.com/watch?v=v7EhU1Y-mHo
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
	halfMax = 472;	//max = 945
	


	while(1){
		x = ADC;                         // ADC is a 10-bit number, we store it in an unsigned short
		my_char = (char)x;		 // this coverts the 10-bit adc into 8bits, and stores it in a char so it can be assigned to PORTB's 8 pins
		my_char_too = (char)(x >> 8);	 // the ADC's remaining 2 bits are stored in a seperate char, which will be assigned to PORTD. 
		


		/*Here, halfMax is a 9-bit number, if we were to compare it to my_char, the light will never tutrn on because my_char can only hold 8 bits, thus, it will always be 			less that halfMax, we have to compare halfMax directly with the raw ADC*/

		if(ADC >= halfMax){ PORTC = 1; } 
		else{ PORTC = 0; }

	}

    return 1;
}

