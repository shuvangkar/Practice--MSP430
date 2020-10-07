/*
 * NRF24_Driver.h
 *
 *  Created on: Aug 27, 2020
 *      Author: Shuvangkar
 */

#ifndef NRF24_DRIVER_H_
#define NRF24_DRIVER_H_
#include <msp430.h>
#include <stdint.h>
#include "general.h"
#include "SPI.h"
#include "nRF24_register.h"


#define CE_PORT_SET() (CE_PORT_DIR |= CE_PIN)
#define CE_ENABLE()   (CE_PORT_OUT |= CE_PIN)
#define CE_DISABLE()  (CE_PORT_OUT &= ~CE_PIN)

uint8_t read_register(uint8_t addr);
uint8_t write_register(uint8_t addr, uint8_t data);

uint8_t write_bytes_in_register(uint8_t addr,uint8_t *payload,uint8_t len);
uint8_t *read_bytes_in_register(uint8_t addr,uint8_t *bucket,uint8_t len);

void nrf_set_tx_addr(uint8_t *addr,uint8_t len);
void nrf_set_rx_addr(uint8_t *addr, uint8_t len, uint8_t pipe);

void nrf_write_tx_payload(uint8_t *data, uint8_t len);
uint8_t *nrf_read_rx_payload(uint8_t *data, uint8_t len);

void nrf_flush_tx();
void nrf_flush_rx();

void nrf_set_addr_width(uint8_t width);
void nrf_set_channel(uint8_t channel);
void nrf_set_tx_dbm_speed(uint8_t);

void nrf_start_transmit();
void nrf_start_receive();
//void nrf_set_air_speed(uint8_t speed);





extern uint8_t nrf_status;
#endif /* NRF24_DRIVER_H_ */
