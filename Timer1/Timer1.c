/*
 * Timer1.c
 *
 *  Created on: Mar 7, 2018
 *      Author: Aser
 */

#define _TIMER1_FILE_
#include <avr/io.h>
#include <avr/interrupt.h>
#include "common.h"
#include "Timer1.h"
#include "STKPRNT.h"




ISR (TIMER1_OVF_vect)    // Timer1 ISR
{

	//PORTD ^= (1 << 5);
	TCNT1 = 65536-((5000*(F_CPU/1000000))/64); // wait for 5ms timer ticks


		EVENT_SET(ev_5ms);


}
void Timer1_init(void)
{
	 TCNT1 = 65536-((5000*(F_CPU/1000000))/64);;   // for 5 ms at F_CPU MHz

		TCCR1A = 0x00;
		TCCR1B = (1<<CS10) | (1<<CS11);;  // Timer mode with 64 prescler
		TIMSK = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
		sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
}
