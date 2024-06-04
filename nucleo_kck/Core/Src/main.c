#include<stdio.h>
#include<stdint.h>
#include<interrupt.h>

#define i2c 0x40005400

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
}i2c_1;


#define i2c_base ((i2c_1*)i2c)

uint32_t* gpiob = 0x40020400;
uint32_t* type=0x40020404;
uint32_t* gpios =0x40020408;
uint32_t* gpioi =0x4002040c;
uint32_t* af = 0x40020424;

void afio(){
uint32_t* rcc = 0x40023830;
uint32_t* rcc1 = 0x40023840;
*rcc1 &= ~(1<<21);
*rcc1 |= 1<<21;
*rcc &= ~(1<<1);
*rcc |= 1<<1;
*af &= ~(4<<0);
*af |= 4<<0;
*af &= ~(4<<4);
*af |= 4<<4;



*gpiob &= ~(2<<16);
*gpiob |= 2<<16;

*gpiob &= ~(2<<18);
*gpiob |= 2<<18;

*type =1<<8;
*type =1<<9;

*gpios |= 2<<16;
*gpios |= 2<<18;

*gpioi |= 1<<16;
*gpioi  |= 1<<18;
}

void init(uint32_t addr){

		i2c_base->I2C_CR1 |= 1<<15;
			i2c_base->I2C_CR1 &= ~(1<<15);


		i2c_base->I2C_CR2 = 0x2d;

		uint16_t ccrvalue= 0xA0;

		i2c_base->I2C_OAR1 = addr<<1;
		i2c_base->I2C_OAR1 &= ~(1);
		i2c_base->I2C_OAR1 = 1<<14;
		i2c_base->I2C_CCR = 1<<15;
		i2c_base->I2C_CCR = 0x96;
		i2c_base->I2C_TRISE = 46;

	}
void pe(){
	i2c_base->I2C_CR1 &= ~1;
	i2c_base->I2C_CR1 =1;
}

void start(){

	i2c_base->I2C_CR1 |= 1<<8;
   //  i2c_base->I2C_SR1 = 1<<0;

	while (!(i2c_base->I2C_SR1 & (1<<0)));
}
void addr(uint32_t slave){

	i2c_base->I2C_DR = slave<<1;
	i2c_base->I2C_DR &= ~(1);

	while (!(i2c_base->I2C_SR1 & 132));
	int dummyread = i2c_base->I2C_SR1;
	 dummyread = i2c_base->I2C_SR2;

}
void recaddr(uint8_t slave){
	ack();
	i2c_base->I2C_DR = (slave<<1|1);

	i2c_base->I2C_CR1 &= ~(1<<10);
	while (!(i2c_base->I2C_SR1 & (1<<1)));
	int dummyread = i2c_base->I2C_SR1;
	 dummyread = i2c_base->I2C_SR2;
}

void write(uint8_t *data,int len){

	while(len>0){
		i2c_base->I2C_DR = *data;
		while (!(i2c_base->I2C_SR1 & 1<<7));
     data++;
		len--;
	}
	}
void stop(){


	//while (!(i2c_base->I2C_SR1 &= 132));
			i2c_base->I2C_CR1 = 1<<9;
	}
uint8_t multipleread(uint8_t *buffer,uint8_t size,uint8_t slave){
	int remaining=size-1;
	int dummyread;
	ack();

	i2c_base->I2C_DR = (slave<<1|1);
//	i2c_base->I2C_CR1 |= (1<<10);
	while (!(i2c_base->I2C_SR1 & (1<<1)));
	dummyread = i2c_base->I2C_SR1;
	 dummyread = i2c_base->I2C_SR2;
	 while (remaining>=2)
	 {
	 	/**** STEP 2-c ****/
	 	while (!(i2c_base->I2C_SR1 & (1<<6)));  // wait for RxNE to set

	 	/**** STEP 2-d ****/
	 	buffer[remaining] = i2c_base->I2C_DR;  // copy the data into the buffer

	 	/**** STEP 2-e ****/
	 	i2c_base->I2C_CR1 |= 1<<10;  // Set the ACK bit to Acknowledge the data received

	 	remaining--;
	 }

	 // Read the SECOND LAST BYTE
	 while (!(i2c_base->I2C_SR1 & (1<<6)));
	 // wait for RxNE to set
	 buffer[remaining] = i2c_base->I2C_DR;
	 printf("%d\n", buffer[remaining]);

	 /**** STEP 2-f ****/
	 i2c_base->I2C_CR1 &= ~(1<<10);
	 i2c_base->I2C_CR1 |= (1<<9);// clear the ACK bit

	 /**** STEP 2-g ****/
	   // Stop I2C

	 remaining--;

	 // Read the Last BYTE
	 while (!(i2c_base->I2C_SR1 & (1<<6)));

	 // wait for RxNE to set
	 buffer[remaining] = i2c_base->I2C_DR;
	 printf("%d\n", buffer[remaining]);
	 printf("kck\n");

	}

