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
int counter = 0;
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	    /// stop watchdog timer
	P2DIR |= BIT1;                 /// set P2.1 as output mode
	for(;;)
	{
	    P2OUT ^= BIT1;             ///toggle P2.1 pin
	    unsigned long i;
	    for(i = 0; i<20000;i++);
	    counter++;
	}

	return 0;
}
