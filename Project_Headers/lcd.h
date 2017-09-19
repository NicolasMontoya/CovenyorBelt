/*
 * lcd.h
 *
 *  Created on: Sep 19, 2017
 *      Author: Nicolas
 */

#ifndef LCD_H_
#define LCD_H_

#include "derivative.h"

#define LCD_NOP() __asm NOP; __asm NOP; __asm NOP; __asm NOP; __asm NOP; __asm NOP; __asm NOP; \
                  __asm NOP; __asm NOP; __asm NOP; __asm NOP; __asm NOP; __asm NOP; __asm NOP
                  

// Configuration parameters of LCD
#define LCD_ROWS 2
#define LCD_COLS 12

// Configuration I/O LCD
#define LCD_DIR_CONTROL		PTADD_PTADD3
#define LCD_DIR_ENABLE		PTADD_PTADD4
#define LCD_DIR_ADDRESS		PTBDD
#define LCD_PIN_ENABLE 		PTAD_PTAD4
#define LCD_PIN_CONTROL 	PTAD_PTAD3
#define LCD_PIN_ADDRESS		PTBD

// Manage address for control pins
#define OUT_ENABLE()		LCD_DIR_ENABLE = 1
#define IN_ENABLE()			LCD_DIR_ENABLE = 0
#define OUT_CONTROL()		LCD_DIR_CONTROL = 1
#define IN_CONTROL()		LCD_DIR_CONTROL = 0
#define OUT_ADDRESS()		LCD_DIR_ADDRESS = 0xFF
#define IN_ADDRESS()		LCD_DIR_ADDRESS = 0x00

// Manage control pins for the LCD
#define LCD_ENABLE()	LCD_PIN_ENABLE = 1
#define LCD_DISABLE()	LCD_PIN_ENABLE = 0
#define LCD_CMD()		LCD_PIN_CONTROL = 0
#define LCD_DATA()		LCD_PIN_CONTROL = 1


// Commands LCD
#define LCD_CLEAR                   0x01
#define LCD_CURATHOME               0x02
#define LCD_ENTRYMODSET             0x04
#define LCD_ONOFFCONTROL            0x08
#define LCD_CURDISPSHIFT            0x10
#define LCD_FUNCTIONSET             0x20
#define LCD_SETADDRCGRAM            0x40
#define LCD_SETADDRDDRAM            0x80
#define LCD_INITIALIZE              0x30

// Entry Mode Set
// Select move direction parameter in EntryModSet
#define LCD_ENTRYMODSET_CURINC      0x02
#define LCD_ENTRYMODSET_CURDEC      0x00
// Select shift parameter in EntryModSet
#define LCD_ENTRYMODSET_SHIFTDISP   0x01
#define LCD_ENTRYMODSET_DISPNOSHIFT 0x00

// Display On/Off
// Select display parameter in On/Off Control
#define LCD_ONOFFCONTROL_DISPON     0x04
#define LCD_ONOFFCONTROL_DISPOFF    0x00
// Select cursor parameter in On/Off Control
#define LCD_ONOFFCONTROL_CURSON     0x02
#define LCD_ONOFFCONTROL_CURSOFF    0x00
// Select Blink cursor parameter in On/Off Control
#define LCD_ONOFFCONTROL_BLINKON    0x01
#define LCD_ONOFFCONTROL_BLINKOFF   0x00

// Shift
// Select cursor move parameter in Cursor/Display Shift
#define LCD_CURDISPSHIFT_DISPSHIFT  0x08
#define LCD_CURDISPSHIFT_CURSMOVE   0x00
// Select shift direction parameter in Cursor/Display Shift
#define LCD_CURDISPSHIFT_RIGHTSHIFT 0x04
#define LCD_CURDISPSHIFT_LEFTSHIFT  0x00

// Set Function
// Select data length parameter in FunctionSet
#define LCD_FUNCTIONSET_8BITS				0x10
#define LCD_FUNCTIONSET_4BITS				0x00
// Select number of display lines parameter in FunctionSet
#define LCD_FUNCTIONSET_2LINE				0x08
#define LCD_FUNCTIONSET_1LINE				0x00
// Select character font parameter in FunctionSet
#define LCD_FUNCTIONSET_5X10				0x04
#define LCD_FUNCTIONSET_5X7 				0x00

// No parameters
#define LCD_NOPARAMETER		0x00

//Delays constants
#define LCD_DELAY_LONG		1640
#define LCD_DELAY_SHORT		42

//Lines of LCD
#define FIRST_LCD_LINE		0x00
#define SECOND_LCD_LINE		0x40

// Extra constants
#define MSMODTIMER	360
#define USMODTIMER	3

// Prototypes general functions

void LCD_SetCommand(unsigned char, unsigned char);
void LCD_SetDataRAM(unsigned char);
void LCD_Initialize(unsigned char);

// Prototypes print functions

void LCD_WriteMsg(byte,const byte *, word);
void LCD_WriteMsgNow(const byte *, word);

void msDelay(word);
void usDelay(word);
void LCD_Init(void);
void FuncPrint(unsigned int);




#endif /* LCD_H_ */
