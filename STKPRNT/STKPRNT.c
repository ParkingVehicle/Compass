/*
 * STKPRNT.c
 *
 *  Created on: Mar 7, 2018
 *      Author: Aser
 */
/////////////   STKPRNT includes and local declarations //////////////////
#define _STKPRNT_FILE_
#include "common.h"
#include "STACK.h"
#include "STKPRNT.h"
#include "UART_Drive.h"


static char SerialStack[STACKMAX];
static char *StackPointerFront = SerialStack;
static char *StackPointerRear = SerialStack;


//////////////// STKPRNT init functions //////////
void STKPRNT_init(void)
{
	//initialize USART with 9600 BaudRate
	USART_Init(51);
}
//////////////// STKPRNT Runnables ///////////////
void STKPRNT_5ms(void)
{
	if((!isStackEmpty())&&(USART_CheckTransmitAvailable())) //stack is not empty
	{
		USART_Transmit(*StackPointerRear);
		IncStackPtrR();
	}
}

////////////  STKPRNT Global Interfaces ///////////

StackSt STKPRNT_PrintSerial(char *ch)
{
	uint8 NumOfChars = 0;
	StackSt ret = E_NOK;
	char * temp_ch = ch;
	while(*(temp_ch++) != 0 && NumOfChars < 254)
	{
		NumOfChars ++;
	}
	if(NumOfChars < REMAIN_STACK)
	{
		while(!isStackFull()&&(*ch != 0))
				{
					*(StackPointerFront)=*(ch++);
					IncStackPtrF();
				}
	}else
	{
		ret = E_OK;
	}
	return ret;
}

void STKPRNT_Blocking_PrintStr(const char * sent)
{
	// USART_Transmit(*(sent+2))
	while(*(sent) != 0)
	{
		USART_Transmit(*sent++);
	}
}
