 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the ATmega32 LCD driver
 *
 * Author: Ahmed Abd El-Halim Ahmed
 *
 *******************************************************************************/


#include "gpio.h"
#include "common_macros.h"
#include "lcd.h"
#include <util/delay.h>
#include <stdlib.h>

#define LCD_MOOD 8

#if ((LCD_MOOD == 8) || (LCD_MOOD == 4))

#else
#error "Please use LCD with 8-bits mood or 4-bits mood"
#endif

void LCD_sendCommand(uint8 command){
	GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, 0); /* RS = 0 */
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, 1);
	_delay_ms(1);
#if LCD_MOOD == 8
	GPIO_writePort(LCD_DATA_PORT_ID, command);
#else
	GPIO_writePin(LCD_DATA_PORT_ID, PIN3_ID, GET_BIT(command,4));
	GPIO_writePin(LCD_DATA_PORT_ID, PIN4_ID, GET_BIT(command,5));
	GPIO_writePin(LCD_DATA_PORT_ID, PIN5_ID, GET_BIT(command,6));
	GPIO_writePin(LCD_DATA_PORT_ID, PIN6_ID, GET_BIT(command,7));

	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, 0);
	_delay_ms(1);

	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, 1);
	_delay_ms(1);

	GPIO_writePin(LCD_DATA_PORT_ID, PIN3_ID, GET_BIT(command,0));
	GPIO_writePin(LCD_DATA_PORT_ID, PIN4_ID, GET_BIT(command,1));
	GPIO_writePin(LCD_DATA_PORT_ID, PIN5_ID, GET_BIT(command,2));
	GPIO_writePin(LCD_DATA_PORT_ID, PIN6_ID, GET_BIT(command,3));


#endif
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, 0);
	_delay_ms(1);
}

void LCD_displayChar(uint8 data){
	GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, 1);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, 1);
	_delay_ms(1);

#if LCD_MOOD == 8
	GPIO_writePort(LCD_DATA_PORT_ID, data);
#else
	GPIO_writePin(LCD_DATA_PORT_ID, PIN3_ID, GET_BIT(data,4));
	GPIO_writePin(LCD_DATA_PORT_ID, PIN4_ID, GET_BIT(data,5));
	GPIO_writePin(LCD_DATA_PORT_ID, PIN5_ID, GET_BIT(data,6));
	GPIO_writePin(LCD_DATA_PORT_ID, PIN6_ID, GET_BIT(data,7));

	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, 0);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, 1);
	_delay_ms(1);

	GPIO_writePin(LCD_DATA_PORT_ID, PIN3_ID, GET_BIT(data,0));
	GPIO_writePin(LCD_DATA_PORT_ID, PIN4_ID, GET_BIT(data,1));
	GPIO_writePin(LCD_DATA_PORT_ID, PIN5_ID, GET_BIT(data,2));
	GPIO_writePin(LCD_DATA_PORT_ID, PIN6_ID, GET_BIT(data,3));

#endif
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, 0);
	_delay_ms(1);
}

void LCD_init(){
	GPIO_setupPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, 1);
	GPIO_setupPinDirection(LCD_E_PORT_ID, LCD_E_PIN_ID, 1);
	_delay_ms(20);
#if LCD_MOOD == 8
	GPIO_setupPortDirection(LCD_DATA_PORT_ID, 1);
	LCD_sendCommand(0x38);
#else
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, PIN3_ID, 1);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, PIN4_ID, 1);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, PIN5_ID, 1);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID, PIN6_ID, 1);
	LCD_sendCommand(0x33);
	LCD_sendCommand(0x32);
	LCD_sendCommand(0x28);

#endif

	LCD_sendCommand(0x0C);
	LCD_sendCommand(0x01);
}

void LCD_displayString(const char *str){
	while((*str) != '\0'){
		LCD_displayChar(*str);
		str++;
	}
}

void LCD_moveCursor(uint8 row, uint8 col){
	uint8 position = 0;
	switch(row){
	case 0:
		position = col;
		break;
	case 1:
		position = col + 0x40;
		break;
	case 2:
		position = col + 0x10;
		break;
	case 3:
		position = col + 0x50;
		break;
	}
	LCD_sendCommand(position | 0x80);
}

void LCD_displayStringRowColumn(uint8 row, uint8 col, const char* str){
	LCD_moveCursor(row, col);
	LCD_displayString(str);
}

void LCD_integerToString(int data){
	char str[16];
	itoa(data, str, 10);
	LCD_displayString(str);
}

void LCD_clearScreen(){
	LCD_sendCommand(0x01);
}









