#include "delay.h"

volatile unsigned long timer0OverflowCount = 0;

ISR(TIMER0_OVF_vect)
{
  timer0OverflowCount++;
}

unsigned long customMicros() 
{
    uint8_t oldSREG = SREG;  // Save status register

    //disable interrupts otherwise could interfere with calculation here
    cli();  
    
    // Calculate microseconds based on overflow count and current timer value
    // We need to multiply by 128 which we can use the nice trick of left shifting by 7 and right shift by 1 to divide by 2   
    // This might be optimised by the compiler anyways (I haven't checked) but is a nice trick especially when working with resource intensive longs  
    unsigned long microsNow = (timer0OverflowCount<<7) + (TCNT0 >> 1);

    /* 
    Restore status register - in our case we will always want global interrupts enabled but for using this in other programs where maybe they 
    are wanted to be disabled for some time we will just set the register to whatever it was before we turned global interrupts off
    (which could have been what it was originally anyways)
    */
    SREG = oldSREG;  

    return microsNow;
}
unsigned long customMillis()
{
  uint8_t oldSREG=SREG;
  cli();
  unsigned long millisNow = ((timer0OverflowCount<<7) + (TCNT0 >> 1))/1000; 

  SREG=oldSREG;
  return millisNow;
}