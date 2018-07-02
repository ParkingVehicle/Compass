/*
 * STACK.h
 *
 *  Created on: Mar 7, 2018
 *      Author: Nada
 */


#ifndef INCLUDES_STACK_H_
#define INCLUDES_STACK_H_

#define STACKMAX 150


#define isStackFull()  ( StackSize >= (STACKMAX - 1))
#define isStackEmpty() ( StackSize == 0)
#define IncStackPtrF()  																								\
	if(StackSize <STACKMAX-1){																							\
		((StackPointerFront-SerialStack) < (STACKMAX-1) ? (StackPointerFront++) : (StackPointerFront=SerialStack)); 	\
		StackSize++;																									\
	}
#define IncStackPtrR()  																								\
	if(StackSize !=0){ 																									\
	((StackPointerRear-SerialStack) < (STACKMAX-1) ? (StackPointerRear++) : (StackPointerRear=SerialStack)); 			\
	StackSize--; 																										\
	}

#define REMAIN_STACK ((STACKMAX-1) - StackSize)

#ifdef _STKPRNT_FILE_
	unsigned char StackSize = 0;
#else
	extern unsigned char StackSize = 0;
#endif




#endif /* INCLUDES_STACK_H_ */
