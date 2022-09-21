/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Wagner Morais on Aug 2022.
 */
#ifndef LED_H
#define LED_H

// Similar to rpi-gpio.h
//#define LED_ON            1
//#define LED_OFF           0
#define LEDHH_GPFSEL      GPFSEL1
#define LEDHH_GPFBIT      18
#define LEDHH_GPSET       GPSET0
#define LEDHH_GPCLR       GPCLR0
#define LEDHH_GPIO_BIT    16
#define LEDHH_GPIO        16

#define LEDHH_ON()        do { RPI_GetGpio()->LEDHH_GPSET = ( 1 << LEDHH_GPIO_BIT ); } while( 0 )
#define LEDHH_OFF()       do { RPI_GetGpio()->LEDHH_GPCLR = ( 1 << LEDHH_GPIO_BIT ); } while( 0 )



void led_init();
void led_on();
void led_off();
/** @brief Toggle led
 * 
 *  @param x -1 turns led off 1 turns led on
 * 
 *  @return void
 * 
 *  Pre-condition: none
 * 
 *  Post-condition: none
 * 
 * */
void led_toggle();
void led_blink();


#endif
