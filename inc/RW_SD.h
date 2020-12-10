/*
 * RW_SD.h
 *
 *  Created on: Dec 6, 2020
 *      Author: cristian
 */

#ifndef _TP_RW_SD_H_
#define _TP_RW_SD_H_

void initSPI();
uint8_t writeSD(char* writeBuff, uint8_t size);
uint8_t readSD(char* readBuff,  uint8_t size);


#endif /* EJERCICIOS_ESPECIALIZACION_TPFINALPDM_INC_RW_SD_H_ */
