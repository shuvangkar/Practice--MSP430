#include <msp430.h> 

#include "nrf24.h"


/*********flash commands**********/
#define WB_WRITE_ENABLE       0x06
#define WB_WRITE_DISABLE      0x04
#define WB_CHIP_ERASE         0xc7
#define WB_READ_STATUS_REG_1  0x05
#define WB_READ_DATA          0x03
#define WB_PAGE_PROGRAM       0x02
#define WB_JEDEC_ID           0x9f


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

	P1DIR |= BIT7;

	nrf_begin();
	nrf_common_begin();
	nrf_tx_begin();

	while(1)
	{
//	    CS_ENABLE();
//	    res = spi_transfer(0x00);
//	    res2 = spi_transfer(0xFF);
//	    CS_DISABLE();

//	    write_register(RF24_CONFIG,0b01010111);
	    nrf_set_tx_addr(tx_addr,sizeof(tx_addr));
	    res = read_register(RF24_CONFIG);
	    res2 =read_register(RF24_SETUP_AW);
	    read_bytes_in_register(RF24_TX_ADDR,read_buf,sizeof(read_buf));

//	    res = read_register(RF24_STATUS);
//	    P1OUT |= BIT7;
//	    CS_DISABLE();
//	    CE_ENABLE();
//	    P2OUT |= BIT1;
//	    for(long i = 0; i<400000;i++);
//	    CE_DISABLE();
//	    CS_ENABLE();
//	    P2OUT &=~(BIT1);
//
//	    P1OUT &= ~BIT7;
	    for(long i = 0; i<400000;i++);
	    P2OUT ^= BIT1;             ///toggle P2.1 pin
	}

	return 0;
}
