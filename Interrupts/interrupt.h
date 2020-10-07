/*
 * interrupt.h
 *
 *  Created on: Oct 7, 2020
 *      Author: sshuv
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include <msp430.h>
#include "stdint.h"

#define INT_PORT1_PIN0
//#define INT_PORT1_PIN1
//#define INT_PORT1_PIN2

#define INT_PORT2_PIN2

typedef void (*isr_t)(void);

typedef enum edge
{
    FALLING = 0,
    RISING,
}edge_e;

void attachInterrupt1(uint8_t pin, edge_e edge, isr_t isrPtr);
void attachInterrupt2(uint8_t pin, edge_e edge, isr_t isrPtr);



#endif /* INTERRUPT_H_ */
