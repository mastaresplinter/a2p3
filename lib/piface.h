/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

/*
 * Modified by Wagner Morais on Sep 2022.
 */

#ifndef _PIFACE_H
#define _PIFACE_H

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

/* PiFace Hardware Description */

/* MCP23S17 Control Register */
#define MCP_IODIRA      0x00
#define MCP_IODIRB      0x01
#define MCP_IPOLA       0x02
#define MCP_IPOLB       0x03
#define MCP_GPINTENA    0x04
#define MCP_GPINTENB    0x05
#define MCP_DEFVALA     0x06
#define MCP_DEFVALB     0x07
#define MCP_INTCONA     0x08
#define MCP_INTCONB     0x09
#define MCP_IOCON       0x0A
#define MCP_IOCON_      0x0B
#define MCP_GPPUA       0x0C
#define MCP_GPPUB       0x0D
#define MCP_INTFA       0x0E
#define MCP_INTFB       0x0F
#define MCP_INTCAPA     0x10
#define MCP_INTCAPB     0x11
#define MCP_GPIOA       0x12
#define MCP_GPIOB       0x13
#define MCP_OLATA       0x14
#define MCP_OLATB       0x15

/* HD44780 Control Pins */
#define LCD_DB4     (1 << 0)
#define LCD_DB5     (1 << 1)
#define LCD_DB6     (1 << 2)
#define LCD_DB7     (1 << 3)
#define LCD_EN      (1 << 4)
#define LCD_RW      (1 << 5)
#define LCD_RS      (1 << 6)
#define LCD_BL      (1 << 7)

/*Display Cursor Positions*/
#define SET_DDRAM_ADR   (1<<7)
#define CUR_LINE_1      0x00
#define CUR_LINE_2      0x40


#define PUTTOLDC(fmt, args...){ \
	char s[9]; \
    sprintf(s, fmt, ##args); \
    piface_puts(s); \
}


static const uint8_t ROW_OFFSETS[] = {0, 0x40};


 /** @brief Initializes the piface display for instructions
 * 
 *  @param void
 *
 *	@return void
 *
 *  Pre-condition: none
 * 
 *  Post-condition: 4-bit mode enabled
 *  function set; N = 1 for two rows, F = 0 for 5x8 display
 *  entry mode set; I/D = 1 for direction left to right, S = 0 for shift off 
 *  display on/off; D = 1 for display on, C = 1 for cursor on; B = 0 for blinking off
 *  
 *  properties: 
 *  After initializing the piface it should be ready for instructions in 4-bit mode.
 */
void piface_init(void);

 /** @brief Sets the cursor position
 * 
 *  @param col the column where the cursor will be placed
 * 
 *  @param row the row where the cursor will be placed
 *
 *	@return void
 *
 *  Pre-condition: The value of col is between 0 and 7, the value of row is either 0 or 1.
 * 
 *  Post-condition: none
 *  
 *  properties: 
 *  After positioning the cursor the next character written to the screen will be placed at this position.
 */
void piface_set_cursor(uint8_t col, uint8_t row);

 /** @brief Writes a character to the display
 * 
 *  @param c is the character being displayed to the screen
 *
 *	@return void
 *
 *  Pre-condition: If the integer value of c is less than 32 or greater than 126 an error will occur.
 * 
 *  Post-condition: none
 *
 *  properties: 
 *  Write a character at the current cursor position, if the character \n the cursor will be set in the bottom left position (col = 0, row = 1)
 */
void piface_putc(char c);

 /** @brief Writes a string to the display
 * 
 *  @param s is the string to be written to the display
 *
 *	@return void
 *
 *  Pre-condition: s is not NULL
 * 
 *  Post-condition: none
 *
 *  properties: 
 *  Always start writing from top left (col = 0, row = 0), each line fits 16 characters, 32 characters in total. The maximum length of the string 
 *  can be 32 characters. After 16 characters or \n the cursor position will be set to the bottom left (col = 0, row = 1)
 */
void piface_puts(char s[]);

/** @brief Clears the display
 * 
 *	@return void
 *
 *  Pre-condition: none
 * 
 *  Post-condition: none
 *
 *  properties: 
 *  After clearing the display the cursor position should return to top left (col = 0, row = 0)
 */
void piface_clear();

// void print_at_seg(int seg, int num);
// void printf_at_seg(int seg, const char* fmt, ...);
#endif
