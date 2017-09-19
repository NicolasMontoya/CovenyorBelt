

// Headers files for accessing the MCU registers
#include <hidef.h>
#include "derivative.h"
#include "timer.h"
#include "events.h"
#include "lcd.h"


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

  
  //SYSTEM INITIALIZATION
  SOPT1_COPT = 0;
  Port_Init();
  TIMER1_Init();
  LCD_Init();

  // ENABLE INTERRUPTS 
  EnableInterrupts;
  for(;;) 
  {
    __asm WAIT;
    processEvents();
    msDelay(10);
    TPM1C0SC;// 1.READING TPMxSC WHEN TOF IS SET
    TPM1C0SC_CH0F = 0; // 2. WRITING A LOGIC 0 TO CH0F
    
    
  }
}//main


