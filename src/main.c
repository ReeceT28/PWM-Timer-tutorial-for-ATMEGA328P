#include "timers.h"
#include "delay.h"
int increment = 1; 

// Interval for LED brightness change in microseconds
unsigned long lastMillisPB2 = 0;  // Store the last time we updated the LED brightness
unsigned long lastMicrosPB1=0;

void setup() 
{
  DDRB |= (1 << DDB1) | (1<<DDB2); // IMPORTANT SET PIN TO OUTPUT FIRST
  
  timer0Setup();
  timer1Setup();

  sei();
}

void loop() 
{ 
  // We could perhaps handle the incrementing of the OCR1A register using
  // timer overflows as we very frequently execute this
  // but this is just a demonstration of how we use non-blocking delays
  if(customMicros()-lastMicrosPB1>=50)
  {
    lastMicrosPB1 = customMicros();

    OCR1A += increment;

    if (OCR1A >= ICR1) 
    {
      increment = -1; 
    }
    else if (OCR1A <= 0)
    {
      increment = 1; 
    }
  }

  

  if(customMillis()-lastMillisPB2 >= 1000 )
  {
    lastMillisPB2=customMillis();
    
    PORTB^=(1<<PB2);
  }

}

int main(void)
{
  setup();

  while(1)
  {
    loop();
  }
  return 0;
}
