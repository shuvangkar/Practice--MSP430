/*
 * NRF24_Driver.h
 *
 *  Created on: Aug 27, 2020
 *      Author: Shuvangkar
 */

#ifndef NRF24_DRIVER_H_
#define NRF24_DRIVER_H_
#include <stdint.h>
#include "general.h"
#include "SPI.h"
#include "nRF24_register.h"

#define AIR_DATA_SPEED  AIR_SPEED_2MB



uint8_t read_register(uint8_t addr);
uint8_t write_register(uint8_t addr, uint8_t data);

void write_tx_payload(uint8_t *data, uint8_t length);

void flush_tx();
void flush_rx();

void nrf_set_addr_width(uint8_t width);
void nrf_set_channel(uint8_t channel);
void nrf_set_tx_power(uint8_t power);
//void nrf_set_air_speed(uint8_t speed);

extern uint8_t nrf_status;
#endif /* NRF24_DRIVER_H_ */
