/*
 * interrupt.h
 *
 *  Created on: 20-Jun-2023
 *      Author: Admin
 */

#ifndef INC_INTERRUPT_H_
#define INC_INTERRUPT_H_
uint32_t *p = 0xe000e100;

void i2c_inten(uint32_t irq){
	 *(p+((irq/32)*100))|=1<<irq;
}




















#endif /* INC_INTERRUPT_H_ */
