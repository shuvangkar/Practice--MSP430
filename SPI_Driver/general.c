/*
 * general.c
 *
 *  Created on: Sep 2, 2020
 *      Author: sshuv
 */
#include "general.h"



void set_mcu_clock()
{
#if (MCU_CLOCK == SMCLK_1MHZ)
#warning "SELECTED CLOCK : 1MHZ"
    //Set MCLK = SMCLK = 1MHz
     BCSCTL1 = CALBC1_1MHZ; // Set DCO Clock to 1MHz
     DCOCTL = CALDCO_1MHZ;
#elif
#error "Clock not select"
#endif
}


void delay_us(uint32_t us)
{
    do
    {
       __delay_cycles(1);
    }while(--us);
}
void delay(int32_t ms)
{
    do
    {
        __delay_cycles(1000);
    }while(--ms);

}

