/*
 * Compass.h
 *
 *  Created on: Jun 27, 2018
 *      Author: NadaHasan
 */

#ifndef COMPASS_COMPASS_H_
#define COMPASS_COMPASS_H_




extern int16_t mxraw ;
extern int16_t myraw ;
extern int16_t mzraw ;
extern double mx ;
extern double my ;
extern double mz ;


void Compass_Init(void);
void Compass_Cyclic20ms(void);
void Compass_setCompassData(comp_str *CompassStatus);

void Compass_getCompassData(comp_str * CompassStatus);
#endif /* COMPASS_COMPASS_H_ */
