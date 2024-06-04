/*
 * I2C_driver.h
 *
 *  Created on: 17-Apr-2023
 *      Author: Admin
 */

#ifndef INC_I2C_DRIVER_H_
#define INC_I2C_DRIVER_H_
#include "stm32f103c6xx.h"
#include "driver_gpio_kck.h"

#define i2c I2C1_BASEADDR
#define clkaddr ((uint32_t*)RESET_RCC+0x04)
typedef struct {
	uint32_t I2C_CR1;
	uint32_t I2C_CR2;
	uint32_t I2C_OAR1;
	uint32_t I2C_OAR2;
	uint32_t I2C_DR;
	uint32_t I2C_SR1;
	uint32_t I2C_SR2;
	uint32_t I2C_CCR;
	uint32_t I2C_TRISE;
}i2c_baseaddr;

#define i2c_base  ((i2c_baseaddr*)i2c)

void init(uint8_t addr,uint32_t speed,uint8_t ack);
//void mastersend(uint8_t slave, uint32_t *data, uint32_t len);
void ack();
void pe_enable();
void start();
void addr(uint32_t slave);
void write(uint8_t *data,int len);
void stop();

#endif /* INC_I2C_DRIVER_H_ */
