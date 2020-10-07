#include <msp430.h> 
#include "interrupt.h"


/**
 * main.c
 */

void btnIsr();

int main(void)
{

	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= BIT6;
//	attachInterrupt1(0,FALLING,btnIsr);
	attachInterrupt2(2,FALLING,btnIsr);
	return 0;
}

void btnIsr()
{
    P1OUT ^= BIT6;
}
