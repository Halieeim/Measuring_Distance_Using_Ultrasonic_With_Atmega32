 /******************************************************************************
 *
 * Module: MEASURING DISTANCE APP
 *
 * Author: Ahmed Abd El-Halim Ahmed
 *
 *******************************************************************************/



#include "ultrasonic.h"
#include "lcd.h"
#include "avr/io.h"

int main(){
	uint16 distance = 0;

	ULTRASONIC_init();
	LCD_init();
	SREG |= 1<<7;

	for(;;){
		distance = Ultrasonic_readDistance();
		LCD_displayStringRowColumn(1, 0, "Distance = ");
		if(distance < 100){
			LCD_intgerToString(distance);
			LCD_displayCharacter(' ');
		}
		else{
			LCD_intgerToString(distance);
		}
		LCD_displayString("cm");

	}
}
