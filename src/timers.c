#include "timers.h"

void timer0Setup()
{
  TCCR0A = (1 << WGM01); 
  OCR0A = 255;
  TCCR0B = (1 << CS01); // Prescaler = 8
  TIMSK0 = (1 << TOIE0); // Enable overflow interrupt

}

void timer1Setup()
{
  //Set COM1A1 for non-inverted PWM
  //Set WGM13 and 11 for phase correct with ICR1 as TOP
  //Set CS11 for prescaler of 8

  TCCR1A = (1 << COM1A1) | (1 << WGM11);   
  TCCR1B = (1 << WGM13) | (1 << CS11); 

  ICR1 = 20000;  // using our calculated TOP value
  OCR1A = 0;    // Start with LED off
}