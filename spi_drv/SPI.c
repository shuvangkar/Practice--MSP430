/*
 * SPI.c
 *
 *  Created on: Aug 26, 2020
 *      Author: Shuvangkar
 */

#include "SPI.h"
#include <stdint.h>

#define SPI_CS P3.6



void spi_begin(void)
{
    UCB0CTL1 |= UCSWRST ; //SPI is on hold for configuration

    P1SEL   |= BIT5 | BIT6 | BIT7 ; //P1.5 = SCK | P1.6 = MISO | P1.7 = MOSI
    P1SEL2  |= BIT5 | BIT6 | BIT7;

    CS_PORT_SET();
    CS_DISABLE();

    UCB0CTL1 |= UCSSEL_2 + UCSWRST; //SPI Clock = SMCLK
    UCB0BR0 = 0x01;  // SPI clocked at same speed as SMCLK
    UCB0BR1 = 0x00;
//    UCB0CTL0 |= UCMODE_0; //3 pin SPI
//    UCB0CTL0 |= UCSYNC; //Synchronous mode
//    UCB0CTL0 |= UCMST; //Master Mode
//    UCB0CTL0 |= UCCKPH; //Sampled first edge| shift on next edge
    UCB0CTL0 |= UCMODE_0 | UCSYNC | UCMST | UCMSB | UCCKPH;
    UCB0CTL1 &= ~UCSWRST; //Start SPI state machine.
}

uint8_t spi_transfer(uint8_t reg)
{
    UCB0TXBUF = reg;
    while (!(IFG2 & UCB0RXIFG));

    return UCB0RXBUF;
}
uint16_t spi_transfer16(uint16_t input16)
{
    uint16_t ret16;
    uint8_t *ret8 = (uint8_t*)&ret16;
    uint8_t *input8 = (uint8_t*)&input16;

    UCB0TXBUF = input8[1];
    while (!(IFG2 & UCB0RXIFG));
    ret8[1] = UCB0RXBUF; //Status

    UCB0TXBUF = input8[0];
    while (!(IFG2 & UCB0RXIFG));
    ret8[0] = UCB0RXBUF; //data
    return ret16;

}
