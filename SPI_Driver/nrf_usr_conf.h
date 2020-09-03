/*
 * nrf_usr_conf.h
 *
 *  Created on: Sep 2, 2020
 *      Author: sshuv
 */

#ifndef NRF_USR_CONF_H_
#define NRF_USR_CONF_H_




const uint8_t tx_pipe_addr[] = {'C','B',3,4,'A'};
#define ACK_ON

#define AIR_DATA_SPEED  AIR_SPEED_2MB
#define RETRANSMIT_DELAY 4000
#define RETRANSMIT_COUNT 15

#define RF_CHANNALE_NO 120

/********CE PIN **********/
#define CE_PORT_DIR     P3DIR
#define CE_PORT_OUT     P3OUT
#define CE_PIN          BIT7

#define CE_PORT_SET() (CE_PORT_DIR |= CE_PIN)
#define CE_ENABLE()   (CE_PORT_OUT |= CE_PIN)
#define CE_DISABLE()  (CE_PORT_OUT &= ~CE_PIN)


#endif /* NRF_USR_CONF_H_ */
