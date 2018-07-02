/*
 * LEDH.h
 *
 *  Created on: Jun 27, 2018
 *      Author: NadaHasan
 */

#ifndef LEDH_LEDH_H_
#define LEDH_LEDH_H_
#include "common.h"
//wait 200ms by looping 40 times (5 * 40) = 200ms

#define reset  0
#define NumberOfToggols 10

typedef struct LedStatusStruct{
	uint8_t GreenSt :1;
	uint8_t RedSt  :1;
	uint8_t YellowSt :1;
}LedStatusType;


void LEDH_Cyclic5ms(void);
void LEDH_Init(void);
void Toggol_Yellow_LED(void);
void Update_LED_Status(void);
void LEDH_setLEDStatus(LedStatusType *LEDStatus);

#endif /* LEDH_LEDH_H_ */
