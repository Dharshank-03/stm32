/*
 * driver_spi_kck.c
 *
 *  Created on: 21-Mar-2023
 *      Author: Admin
 */
#include "driver_gpio_kck.h"
#include "stm32f103c6spi.h"

void spi_init (){
       // mode{
	SPI1_CLK_EN();
	spi_IN->SPI_CR1 |= (0<<0);
	spi_IN->SPI_CR1 |= (0<<1);
	spi_IN->SPI_CR1 |= (1<<2);
	//SPEED
	spi_IN->SPI_CR1 |= (3<<3);
	//spi_IN->SPI_CR1 |= (1<<10);
	//enable
	//spi_IN->SPI_CR1 |= (1<<7);
	///
	//spi_IN->SPI_CR1 |= (1<<11);
	spi_IN->SPI_CR2=0;
}

void spi_send(uint8_t *p,uint8_t len){
		while (len>0){
			if ((spi_IN->SPI_SR) & (1<<1)){
				spi_IN->SPI_DR = *(p);
           //      int a =spi_IN->SPI_DR;
			   p++;
			   len--;
			}

	}
		  uint8_t temp = spi_IN->SPI_DR;
		  temp = spi_IN->SPI_SR;


}
void spi_receive(uint8_t *data,uint8_t len){

	while(len>0){
	if (spi_IN->SPI_SR & 1){
		*data=spi_IN->SPI_DR;
	//	int a=spi_IN->SPI_DR;
		data++;
		len--;
	}

}
}
void spi_ssoe(uint8_t c){
	if (c==1){
		spi_IN->SPI_CR2 |= (1<<2);
	}
}
void spi_en (uint8_t c){
	if(c==1){
		spi_IN->SPI_CR1 |= (1<<2);
		spi_IN->SPI_CR1 |= (1<<6);
	}
	else
		spi_IN->SPI_CR1 &= ~(1<<6);
}
void spi_ssi(uint8_t a){
	if (a==1){
		spi_IN->SPI_CR1 |= (1<<9);
		spi_IN->SPI_CR1 |= (1<<8);






	}
}

