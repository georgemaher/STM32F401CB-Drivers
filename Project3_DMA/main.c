
#include"DMA.h"
#include"stdio.h"
#include"stdlib.h"
#include"GPIO.h"

uint8 flag = 0;


int main(){
	uint32 arr0[5];
	uint32 arr1[5] ;
	vRCC_EnPeripheralClk(AHB1_b ,GPIOA_R);
	vSetGPIO_mode(GPIOA_G , pin1 , out);
	vSetGPIO_outputType(GPIOA_G , pin0 , push_pull);
	vSetGPIO_outputSpeed(GPIOA_G , pin0 , med);
	
	int count = 0;
	for(int i = 0; i<5 ; i++){
	
	arr0[i] = i;
	}	
	
	vDMA_init(DMA2 ,STREAM0, CHANNEL1 , M_M);

	vDMA_setAddresses(DMA2, STREAM0,arr0,arr1,5);
		
	vDMA_enable(DMA2 , STREAM0);
		
	while(1){
		
		for(int i = 0 ; i <5 ; i++){
		 
			if (arr0[i] == arr1[i]){
			count++;
			}

		}			
	
		if(count == 5){
		  vSetGPIO_writePin(GPIOA_G , pin0 , 1);
		  for(int i=0; i<500000; i++);	
	  	vSetGPIO_writePin(GPIOA_G , pin0 , 0);
			for(int i=0; i<500000; i++);	
		}
	}
}

