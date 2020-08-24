#include <msp430.h> 

#include "timerA.h"


uint32_t prev_ms = 0;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P2DIR |= BIT1;                 /// set P2.1 as output mode

	set_mcu_clock();
	timerA_begin();
	_enable_interrupt();
	while(1)
	{
	    if(millis() -prev_ms >=1000 )
	    {
	        prev_ms = ms;
	        P2OUT ^= BIT1;             ///toggle P2.1 pin
	    }
	}

	return 0;
}
