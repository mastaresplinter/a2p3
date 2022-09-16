/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
 */
/*
 * Modified by Wagner Morais on Aug 2022.
 */

#include <stddef.h>
#include <stdlib.h>
#include "expstruct.h"
#include "rpi-systimer.h"
#include "led.h"
#include <piface.h>
#include <string.h>


double faculty(int n) 
{
  if (n != 0) {
    return n * faculty((int)(n - 1));
  } else
    return 1;
}

double ppow(int base, int exp) 
{
  double result = 1.0;
  while (exp != 0) 
  {
    result = result * base;
    exp--;
  }
  return result;
}

void led_toggle(int x)
{
  if (x == 1)
  {
    led_on();
  }
  if (x == -1)
  {
    led_off();
  }
}

ExpStruct *iexp(int x){
    ExpStruct *e = malloc(sizeof(ExpStruct));
    double term = 0;
    double tempFraction = 0;
    int status = 1;
    e->expInt = 1+x;
    e->expFraction = 0;
    int i = 2;
    while(1)
    {
        RPI_WaitMicroSeconds(100000);
        term = (double)ppow(x, i) / faculty(i);
        e->expInt += (int)term;
        tempFraction += (term - (int) term);

        if (term < 0.0001)
          break;
        else
          i++;
    if (i % 5 == 0)
    {
      status *= -1;
		  if (status == LED_ON)
        led_off();
        else if (status == LED_OFF)
        led_on();
        }
    }
    e->expInt += (int)tempFraction;
    e->expFraction = (tempFraction-(int)tempFraction)*100;
    return e;
}