void mpuread(uint8_t Addr,uint8_t* buffer,uint8_t size){

int remaining = size;

/**** STEP 1 ****/
	if (size == 1)
	{
		/**** STEP 1-a ****/
		i2c_base->I2C_DR = Addr<<1|1; //  send the address
		while (!(i2c_base->I2C_SR1 & (1<<1)));  // wait for ADDR bit to set

		/**** STEP 1-b ****/
		i2c_base->I2C_CR1 &= ~(1<<10);  // clear the ACK bit
		uint8_t temp = i2c_base->I2C_SR1 | i2c_base->I2C_SR2;  // read SR1 and SR2 to clear the ADDR bit.... EV6 condition
		i2c_base->I2C_CR1 |= (1<<9);  // Stop I2C

		/**** STEP 1-c ****/
		while (!(i2c_base->I2C_SR1 & (1<<6)));  // wait for RxNE to set

		/**** STEP 1-d ****/
		buffer[size-remaining] = i2c_base->I2C_DR;
		// Read the data from the DATA REGISTER

	}

/**** STEP 2 ****/
	else
	{
		/**** STEP 2-a ****/
		i2c_base->I2C_CR1 |= 1<<10;
		i2c_base->I2C_DR = Addr<<1|1;  //  send the address
		while (!(i2c_base->I2C_SR1 & (1<<1)));  // wait for ADDR bit to set

		/**** STEP 2-b ****/
		uint8_t temp = i2c_base->I2C_SR1 | i2c_base->I2C_SR2;  // read SR1 and SR2 to clear the ADDR bit

		while (remaining>2)
		{
			/**** STEP 2-c ****/
			while (!(i2c_base->I2C_SR1 & (1<<6)));  // wait for RxNE to set

			/**** STEP 2-d ****/
			buffer[size-remaining] = i2c_base->I2C_DR;  // copy the data into the buffer

			/**** STEP 2-e ****/
			i2c_base->I2C_CR1 |= 1<<10;  // Set the ACK bit to Acknowledge the data received
			//printf("%d\n",buffer[size-remaining] );
			remaining--;
		}

		// Read the SECOND LAST BYTE
		while (!(i2c_base->I2C_SR1 & (1<<6)));  // wait for RxNE to set
		buffer[size-remaining] = i2c_base->I2C_DR;

		/**** STEP 2-f ****/
		i2c_base->I2C_CR1 &= ~(1<<10);  // clear the ACK bit

		/**** STEP 2-g ****/
		i2c_base->I2C_CR1 |= (1<<9);  // Stop I2C

		remaining--;

		// Read the Last BYTE
		while (!(i2c_base->I2C_SR1 & (1<<6)));  // wait for RxNE to set
		buffer[size-remaining] = i2c_base->I2C_DR;  // copy the data into the buffer
	}
}



void delay()
{
	for(int i=0;i<50;i++);
}


uint8_t  read(uint8_t slave){
//	for(int i=0;i<1000;i++);
	ack();
	i2c_base->I2C_DR = (slave<<1|1);
	i2c_base->I2C_CR1 &= ~(1<<10);
	while (!(i2c_base->I2C_SR1 & (1<<1)));
	int dummyread = i2c_base->I2C_SR1;
	 dummyread = i2c_base->I2C_SR2;
	nack();
	stop();
	while (!(i2c_base->I2C_SR1 & 1<<6));
	uint8_t a = i2c_base->I2C_DR;
	return a;
}
void nack(){
	i2c_base->I2C_CR1 &= ~(1<<10);
}
void ack(){
	i2c_base->I2C_CR1 = 1<<10;
}

