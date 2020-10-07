#include <msp430.h> 
#include "general.h"
//#include "nrf24.h"


uint8_t res;
uint8_t res2;

uint8_t tx_addr[] = {'A','B','C','D','E'};
uint8_t payload[] = {1,2,3};
uint8_t read_buf[5];
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	set_mcu_clock();
	P2DIR |= BIT1;             // LED pin as output
	P2DIR |= BIT5; //Accelerometer CS pin
	P2OUT |= BIT5; //Keeping high(acc inactive)

	P3DIR |= BIT7;

//	nrf_begin();
//	nrf_common_begin();
//	nrf_tx_begin();

	while(1)
	{
//	    res = read_register(RF24_EN_AA);
//	    res2 =read_register(RF24_SETUP_AW);
//	    read_bytes_in_register(RF24_RX_ADDR_P0,read_buf,sizeof(read_buf));
//	    nrf_write_tx_payload(payload,sizeof(payload));
//	    res = nrf_status;
//	    nrf_start_transmit();//Strat Trasnmission
	    delay_us(100000);
	    P2OUT ^= BIT1;             ///toggle P2.1 pin
	    P3OUT ^= BIT7;
	}


	return 0;
}
