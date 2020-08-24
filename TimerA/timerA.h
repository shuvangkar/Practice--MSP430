/*
 * timerA.h
 *
 *  Created on: Aug 23, 2020
 *      Author: Shuvangkar
 */

#ifndef TIMERA_H_
#define TIMERA_H_

#include <msp430.h>
#include <stdint.h>

void set_mcu_clock();
void timerA_begin();

uint32_t millis();


extern uint32_t ms;

#endif /* TIMERA_H_ */
