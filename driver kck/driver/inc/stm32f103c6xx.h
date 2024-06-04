/*
 * stm32f103c6xx.h
 *
 *  Created on: Jan 28, 2023
 *      Author: Admin
 */

#ifndef INC_STM32F103C6XX_H_
#define INC_STM32F103C6XX_H_
#include <stdint.h>
#define VO volatile

//interrupt handle

typedef struct{
	uint32_t NVIC_ISERS[2];

}NVIC_ISER_REG;

typedef struct{
	uint32_t NVIC_ICERS[2];
}NVIC_ICER_REG;

typedef struct {
	uint32_t NVIC_IPRS[20];
}NVIC_PRI;

#define NVIC_ISER ((NVIC_ISER_REG*)NVIC_BASEADDR)
#define NVIC_ICER ((NVIC_ICER_REG*)NVIC_ICER_BASE)
#define NVIC_IPR  ((NVIC_PRI*)NVIC_PRIORITY)
#define NVIC_ISPRx  (uint32_t*) (NVIC_BASEADDR+0x100)
#define NVIC_ICPRx  (uint32_t*) (NVIC_BASEADDR+0x180)

#define NVIC_BASEADDR 0xE000E100
#define NVIC_ICER_BASE (NVIC_BASEADDR+0x080)
#define NVIC_PRIORITY  (NVIC_BASEADDR+0x300)






















// memory address
#define FLASH_ADDR 0x08000000U
#define SRAM_ADDR  0x20000000U

//clock address
#define AHB_ADDR 0x40018000U
#define APB1_ADDR 0x40000000U
#define APB2_ADDR 0x40010000U

#define RESET_RCC 0x40021000U
//APB2 ADDRESS INTERFACE
#define GPIOA_BASEADDR (APB2_ADDR+0x0800)
#define GPIOB_BASEADDR (APB2_ADDR+0x0C00)
#define GPIOC_BASEADDR (APB2_ADDR+0x1000)
#define GPIOD_BASEADDR  (APB2_ADDR+0x1400)
#define GPIOE_BASEADDR  (APB2_ADDR+0x1800)
#define GPIOF_BASEADDR  (APB2_ADDR+0x1800)
#define GPIOG_BADEADDR (APB2_ADDR+0x2000)



#define USART_BASEADDR (APB2_ADDR+0x3800)

#define EXTI_BASEADDR (APB2_ADDR+0x0400)
#define AFIO_BASEADDR (APB2_ADDR+0X0000)

//APB1 ADDRESS INTERFACE

#define I2C1_BASEADDR (APB1_ADDR+0x5400)
#define I2C2_BADEADDR (APB1_ADDR+0x5800)


#define USART2_BASEADDR (APB1_ADDR+0x5400)
#define USART3_BASEADDR (APB1_ADDR+0x4800)
#define UART4_BASEADDR (APB1_ADDR+0x4C00)
#define UART5_BASEADDR (APB1_ADDR+0x5000)

#define SPI1_BASEADDR (APB2_ADDR+0x3000)
#define SPI2_BASEADDR (APB1_ADDR+0x3800)
#define SPI3_BASEADDR (APB1_ADDR+0x3C00)



typedef struct{
 VO	uint32_t CRL;
 VO	uint32_t CRH;
 VO	uint32_t IDR;
 VO	uint32_t ODR;
 VO	uint32_t BSRR;
 VO	uint32_t BRR;
 VO	uint32_t LCKR;

}GPIO_TYPE ;

#define GPIOA  ((GPIO_TYPE*)GPIOA_BASEADDR)
#define GPIOB  ((GPIO_TYPE*)GPIOB_BASEADDR)
#define GPIOC  ((GPIO_TYPE*)GPIOC_BASEADDR)
#define GPIOD  ((GPIO_TYPE*)GPIOD_BASEADDR)
#define GPIOE  ((GPIO_TYPE*)GPIOE_BASEADDR)
#define GPIOF  ((GPIO_TYPE*)GPIOF_BASEADDR)
#define GPIOG  ((GPIO_TYPE*)GPIOG_BASEADDR)

typedef struct{
	VO uint32_t RCC_CR;
	VO uint32_t RCC_CFGR;
	VO uint32_t RCC_CIR;
	VO uint32_t RCC_APB2RSTR;
	VO uint32_t RCC_APB1RSTR;
	VO uint32_t RCC_AHBENR;
	VO uint32_t RCC_APB2ENR;
	VO uint32_t RCC_APB1ENR;
	VO uint32_t RCC_BDCR;
	VO uint32_t RCC_CSR;
	VO uint32_t RCC_AHBSTR;
	VO uint32_t RCC_CFGR2;

}RCC_BASEADDR;

