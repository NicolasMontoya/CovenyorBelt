

// Headers files for accessing the MCU registers
#include <hidef.h>
#include "derivative.h"
#include "timer.h"
#include "events.h"
#include "lcd.h"
#include "general.h"

#define CR   0x0D



// PORT FUNCTION INITIALIZATION
void Port_Init(void)
{
	PTDDD=0xFF;//OUT FOR LEDS
	PTDD=0x00;
	
}



//MAIN FUNCTION
void main(void) 
{
  // VARIABLES DECLARATIONS
	const char noworking[] = "Status: Stop";
  
  //SYSTEM INITIALIZATION
  SOPT1_COPT = 0;
  Port_Init();
  TIMER1_Init();
  LCD_Init();
  SCI_Init();
  msDelay(4);
  // ENABLE INTERRUPTS 
  EnableInterrupts;
  LCD_WriteMsg(0x00,noworking,0);
  for(;;) 
  {
    __asm WAIT;
    processEvents();
    msDelay(20);
    TPM1C0SC;// 1.READING TPMxSC WHEN TOF IS SET
    TPM1C0SC_CH0F = 0; // 2. WRITING A LOGIC 0 TO CH0F 
    TPM1C1SC;// 1.READING TPMxSC WHEN TOF IS SET
    TPM1C1SC_CH1F = 0; // 2. WRITING A LOGIC 0 TO CH2F
    
  }
}//main


