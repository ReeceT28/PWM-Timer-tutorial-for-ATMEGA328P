#ifndef TIMERS_H
#define TIMERS_H

#include <avr/io.h>
#include <avr/interrupt.h>

// Function to set up Timer0
void timer0Setup(void);

// Function to set up Timer1
void timer1Setup(void);

#endif // TIMERS_H