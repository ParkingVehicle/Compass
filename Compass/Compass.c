/*
 * Compass.c
 *
 *  Created on: Jun 27, 2018
 *      Author: NadaHasan
 */



#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "math.h"
#include "CAN_APP.h"
#include "Compass.h"
#include "hmc5883l.h"

#define MAGN_DOCALIBRATION 0 //enable or disable magnetometer calibration
#define magncal_getrawdata(mxraw, myraw, mzraw) hmc5883l_getrawdata(mxraw, myraw, mzraw); //set the function that return magnetometer raw values
#include "magn_docalibration.h"

/*
static int16_t mxraw = 0;
static int16_t myraw = 0;
static int16_t mzraw = 0;
static double mx = 0;
static double my = 0;
static double mz = 0;

*/
	int16_t mxraw = 0;
	int16_t myraw = 0;
	int16_t mzraw = 0;
	double mx = 0;
	double my = 0;
	double mz = 0;


static comp_str compass;
static CompState LocalCompState = COMP_INIT;
void Update_Compass_Status(void);

void Compass_Init(void)
{
	//DDRA = 0xFF;
	//PORTA = 0x00;
	if(HMC_ERR_I2C == hmc5883l_init())
	{
		LocalCompState = COMP_INIT;
		STKPRNT_PrintSerial("HMC is not connected, please connect !!! \n\r");

	}else{
		LocalCompState = COMP_RUNNING;
	}

}
void Compass_ReInit(void)
{
	//DDRA = 0xFF;
	//PORTA = 0x00;
	if(HMC_ERR_I2C == hmc5883l_init())
	{
		LocalCompState = COMP_INIT;

	}else{
		LocalCompState = COMP_RUNNING;
	}

}

void Compass_Cyclic20ms(void)
{
	if(LocalCompState == COMP_RUNNING)
	{
		Update_Compass_Status();
	}else{
		// Re init the module
		Compass_ReInit();
	}

}



void Compass_setCompassData(comp_str *CompassStatus)
{
	compass.heading = CompassStatus->heading;
}
void Compass_getCompassData(comp_str * CompassStatus)
{
	CompassStatus -> heading = compass.heading;
}
void Compass_getModuleStatus(CompState *InCompState)
{
	*InCompState = LocalCompState;
}
////////////////////   Begin of Local functions ////////////////////
void Update_Compass_Status(void)
{
	float heading = 0;
	HmcStdtype HmcStatus;
	hmc5883l_getrawdata(&mxraw, &myraw, &mzraw);
	HmcStatus = hmc5883l_getdata(&mx, &my, &mz);
	if(HmcStatus == HMC_ERR_I2C)
	{
		LocalCompState = COMP_INIT;
		STKPRNT_PrintSerial("HMC waiting to connect !!! \n\r");
	}

	heading = atan2((double)myraw,(double)mxraw)*57.29578;
	if(heading < 0)
		heading = 360 + heading;


	compass.heading = heading;
}

//////////////////    End of Local functions ////////////////////
