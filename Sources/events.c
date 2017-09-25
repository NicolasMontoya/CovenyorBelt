/*
 * events.c

 *
 *  Created on: Sep 19, 2017
 *      Author: Nicolas
 */
#include "events.h"
#include "lcd.h"
#include "timer.h"



volatile unsigned char Flag_Int_IC=0;
volatile unsigned char Flag_Int_OC=0;
unsigned int count_Ovf=0; 
unsigned int time_edge_1=0, time_edge_2 = 0;
unsigned long  time_pulse_width=0;
char flag=0;//VARIABLE FOR INDICATING A FIRST EDGE OR SECOND EDGE
unsigned int bottleA=0, bottleB = 0,bottleC = 0, NoBottle = 0;
volatile unsigned int Flag_STATE = 0;
volatile unsigned int Flag_SCI = 0;
unsigned int state = 0;

const char noworking[] = "Status: Stop";
const char working[] = "Status: Working";
char ReciveData;


// Interrupts
//Timer
interrupt 9 void TPM1_IC_ISR(void){//INTERRUPT ENABLE
	// CLEAR TOF IN TWO STEPS:
	TPM1C0SC;// 1.READING TPMxSC WHEN TOF IS SET
	TPM1C0SC_CH0F = 0; // 2. WRITING A LOGIC 0 TO CH0F
	Flag_Int_IC=1;
}

interrupt 10 void TPM1_CH1_ISR(void){//INTERRUPT DISABLE
	// CLEAR TOF IN TWO STEPS:
	TPM1C1SC;// 1.READING TPMxSC WHEN TOF IS SET
	TPM1C1SC_CH1F = 0; // 2. WRITING A LOGIC 0 TO CH2F
	Flag_STATE = 1;
}

interrupt 15 void TPM1_OvF_ISR(void){//INTERRUPT ENABLE
	// CLEAR TOF IN TWO STEPS:
	TPM1SC;// 1.READING TPMxSC WHEN TOF IS SET
	TPM1SC_TOF = 0; // 2. WRITING A LOGIC 0 TO TOF
	count_Ovf++;  
}

interrupt 23 void SCIRecive_ISR(void){
	SCI2S1;
	ReciveData = SCI2D;
	Flag_SCI = 1;		
}


void processEvents(void){
	if(state == 1){
		if(count_Ovf >= 15){
			Flag_STATE = 0;
			state = !state;
			printState(state);
			Flag_Int_IC = 0;
			count_Ovf = 0;
		}
		if(Flag_STATE == 1){
					Flag_STATE = 0;
					state = !state;
					printState(state);
					Flag_Int_IC = 0;
					msDelay(400);
		}
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
				
				if(time_pulse_width >= 310001 && time_pulse_width <= 370000)
				{
					bottleA++;
					PrintBottlesMSG(bottleA,0);
				}
				else if(time_pulse_width >= 270000 && time_pulse_width <= 310000){
					bottleB++;					
				}
				else if(time_pulse_width >= 370001 && time_pulse_width <= 400000){
					bottleC++;
				}
				else{
					NoBottle++;
				}
				
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
	}else{
		if(Flag_SCI == 1){
			Flag_SCI = 0;
			ReciveData += 1;
			while(SCI2S1_TDRE == 0);
			SCI2D = ReciveData;
			
		}
		if(Flag_STATE == 1){
			Flag_STATE = 0;
			state = !state;
			printState(state);
			Flag_Int_IC = 0;
			msDelay(400);
		}
	}
}

void printState(unsigned int data)
{
	if(data == 0)
	{
		LCD_SetCommand(LCD_CLEAR, LCD_NOPARAMETER);
		msDelay(2);
		LCD_WriteMsg(0x00,noworking,0);
		PTDD_PTDD0 = 0;
	}
	else{
		LCD_WriteMsg(0x00,working,0);
		PrintBottlesMSG(bottleA,0);
		PTDD_PTDD0 = 1;
	}
}
