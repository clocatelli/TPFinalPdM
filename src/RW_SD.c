/*
 * RW_SD.c
 *
 *  Created on: Dec 6, 2020
 *      Author: cristian
 */
#include "sapi.h"     // <= sAPI header

#include "ff.h"       // <= Biblioteca FAT FS
#include "fssdc.h"      // API de bajo nivel para unidad "SDC:" en FAT FS

#define FILENAME "SDC:/hola.txt"

static FATFS fs;           // <-- FatFs work area needed for each volume
static FIL fp;             // <-- File object needed for each open file

UINT nbytes;

void initSPI(){
	   // SPI configuration
	   spiConfig( SPI0 );

	   // Initialize SD card driver
	   FSSDC_InitSPI ();
	   // Give a work area to the default drive
	   if( f_mount( &fs, "SDC:", 0 ) != FR_OK ) {
	      // If this fails, it means that the function could
	      // not register a file system object.
	      // Check whether the SD card is correctly connected
	   }
}

uint8_t writeSD(char* writeBuff, uint8_t size) {
	uint8_t i = 0;

	for (i = 0; i < 5; i++) {

		if (f_open(&fp, FILENAME, FA_WRITE | FA_OPEN_ALWAYS) == FR_OK) {
			f_write(&fp, writeBuff, size, &nbytes);

			f_close(&fp);

			if (nbytes == size) {
				// Turn ON LEDG if the write operation was successful
				gpioWrite(LEDG, ON);
			}
		} else {
			// Turn ON LEDR if the write operation was fail
			gpioWrite(LEDR, ON);
		}
	}
}

uint8_t readSD(char* readBuff, uint8_t size) {
	uint8_t i = 0;
	for (i = 0; i < 5; i++) {

		if (f_open(&fp, FILENAME, FA_READ) == FR_OK) {
			f_read(&fp, readBuff, size, &nbytes);

			f_close(&fp);

			if (nbytes == size) {
				// Turn ON LEDG if the write operation was successful
				gpioWrite(LEDG, ON);
				return 1;
			}
		} else {
			// Turn ON LEDR if the write operation was fail
			gpioWrite(LEDR, ON);
			return 0;
		}
	}
}
