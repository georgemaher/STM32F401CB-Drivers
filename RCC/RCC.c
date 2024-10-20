#include"RCC.h"




/*By default, after a system reset, the HSI oscillator is selected as the system clock.
	When a clock source is used directly or through PLL as the system clock, it is not possible to stop it.	*/

void vRCC_setSysClk(Clk_Src_t clk, 	HSE_Src_t hseSrc, PLL_Src_t pllSrc, AHB_PreScaler_t ahb , APB1_PreScaler_t apb1 , APB2_PreScaler_t apb2 ){
  /* Handling setting the clock source*/
	switch(clk){
		
		case(HSI) : 
			RCC_REGS->RCC_CR |= (1U << 0);  // enabling HSI		
//			while(!(RCC_REGS->RCC_CR &= (1U <<1))){} // waiting HSE to stabilize
				
			
			
		
			RCC_REGS->RCC_CFGR &= ~(1U << 0); // setting the SW bits to HSI
			RCC_REGS->RCC_CFGR &= ~(1U << 1);		

		break;
		
		
		
		
		case(HSE) : 
			RCC_REGS->RCC_CR |= (1U << 16);  // enabling HSE			
			while(!(RCC_REGS->RCC_CR &= (1U << 17))){} // waiting HSE to stabilize
				
			if(!hseSrc){ // external clock
			
				RCC_REGS->RCC_CR |= (1U << 18); // Enabling BYPASS to use external clk	
			}
			else{ // crystal
			
				RCC_REGS->RCC_CR |= (1U << 18); // disabling BYPASS 	
			}
		
			RCC_REGS->RCC_CFGR |= (1U << 0); // setting the SW bits to HSE
			RCC_REGS->RCC_CFGR &= ~(1U << 1);		

		break;

		case(PLL)	:					
			RCC_REGS->RCC_CR |= (1U << 24);  // enabling PLL			
			while(!(RCC_REGS->RCC_CR &= (1U << 25))){} // waiting PLL to stabilize
			if(!pllSrc){ // HSE source
			RCC_REGS->RCC_CR |= (1U << 16); // enabling HSE	
			RCC_REGS->RCC_CR |= (1U << 18); // disabling BYPASS 
			RCC_REGS->RCC_PLLCFGR |=(1U << 22); // HSE selected as source for PLL
			}
			else{
			
			RCC_REGS->RCC_CR |= (1U << 0 ); // Enabling HSI
			while(!(RCC_REGS->RCC_CR &= (1U << 1))){} // waiting HSI to stabilize		
			RCC_REGS->RCC_PLLCFGR &= ~(1U << 22); // HSI selected as a source for PLL
				
			}
			
			RCC_REGS->RCC_CFGR |= (1U << 1); // setting the SW bits to PLL
			RCC_REGS->RCC_CFGR &= ~(1U << 0);		
			
		break;
		
		default: break;
	}
	/* Handling setting the prescalers*/
	switch(ahb){
		case 0 : 
		RCC_REGS->RCC_CFGR &= ~((1U<<7) | (1U<<6)|(1U<<5)|(1U<<4));		// 0b0000		
		break;
		case 1 : 
		RCC_REGS->RCC_CFGR	|= (1U<<7);
		RCC_REGS->RCC_CFGR &= ~( (1U<<6)|(1U<<5)|(1U<<4));		// 0b1000		
		break;
		case 2 : 					
		RCC_REGS->RCC_CFGR	|= ((1U<<7) | (1U<<4));
		RCC_REGS->RCC_CFGR &= ~( (1U<<6)|(1U<<5));		// 0b1001		
		break;
		case 3 : 					 					
		RCC_REGS->RCC_CFGR	|= ((1U<<7) | (1U<<5));
		RCC_REGS->RCC_CFGR &= ~( (1U<<6)|(1U<<4));		// 0b1010			
		break;
		case 4 : 				
		RCC_REGS->RCC_CFGR	|= ((1U<<7) | (1U<<5)|(1U<<4));
		RCC_REGS->RCC_CFGR &= ~( (1U<<6));		// 0b1011			
		break;
		case 5 : 					
		RCC_REGS->RCC_CFGR	|= ((1U<<7) | (1U<<6));
		RCC_REGS->RCC_CFGR &= ~( (1U<<5)|(1U<<4));		// 0b1100	
		break;
		case 6 : 					
		RCC_REGS->RCC_CFGR	|= ((1U<<7) | (1U<<6)|(1U<<4));
		RCC_REGS->RCC_CFGR &= ~( (1U<<5));		// 0b1101		
		break;
		case 7 : 					
		RCC_REGS->RCC_CFGR	|= ((1U<<7) | (1U<<6)|(1U<<5));
		RCC_REGS->RCC_CFGR &= ~( (1U<<4));		// 0b1110		
		break;
		case 8 : 					
		RCC_REGS->RCC_CFGR |= ((1U<<7) | (1U<<6)|(1U<<5)|(1U<<4));		// 0b1111		
		break;
		default:					break;
	}
	
	
	switch(apb1){
		case 0 : 
		RCC_REGS->RCC_CFGR &= ~((1U<<12) | (1U<<11)|(1U<<10));		// 0b000	
		break;
		case 1 : 
		RCC_REGS->RCC_CFGR	|= (1U<<12);
		RCC_REGS->RCC_CFGR &= ~( (1U<<11)|(1U<<10));		// 0b100		
		break;
		case 2 : 					
		RCC_REGS->RCC_CFGR	|= ((1U<<12) | (1U<<10));
		RCC_REGS->RCC_CFGR &= ~( (1U<<11));		// 0b101		
		break;
		case 3 : 					 					
		RCC_REGS->RCC_CFGR	|= ((1U<<12) | (1U<<11));
		RCC_REGS->RCC_CFGR &= ~( (1U<<10));		// 0b110			
		break;
		case 4 : 				
		RCC_REGS->RCC_CFGR	|= ((1U<<12) | (1U<<11)|(1U<<10));				// 0b111	
		break;
	
		default:					break;
	}
	
	switch(apb2){
		case 0 : 
		RCC_REGS->RCC_CFGR &= ~((1U<<15) | (1U<<14)|(1U<<13));		// 0b000	
		break;
		case 1 : 
		RCC_REGS->RCC_CFGR	|= (1U<<15);
		RCC_REGS->RCC_CFGR &= ~( (1U<<13)|(1U<<14));		// 0b100		
		break;
		case 2 : 					
		RCC_REGS->RCC_CFGR	|= ((1U<<15) | (1U<<13));
		RCC_REGS->RCC_CFGR &= ~( (1U<<14));		// 0b101		
		break;
		case 3 : 					 					
		RCC_REGS->RCC_CFGR	|= ((1U<<15) | (1U<<14));
		RCC_REGS->RCC_CFGR &= ~( (1U<<13));		// 0b110			
		break;
		case 4 : 				
		RCC_REGS->RCC_CFGR	|= ((1U<<14) | (1U<<15)|(1U<<13));				// 0b111	
		break;
	
		default:					break;
	}
}


/*Enabling a peripheral on a selected bus, */

/*When accessing one peripheral, simply put other buses arguments to zero */
void vRCC_EnPeripheralClk(BUS_t bus ,uint16	periph){
	
 switch(bus){
	
	 
	case AHB1_b :				
		
	RCC_REGS->RCC_AHB1ENR |= (1U << periph);
	
	break;

	case AHB2_b :				
		
	RCC_REGS->RCC_AHB2ENR |= (1U << periph);

	break;

	case APB1_b :				
	
	RCC_REGS->RCC_APB1ENR |= (1U << periph);

	break;

	case APB2_b :				
	
	RCC_REGS->RCC_APB2ENR |= (1U << periph);

	break;	 
	 
  default:           break;
 }

}
	




