#include"GPIO.h"

/*
set the mode for the Port pin
*/
void	vSetGPIO_mode(PortName port , PinNum pinNum, PinMode pinMode){
	switch(port){
		case	GPIOA_G:	GPIOA_REGS->GPIO_MODER |= (pinMode << pinNum*2);					break;
		case	GPIOB_G:	GPIOB_REGS->GPIO_MODER |=	(pinMode << pinNum*2);					break;
		case	GPIOC_G:	GPIOC_REGS->GPIO_MODER |= (pinMode << pinNum*2);					break;
		case	GPIOD_G:	GPIOD_REGS->GPIO_MODER |=	(pinMode << pinNum*2);					break;
		case	GPIOE_G:	GPIOE_REGS->GPIO_MODER |= (pinMode << pinNum*2);					break;
		case	GPIOH_G:	GPIOH_REGS->GPIO_MODER |=	(pinMode << pinNum*2);					break;
		default:																																break;

	}
}


/*
set the outPut type as push-pull or open drain.
*/
void	vSetGPIO_outputType(PortName port , PinNum pin , OutputMode mode){

	switch(port){
		case	GPIOA_G:	GPIOA_REGS->GPIO_OTYPER |= (mode << pin);					break;
		case	GPIOB_G:	GPIOB_REGS->GPIO_OTYPER |=	(mode << pin);				break;
		case	GPIOC_G:	GPIOC_REGS->GPIO_OTYPER |= (mode << pin);					break;
		case	GPIOD_G:	GPIOD_REGS->GPIO_OTYPER |=	(mode << pin);				break;
		case	GPIOE_G:	GPIOE_REGS->GPIO_OTYPER |= (mode << pin);					break;
		case	GPIOH_G:	GPIOH_REGS->GPIO_OTYPER |=	(mode << pin);			  break;
		default:																												break;

	}

}

/*
set the output speed as one of the four options.
*/
void	vSetGPIO_outputSpeed(PortName port , PinNum pin , Output_speed  speed){

	switch(port){
		case	GPIOA_G:	GPIOA_REGS->GPIO_OSPEEDR |= (speed << pin*2);					break;
		case	GPIOB_G:	GPIOB_REGS->GPIO_OSPEEDR |=	(speed << pin*2);					break;
		case	GPIOC_G:	GPIOC_REGS->GPIO_OSPEEDR |= (speed << pin*2);					break;
		case	GPIOD_G:	GPIOD_REGS->GPIO_OSPEEDR |=	(speed << pin*2);					break;
		case	GPIOE_G:	GPIOE_REGS->GPIO_OSPEEDR |= (speed << pin*2);					break;
		case	GPIOH_G:	GPIOH_REGS->GPIO_OSPEEDR |=	(speed << pin*2);					break;
		default:																														break;

	}


}


/*
set the pull up or down resistors.
*/

void	vSetGPIO_PullType(PortName port , PinNum pin , Pull_type	type){
	switch(port){
		case	GPIOA_G:	GPIOA_REGS->GPIO_PUPDR |= (type << pin*2);					break;
		case	GPIOB_G:	GPIOB_REGS->GPIO_PUPDR |=	(type << pin*2);					break;
		case	GPIOC_G:	GPIOC_REGS->GPIO_PUPDR |= (type << pin*2);					break;
		case	GPIOD_G:	GPIOD_REGS->GPIO_PUPDR |=	(type << pin*2);					break;
		case	GPIOE_G:	GPIOE_REGS->GPIO_PUPDR |= (type << pin*2);					break;
		case	GPIOH_G:	GPIOH_REGS->GPIO_PUPDR |=	(type << pin*2);					break;
		default:																													break;

	}

}


