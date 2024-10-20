#include"EXTI.h"
#include"RCC.h"


void vEXTI_Enable(PortName port, uint8 extline_pin){
	uint8 pin = 0 ;
		
		vRCC_EnPeripheralClk(APB2_b , SYSCFG);
	if(extline_pin >= 0 && extline_pin < 4){
		switch(port){
			case (GPIOA_G): 
			SYS_CFG_REGS->EXTICR1 &=~ ((1U << extline_pin*4)| (1U << ((extline_pin*4)+ 1))| (1U << ((extline_pin*4)+ 2))| (1U << ((extline_pin*4)+ 3)));
			break;
			case (GPIOB_G):
		  SYS_CFG_REGS->EXTICR1=(SYS_CFG_REGS->EXTICR1 | (1U <<extline_pin*4)) &~ ((1U << ((extline_pin*4)+ 1))| (1U << ((extline_pin*4)+ 2))| (1U << ((extline_pin*4)+ 3)));
			break;
			case (GPIOC_G):
		  SYS_CFG_REGS->EXTICR1=(SYS_CFG_REGS->EXTICR1 |(1U << ((extline_pin*4)+ 1) )) &~ ((1U <<extline_pin*4)| (1U << ((extline_pin*4)+ 2))| (1U << ((extline_pin*4)+ 3)));
			break;
			case (GPIOD_G):
		  SYS_CFG_REGS->EXTICR1=(SYS_CFG_REGS->EXTICR1 |((1U << ((extline_pin*4)+ 1) )|(1U <<extline_pin*4))) &~ ( (1U << ((extline_pin*4)+ 2))| (1U << ((extline_pin*4)+ 3)));
			break;
			case (GPIOE_G):
		  SYS_CFG_REGS->EXTICR1=(SYS_CFG_REGS->EXTICR1 |(1U << ((extline_pin*4)+ 2) )) &~ ((1U <<extline_pin*4)| (1U << ((extline_pin*4)+ 1))| (1U << ((extline_pin*4)+ 3)));
			break;
			case (GPIOH_G):
		  SYS_CFG_REGS->EXTICR1=(SYS_CFG_REGS->EXTICR1|((1U<<((extline_pin*4)+ 1))|(1U <<extline_pin*4)|(1U<<((extline_pin*4)+2))))&~ ((1U <<((extline_pin*4)+ 3)));
			break;
			default:	break;
		}
	}
	if(extline_pin >= 4 && extline_pin < 8){
		pin = extline_pin -4;
		switch(port){
			case (GPIOA_G): 
			SYS_CFG_REGS->EXTICR2 &=~ ((1U << pin*4)| (1U << ((pin*4)+ 1))| (1U << ((pin*4)+ 2))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOB_G):
		  SYS_CFG_REGS->EXTICR2=(SYS_CFG_REGS->EXTICR2 | (1U <<pin*4)) &~ ((1U << ((pin*4)+ 1))| (1U << ((pin*4)+ 2))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOC_G):
		  SYS_CFG_REGS->EXTICR2=(SYS_CFG_REGS->EXTICR2 |(1U << ((pin*4)+ 1) )) &~ ((1U <<pin*4)| (1U << ((pin*4)+ 2))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOD_G):
		  SYS_CFG_REGS->EXTICR2=(SYS_CFG_REGS->EXTICR2 |((1U << ((pin*4)+ 1) )|(1U <<pin*4))) &~ ( (1U << ((pin*4)+ 2))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOE_G):
		  SYS_CFG_REGS->EXTICR2=(SYS_CFG_REGS->EXTICR2 |(1U << ((pin*4)+ 2) )) &~ ((1U <<pin*4)| (1U << ((pin*4)+ 1))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOH_G):
		  SYS_CFG_REGS->EXTICR2=(SYS_CFG_REGS->EXTICR2|((1U<<((pin*4)+ 1))|(1U <<pin*4)|(1U<<((pin*4)+2))))&~ ((1U <<((pin*4)+ 3)));
			break;
			default:	break;
		}
	}
	if(extline_pin >= 8 && extline_pin < 12){
		pin = extline_pin - 8;
		switch(port){
			case (GPIOA_G): 
			SYS_CFG_REGS->EXTICR3 &=~ ((1U << pin*4)| (1U << ((pin*4)+ 1))| (1U << ((pin*4)+ 2))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOB_G):
		  SYS_CFG_REGS->EXTICR3=(SYS_CFG_REGS->EXTICR3 | (1U <<pin*4)) &~ ((1U << ((pin*4)+ 1))| (1U << ((pin*4)+ 2))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOC_G):
		  SYS_CFG_REGS->EXTICR3=(SYS_CFG_REGS->EXTICR3 |(1U << ((pin*4)+ 1) )) &~ ((1U <<pin*4)| (1U << ((pin*4)+ 2))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOD_G):
		  SYS_CFG_REGS->EXTICR3=(SYS_CFG_REGS->EXTICR3 |((1U << ((pin*4)+ 1) )|(1U <<pin*4))) &~ ( (1U << ((pin*4)+ 2))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOE_G):
		  SYS_CFG_REGS->EXTICR3=(SYS_CFG_REGS->EXTICR3 |(1U << ((pin*4)+ 2) )) &~ ((1U <<pin*4)| (1U << ((pin*4)+ 1))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOH_G):
		  SYS_CFG_REGS->EXTICR3=(SYS_CFG_REGS->EXTICR3|((1U<<((pin*4)+ 1))|(1U <<pin*4)|(1U<<((pin*4)+2))))&~ ((1U <<((pin*4)+ 3)));
			break;
			default:	break;
		}
	}
	if(extline_pin >= 12 && extline_pin < 16){
		pin  = extline_pin - 12;
		switch(port){
			case (GPIOA_G): 
			SYS_CFG_REGS->EXTICR4 &=~ ((1U << pin*4)| (1U << ((pin*4)+ 1))| (1U << ((pin*4)+ 2))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOB_G):
		  SYS_CFG_REGS->EXTICR4=(SYS_CFG_REGS->EXTICR4 | (1U <<pin*4)) &~ ((1U << ((pin*4)+ 1))| (1U << ((pin*4)+ 2))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOC_G):
		  SYS_CFG_REGS->EXTICR4=(SYS_CFG_REGS->EXTICR4 |(1U << ((pin*4)+ 1) )) &~ ((1U <<pin*4)| (1U << ((pin*4)+ 2))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOD_G):
		  SYS_CFG_REGS->EXTICR4=(SYS_CFG_REGS->EXTICR4 |((1U << ((pin*4)+ 1) )|(1U <<pin*4))) &~ ( (1U << ((pin*4)+ 2))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOE_G):
		  SYS_CFG_REGS->EXTICR4=(SYS_CFG_REGS->EXTICR4 |(1U << ((pin*4)+ 2) )) &~ ((1U <<pin*4)| (1U << ((pin*4)+ 1))| (1U << ((pin*4)+ 3)));
			break;
			case (GPIOH_G):
		  SYS_CFG_REGS->EXTICR4=(SYS_CFG_REGS->EXTICR4|((1U<<((pin*4)+ 1))|(1U <<pin*4)|(1U<<((pin*4)+2))))&~ ((1U <<((pin*4)+ 3)));
			break;
			default:	break;
		}
	}
	EXTI_REGS->EXTI_IMR |= (1U << extline_pin);
}


void vEXTI_SelectTrigger( uint8 extline, uint8 trigger){

	switch(trigger){
		case(TRIGGER_FALLING):	
		EXTI_REGS->EXTI_FTSR |= (1U << extline);		
		EXTI_REGS->EXTI_RTSR &=~(1U << extline);	
		break;
		
		case(TRIGGER_RISING):		
		EXTI_REGS->EXTI_RTSR |= (1U << extline);		
		EXTI_REGS->EXTI_FTSR &=~(1U << extline);	
		break;
		
		default:	break;
		
	}
}

void vEXTI_SoftwareInt( uint8 extline)
{

EXTI_REGS->EXTI_SWIER |= (1U << extline);

}
uint8 uEXTI_ReadPending( uint8 pinNum){

return (EXTI_REGS->EXTI_PR  & (1U << pinNum));


}
void vEXTI_ClearPending(uint8 pinNum){

EXTI_REGS->EXTI_PR	|= ( 1U << pinNum);

}