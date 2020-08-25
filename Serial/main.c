#include <msp430.h> 

#include "hardwareSerial.h"


/**
 * main.c
 */

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	set_mcu_clock();
	serial_begin();
	P2DIR |= BIT1;                 /// set P2.1 as output mode
	


	while(1)
	{
	    serial_print("Hello \n");
	    serial_print_int(123);
	    for(long i = 0; i<40000;i++);
	    P2OUT ^= BIT1;             ///toggle P2.1 pin

	}

	return 0;
}
