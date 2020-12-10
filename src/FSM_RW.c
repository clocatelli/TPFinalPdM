/*
 * MEF_RW.c
 *
 *  Created on: Dec 6, 2020
 *      Author: cristian
 */

#include "sb_GPIO.h"
#include "RW_SD.h"
#include "show_UART.h"
#include "FSM_RW.h"
#include "sapi.h"

typedef enum {
	WAITING_WRITE, WAITING_READ, WRITING, SHOWING
} FSMState_t;

FSMState_t FSMState;
char info[200];
uint8_t size;

void entryState() {
	FSMState = WAITING_WRITE;
}

void FSM_State() {

	switch (FSMState) {

	case WAITING_WRITE:
		/* CHECK TRANSITION CONDITIONS */
		if (buttonPressed(TEC1)) { // @suppress("Symbol is not resolved")
			UART_sendInfo("TEC1 Pressed. Waiting for input.\r\n");
			FSMState = WRITING;
		}
		break;

	case WAITING_READ:
		/* CHECK TRANSITION CONDITIONS */
		if (buttonPressed(TEC2)) { // @suppress("Symbol is not resolved")
			UART_sendInfo("TEC2 Pressed\r\n");
			FSMState = SHOWING;
		}
		break;

	case WRITING:
		/* CHECK TRANSITION CONDITIONS */
		if (UART_receiveInfo(info, &size)) {
			if(writeSD(info, size)){
				UART_sendInfo("Writing SD. Waiting for TEC2 to show.\r\n");
				FSMState = WAITING_READ;
			}
		}
		break;

	case SHOWING:
		/* CHECK TRANSITION CONDITIONS */
		if (readSD(info, size)) {
			UART_sendInfo("Reading SD\r\n");
			if(UART_sendInfo(info)) {
				FSMState = WAITING_WRITE;
			}
		}
		break;
	}
}
