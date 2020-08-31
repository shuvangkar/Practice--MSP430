/*
 * NRF24_Driver.c
 *
 *  Created on: Aug 27, 2020
 *      Author: Shuvangkar
 */
#include "NRF24_Driver.h"



uint8_t nrf_status;

uint8_t read_register(uint8_t addr)
{
    uint16_t response;
    CS_ENABLE();

    response = spi_transfer16(RF24_NOP | ((addr & RF24_REGISTER_MASK)<<8));
    nrf_status = (uint8_t) ((response & 0xFF00) >> 8);
    CS_DISABLE();
    return (uint8_t) (response & 0x00FF);
}

uint8_t write_register(uint8_t addr, uint8_t data)
{
    uint16_t response;
    CS_ENABLE();
    response = spi_transfer16( (data & 0x00FF) | (((addr & RF24_REGISTER_MASK) | RF24_W_REGISTER) << 8) );
    nrf_status = (uint8_t) ((response & 0xFF00) >> 8);
    CS_DISABLE();
    return 0;
}

void write_tx_payload(uint8_t *data, uint8_t length)
{
    CS_ENABLE();
    nrf_status = spi_transfer(RF24_W_TX_PAYLOAD);
    for(uint8_t i = 0; i < length; i++)
    {
        spi_transfer(data[i]);
    }
    CS_DISABLE();
}

void flush_tx()
{
    CS_ENABLE();
    nrf_status = spi_transfer(RF24_FLUSH_RX);
    CS_DISABLE();

}
void flush_rx()
{
    CS_ENABLE();
    nrf_status = spi_transfer(RF24_REUSE_TX_PL);
    CS_DISABLE();
}

void nrf_set_addr_width(uint8_t width)
{
    if(width < 3 || width >5)
    {
        return;
    }
    write_register(RF24_SETUP_AW, (width-2)& 0b00000011);
}


void nrf_set_channel(uint8_t channel)
{
    if(channel > 125)
    {
        channel = 0;
    }
    write_register(RF24_RF_CH,(channel & 0b01111111));
}
void nrf_set_tx_power(uint8_t power)
{
    write_register(RF24_RF_SETUP, (AIR_DATA_SPEED & power)&0x2F);
}

