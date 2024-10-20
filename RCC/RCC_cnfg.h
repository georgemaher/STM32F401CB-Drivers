
#ifndef RCC_cnfg_H_
#define RCC_cnfg_H_



typedef enum{
	HSI,
	HSE,
	PLL
	
}Clk_Src_t;

typedef enum{
	external,
	crystal
	
}HSE_Src_t;


typedef enum {
	HSE_src,
	HSI_src
	
}PLL_Src_t;


typedef enum{

APB2_pre0,
APB2_pre2,
APB2_pre4,
APB2_pre8,
APB2_pre16	
	
}APB2_PreScaler_t;


typedef enum{
	
APB1_pre0,
APB1_pre2,
APB1_pre4,
APB1_pre8,
APB1_pre16	
	
}APB1_PreScaler_t;




typedef enum{
AHB_pre0,
AHB_pre2,
AHB_pre4,
AHB_pre8,
AHB_pre16,
AHB_pre64,
AHB_pre128,
AHB_pre256,
AHB_pre512
	
}AHB_PreScaler_t;

/*The following typedefs will be used for the Peripheral Clock Enable Function */


typedef enum{
	
	AHB1_b,
	AHB2_b,
	APB1_b,
	APB2_b
	
}BUS_t;



typedef enum{
	GPIOA_R,
	GPIOB_R,
	GPIOC_R,
	GPIOD_R,
	GPIOE_R,
	GPIOH_R = 7,
	CRC 	= 12,
	DMA1_R = 21,
	DMA2_R = 22

	
}AHB1_perip_t;



typedef enum{
	
	OTGFS = 7
	
}AHB2_perip_t;

typedef enum{
	TIM2,
	TIM3,
	TIM4,
	TIM5,
	WWDG = 11,
	SPI2 = 14,
	SPI3 = 15,
	USART2 = 17,
	I2C1   = 21,
	I2C2	 = 22,
	I2C3	 = 23,
	PWR		 = 28

}APB1_perip_t;

typedef enum{
	TIM1,
	USART1 = 4,
	USART6 = 5,
	ADC1	 = 8,
	SDIO	 = 11,
	SPI1	 ,
	SPI4	 ,
	SYSCFG ,
	TIM9 = 16,
	TIM10,
	TIM11
	

}APB2_perip_t;




#endif