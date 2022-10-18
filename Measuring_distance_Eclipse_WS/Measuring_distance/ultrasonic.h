 /******************************************************************************
 *
 * Module: ULTRASONIC
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for the ULTRASOINC driver
 *
 * Author: Ahmed Abd El-Halim Ahmed
 *
 *******************************************************************************/


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

void ULTRASONIC_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASONIC_H_ */
