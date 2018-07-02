/*
 * CAN_APP.h
 *
 *  Created on: Jun 27, 2018
 *      Author: NadaHasan
 */

#ifndef CAN_APP_CAN_APP_H_
#define CAN_APP_CAN_APP_H_

typedef struct comp_struct{
	uint32_t heading;

}comp_str;
typedef enum {
	COMP_INIT,
	COMP_RUNNING
}CompState;
void CAN_APP_Init(void);
void CAN_APP_Cyclic20ms(void);

#endif /* CAN_APP_CAN_APP_H_ */
