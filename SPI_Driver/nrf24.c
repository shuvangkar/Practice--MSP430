/*
 * nrf24.c
 *
 *  Created on: Aug 31, 2020
 *      Author: sshuv
 */
#include "nrf24.h"


//void nrf24_begin()
//{
//    //begin SPI
//    spi_begin();
//    //Wait 100ms
//
//
//
//    //Set address width of the register
//    //Select Channel
//
//    //set output power
//    nrf_set_tx_power(MINUS_12_DBM);
//}

void nrf_begin()
{
    //begin SPI
    spi_begin();
    //send NOP
    spi_transfer(RF24_NOP);
    //Wait 100ms
    delay(100);
}

void nrf_common_begin()
{
    //Disable all RX pipes
    write_register(RF24_EN_RXADDR, 0x00);
    //disable auto acknowledgment
    write_register(RF24_EN_AA, 0x00);
    //disable dynamic payload
    write_register(RF24_DYNPD, 0x00);
    //Set address width of the register
    nrf_set_addr_width(5);//

}

void nrf_tx_begin()
{
    //Set basic Config
    write_register(RF24_CONFIG,
                   DIS_ALL_INT   |
                   CRC_EN_2_BYTE |
                   PWR_DOWN      |
                   TX_MODE);

    //set tx power
    nrf_set_tx_power(MINUS_12_DBM);
    //in TX mode only enable acknowledge only in data pipe 0
    //Set pipe data pipe address
    //set same address as pipe 0 address
}

void nrf_rx_begin()
{

    //Set basic Config
    write_register(RF24_CONFIG,
                   DIS_ALL_INT   |
                   CRC_EN_2_BYTE |
                   PWR_UP        |
                   RX_MODE);

}