typedef struct {

	VO	uint32_t EXTI_IMR;
	VO  uint32_t EXTI_EMR;
	VO  uint32_t EXTI_RTSR;
	VO  uint32_t EXTI_FTSR;
	VO  uint32_t EXTI_SWIER;
	VO  uint32_t EXTI_PR;
}EXTI_REG;


typedef struct{
	VO uint32_t AFIO_EVCR ;
	VO uint32_t AFIO_MAPR ;
	VO uint32_t AFIO_EXTICR[3] ;


	VO uint32_t AFIO_MAPR2 ;
}AFIO_TYPE;

#define AFIO ((AFIO_TYPE*)AFIO_BASEADDR)

#define GPIOA_EXIT 0x0
#define GPIOB_EXIT 0x1
#define GPIOC_EXIT 0x2
#define GPIOD_EXIT 0x3



#define RCC ((RCC_BASEADDR*)RESET_RCC)
#define EXTI ((EXTI_REG*)EXTI_BASEADDR)

// CLOCK ENABLE FOR PORT GPIO
#define PORTA_CLK_EN() ((RCC->RCC_APB2ENR) |= (1<<2))
#define PORTB_CLK_EN() ((RCC->RCC_APB2ENR) |= (1<<3))
#define PORTC_CLK_EN() ((RCC->RCC_APB2ENR) |= (1<<4))
#define PORTD_CLK_EN() ((RCC->RCC_APB2ENR) |= (1<<5))
#define PORTE_CLK_EN() ((RCC->RCC_APB2ENR) |= (1<<6))

//CLOCK ENABLE FOR SPI


#define SPI1_CLK_EN() ((RCC->RCC_APB2ENR) |= (1<<12))
#define SPI2_CLK_EN() ((RCC->RCC_APB1ENR) |= (1<<14))
#define SPI3_CLK_EN() ((RCC->RCC_APB1ENR) |= (1<<15))



//CLOCK ENABLE FOR USART
#define USART1_CLK_EN() ((RCC->RCC_APB2ENR) |= (1<<14))
#define USART2_CLK_EN() ((RCC->RCC_APB1ENR) |= (1<<17))
#define USART3_CLK_EN() ((RCC->RCC_APB1ENR) |= (1<<18))
#define UART4_CLK_EN() ((RCC->RCC_APB1ENR) |= (1<<19))
#define UART5_CLK_EN() ((RCC->RCC_APB1ENR) |= (1<<20))

//CLOCK ENABLE FOR I2C
#define I2C1_CLK_EN() ((RCC->RCC_APB1ENR)|= (1<<21))
#define I2C2_CLK_EN() ((RCC->RCC_APB1ENR)|= (1<<22))

#define AFIO_CLK_EN() (RCC->RCC_APB2ENR |= 1)



//CLOCK DISABLE FOR PORT GPIO

#define PORTA_CLK_DI() ((RCC->RCC_APB2ENR) &= ~(1<<2))
#define PORTB_CLK_DI() ((RCC->RCC_APB2ENR) &= ~(1<<3))
#define PORTC_CLK_DI() ((RCC->RCC_APB2ENR) &= ~(1<<4))
#define PORTD_CLK_DI() ((RCC->RCC_APB2ENR) &= ~(1<<5))
#define PORTE_CLK_DI() ((RCC->RCC_APB2ENR) &= ~(1<<6))

//CLOCK DISABLE FOR SPI
#define SPI1_CLK_DI() ((RCC->RCC_APB2ENR) &= ~(1<<12))
#define SPI2_CLK_DI() ((RCC->RCC_APB1ENR) &= ~(1<<14))
#define SPI3_CLK_DI() ((RCC->RCC_APB1ENR) &= ~(1<<15))

//CLOCK DISABLE FOR USART
#define USART1_CLK_DI() ((RCC->RCC_APB2ENR) &= ~(1<<14))
#define USART2_CLK_DI() ((RCC->RCC_APB1ENR) &= ~(1<<17))
#define USART3_CLK_DI() ((RCC->RCC_APB1ENR) &= ~(1<<18))
#define UART4_CLK_DI() ((RCC->RCC_APB1ENR) &= ~(1<<19))
#define UART5_CLK_DI() ((RCC->RCC_APB1ENR) &= ~(1<<20))

//CLOCK DISABLE FOR I2C
#define I2C1_CLK_DI() ((RCC->RCC_APB1ENR)&= ~(1<<21))
#define I2C2_CLK_DI() ((RCC->RCC_APB1ENR)&= ~(1<<22))


#define AFIO_CLK_DI() (RCC->RCC_APB2ENR &= ~(1))




#include "driver_gpio_kck.h"
#include"stm32f103c6spi.h"
#include"I2C_driver.h"


#endif /* INC_STM32F103C6XX_H_ */
