#ifndef DELAY_H
#define DELAY_H

#include <avr/io.h>
#include <avr/interrupt.h>

// Global variable for timer0 overflow tracking
extern volatile unsigned long timer0OverflowCount;

// Custom microsecond delay function
unsigned long customMicros(void);

// Custom millisecond delay function
unsigned long customMillis(void);

#endif // DELAY_H
