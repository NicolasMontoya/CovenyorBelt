/*
 * events.c

 *
 *  Created on: Sep 19, 2017
 *      Author: Nicolas
 */
#include "events.h"
#include "lcd.h"

volatile unsigned char Flag_Int_IC=0;
volatile unsigned char Flag_Int_OC=0;
unsigned int count_Ovf=0; 
unsigned int time_edge_1=0, time_edge_2 = 0;
unsigned long  time_pulse_width=0;
char flag=0;//VARIABLE FOR INDICATING A FIRST EDGE OR SECOND EDGE
unsigned int bottles = 0;



// Interrupts
//Timer
interrupt 9 void TPM1_IC_ISR(void){//INTERRUPT ENABLE
	// CLEAR TOF IN TWO STEPS:
	TPM1C0SC;// 1.READING TPMxSC WHEN TOF IS SET
	TPM1C0SC_CH0F = 0; // 2. WRITING A LOGIC 0 TO CH0F
	Flag_Int_IC=1;
}

interrupt 11 void TPM1_OC_ISR(void){//INTERRUPT DISABLE
	// CLEAR TOF IN TWO STEPS:
	TPM1C2SC;// 1.READING TPMxSC WHEN TOF IS SET
	TPM1C2SC_CH2F = 0; // 2. WRITING A LOGIC 0 TO CH2F
	Flag_Int_OC=1;
}

interrupt 15 void TPM1_OvF_ISR(void){//INTERRUPT ENABLE
	// CLEAR TOF IN TWO STEPS:
	TPM1SC;// 1.READING TPMxSC WHEN TOF IS SET
	TPM1SC_TOF = 0; // 2. WRITING A LOGIC 0 TO TOF
	count_Ovf++;  
}


void processEvents(void){
    if(Flag_Int_IC==1){
    	Flag_Int_IC=0;//DON'T FORGET TO TURN OFF THE FLAG
    	
    	if (flag==0){//FIRST EDGE
    		count_Ovf=0;
    		time_edge_1=TPM1C0V;//CAPTURE THE TIME INDICATING A RISING OR FALLING EDGE
    		flag=1;//SECOND EDGE
    	}
    	else if(flag==1){//SECOND EDGE
    		time_edge_2=TPM1C0V;//CAPTURE THE TIME INDICATING THE OTHERWISE
    		flag=0;//FISRT EDGE (NEW PULSE)
    		time_pulse_width=(long)(count_Ovf*MODULO+time_edge_2-time_edge_1);//TIME BETWEEN time_edge_1 AND time_edge_2 
       		bottles++;
       		FuncPrint(bottles);
    		count_Ovf=0;
    		/*
			 * count_Ovf: NUMBER OF TIMES AN OVERFLOWS OCCURS
			 * time_pulse_width=(number_of_times_that_happens_OVERFLOW)*(VALUE_MODULE)+time_edge_1-time_edge_2
			 * 
			 * with this formulates, we considered all cases.
			 * 
			 * */
    	}	
    }
}
