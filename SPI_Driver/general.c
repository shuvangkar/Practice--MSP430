/*
 * general.c
 *
 *  Created on: Sep 2, 2020
 *      Author: sshuv
 */
#include "general.h"

void delay(int32_t ms)
{
    do
    {
        __delay_cycles(1000);
    }while(--ms);

}

