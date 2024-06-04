/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "main.h"
#include<stdio.h>
#include<stdint.h>


void trobleshoot(){
	uint32_t *rcc = (uint32_t*) 0x40023800;
	uint32_t *rcc1 = (uint32_t*) 0x40023830;
	uint32_t *rcc2 = (uint32_t*) 0x40023840;

	*rcc1 |= 1<<1;
	*rcc2 |= 1<<21;

	uint32_t *p= (uint32_t*) 0x40020400;
	uint32_t *p1= (uint32_t*) 0x40020404;
	uint32_t *p2= (uint32_t*) 0x4002040c;
	uint32_t *p22= (uint32_t*) 0x40020408;
	uint32_t *p3= (uint32_t*) 0x40020424;
	*p |=  (2<<16) | (2<<18);
	*p1 |= (1<<8) | (1<<9);
	*p2 |= (1<<16) | (1<<18);
	*p22 |= (3<<16) | (3<<18);

	*p3 |= (4<<0) | (4<<4);
}

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

#define i2c_base  ((i2c_baseaddr*)0x40005400)

void init(uint32_t addr){




	i2c_base->I2C_CR1 |= 1<<15;
		i2c_base->I2C_CR1 &= ~(1<<15);


	i2c_base->I2C_CR2 = 0x08;

	uint16_t ccrvalue= 0xA0;

	i2c_base->I2C_OAR1 = addr<<1;
	i2c_base->I2C_OAR1 &= ~(1);
	i2c_base->I2C_OAR1 = 1<<14;
	i2c_base->I2C_CCR = 1<<15;
	i2c_base->I2C_CCR = 0x1b;
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
void addr(uint8_t slave){
	i2c_base->I2C_DR = slave<<1;
	while (!(i2c_base->I2C_SR1 & 1<<1 ));

		int dummyread = i2c_base->I2C_SR1;
		 dummyread = i2c_base->I2C_SR2;
}
void recaddr(uint8_t slave,uint8_t *a,uint8_t len){
	ack();

	i2c_base->I2C_DR = slave<<1|1;

	//i2c_base->I2C_CR1 &= ~(1<<10);

	while (!(i2c_base->I2C_SR1 & 1<<1 ));
	int dummyread = i2c_base->I2C_SR1;
	 dummyread = i2c_base->I2C_SR2;
	 if(len==1){
	 nack();
	 stop();
	 while (!(i2c_base->I2C_SR1 & 1<<6 ));

	 *a=i2c_base->I2C_DR;

	 }
	 else{
		 ack();
		 int temp=0;
		 while(len>3){
			 while (!(i2c_base->I2C_SR1 & 1<<6 ));
				 *(a+temp)=i2c_base->I2C_DR;
			//	 printf("%d\n",*a);
				 len--;
				 temp++;
		 }

		 while(!(i2c_base->I2C_SR1 & 1<<2 ));
		 *(a+temp)=i2c_base->I2C_DR;
		 temp++;
		 nack();

		 *(a+temp)=i2c_base->I2C_DR;
		 temp++;
		 while (!(i2c_base->I2C_SR1 & 1<<6 ));
		 stop();
		 *(a+temp)=i2c_base->I2C_DR;

}}

void write(uint8_t *data,int len){

	while(len>0){
		i2c_base->I2C_DR = *data;
		while (!(i2c_base->I2C_SR1 &= 1<<7));
     data++;
		len--;
	}
	}
void stop(){


	while (!(i2c_base->I2C_SR1 &= 132));
			i2c_base->I2C_CR1 = 1<<9;
	}


void nack(){
	i2c_base->I2C_CR1 &= ~(1<<10);
}



int main( )
{
	uint16_t x;
		uint16_t y;
		uint16_t z;
		char a[] = "kannan kck 3";
	int  k = 0x51;
	uint8_t c = 0x6b;
	uint8_t r=0;

		uint8_t c1 = 0x6b;
		uint8_t kck;
		trobleshoot();
	//	pe_enable();
		init(0x62);
	printf("kck\n");
	uint8_t p=0x3b;
	uint8_t p1=0xff;
	//i2c_base->I2C_CR2 = 1<<9;
	uint8_t h=0x1c;
	uint8_t j[6];
	//printf("%d\n",h);

		// start();
		// I2C_Read(0x68, &r, 1);
	pe_enable();
	ack();
	start();

			addr(0x68);
				write(&c,1);
				//write(&p1,1);
				write(&r,1);
			stop();
			pe_enable();
						start();
								addr(0x68);
					write(&h,1);
					write(&r,1);
				stop();
				while(1){
			pe_enable();
			ack();
			start();
					addr(0x68);
					write(&p, 1);
	stop();
	pe_enable();
	start();
	        recaddr(0x68,&j,6);
	        x= (uint16_t) (j[0]<<8|j[1]);
	        float gx = x/16384.0;
	        y= j[2]<<8|j[3];
	        float gy = y/16384.0;
	        z=j[4]<<8|j[5];
	        printf("x=%d\n",gx);
	       // printf("y=%.3f\n",gy);
	       // printf("x=%d\n",x/16384);



	}
}



	/* Private includes ----------------------------------------------------------*/
	/* USER CODE BEGIN Includes */

	/* USER CODE END Includes */

	/* Private typedef -----------------------------------------------------------*/
	/* USER CODE BEGIN PTD */

	/* USER CODE END PTD */

	/* Private define ------------------------------------------------------------*/
	/* USER CODE BEGIN PD */
	/* USER CODE END PD */

	/* Private macro -------------------------------------------------------------*/
	/* USER CODE BEGIN PM */

	/* USER CODE END PM */

	/* Private variables ---------------------------------------------------------*/


	/* USER CODE END PFP */

	/* Private user code ---------------------------------------------------------*/
	/* USER CODE BEGIN 0 */

	/* USER CODE END 0 */

	/**
	  * @brief  The application entry point.
	  * @retval int
	  */












