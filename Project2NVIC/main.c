#include<stdio.h>
#include<stdlib.h>
#include"GPIO.h"
#include"RCC.h"
#include"NVIC.h"
#include"EXTI.h"
uint8 flag= 0;
int main(){
	vRCC_EnPeripheralClk(AHB1_b, GPIOA_G);// enable clock for portA
	vSetGPIO_mode(GPIOA_G , pin1 , out);
	vSetGPIO_outputType(GPIOA_G , pin1, push_pull);
	vSetGPIO_outputSpeed(GPIOA_G, pin1 , low);
	
	vSetGPIO_mode(GPIOA_G , pin3 , in);
	vSetGPIO_PullType(GPIOA_G , pin3, up);
	
	vEXTI_Enable(GPIOA_G,3);
	vEXTI_SelectTrigger(3 , TRIGGER_RISING);
	vNVIC_EnableInt(9);
	
	
	while(1){
	if(flag){
		vSetGPIO_writePin(GPIOA_G , pin1, 1);
		
		
	for(int i=0; i<500000; i++);	
	
	vSetGPIO_writePin(GPIOA_G , pin1, 0);

	for(int i=0; i<500000; i++);
	flag= 0;
	}

	}

}
void EXTI3_IRQHandler(void){
flag = 1;

}