/*
 *  nrf24.h
 *
 *  Created on: Aug 31, 2020
 *  Author: sshuv
 */
#include <stdint.h>
#include "SPI.h"
#include "NRF24_Driver.h"


void nrf_begin();
void nrf_common_begin();
void nrf_tx_begin();
void nrf_rx_begin();


