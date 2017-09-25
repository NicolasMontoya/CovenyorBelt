/*
 * general.c

 *
 *  Created on: Sep 24, 2017
 *      Author: Nicolas
 */
#include "general.h"

char acummulator[4];

char* BCDConverter(unsigned int number){
	if(number > 99){
		acummulator[0] = (number / 100) + '0';
		acummulator[1] = ((number % 100) / 10) + '0';
		acummulator[2] = ((number % 100) % 10) + '0';
		acummulator[3] = '\0';
	}
	else if(number > 9){
		acummulator[0] = (number / 10) + '0';
		acummulator[1] = (number % 10) + '0';
		acummulator[2] = '\0';
	}
	else{
		acummulator[0] = number + '0';
		acummulator[1] = '\0';
	}
	return acummulator;
}

void msDelay(word ms){
	unsigned int i;
	unsigned int j;
	for(j=0;j < ms;j++){
		for(i=0;i < MSMODTIMER;i++){
			
		}
	}
}
void usDelay(word us){
	unsigned int i;
	unsigned int j;
	for(j=0;j < us;j++){
		for(i=0;i < USMODTIMER;i++){
			
		}
	}
}
