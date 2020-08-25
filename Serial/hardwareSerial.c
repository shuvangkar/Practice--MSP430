/*
 * hardwareSerial.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Shuvangkar
 */

#include "hardwareSerial.h"

void serial_begin(void)
{
    /*
     * PxSEL & PxSEL2 both registers select the pin attribute
     */
    P1SEL |= BIT1+BIT2;
    P1SEL2 |= BIT1+BIT2;  //P1.1 = RXD | P1.2 = TXD
    UCA0CTL1 |= UCSWRST;  //USCI logic held in reset state means disabled

    UCA0CTL1 |= UCSSEL_2; //SMCLK clock source

    UCA0BR0 = 104;        // 104 defined in datasheet for 9600 baudrate while SMCLK is selected
    UCA0BR1 = 0x00;       //ignore
    UCA0MCTL = UCBRS_1;   //modulation stage comes from baud rate table.
    UCA0CTL0 = 0x00;                        //ignore
    UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**

}
void serial_print(char *str)
{
    /*
     * UCBUSY Flag =
     * 1 USCI transmitting or receiving
     * 0 USCI inactive
     */
    while(*str)
    {
        UCA0TXBUF = *str;
        while(UCA0STAT & UCBUSY);
        str++;
    }

}

void set_mcu_clock(void)
{
    //Set MCLK = SMCLK = 1MHz
    BCSCTL1 = CALBC1_1MHZ; // Set DCO Clock to 1MHz
    DCOCTL = CALDCO_1MHZ;
}
