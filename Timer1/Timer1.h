/*
 * Timer1.h
 *
 *  Created on: Mar 7, 2018
 *      Author: Aser
 */

#ifndef SRC_TIMER1_TIMER1_H_
#define SRC_TIMER1_TIMER1_H_

#ifdef _TIMER1_FILE_
	volatile uint8 ev_5ms;
#else
	extern volatile uint8 ev_5ms;
#endif
void Timer1_init(void);

#endif /* SRC_TIMER1_TIMER1_H_ */
