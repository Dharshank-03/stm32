/*
 * driver_gpio_kck.h
 *
 *  Created on: 29-Jan-2023
 *      Author: Admin
 */

#ifndef INC_DRIVER_GPIO_KCK_H_
#define INC_DRIVER_GPIO_KCK_H_
#include "stm32f103c6xx.h"


typedef struct {
 uint8_t pinnum;
 uint8_t pinmode;
 uint8_t pinspeed;
 uint8_t pinpucontrol;
 uint8_t pinouttype;
 uint8_t pinaltfunc;

}PINCONFIG_T;







typedef struct{
	GPIO_TYPE *GPIOX;
	PINCONFIG_T PINCONFIG;
}GPIO_HANDLE;


/*  API INTERFACE FUNCTI0N
 *
 */
// initialization
void GPIO_CONFIG(uint16_t pinnum,uint16_t mode,GPIO_TYPE *GPIOX );
void GPIO_deinit(GPIO_TYPE *GPIOX);

//clk enable
void GPIO_periclkcont(GPIO_TYPE *GPIOX,uint8_t enordi);

//read and write data
uint8_t GPIO_readfrominputpin(GPIO_TYPE *GPIOX,uint8_t pinnumber);
uint16_t GPIO_readfrominputport(GPIO_TYPE *GPIOX,uint16_t pinnumber);
void GPIO_writetooutputpin(uint8_t pinnumber,uint8_t value,GPIO_TYPE *GPIOX );
void GPIO_writetooutputport(GPIO_TYPE *GPIOX,uint8_t value);

//toggle pin
void GPIO_togglepin(GPIO_TYPE *GPIOX,uint8_t number );

//interrupt handle
void interrupt_en(uint32_t GPIOPIN,uint32_t GPIOX,uint32_t type);
void GPIO_IRQinterrupt(uint32_t IRQNUMBER,uint8_t enordi);
void GPIO_IRQCONFIG(uint8_t pinnumber,uint32_t IRQNUMBER);
void GPIOIRQ_HANDLE(uint32_t pinnumber);

//afio pins

// macros for gpio mode


#define GPIO_INT_FT 2
#define GPIO_INT_RT 3
#define GPIO_INT_RFT 4

//INPUT MODE MACROS
#define GPIO_MODE_INPUT  0X0
#define GPIO_MODE_ANALOG    0x0
#define GPIO_MODE_FLOATING  0x4
#define GPIO_MODE_PULLUP    0x8
#define GPIO_MODE_PULLDOWN  0x8

//OUTPUT MODE MACROS
#define GPIO_MODE_OUTPUT  0X2
#define GPIO_GP_PP 0x2
#define GPIO_AF_PP 0xA
#define GPIO_GP_OP 0x6
#define GPIO_AF_OP 0xe

//OUTPUT SPEED
#define GPIO_LOW_SPEED  2
#define GPIO_MEDIUM_SPEED 1
#define GPIO_HIGH_SPEED 3

//GPIO PIN NUMBER
#define GPIOPIN_NO_0 0
#define GPIOPIN_NO_1 1
#define GPIOPIN_NO_2 2
#define GPIOPIN_NO_3 3
#define GPIOPIN_NO_4 4
#define GPIOPIN_NO_5 5
#define GPIOPIN_NO_6 6
#define GPIOPIN_NO_7 7
#define GPIOPIN_NO_8 8
#define GPIOPIN_NO_9 9
#define GPIOPIN_NO_10 10
#define GPIOPIN_NO_11 11
#define GPIOPIN_NO_12 12
#define GPIOPIN_NO_13 13
#define GPIOPIN_NO_14 14
#define GPIOPIN_NO_15 15

#define enable 1
#define disable 0


#define EXTI0  6
#define EXTI1  7
#define EXTI2  8
#define EXTI3  9
#define EXTI4  10
#define EXTI9_5 23
#define EXTI15_10 40















#endif /* INC_DRIVER_GPIO_KCK_H_ */













