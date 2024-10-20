#include<stdio.h>
#include<stdlib.h>
#include"GPIO.h"
#include"RCC.h"
#include <time.h>


int main(){
	vRCC_EnPeripheralClk(AHB1_b, GPIOA_G);// enable clock for portA
	vSetGPIO_mode(GPIOA_G , pin1 , out);



	vSetGPIO_outputType(GPIOA_G , pin1, push_pull);
	vSetGPIO_outputSpeed(GPIOA_G, pin1 , low);
	
	
	while(1){
	vSetGPIO_writePin(GPIOA_G , pin1, 1);
		
		
	for(int i=0; i<500000; i++);	
	
	vSetGPIO_writePin(GPIOA_G , pin1, 0);

	for(int i=0; i<500000; i++);
	

	}

}
