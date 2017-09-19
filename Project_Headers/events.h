/*
 * events.h

 *
 *  Created on: Sep 19, 2017
 *      Author: Nicolas
 */

#ifndef EVENTS_H_
#define EVENTS_H_

#include "derivative.h"
#include "timer.h"
#include "lcd.h"

extern volatile unsigned char Flag_Int_IC;//variable for indicating to main program that an Input Capture(IC) has ocurred
extern volatile unsigned char Flag_Int_OC;//variable for indicating to main program that an Output Compare(OC) has ocurred
extern unsigned int  count_Ovf; //variable for indicating count overflow
extern unsigned int time_edge_1, time_edge_2;//variable for indicating a rising or falling edge
extern unsigned long  time_pulse_width;//variable for indicating pulse width

void processEvents(void);

#endif /* EVENTS_H_ */
