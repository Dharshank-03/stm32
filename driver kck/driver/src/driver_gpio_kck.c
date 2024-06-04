/*
 * driver_gpio_kck.c
 *
 *  Created on: 29-Jan-2023
 *      Author: Admin
 */

#include "driver_gpio_kck.h"

void GPIO_periclkcont(GPIO_TYPE *GPIOX,uint8_t enordi){
	if (enordi==enable ){
		if (GPIOX==GPIOA)
			PORTA_CLK_EN();
		else if (GPIOX==GPIOB)
			PORTB_CLK_EN();
		else if (GPIOX==GPIOC)
			PORTC_CLK_EN();
		else if (GPIOX==GPIOD)
			PORTD_CLK_EN();
		else if (GPIOX==GPIOE)
			PORTE_CLK_EN();


	}
	else {
		if (GPIOX==GPIOA)
					PORTA_CLK_DI();
				else if (GPIOX==GPIOB)
					PORTB_CLK_DI();
				else if (GPIOX==GPIOC)
					PORTC_CLK_DI();
				else if (GPIOX==GPIOD)
					PORTD_CLK_DI();
				else if (GPIOX==GPIOE)
					PORTE_CLK_DI();


	}
}

void GPIO_CONFIG( uint16_t pinnumber,uint16_t mode,GPIO_TYPE *GPIOX ){

	 if (pinnumber<=7){
		 GPIOX->CRL &= ~( 0xF << (4*pinnumber ));
	 	 GPIOX->CRL |= (mode << (4*pinnumber));
	 }
	 else if(pinnumber>=8){
		 GPIOX->CRH &= ~(0XF << (4*(pinnumber-8)));
		 GPIOX->CRH |= (mode << (4*(pinnumber-8)));
	 }

}
uint8_t GPIO_readfrominputpin(GPIO_TYPE *GPIOX,uint8_t pinnumber){
	//GPIOX->IDR |= (1<<pinnumber);
	uint8_t value = (uint8_t) ((GPIOX->IDR >> pinnumber)&0x1) ;
	return value;
}
void GPIO_writetooutputpin(uint8_t pinnumber,uint8_t value,GPIO_TYPE *GPIOX  ){
	if (value ==1 )
	GPIOX->ODR |= (value<<pinnumber);
	else
	GPIOX->ODR &= value<<pinnumber;
}
void interrupt_en(uint32_t GPIOPIN,uint32_t GPIOX_EXIT,uint32_t type) {
	//exti enable
	EXTI->EXTI_IMR |= (1<<GPIOPIN);
	//TYPE OF INTERRUPT
	if(type==3){
		EXTI->EXTI_RTSR |=(1<<GPIOPIN);
	}
	else if (type==2){
		EXTI->EXTI_FTSR=(1<<GPIOPIN);
	}
	//enable the pin
	//AFIO->AFIO_EXTICR[GPIOPIN/4] &= ~(0X0 << ((GPIOPIN%4)*4));
 if (GPIOX_EXIT==0){
	 AFIO->AFIO_EXTICR[GPIOPIN/4] |= ~((0XF)<< (GPIOPIN%4)*4);
 }
	AFIO->AFIO_EXTICR[GPIOPIN/4] |= (GPIOX_EXIT << ((GPIOPIN%4)*4)) ;





}


void GPIO_IRQinterrupt(uint32_t IRQNUMBER,uint8_t enordi){
	if(enordi==1)
    NVIC_ISER->NVIC_ISERS[(IRQNUMBER/32)] |= 1<<(4%32);
	else
    NVIC_ICER->NVIC_ICERS[IRQNUMBER/32] |= 1<<(IRQNUMBER%32);
   // NVIC_ISER->NVIC_ISERS[IRQNUMBER-7] |= 1<<7;


}
void GPIO_IRQCONFIG(uint8_t IRQNUMBER,uint32_t IRQPRIORITY){
	NVIC_IPR->NVIC_IPRS[IRQNUMBER/4] |= IRQPRIORITY << (((IRQNUMBER%4)*8)+4);
	}

void GPIOIRQ_HANDLE(uint32_t pinnumber){
  if( *NVIC_ICPRx & (1<<pinnumber)){
      *NVIC_ICPRx |= (1<<pinnumber);

  }
	}













