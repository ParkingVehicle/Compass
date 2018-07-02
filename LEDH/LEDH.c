/*
 * LEDH.c
 *
 *  Created on: Jun 27, 2018
 *      Author: NadaHasan
 */

#include "LED.h"
#include "LEDH.h"

LedStatusType LedStatusLocal;
void LEDH_Init(void)
{
	// init LEDS
		LED_INIT(RED);
		LED_INIT(YELLOW);
		LED_INIT(GREEN);

		// Turn Green LED ON on init
		LedStatusLocal.GreenSt=ON;

}

void LEDH_Cyclic5ms(void)
{
	Toggol_Yellow_LED();  // will only execute few times
	Update_LED_Status(); // will run forever
}

void Toggol_Yellow_LED(void)
{
	static uint8_t counter_time;
	static uint8_t NumberOfToggolsCount;
	if(counter_time == T200ms)
	{
		LedStatusLocal.YellowSt ^= 1;
		counter_time = reset;
		NumberOfToggolsCount ++;
	}
	if(NumberOfToggolsCount < NumberOfToggols)
	{
		counter_time++;
	}
}
void Update_LED_Status(void)
{
	if(LedStatusLocal.RedSt == ON)
		LED_ON(RED);
	else
		LED_OFF(RED);
	if(LedStatusLocal.GreenSt == ON)
		LED_ON(GREEN);
	else
		LED_OFF(GREEN);
	if(LedStatusLocal.YellowSt == ON)
		LED_ON(YELLOW);
	else
		LED_OFF(YELLOW);
}

void LEDH_setLEDStatus(LedStatusType *LEDStatus)
{

	LedStatusLocal.GreenSt = LEDStatus->GreenSt;
	LedStatusLocal.RedSt = LEDStatus->RedSt;
	LedStatusLocal.YellowSt = LEDStatus->YellowSt;

}

