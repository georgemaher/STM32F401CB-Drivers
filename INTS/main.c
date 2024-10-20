#include<stdio.h>
#include<stdlib.h>
#include"NVIC.h"
#include"EXTI.h"

int main(){

//int x =	0b11100101; // 100 starting 3 index
//	
//int y = (x & (0b111 << 3)) >> 3; // read specific 3 bits.

//x= (x | (1U <<((1*4)+1))) &~ ((1U << (1*4))| (1U << ((1*4)+ 2))| (1U << ((1*4)+ 3)));
		

printf("NVIC1 Val = %p \n" , &NVIC_ISER0);
printf("NVIC2 Val = %p \n" , &NVIC_ISER1);
printf("NVIC3 Val = %p \n" , &NVIC_ISER2);
printf("NVIC4 Val = %p \n" , &NVIC_ICER0);	
printf("NVIC5 Val = %p \n" , &NVIC_ICER1);	
printf("NVIC6 Val = %p \n" , &NVIC_ICER2);	
printf("NVIC7 Val = %p \n" , &NVIC_ISPR0);	
printf("NVIC8 Val = %p \n" , &NVIC_ISPR1);	
printf("NVIC9 Val = %p \n" , &NVIC_ISPR2);	
printf("NVIC10 Val = %p \n" , &NVIC_ICPR0);	
printf("NVIC11 Val = %p \n" , &NVIC_ICPR1);	
printf("NVIC12 Val = %p \n" , &NVIC_ICPR2);	
printf("NVIC13 Val = %p \n" , &NVIC_IABR0);	
printf("NVIC14 Val = %p \n" , &NVIC_IABR1);	
printf("NVIC15 Val = %p \n" , &NVIC_IABR2);
printf("NVIC16 Val = %p \n" , &NVIC_IPR[0]);	
printf("NVIC17 Val = %p \n" , &NVIC_IPR[4]);	
//printf("NVIC18 Val = %p \n" , &NVIC_IPR[2]);	
printf("NVIC19 Val = %p \n" , &NVIC_IPR[236]);	
printf("EXTI0 Val = %p \n" , &EXTI_REGS->EXTI_IMR);
printf("EXTI1 Val = %p \n" , &EXTI_REGS->EXTI_EMR);
printf("EXTI2 Val = %p \n" , &EXTI_REGS->EXTI_RTSR);
printf("EXTI3 Val = %p \n" , &EXTI_REGS->EXTI_FTSR);
printf("EXTI4 Val = %p \n" , &EXTI_REGS->EXTI_SWIER);
printf("EXTI5 Val = %p \n" , &EXTI_REGS->EXTI_PR);
printf("SYS0 Val = %p \n" , &SYS_CFG_REGS->MEMRMP);
printf("SYS1 Val = %p \n" , &SYS_CFG_REGS->PMC);
printf("SYS2 Val = %p \n" , &SYS_CFG_REGS->EXTICR1);
printf("SYS3 Val = %p \n" , &SYS_CFG_REGS->EXTICR2);
printf("SYS4 Val = %p \n" , &SYS_CFG_REGS->EXTICR3);
printf("SYS5 Val = %p \n" , &SYS_CFG_REGS->EXTICR4);









}