/*
 * sci.h
 *
 *  Created on: Sep 25, 2017
 *      Author: Nicolas
 */

#ifndef SCI_H_
#define SCI_H_

#include "derivative.h"

void SCI_Init(void);
byte SCI_GetChar(void);
void SCI_PutChar(byte);
void SCI_PutMsg(const byte *);

#endif /* SCI_H_ */
