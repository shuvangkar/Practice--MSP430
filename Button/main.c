/*
 * @file main_button.c
 * @brief Button takes input and control an LED
 *
 * This is GPIO example. One pin is set as input and another pin is set as output.The button
 * takes input and turn on led when button pressed and turn off led when button released.
 *
 *@author Shuvangkar Shuvo
 * @date 02.04.2020
 */

#include <msp430.h> 

unsigned char pinState = 0;
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	/// stop watchdog timer
	P1DIR |= BIT0;              ///Set P1.0 as output
	P1DIR &= ~BIT3;             ///Set P1.3 as button input
	
	P1REN |= BIT3;              ///Enable Resistor
	P1OUT |= BIT3;              ///Pull up button

	while(1)
	{
	    pinState = P1IN & BIT3;
	    if(pinState)
	    {
	        P1OUT |= BIT0;
	    }
	    else
	    {
	        P1OUT &=~BIT0;
	    }
	}

	return 0;
}
