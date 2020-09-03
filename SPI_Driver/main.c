#include <msp430.h> 

#include "nrf24.h"


uint8_t res;
uint8_t res2;

uint8_t tx_addr[] = {'A','B','C','D','E'};
uint8_t read_buf[5];
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
//	spi_begin();
//	CE_PORT_SET();
	P2DIR |= BIT1;             // set P2.1 as output mode

	P2DIR |= BIT5; //Accelerometer CS pin
	P2OUT |= BIT5; //Keeping high(acc inactive)
//	for(long i = 0; i<40000;i++);
//	res = spi_transfer(WB_READ_STATUS_REG_1);
//	res2 = spi_transfer(0xFF);

//	P1DIR |= BIT7;

	nrf_begin();
	nrf_common_begin();
	nrf_tx_begin();

	while(1)
	{
//	    res = read_register(RF24_EN_AA);
//	    res2 =read_register(RF24_SETUP_AW);
//	    read_bytes_in_register(RF24_RX_ADDR_P0,read_buf,sizeof(read_buf));

	    for(long i = 0; i<400000;i++);
	    P2OUT ^= BIT1;             ///toggle P2.1 pin
	}
	nrf_start_transmit();//Strat Trasnmission

	return 0;
}
