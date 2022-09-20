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

int led_status = LED_OFF;

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
  if (x == LED_ON)
  {
    led_on();
  }
  if (x == LED_OFF)
  {
    led_off();
  }
}

ExpStruct *iexp(int x){
    ExpStruct *e = malloc(sizeof(ExpStruct));
    double term = 0;
    double tempFraction = 0;
    e->expInt = 1+x;
    e->expFraction = 0;
    int i = 2;
    while(1)
    {
      RPI_WaitMicroSeconds(100000);
      if (i % 2 == 0)
      {
        led_status *= -1;
        led_toggle(led_status);
      }
      
      term = (double)ppow(x, i) / faculty(i);
      e->expInt += (int)term;
      tempFraction += (term - (int) term);

      if (term < 0.0001)
        break;
      else
        i++;
    }
    e->expInt += (int)tempFraction;
    e->expFraction = (tempFraction-(int)tempFraction)*100;
    return e;
}