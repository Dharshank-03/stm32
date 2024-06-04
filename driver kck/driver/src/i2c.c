/*
 * i2c.c
 *
 *  Created on: 19-Apr-2023
 *      Author: Admin
 */

#include "stm32f103c6xx.h"
#include "I2C_driver.h"


int clkapb(){
	int temp;
	temp = *clkaddr>>4 & 15;
	int	clk;
	int n=1;
	while (temp>=8){


	int	clk=8/(2*n);
		n=n*2;
	}
	return clk;
}
int clkapb1(int hsi){
	int n=1;
	int temp;
	temp= *clkaddr>>8 & 15;
	int clk1;
	while(temp>=4){
		int clk1=hsi/(2*n);
		n=n*2;
	}
return clk1;
}




void init(uint8_t addr,uint32_t speed,uint8_t ack){



i2c_base->I2C_CR1 |= 1<<15;
i2c_base->I2C_CR1 &= ~(1<<15);


int clk = clkapb();
int ccr = clkapb1(clk);

i2c_base->I2C_CR2 = 0x08;

uint16_t ccrvalue= (ccr/1000000)/(speed/1000000);

i2c_base->I2C_OAR1 = addr<<1;
i2c_base->I2C_OAR1 &= ~(1);
i2c_base->I2C_OAR1 = 1<<14;
i2c_base->I2C_CCR = 0x50;
i2c_base->I2C_TRISE = 8+1;


}
void ack(){
	i2c_base->I2C_CR1 |= 1<<10;
}
void pe_enable(){
	i2c_base->I2C_CR1 |= 1<<0;

}
void start(){
	i2c_base->I2C_CR1 |= 1<<8;
   //  i2c_base->I2C_SR1 = 1<<0;
	while (!(i2c_base->I2C_SR1 & (1<<0)));
}
void addr(uint32_t slave){
	i2c_base->I2C_DR = slave<<1;
	i2c_base->I2C_DR &= ~(1);

	while (!(i2c_base->I2C_SR1 &= 1<<7)&&(i2c_base->I2C_SR1&= 1<<2));
	int dummyread = i2c_base->I2C_SR1;
	 dummyread = i2c_base->I2C_SR2;

}

void write(uint8_t *data,int len){
	while(len>0){
		i2c_base->I2C_DR = *data;
		while (!(i2c_base->I2C_SR1 &= 1<<7)&&(i2c_base->I2C_SR1&= 1<<2));
		data++;
		len--;

	}
	}
	void stop(){


		   while (!((i2c_base->I2C_SR1 &= 1<<7)&&(i2c_base->I2C_SR1&= 1<<2)));
			i2c_base->I2C_CR1 = 1<<9;
	}


