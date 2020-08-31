/*
 * SPI.h
 *
 *  Created on: Aug 26, 2020
 *      Author: Shuvangkar
 */

#ifndef SPI_H_
#define SPI_H_
#include <msp430.h>
#include <stdint.h>

#define CS_PORT_DIR     P3DIR
#define CS_PORT_OUT     P3OUT
#define CS_PIN          BIT6

#define CE_PORT_DIR     P3DIR
#define CE_PORT_OUT     P3OUT
#define CE_PIN          BIT7

//#define CS_PORT_DIR     P1DIR
//#define CS_PORT_OUT     P1OUT
//#define CS_PIN          BIT4


#define CS_PORT_SET() (CS_PORT_DIR |= CS_PIN)
#define CS_ENABLE() (CS_PORT_OUT &= ~CS_PIN)
#define CS_DISABLE() (CS_PORT_OUT |= CS_PIN)

#define CE_PORT_SET() (CE_PORT_DIR |= CE_PIN)
#define CE_ENABLE()   (CE_PORT_OUT |= CE_PIN)
#define CE_DISABLE()  (CE_PORT_OUT &= ~CE_PIN)

void spi_begin(void);
uint8_t spi_transfer(uint8_t reg);
uint16_t spi_transfer16(uint16_t input16);

#endif /* SPI_H_ */
