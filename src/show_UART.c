/*
 * show_UART.c
 *
 *  Created on: Dec 6, 2020
 *      Author: cristian
 */

#include "show_UART.h"
#include "sapi.h"


void init (void)
{
	// Inicializar UART_USB a 115200 baudios
	uartConfig( UART_USB, 115200 );

}

uint8_t UART_receiveInfo(char* information, uint8_t* size) {
	char dato = 0;
	uint8_t i = 0;
	while (1) {
		// Si recibe un byte de la UART_USB lo guardarlo en la variable dato.
		if (uartReadByte(UART_USB, &dato)) {
			if (dato != '\r') {
				information[i] = dato;
				i++;
			} else {
				information[i] = '\r';
				information[i + 1] = '\n';
				*size = i + 2;
				return 1;
			}
		}
	}
	return 0;
}

uint8_t UART_sendInfo(char* information)
{
	uint8_t i = 0;
	while (information[i] != '\r') {
	    uartWriteByte(UART_USB, information[i]);
	    i++;
	}
	if(information != NULL)
	{
		uartWriteString( UART_USB, "\r\n" );
		return 1;
	} else {
		return 0;
	}
}




