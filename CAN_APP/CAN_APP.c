
#include "common.h"
#include "can.h"
#include "STKPRNT.h"
#include "CAN_APP.h"
#include "Compass.h"
#include "can.h"

#include "UART_Drive.h"



void CompassMsgSend(can_t * msg);

const uint8_t can_filter[] PROGMEM =
	{
		// Group 0
		MCP2515_FILTER(0),				// Filter 0
		MCP2515_FILTER(0),				// Filter 1

		// Group 1
		MCP2515_FILTER_EXTENDED(0),		// Filter 2
		MCP2515_FILTER_EXTENDED(0),		// Filter 3
		MCP2515_FILTER_EXTENDED(0),		// Filter 4
		MCP2515_FILTER_EXTENDED(0),		// Filter 5

		MCP2515_FILTER(0),				// Mask 0 (for group 0)
		MCP2515_FILTER_EXTENDED(0),		// Mask 1 (for group 1)
	};
void CAN_APP_Init(void)
{

	if(can_init(BITRATE_125_KBPS))
	{
		// Load filters and masks
			can_static_filter(can_filter);
#ifdef debug_data
		//STKPRNT_PrintSerial("Module initialized !! \r\n");
		//STKPRNT_PrintSerial("Starting Can Filter\r\n");
		STKPRNT_PrintSerial("Can Filter initialized\r\n");
	}else{
		STKPRNT_PrintSerial("Module is not connected !! \r\n");
		STKPRNT_PrintSerial("Aborting application ........\r\n");
#endif
	}

}

void CAN_APP_Cyclic20ms(void)
{
	can_t msg;
	CompassMsgSend(&msg);
	can_send_message(&msg);
#ifdef debug_data
	STKPRNT_PrintSerial("Message Sent ... \r\n");
#endif
}

/*
 * This interface prepare and fill in the can message with compass data
 * passed in through compass_data
 */

void CompassMsgSend(can_t * msg)
{
//#define debug_data
	// convert from float to array of bytes
	comp_str compass_data_local;
	char ID[9]="000000\r\n";
	ID[8]=0;
	// get data from compass
	Compass_getCompassData(&compass_data_local);




	// Create message buffer
	/*ID[8]=0;
	msg->id = 0x123456;
	msg->flags.rtr = 0;
	msg->flags.extended = 1;

	msg->length = 4;
	msg->data[0] = bytes[0];
	msg->data[1] = bytes[1];
	msg->data[2] = bytes[2];
	msg->data[3] = bytes[3];
*/


	msg->id = 0x123457;

	msg->flags.rtr = 0;
	msg->flags.extended = 1;

	msg->length = 4;

	//msg->data[0] = (uint8_t)0x55;
	msg->data[0] = (uint8_t)compass_data_local.heading;
	msg->data[1] = (uint8_t) (compass_data_local.heading>>8);
	//msg->data[2] = 0x00;
	//msg->data[3] = 0x00;

#ifdef debug_data
	//HexToAscii(msg->id,ID);
	//STKPRNT_PrintSerial("ID to be transmitted: 0x");

	//STKPRNT_Blocking_PrintStr("c: ");
	//STKPRNT_PrintSerial(ID);
	DecToAscii(compass_data_local.heading,ID);
	STKPRNT_PrintSerial(ID);
#endif

}
