/*
 * nrf24.c
 *
 *  Created on: Aug 31, 2020
 *      Author: sshuv
 */
#include "nrf24.h"


void nrf24_begin()
{
    //begin SPI
    spi_begin();

    write_register(RF24_CONFIG,0b01111100);//Disable interrupt, 2 byte crc, power down, ptx mode
    nrf_set_addr_width(5);
    //Select Channel
    //set output power
    nrf_set_tx_power(MINUS_18_DBM);
    //set air data rate
    //Enable CRC
    //
}
