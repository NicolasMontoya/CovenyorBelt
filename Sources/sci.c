/*
 * sci.c
 *
 *  Created on: Sep 25, 2017
 *      Author: Nicolas
 */

#include "sci.h"

void SCI_Init(void){
	
	SCI2C1 = 0x00;
	SCI2C2 = 0x2C;
	SCI2C3 = 0x00;
	SCI2BDH = 0x00;
	SCI2BDL = 52;

}

void SCI_PutChar(byte Data) {
  while(SCI2S1_TDRE == 0);
  SCI2D = Data;
}

byte SCI_GetChar(void) {
  while(SCI2S1_RDRF == 0);
  return SCI2D;// The RDRF flag is cleared at end of execution. Why?
}

void SCI_PutMsg(const byte * Data) {
  while(*Data != '\0') {
	SCI_PutChar(*Data++);
  }
}

