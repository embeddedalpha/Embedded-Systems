/*
 * GC9A01_I2C.h
 *
 *  Created on: 04-Jun-2021
 *  Updated on: 07-Jun-2021
 *      Author: Kunal
 */

#ifndef GC9A01_LCD_DRIVER_GC9A01_H_
#define GC9A01_LCD_DRIVER_GC9A01_H_

#include "main.h"
#include "SPI/SPI.h"
#include "GPIO/GPIO.h"

struct SPI_Config GC9A01;

void GC9A01_DC_Low(void);

void GC9A01_DC_High(void);

void GC9A01_Init(SPI_TypeDef *SPI);

void GC9A01_Send_Command(uint8_t command, uint8_t data);

void GC9A01_RS_Low(void);

void GC9A01_RS_High(void);

void GC9A01_Send_Buffer_Data(uint8_t *buffer, int length);


#endif /* GC9A01_LCD_DRIVER_GC9A01_H_ */
