/*
 * show_UART.h
 *
 *  Created on: Dec 6, 2020
 *      Author: cristian
 */

#ifndef _TP_SHOW_UART_H_
#define _TP_SHOW_UART_H_

#include "sapi.h"

void init (void);

uint8_t UART_sendInfo(char* information);

uint8_t UART_receiveInfo(char* information, uint8_t* size);

#endif /* EJERCICIOS_ESPECIALIZACION_TPFINALPDM_INC_SHOW_UART_H_ */
