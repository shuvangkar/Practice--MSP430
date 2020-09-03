/*
 * NRF24_Driver.c
 *
 *  Created on: Aug 27, 2020
 *      Author: Shuvangkar
 */
#include "NRF24_Driver.h"
#include "nRF24_register.h"

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

uint8_t write_bytes_in_register(uint8_t addr,uint8_t *payload, uint8_t len)
{
    uint8_t *ptr = payload;
    CS_ENABLE();
    nrf_status = spi_transfer(addr | RF24_W_REGISTER);
    for(uint8_t i = 0; i< len ; i++)
    {
        spi_transfer(ptr[i]);
    }
    CS_DISABLE();
    return nrf_status;
}

uint8_t *read_bytes_in_register(uint8_t addr,uint8_t *bucket,uint8_t len)
{
    uint8_t *ptr = bucket;
    CS_ENABLE();
    nrf_status = spi_transfer(addr & RF24_REGISTER_MASK);
    for(uint8_t i = 0; i< len; i++)
    {
        ptr[i] = spi_transfer(0xFF);
    }
    CS_DISABLE();
    return bucket;
}

void nrf_set_tx_addr(uint8_t *addr,uint8_t len)
{
    write_bytes_in_register(RF24_TX_ADDR,addr,len);
}

void nrf_set_rx_addr(uint8_t *addr, uint8_t len, uint8_t pipe)
{
    if(pipe > 5)
    {
        pipe = 1;
    }
    write_bytes_in_register(RF24_RX_ADDR_P0+pipe,addr,len);
}
void write_tx_payload(uint8_t *data, uint8_t len)
{
    write_bytes_in_register(RF24_W_TX_PAYLOAD,data,len);
//    CS_ENABLE();
//    nrf_status = spi_transfer(RF24_W_TX_PAYLOAD);
//    for(uint8_t i = 0; i < len; i++)
//    {
//        spi_transfer(data[i]);
//    }
//    CS_DISABLE();
}
uint8_t *read_rx_payload(uint8_t *data, uint8_t len)
{
    return read_bytes_in_register(RF24_R_RX_PAYLOAD,data,len);
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
    //If channel exceeds rset value to 100 channel.
    if(channel > 125)
    {
        channel = 100;
    }
    write_register(RF24_RF_CH,(channel & 0b01111111));
}
void nrf_set_tx_dbm_speed(uint8_t power_speed)
{
    write_register(RF24_RF_SETUP, (power_speed)&0x2F);
}


