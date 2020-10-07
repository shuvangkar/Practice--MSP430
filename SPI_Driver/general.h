/*
 * general.h
 *
 *  Created on: Aug 31, 2020
 *      Author: sshuv
 */

#ifndef GENERAL_H_
#define GENERAL_H_
#include <msp430.h>
#include <stdint.h>

#define MCU_CLOCK SMCLK_1MHZ


typedef uint8_t byte; //uint8_t type can be defined using byte

void set_mcu_clock();
void delay(int32_t ms);
void delay_us(uint32_t us);

#endif /* GENERAL_H_ */
