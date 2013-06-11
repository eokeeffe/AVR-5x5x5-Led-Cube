/*
 * LED_CUBE.c
 *
 * Created: 05/06/2013 18:33:46
 *  Author: evan
 */ 

#include "cube.h"
#include "avr.h"
#include <stdlib.h>
#include <avr/io.h>
#include <avr/delay.h>

void activateLED(char led)
{
	switch(led)
	{
		case 1:{SET_BIT(PORTD,PD7); break;}
		case 2:{SET_BIT(PORTC,PC0); break;}
		case 3:{SET_BIT(PORTC,PC1); break;}
		case 4:{SET_BIT(PORTC,PC2); break;}
		case 5:{SET_BIT(PORTC,PC3); break;}
		case 6:{SET_BIT(PORTC,PC4); break;}
		case 7:{SET_BIT(PORTC,PC5); break;}
		case 8:{SET_BIT(PORTC,PC6); break;}
		case 9:{SET_BIT(PORTC,PC7); break;}
		case 10:{SET_BIT(PORTA,PA7); break;}
		case 11:{SET_BIT(PORTA,PA6); break;}
		case 12:{SET_BIT(PORTA,PA5); break;}
		case 13:{SET_BIT(PORTA,PA4); break;}
		case 14:{SET_BIT(PORTA,PA3); break;}
		case 15:{SET_BIT(PORTA,PA2); break;}
		case 16:{SET_BIT(PORTA,PA1); break;}
		case 17:{SET_BIT(PORTA,PA0); break;}
		case 18:{SET_BIT(PORTD,PD6); break;}
		case 19:{SET_BIT(PORTD,PD5); break;}
		case 20:{SET_BIT(PORTD,PD4); break;}
		case 21:{SET_BIT(PORTD,PD3); break;}
		case 22:{SET_BIT(PORTD,PD2); break;}
		case 23:{SET_BIT(PORTD,PD1); break;}
		case 24:{SET_BIT(PORTD,PD0); break;}
		case 25:{SET_BIT(PORTB,PB5); break;}
		default:{break;}
	}
}

void deActivateLED(char led)
{
	switch(led)
	{
		case 1:{CLR_BIT(PORTD,PD7); break;}
		case 2:{CLR_BIT(PORTC,PC0); break;}
		case 3:{CLR_BIT(PORTC,PC1); break;}
		case 4:{CLR_BIT(PORTC,PC2); break;}
		case 5:{CLR_BIT(PORTC,PC3); break;}
		case 6:{CLR_BIT(PORTC,PC4); break;}
		case 7:{CLR_BIT(PORTC,PC5); break;}
		case 8:{CLR_BIT(PORTC,PC6); break;}
		case 9:{CLR_BIT(PORTC,PC7); break;}
		case 10:{CLR_BIT(PORTA,PA7); break;}
		case 11:{CLR_BIT(PORTA,PA6); break;}
		case 12:{CLR_BIT(PORTA,PA5); break;}
		case 13:{CLR_BIT(PORTA,PA4); break;}
		case 14:{CLR_BIT(PORTA,PA3); break;}
		case 15:{CLR_BIT(PORTA,PA2); break;}
		case 16:{CLR_BIT(PORTA,PA1); break;}
		case 17:{CLR_BIT(PORTA,PA0); break;}
		case 18:{CLR_BIT(PORTD,PD6); break;}
		case 19:{CLR_BIT(PORTD,PD5); break;}
		case 20:{CLR_BIT(PORTD,PD4); break;}
		case 21:{CLR_BIT(PORTD,PD3); break;}
		case 22:{CLR_BIT(PORTD,PD2); break;}
		case 23:{CLR_BIT(PORTD,PD1); break;}
		case 24:{CLR_BIT(PORTD,PD0); break;}
		case 25:{CLR_BIT(PORTB,PB5); break;}
		default:{break;}
	}
}

void setlevel(char level)
{
	/* 
		Turn on the layer specified
		Setting the column activates an led
		but clearing the pin on the layer will activate the layer
	*/
	switch(level)
	{
		case 1:{
			CLR_BIT(PORTB,0);
			CLR_BIT(PORTB,1);
			CLR_BIT(PORTB,2);
			CLR_BIT(PORTB,3);
			
			SET_BIT(PORTB,4);
			
			break;
		}
		case 2:{
			CLR_BIT(PORTB,0);
			CLR_BIT(PORTB,1);
			CLR_BIT(PORTB,2);
			CLR_BIT(PORTB,4);
			SET_BIT(PORTB,3);
			
			break;
		}
		case 3:{
			CLR_BIT(PORTB,0);
			CLR_BIT(PORTB,1);
			CLR_BIT(PORTB,3);
			CLR_BIT(PORTB,4);
			SET_BIT(PORTB,2);
			
			break;
		}
		case 4:{
			CLR_BIT(PORTB,0);
			CLR_BIT(PORTB,2);
			CLR_BIT(PORTB,3);
			CLR_BIT(PORTB,4);
			SET_BIT(PORTB,1);
			
			break;
		}
		case 5:{
			CLR_BIT(PORTB,1);
			CLR_BIT(PORTB,2);
			CLR_BIT(PORTB,3);
			CLR_BIT(PORTB,4);
			SET_BIT(PORTB,0);
			
			break;
		}
		default:{break;}
	}
}

