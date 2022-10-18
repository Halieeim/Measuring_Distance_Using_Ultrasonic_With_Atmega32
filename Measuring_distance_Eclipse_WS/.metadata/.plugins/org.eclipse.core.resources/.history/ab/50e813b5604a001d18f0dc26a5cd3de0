 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: header file for the ATmega32 LCD driver
 *
 * Author: Ahmed Abd El-Halim Ahmed
 *
 *******************************************************************************/


#ifndef LCD_H_
#define LCD_H_
#include "std_types.h"

#define LCD_RS_PORT_ID                 PORTD_ID
#define LCD_RS_PIN_ID                  PIN0_ID
#define LCD_E_PORT_ID                  PORTD_ID
#define LCD_E_PIN_ID                   PIN2_ID
#define LCD_DATA_PORT_ID               PORTC_ID

void LCD_sendCommand(uint8 command);

void LCD_displayChar(uint8 data);

void LCD_init(void);

void LCD_displayString(const char* str);

void LCD_moveCursor(uint8 row, uint8 col);

void LCD_displayStringRowColumn(uint8 row, uint8 col, const char* str);

void LCD_integerToString(int data);

void LCD_clearScreen();

#endif /* LCD_H_ */
