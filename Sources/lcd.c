/*
 * lcd.c
 *
 *  Created on: Sep 19, 2017
 *      Author: Nicolas
 */
#include "lcd.h"

void LCD_Initialize(unsigned char InitValue){
	LCD_CMD();
	LCD_PIN_ADDRESS = InitValue;
	LCD_ENABLE();
	LCD_NOP();
	LCD_DISABLE();
}
 const byte MsgBottleA[] = "Bottles A: ";
 const byte MsgBottleB[] = "Bottles B: ";
 const byte MsgBottleC[] = "Bottles C: ";
 const byte MsgBottleE[] = "No bottle: ";
 
 char* number;
 

void PrintBottlesMSG(unsigned int a, unsigned int type){
	if(type == 0)
	{
		LCD_WriteMsg(SECOND_LCD_LINE,MsgBottleA,0);
	}
	else if(type == 1)
	{
		LCD_WriteMsg(SECOND_LCD_LINE,MsgBottleB,0);
	}
	else if(type == 2)
	{
		LCD_WriteMsg(SECOND_LCD_LINE,MsgBottleC,0);
	}
	else{
		LCD_WriteMsg(SECOND_LCD_LINE,MsgBottleE,0);
	}
	
	number = BCDConverter(a);
	LCD_WriteMsgNow(number,0);
	
}


void LCD_WriteMsg(byte StartDir, const byte *Msg, word delay){
	LCD_SetCommand(LCD_SETADDRDDRAM, StartDir);
	usDelay(60);
	while (*Msg!='\0')
		{
			LCD_SetDataRAM(*(Msg++));
			if (delay > 0){
			  msDelay(delay);
			}else{
				usDelay(50);
			}
		}
}
void LCD_WriteMsgNow( byte *Msg, word delay){

	while (*Msg!='\0')
		{
			LCD_SetDataRAM(*(Msg++));
			if (delay > 0){
			  msDelay(delay);
			}else{
				usDelay(50);
			}
		}
}


void LCD_Init(){
	
	OUT_ENABLE();
	OUT_CONTROL();
	OUT_ADDRESS();
	
	LCD_CMD();
	LCD_DISABLE();
	LCD_PIN_ADDRESS = 0;
	
	msDelay(16);
	LCD_Initialize(LCD_INITIALIZE);
	msDelay(5);
	LCD_Initialize(LCD_INITIALIZE);
	usDelay(100);
	LCD_Initialize(LCD_INITIALIZE);
	usDelay(100);
	
	LCD_SetCommand(LCD_CLEAR, LCD_NOPARAMETER);
	msDelay(2);
	LCD_SetCommand(LCD_ENTRYMODSET,LCD_ENTRYMODSET_CURINC);
	usDelay(42);
	LCD_SetCommand(LCD_ONOFFCONTROL,LCD_ONOFFCONTROL_DISPON);
	usDelay(42);
	LCD_SetCommand(LCD_FUNCTIONSET,(LCD_FUNCTIONSET_8BITS | LCD_FUNCTIONSET_2LINE ));
	usDelay(42);
	
}

void LCD_SetCommand(unsigned char command, unsigned char parameters){
	LCD_CMD();
	LCD_PIN_ADDRESS = (command | parameters);
	LCD_ENABLE();
	LCD_NOP();
	LCD_DISABLE();
}

void LCD_SetDataRAM(unsigned char data){
	LCD_DATA();
	LCD_PIN_ADDRESS = data;
	LCD_ENABLE();
	LCD_NOP();
	LCD_DISABLE();
}


