#include <msp430.h> 

#include "hardwareSerial.h"


/**
 * main.c
 */

uint16_t  counter = 10000;
int32_t test2 = -234567890;
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	set_mcu_clock();
	serial_begin();
	P1DIR |= BIT0;             // set P2.1 as output mode
	P1OUT &=~BIT0;
//	LPM4;
	while(1)
	{
	    counter++;
	    serial_print("\r\nValue : ");
	    serial_print_uint(counter);
//	    serial_print_int2(counter);
//	    serial_print_long(++test2);
	    long i;
	    for(i = 0; i<400000;i++);
	    P1OUT ^= BIT0;             ///toggle P2.1 pin

	}

	return 0;
}