/*
reads the data on the corresponding pin
*/
uint8	uSetGPIO_readPin(PortName port , PinNum pin ){

	uint8 data = 0;
	switch(port){
		case	GPIOA_G:	data= (GPIOA_REGS->GPIO_IDR &(1U<<pin) );					break;
		case	GPIOB_G:	data= (GPIOB_REGS->GPIO_IDR &(1U<<pin) );					break;
		case	GPIOC_G:	data= (GPIOC_REGS->GPIO_IDR &(1U<<pin) );					break;
		case	GPIOD_G:	data= (GPIOD_REGS->GPIO_IDR &(1U<<pin) );					break;
		case	GPIOE_G:	data= (GPIOE_REGS->GPIO_IDR &(1U<<pin) );					break;
		case	GPIOH_G:	data= (GPIOH_REGS->GPIO_IDR &(1U<<pin) );					break;
		default:																												break;

	}
	return data;
}
/*
write data to the corresponding pin
*/
void	vSetGPIO_writePin(PortName port , PinNum pin, uint8 data ){
	if(data == 1 ){
		switch(port){
			case	GPIOA_G:	GPIOA_REGS->GPIO_ODR |= (1U << pin);					break;
			case	GPIOB_G:	GPIOB_REGS->GPIO_ODR |=	(1U << pin);					break;
			case	GPIOC_G:	GPIOC_REGS->GPIO_ODR |= (1U << pin);					break;
			case	GPIOD_G:	GPIOD_REGS->GPIO_ODR |=	(1U << pin);					break;
			case	GPIOE_G:	GPIOE_REGS->GPIO_ODR |= (1U << pin);					break;
			case	GPIOH_G:	GPIOH_REGS->GPIO_ODR |=	(1U << pin);					break;
			default:																											break;
		}
	}
	if(data == 0){
		switch(port){
			case	GPIOA_G:	GPIOA_REGS->GPIO_ODR &=~ (1U << pin);					break;
			case	GPIOB_G:	GPIOB_REGS->GPIO_ODR &=~ (1U << pin);					break;
			case	GPIOC_G:	GPIOC_REGS->GPIO_ODR &=~ (1U << pin);					break;
			case	GPIOD_G:	GPIOD_REGS->GPIO_ODR &=~ (1U << pin);					break;
			case	GPIOE_G:	GPIOE_REGS->GPIO_ODR &=~ (1U << pin);					break;
			case	GPIOH_G:	GPIOH_REGS->GPIO_ODR &=~ (1U << pin);					break;
			default:																								  	break;
		}
	}
}
/*
locks the configuration for the corresponding pin.
*/
void	vSetGPIO_lockPin(PortName port , PinNum pin ){

	switch(port){
			case	GPIOA_G:	GPIOA_REGS->GPIO_LCKR |= ((1U<<pin15)|(1U<<pin));
										GPIOA_REGS->GPIO_LCKR = (GPIOA_REGS->GPIO_LCKR | (1U<<pin)) &~ (1U<<pin15);	// sets the same bit and clear the lckk
										GPIOA_REGS->GPIO_LCKR |= ((1U<<pin15)|(1U<<pin));
										while(!(GPIOA_REGS->GPIO_LCKR	&	(1U<<pin15))){}
										break;
			case	GPIOB_G:	GPIOB_REGS->GPIO_LCKR |= ((1U<<pin15)|(1U<<pin));
                    GPIOB_REGS->GPIO_LCKR = (GPIOB_REGS->GPIO_LCKR | (1U<<pin)) &~ (1U<<pin15);	// sets the same bit and clear the lckk
                    GPIOB_REGS->GPIO_LCKR |= ((1U<<pin15)|(1U<<pin));
										while(!(GPIOB_REGS->GPIO_LCKR	&	(1U<<pin15))){}
										break;
			case	GPIOC_G:	GPIOC_REGS->GPIO_LCKR |= ((1U<<pin15)|(1U<<pin));
										GPIOC_REGS->GPIO_LCKR = (GPIOC_REGS->GPIO_LCKR | (1U<<pin)) &~ (1U<<pin15);	// sets the same bit and clear the lckk
										GPIOC_REGS->GPIO_LCKR |= ((1U<<pin15)|(1U<<pin));
										while(!(GPIOC_REGS->GPIO_LCKR	&	(1U<<pin15))){}
										break;
			case	GPIOD_G:	GPIOD_REGS->GPIO_LCKR |= ((1U<<pin15)|(1U<<pin));
										GPIOD_REGS->GPIO_LCKR = (GPIOD_REGS->GPIO_LCKR | (1U<<pin)) &~ (1U<<pin15);	// sets the same bit and clear the lckk
										GPIOD_REGS->GPIO_LCKR |= ((1U<<pin15)|(1U<<pin));
										while(!(GPIOD_REGS->GPIO_LCKR	&	(1U<<pin15))){}
										break;
			case	GPIOE_G:	GPIOE_REGS->GPIO_LCKR |= ((1U<<pin15)|(1U<<pin));
										GPIOE_REGS->GPIO_LCKR = (GPIOE_REGS->GPIO_LCKR | (1U<<pin)) &~ (1U<<pin15);	// sets the same bit and clear the lckk
										GPIOE_REGS->GPIO_LCKR |= ((1U<<pin15)|(1U<<pin));
										while(!(GPIOE_REGS->GPIO_LCKR	&	(1U<<pin15))){}
										break;
			case	GPIOH_G:	GPIOH_REGS->GPIO_LCKR |= ((1U<<pin15)|(1U<<pin));
										GPIOH_REGS->GPIO_LCKR = (GPIOH_REGS->GPIO_LCKR | (1U<<pin)) &~ (1U<<pin15);	// sets the same bit and clear the lckk
										GPIOH_REGS->GPIO_LCKR |= ((1U<<pin15)|(1U<<pin));
										while(!(GPIOH_REGS->GPIO_LCKR	&	(1U<<pin15))){}
										break;
			default:			break;
		}


}
/*
select one of the alternate functions
*/
void	vSetGPIO_alternateFunction(PortName port , PinNum pin , AlternateFunctions af){
	if(pin < 8 && pin >= 0){
		switch(port){
			case	GPIOA_G:	GPIOA_REGS->GPIO_AFRL |= (af << pin*4);					break;
			case	GPIOB_G:	GPIOB_REGS->GPIO_AFRL |= (af << pin*4);				  break;
			case	GPIOC_G:	GPIOC_REGS->GPIO_AFRL |= (af << pin*4);					break;
			case	GPIOD_G:	GPIOD_REGS->GPIO_AFRL |= (af << pin*4);			  	break;
			case	GPIOE_G:	GPIOE_REGS->GPIO_AFRL |= (af << pin*4);					break;
			case	GPIOH_G:	GPIOH_REGS->GPIO_AFRL |= (af << pin*4);	   			break;
			default:																											break;

		}
	}
	if(pin < 16 && pin >= 8){

		uint16 adjPin = pin - 8;

		switch(port){
			case	GPIOA_G:	GPIOA_REGS->GPIO_AFRH |= (af << adjPin*4);					break;
			case	GPIOB_G:	GPIOB_REGS->GPIO_AFRH |= (af << adjPin*4);					break;
			case	GPIOC_G:	GPIOC_REGS->GPIO_AFRH |= (af << adjPin*4);					break;
			case	GPIOD_G:	GPIOD_REGS->GPIO_AFRH |= (af << adjPin*4);					break;
			case	GPIOE_G:	GPIOE_REGS->GPIO_AFRH |= (af << adjPin*4);					break;
			case	GPIOH_G:	GPIOH_REGS->GPIO_AFRH |= (af << adjPin*4);					break;
			default:																													break;

		}
	}


}
