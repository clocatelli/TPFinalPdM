/*
 * sb_GPIO.h
 *
 *  Created on: Dec 6, 2020
 *      Author: cristian
 */

#ifndef _TP_SB_GPIO_H_
#define _TP_SB_GPIO_H_

#include "sapi.h"

uint8_t buttonPressed(gpioMap_t button);
void entryStateButton(gpioMap_t button);
void update(gpioMap_t button);


#endif /* _TP_SB_GPIO_H_ */
