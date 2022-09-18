/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
	Wagner de Morais (Wagner.deMorais@hh.se)
*/

#include <stdio.h>
#include <stdlib.h>
#include "led.h"
#include "expstruct.h"
#include "rpi-systimer.h"
#include "piface.h"
#include "uart.h"


#define LINE 32

int main()
{
	char str[LINE];
	led_init();
	piface_init();
	piface_clear();

	piface_puts("DT8025 - A2P3");
	RPI_WaitMicroSeconds(2000000);	
	
    ExpStruct* value;
  
    int i = 0; 
	// cyclic execution
	while (1)
	{
		for(i = 0; i < 21; i++)
		{
		value = iexp(i);
		piface_clear();
		sprintf(str, "%d: %d.%d",i, value->expInt, value->expFraction);
		piface_puts(str);
		free(value);
		}
	}
	
	return 0;

}
