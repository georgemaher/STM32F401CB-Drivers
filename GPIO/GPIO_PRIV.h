#include"STD_TYPES.h"


#ifndef GPIO_PRIV_H_
#define GPIO_PRIV_H_

//GPIO F/G/H/I/J/K (except GPIOH0 and GPIOH1) are not available in STM32F401xB/C and
//STM32F401xD/E.
#define	GPIOH_BASE_ADDRESS				0x40021C00	
#define	GPIOE_BASE_ADDRESS				0x40021000
#define	GPIOD_BASE_ADDRESS				0x40020C00
#define	GPIOC_BASE_ADDRESS				0x40020800
#define	GPIOB_BASE_ADDRESS				0x40020400
#define	GPIOA_BASE_ADDRESS				0x40020000


typedef struct{
	
volatile	uint32	GPIO_MODER;
volatile	uint32	GPIO_OTYPER;
volatile	uint32	GPIO_OSPEEDR;
volatile	uint32	GPIO_PUPDR;
volatile	uint32	GPIO_IDR;
volatile	uint32	GPIO_ODR;
volatile	uint32	GPIO_BSRR;
volatile	uint32	GPIO_LCKR;
volatile	uint32	GPIO_AFRL;
volatile	uint32	GPIO_AFRH;
	
}GPIO_struct_t;


#define GPIOA_REGS						((GPIO_struct_t *)GPIOA_BASE_ADDRESS)
#define GPIOB_REGS						((GPIO_struct_t *)GPIOB_BASE_ADDRESS)
#define GPIOC_REGS						((GPIO_struct_t *)GPIOC_BASE_ADDRESS)
#define GPIOD_REGS						((GPIO_struct_t *)GPIOD_BASE_ADDRESS)
#define GPIOE_REGS						((GPIO_struct_t *)GPIOE_BASE_ADDRESS)
#define GPIOH_REGS						((GPIO_struct_t *)GPIOH_BASE_ADDRESS)





#endif