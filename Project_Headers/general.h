/*
 * general.h
 *
 *  Created on: Sep 24, 2017
 *      Author: Nicolas
 */

#ifndef GENERAL_H_
#define GENERAL_H_

#include "derivative.h"

// Library for control the time and BCDConverter

void msDelay(word);
void usDelay(word);
char* BCDConverter(unsigned int); 

#define MSMODTIMER	360
#define USMODTIMER	3

#endif /* GENERAL_H_ */
