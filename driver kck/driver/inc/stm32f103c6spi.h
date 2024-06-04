/*
 * stm32f103c6spi.h
 *
 *  Created on: 21-Mar-2023
 *      Author: Admin
 */


#ifndef INC_STM32F103C6SPI_H_
#define INC_STM32F103C6SPI_H_
//base address of spi communication
#include "stm32f103c6xx.h"
#include "driver_gpio_kck.h"




typedef struct{
VO uint32_t SPI_CR1 ;
VO uint32_t SPI_CR2 ;
VO uint32_t SPI_SR ;
VO uint32_t SPI_DR;
VO uint32_t SPI_CRCPR;
VO uint32_t SPI_RXCRCR;
VO uint32_t SPI_TXCRCR;
VO uint32_t SPI_I2SCFGR;
VO uint32_t SPI_I2SPR;
}spi_config;

#define spi_IN ((spi_config*)SPI1_BASEADDR)


// spi initialize
void spi_en(uint8_t c);

void spi_init ();
void spi_deinit();

//spi data transfer
void spi_send(uint8_t *p,uint8_t len);

//spi data receiver
void  spi_receive(uint8_t *data,uint8_t len);




#endif /* INC_STM32F103C6SPI_H_ */
