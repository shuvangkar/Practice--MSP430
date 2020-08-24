/*
 * timerA.c
 *
 *  Created on: Aug 23, 2020
 *      Author: Shuvangkar
 */

#include "timerA.h"

uint32_t ms = 0;

//Timer ISR
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer_A_CCR0_ISR(void)
{
    ms++;
}

uint32_t millis()
{
    return ms;
}
void set_mcu_clock()
{
    //Set MCLK = SMCLK = 1MHz
    BCSCTL1 = CALBC1_1MHZ; // Set DCO Clock to 1MHz
    DCOCTL = CALDCO_1MHZ;
}
void timerA_begin()
{
    TACCR0 = 0; //Initially, Stop the Timer
    TACCTL0 |= CCIE; // Enable counter interrupt on counter compare register 0

    /*
     * IDx = Input divider
     * TASSELx  = Timer_A closk source select
     * MCx  = Timer mode control bits
     */
    TACTL = TASSEL_2 + ID_0 + MC_1; //Clock source = SMCLK | SMCLK/1 | Up Mode
    TACCR0 = 1000-1; // 1KHz Timer
}
