/*
 * avr.h
 *
 * Created: 18/05/2013 22:55:23
 *  Author: evan
 */ 


#ifndef AVR_H_
#define AVR_H_

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/io.h>

#define XTAL_FRQ 8000000lu

#define SET_BIT(p,i) ((p) |=  (1 << (i)))
#define CLR_BIT(p,i) ((p) &= ~(1 << (i)))
#define GET_BIT(p,i) ((p) &   (1 << (i)))

#define WDR() asm volatile("wdr"::)
#define CLI() asm volatile("cli"::)
#define SEI() asm volatile("sei"::)
#define NOP() asm volatile("nop"::)
#define RST() for(;;);

#define TRUE 1
#define FALSE 0

void reset();
void setlevel(char level);//set individual layer
void activateLED(char led);//set the individual led
void deActivateLED(char led);//clear the individual led
void singleLed(char led);

//animation functions 
int getRandom(int limit);//get a random number in the limit of 0-limit

#endif /* AVR_H_ */