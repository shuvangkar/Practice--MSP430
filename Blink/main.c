/*
 * @file main_blink.c
 * @brief Hello world program for msp430
 *
 * This is the first program for the msp430 microcontroller series.
 * This just toggle an led after a certain interval
 *
 * @author Shuvangkar Shuvo
 * @date 30.03.2020
 */

#include <msp430.h> 

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	    /// stop watchdog timer
	P1DIR |= BIT0;                 /// set PI.0 as output mode
	for(;;)
	{
	    P1OUT ^= BIT0;             ///toggle P1.0 pin
	    unsigned long i;
	    for(i = 0; i<20000;i++);
	}

	return 0;
}
