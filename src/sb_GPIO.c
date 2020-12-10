/*
 * sb_GPIO.c
 *
 *  Created on: Dec 6, 2020
 *      Author: cristian
 */

#include "sb_GPIO.h"
#include "sapi.h"

typedef enum{
	B_UP,
	B_DOWN
} buttonState_t;

buttonState_t bState;
delay_t actualizarFSMBoton;

uint8_t buttonPressed(gpioMap_t button) { // @suppress("No return") // @suppress("Type cannot be resolved")

	entryStateButton(button);

    if(delayRead(&actualizarFSMBoton) ){
       update(button);
    }

    switch(bState){
    case B_UP:
    	return 0;
    case B_DOWN:
    	return 1;
    }
}

void entryStateButton(gpioMap_t button) {
	if (!gpioRead(button)) {
		bState = B_DOWN;
	} else {
		bState = B_UP;
	}
}

void update(gpioMap_t button) {

	switch (bState) {

	case B_UP:
		/* CHECK TRANSITION CONDITIONS */
		if (!gpioRead(button)) {
			bState = B_DOWN;
		}
		break;

	case B_DOWN:
		/* CHECK TRANSITION CONDITIONS */
		if (gpioRead(button)) {
			bState = B_UP;
		}
		break;
	}
	delayInit(&actualizarFSMBoton, 40);
}