void singleLed(char led)
{
	/*
		Light only a single LED
	*/
	char set=1;
	while(set<26)
	{
		if(set==led)
		{
			deActivateLED(set);
		}
		else
		{
			activateLED(set);
		}
		set++;
	}
}

void setup()
{
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
	reset();
}

void reset()
{
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
}

void test1()
{
	/*
		Light up an led on each column on each level
	*/
	char led = 1;
	char level = 1;
	setlevel(1);
	while(level<7)
	{
		singleLed(led);
		_delay_ms(400);
		deActivateLED(led);
		_delay_ms(400);
		led++;
		if(led>25){led=1;setlevel(level++);}
	}	
}

void snakePattern()
{
	//Create a snake pattern through the circuit
	char pattern[] = {1,2,3,4,5,10,9,8,7,6,11,12,13,14,15,20,19,18,17,16,21,22,23,24,25};
	char led = 0;
	char level = 1;
	char invert = 1;
	setlevel(1);
	while(level<7)
	{
		singleLed(pattern[led]);
		_delay_ms(450);
		deActivateLED(pattern[led]);
		_delay_ms(450);
		if(invert){led++;}
		else{led--;}
		if(led>24){setlevel(level++);invert=0;}
		if(led<1){setlevel(level++);invert=1;}
	}
}

void IEEE()
{
	// Homage to IEEE
	
	char layer1[] = {1,2,3,4,5,10,15,25,24,23,21,16,11};
	char layer2[] = {3,5,25,21};
	char layer3[] = {3,10,15,25,24,23,21,16,11};
		
	setlevel(1);
	for(int i=0;i<13;i++){singleLed(layer1[i]);}
	_delay_ms(10);
	for(int i=0;i<13;i++){deActivateLED(layer1[i]);}
	_delay_ms(10);
	
	setlevel(2);
	for(int i=0;i<4;i++){singleLed(layer2[i]);}
	_delay_ms(10);
	for(int i=0;i<4;i++){deActivateLED(layer2[i]);}
	_delay_ms(10);
	
	setlevel(3);
	for(int i=0;i<11;i++){singleLed(layer3[i]);}
	_delay_ms(10);
	for(int i=0;i<11;i++){deActivateLED(layer3[i]);}
	_delay_ms(10);
	
	setlevel(4);
	for(int i=0;i<4;i++){singleLed(layer2[i]);}
	_delay_ms(10);
	for(int i=0;i<4;i++){deActivateLED(layer2[i]);}
	_delay_ms(10);
	
	setlevel(5);
	for(int i=0;i<13;i++){singleLed(layer1[i]);}
	_delay_ms(10);
	for(int i=0;i<13;i++){deActivateLED(layer1[i]);}
	_delay_ms(10);
}

int getRandom(int limit)
{
	/*
		Return a hardware random number
		give a limit that wil range the 
		random number to 0-limit
	*/
	return (rand() / (RAND_MAX / limit + 1) );
}

void theMatrix()
{
	char led[10];
	for(int i=0;i<10;i++){led[i]=getRandom(25)+1;}
	
	for(char level=5;level>0;level--)
	{
		setlevel(level);
		for(int i=0;i<10;i++){singleLed(led[i]);}
		_delay_ms(800);
		for(int i=0;i<10;i++){deActivateLED(led[i]);}
		_delay_ms(800);
	}
}

void movingWalls()
{
	char wall1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	char wall2[] = {21,16,11,6,1,22,17,12,7,2,23,18,13,8,3,24,19,14,9,4,25,20,15,10,5};
	char invert = 1;
	char wall = 0;
	for(int i=0;i<4;i++)
	{
		if(invert)
		{
			if(wall==0)
			{
				for(int count=0;count<25;count+=5)
				{
					for(char a=0;a<=4;a++){setlevel(a+1);singleLed(wall1[count+a]);}
					_delay_ms(450);
					for(char a=0;a<=4;a++){setlevel(a+1);deActivateLED(wall1[count+a]);}
					_delay_ms(450);
				}				
				wall++;
			}
			if(wall==1)
			{
				for(int count=0;count<25;count+=5)
				{
					for(char a=0;a<=4;a++){setlevel(a+1);singleLed(wall2[count+a]);}
					_delay_ms(450);
					for(char a=0;a<=4;a++){setlevel(a+1);deActivateLED(wall2[count+a]);}
					_delay_ms(450);
				}
				invert = 0;
				wall++;
			}
		}
		else
		{
			if(wall==2)
			{
				for(int count=24;count>-1;count-=5)
				{
					for(char a=0;a<=4;a++){setlevel(a+1);singleLed(wall1[count+a]);}
					_delay_ms(450);
					for(char a=0;a<=4;a++){setlevel(a+1);deActivateLED(wall1[count+a]);}
					_delay_ms(450);
				}
				wall++;
			}
			if(wall==3)
			{
				for(int count=24;count>-1;count-=5)
				{
					for(char a=0;a<=4;a++){setlevel(a+1);singleLed(wall2[count+a]);}
					_delay_ms(450);
					for(char a=0;a<=4;a++){setlevel(a+1);deActivateLED(wall2[count+a]);}
					_delay_ms(450);
				}
				invert = 1;
				wall=0;
			}
		}
	}
}

int main(void)
{
	setup();
	test1();//test the LEDS are working
	
	//now show some patterns
	for(;;)
	{
		snakePattern();
		for(int i=0;i<1000;i++){IEEE();}
		for(int i=0;i<5;i++){movingWalls();}
		for(int i=0;i<20;i++){theMatrix();}
	}
}