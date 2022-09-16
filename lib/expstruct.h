/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
 */
/*
 * Modified by Wagner Morais on Aug 2022.
 */
 
#ifndef _EXPSTRUCT_H
#define _EXPSTRUCT_H

#define     LED_ON      1
#define     LED_OFF     -1

struct expStruct {
int expInt;
int expFraction;
};

typedef struct expStruct ExpStruct;

double faculty(int);
ExpStruct * iexp (int);
void led_toggle(int);

#endif