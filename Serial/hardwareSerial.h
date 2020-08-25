/*
 * hardwareSerial.h
 *
 *  Created on: Aug 25, 2020
 *      Author: Shuvangkar
 */

#ifndef HARDWARESERIAL_H_
#define HARDWARESERIAL_H_

#include <msp430.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void set_mcu_clock(void);
void serial_begin(void);
void serial_print(char *str);
void serial_print_int(int var);
//void serial_print_float(float var, uint8_t precision);

#endif /* HARDWARESERIAL_H_ */