void I2C_Read (uint8_t Address, uint8_t *buffer, uint8_t size)
{
/**** STEPS FOLLOWED  ************
1. If only 1 BYTE needs to be Read
	a) Write the slave Address, and wait for the ADDR bit (bit 1 in SR1) to be set
	b) the Acknowledge disable is made during EV6 (before ADDR flag is cleared) and the STOP condition generation is made after EV6
	c) Wait for the RXNE (Receive Buffer not Empty) bit to set
	d) Read the data from the DR
2. If Multiple BYTES needs to be read
  a) Write the slave Address, and wait for the ADDR bit (bit 1 in SR1) to be set
	b) Clear the ADDR bit by reading the SR1 and SR2 Registers
	c) Wait for the RXNE (Receive buffer not empty) bit to set
	d) Read the data from the DR
	e) Generate the Acknowlegment by settint the ACK (bit 10 in SR1)
	f) To generate the nonacknowledge pulse after the last received data byte, the ACK bit must be cleared just after reading the
		 second last data byte (after second last RxNE event)
	g) In order to generate the Stop/Restart condition, software must set the STOP/START bit
	   after reading the second last data byte (after the second last RxNE event)
*/


		/**** STEP 1-a ****/
		i2c_base->I2C_DR = (Address<<1|1);
		//HAL_Delay(50);
		//i2c_base->I2C_DR |= 1;
		while (!(i2c_base->I2C_SR1 & (1<<1)));  // wait for ADDR bit to set

		/**** STEP 1-b ****/
		i2c_base->I2C_CR1 &= ~(1<<10);  // clear the ACK bit
		uint8_t temp = i2c_base->I2C_SR1 | i2c_base->I2C_SR2;  // read SR1 and SR2 to clear the ADDR bit.... EV6 condition
		i2c_base->I2C_CR1 |= (1<<9);  // Stop I2C

		/**** STEP 1-c ****/
		while (!(i2c_base->I2C_SR1 & (1<<6)));  // wait for RxNE to set
        delay();
		/**** STEP 1-d ****/
		*buffer = i2c_base->I2C_DR;  // Read the data from the DATA REGISTER


/**** STEP 2 ****/

}

void addri2cit(uint8_t addr,uint8_t* buffer,uint8_t len ){
	printf("kck\n");
	   ack();
       int temp1,temp2,re;
       temp1=(i2c_base->I2C_SR1 & 1);
       temp2 = i2c_base->I2C_CR2 & 1<<9;
       if(temp1 ==1 && temp2 ==1){
    	   printf("i2c is started\n");
    	   i2c_base->I2C_DR = addr<<1 | 1;
       }
       temp1= i2c_base->I2C_SR1 & 1<<1;
       if(temp1==1){
    	   printf("addr is transferred\n");
    	   int tempread = i2c_base->I2C_SR1;
    	   tempread=i2c_base->I2C_SR2;

       }
       if(len ==1){
    	  nack();
    	   while(!(i2c_base->I2C_SR1 & 1<<6));
    	   stop();
    	   *buffer = i2c_base->I2C_DR;
       }
       else{

    	   while(len>2){
    		   while(!(i2c_base->I2C_SR1 & 1<<6));
    		   *(buffer+re) = i2c_base->I2C_DR;
    		   len--;
    		   re++;

    	   }
    	   while(!(i2c_base->I2C_SR1 & 1<<6));
    	    *(buffer+re) = i2c_base->I2C_DR;
    	    re++;
    	  nack();
    	  stop();
    	   while(!(i2c_base->I2C_SR1 & 1<<6));

    	   *(buffer+re) = i2c_base->I2C_DR;

       }
}



int main(){
char m[15]= "kannankck 123";
uint8_t u[6];
uint8_t c =0x6b;
uint8_t r=0;
uint8_t t;
afio();
init(0x62);
uint8_t p=0x3b;
uint8_t p1=0x42;
i2c_base->I2C_CR2 = 1<<9;
pe();
uint8_t h=0x1c;
uint8_t j;
//printf("%d\n",h);

	// start();
	// I2C_Read(0x68, &r, 1);

start();

		addr(0x68);
			write(&c,1);
			write(&r,1);
		stop();
		pe();
		start();
				addr(0x68);
				write(&h,1);
				write(&r,1);
			stop();
printf("kck\n");


	pe();
	start();
			addr(0x68);
			write(&p,1);
			i2c_inten(31);
			start();



			addri2cit(0x68, &u, 6);
		uint16_t accelx = u[0]<<8|u[1];
		uint16_t accely = u[2]<<8|u[3];
		uint16_t accelz = u[4]<<8|u[5];
        float ax = (accelx/16384.000);
        float ay= (accely/16384.000);
        float az =(accelz/16384.000);
	//	printf("accelx%.3f\n",ax);







}
void I2C1_EV_IRQHandler(){
	printf("kck\n");
}
