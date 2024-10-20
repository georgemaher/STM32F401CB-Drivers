#include"RCC.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
	
	vRCC_EnPeripheralClk(AHB1_b , GPIOA, 0 , 0 , 0);
	int y = 0b0101;
	y |= ( (1U << 3) | (1U << 1 ));
	
	printf("first reg:  %d\n" ,y );
	printf("first reg:  %lu\n" , RCC_REGS->RCC_AHB1ENR);
	printf("first reg:  %p\n" , &RCC_REGS->RCC_RESERVED0[1]);

	// thanks to god always
}