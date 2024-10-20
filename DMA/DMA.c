#include"DMA.h"
void vDMA_init(uint8 DMA, uint8 stream, uint8 channel, uint8 direction ){
	
	switch(DMA){
		case(DMA1):	
		/*
		1. If the stream is enabled, disable it by resetting the EN bit in the DMA_SxCR register,
		then read this bit in order to confirm that there is no ongoing stream operation. Writing
		this bit to 0 is not immediately effective since it is actually written to 0 once all the
		current transfers have finished. When the EN bit is read as 0, this means that the
		stream is ready to be configured. It is therefore necessary to wait for the EN bit to be
		cleared before starting any stream configuration. All the stream dedicated bits set in the
		status register (DMA_LISR and DMA_HISR) from the previous data block DMA
		transfer should be cleared before the stream can be re-enabled.
		*/
		DMA1_Instant->StreamID[stream].CR &=~ (1U<<0);
		
		while(DMA1_Instant->StreamID[stream].CR &(1U<<0)){/*Do nothing*/}
		
		vRCC_EnPeripheralClk(AHB1_b, DMA1_R);	// Enable clock for DMA1	
//		DMA1_Instant->LIFCR |= 0xFFFFFFFF;//clearing flags for streams
//		DMA1_Instant->HIFCR |= 0xFFFFFFFF;//clearing flags for streams
		/*
		5. Select the DMA channel (request) using CHSEL[2:0] in the DMA_SxCR register.
		*/
		DMA1_Instant->StreamID[stream].CR |= (channel << 25);	
		/*
			6. If the peripheral is intended to be the flow controller and if it supports this feature, set 
			the PFCTRL bit in the DMA_SxCR register.
		*/	
		DMA1_Instant->StreamID[stream].CR &=~ (1U<<5); // DMA is the flow controller
		/*
			7. Configure the stream priority using the PL[1:0] bits in the DMA_SxCR register.
		*/	
		DMA1_Instant->StreamID[stream].CR |= ((1U<<16) | (1U<<17)); // priority set to V.High	
		/*
		8. Configure the FIFO usage (enable or disable, threshold in transmission and reception)
		*/	
		DMA1_Instant->StreamID[stream].FCR &=~ (1U<<2); // disabling direct mode
		DMA1_Instant->StreamID[stream].FCR |= (1U<<1);
		DMA1_Instant->StreamID[stream].FCR &=~ (1U<<0); // 3/4 threshold
		/*
		9. Configure the data transfer direction, peripheral and memory incremented/fixed mode,
		single or burst transactions, peripheral and memory data widths, Circular mode, 
		Double buffer mode and interrupts after half and/or full transfer, and/or errors in the
		DMA_SxCR register.
		*/
		DMA1_Instant->StreamID[stream].CR |= (direction << 6); // setting direction 
		DMA1_Instant->StreamID[stream].CR |= (1<< 9); // peripheral pointer incrementation enabled
		DMA1_Instant->StreamID[stream].CR |= (1<< 10); // Memory pointer incrementation enabled
	  DMA1_Instant->StreamID[stream].CR |= (1U<<12);  //M and P size is word (32bit)
	  DMA1_Instant->StreamID[stream].CR &=~ (1U<<11);
	  DMA1_Instant->StreamID[stream].CR |= (1U<<14);
	  DMA1_Instant->StreamID[stream].CR &=~ (1U<<13);
		DMA1_Instant->StreamID[stream].CR |= (1U<<4);// Transfer complete interrupt enabled.
		
		break;
		case(DMA2):	
		/*
		1. If the stream is enabled, disable it by resetting the EN bit in the DMA_SxCR register,
		then read this bit in order to confirm that there is no ongoing stream operation. Writing
		this bit to 0 is not immediately effective since it is actually written to 0 once all the
		current transfers have finished. When the EN bit is read as 0, this means that the
		stream is ready to be configured. It is therefore necessary to wait for the EN bit to be
		cleared before starting any stream configuration. All the stream dedicated bits set in the
		status register (DMA_LISR and DMA_HISR) from the previous data block DMA
		transfer should be cleared before the stream can be re-enabled.
		*/
		DMA2_Instant->StreamID[stream].CR &=~ (1U<<0);
		
		while(DMA2_Instant->StreamID[stream].CR &(1U<<0)){}
		
		vRCC_EnPeripheralClk(AHB1_b, DMA2_R);	// Enable clock for DMA2	
		DMA2_Instant->LIFCR |= 0xFFFFFFFF;//clearing flags for streams
		DMA2_Instant->HIFCR |= 0xFFFFFFFF;//clearing flags for streams
		/*
		5. Select the DMA channel (request) using CHSEL[2:0] in the DMA_SxCR register.
		*/
		DMA2_Instant->StreamID[stream].CR |= (channel << 25);	
		/*
			6. If the peripheral is intended to be the flow controller and if it supports this feature, set 
			the PFCTRL bit in the DMA_SxCR register.
		*/	
		DMA2_Instant->StreamID[stream].CR &=~ (1U<<5); // DMA is the flow controller
		/*
			7. Configure the stream priority using the PL[1:0] bits in the DMA_SxCR register.
		*/	
		DMA2_Instant->StreamID[stream].CR |= ((1U<<16) | (1U<<17)); // priority set to V.High	
		/*
		8. Configure the FIFO usage (enable or disable, threshold in transmission and reception)
		*/	
		DMA2_Instant->StreamID[stream].FCR &=~ (1U<<2); // disabling direct mode
		DMA2_Instant->StreamID[stream].FCR |= (1U<<1);
		DMA2_Instant->StreamID[stream].FCR &=~ (1U<<0); // 3/4 threshold
		/*
		9. Configure the data transfer direction, peripheral and memory incremented/fixed mode,
		single or burst transactions, peripheral and memory data widths, Circular mode, 
		Double buffer mode and interrupts after half and/or full transfer, and/or errors in the
		DMA_SxCR register.
		*/
		DMA2_Instant->StreamID[stream].CR |= (direction << 6); // setting direction 
		DMA2_Instant->StreamID[stream].CR |= (1<< 9); // peripheral pointer incrementation enabled
		DMA2_Instant->StreamID[stream].CR |= (1<< 10); // Memory pointer incrementation enabled
	  DMA2_Instant->StreamID[stream].CR |= (1U<<12);  //M and P size is word (32bit)
	  DMA2_Instant->StreamID[stream].CR &=~ (1U<<11);
	  DMA2_Instant->StreamID[stream].CR |= (1U<<14);
	  DMA2_Instant->StreamID[stream].CR &=~ (1U<<13);
		DMA2_Instant->StreamID[stream].CR |= (1U<<4);// Transfer complete interrupt enabled.
		
		break;
		
		default:				break;
	}


}



void vDMA_setAddresses(uint8 DMA,uint8 stream ,uint32* src, uint32* dest , uint32 size){

	//An array is considered to be the same thing as a pointer to the first item in the array.
	
/*
	2. Set the peripheral port register address in the DMA_SxPAR register. The data will be
moved from/ to this address to/ from the peripheral port after the peripheral event.
	
*/
	
switch(DMA){
	case(DMA1):			
		DMA1_Instant->StreamID[stream].CR &=~(1U<<0); // Disabling the stream
		/*
		3. Set the memory address in the DMA_SxMA0R register (and in the DMA_SxMA1R
	  register in the case of a double buffer mode). The data will be written to or read from
	  this memory after the peripheral event.
		*/
	
	  DMA1_Instant->StreamID[stream].PAR = (uint32) src;
		DMA1_Instant->StreamID[stream].M0AR=(uint32) dest;
	/*	
	4. Configure the total number of data items to be transferred in the DMA_SxNDTR
	register. After each peripheral event or each beat of the burst, this value is
	decremented.		
	*/
		DMA1_Instant->StreamID[stream].NDTR = size;
	break;
	
	case(DMA2):			
		DMA2_Instant->StreamID[stream].CR &=~(1U<<0); // Disabling the stream
		DMA2_Instant->StreamID[stream].PAR = (uint32) src;
		DMA2_Instant->StreamID[stream].M0AR=(uint32) dest;
		DMA2_Instant->StreamID[stream].NDTR = size;

	break;

	default: 				break;

	}
}

void vDMA_enable(uint8 DMA , uint8 stream){
/*
		10. Activate the stream by setting the EN bit in the DMA_SxCR register.
		As soon as the stream is enabled, it can serve any DMA request from the peripheral
		connected to the stream.
		*/
	switch(DMA){
		case(DMA1):		DMA1_Instant->StreamID[stream].CR |= (1U<<0); // Re-enabling the stream
									break;
		case(DMA2):		DMA2_Instant->StreamID[stream].CR |= (1U<<0);
		default:			break;
	
	}


}

uint8 u8DMA_trasnferComplete_Clear(uint8 DMA, uint8 stream){
	uint8 flag = 0;
	switch(DMA){
		case(DMA1):		if(stream == 0){
									flag = DMA1_Instant->LISR &(1U<<5);	
									DMA1_Instant->LIFCR |= (1U <<5);
									return (flag);
									}
									else if(stream == 1){
									flag = DMA1_Instant->LISR &(1U<<11);	
									DMA1_Instant->LIFCR |= (1U <<11);
									return (flag);
									
									}
									else if(stream == 2){
									flag = DMA1_Instant->LISR &(1U<<21);	
									DMA1_Instant->LIFCR |= (1U <<21);
									return (flag);
									
									}
									else if(stream == 3){
									flag = DMA1_Instant->LISR &(1U<27);	
									DMA1_Instant->LIFCR |= (1U <<27);
									return (flag);
									
									}
									else if(stream == 4){
									flag = DMA1_Instant->HISR &(1U<<5);
									DMA1_Instant->HIFCR |= (1U <<5);
									return (flag);
									
									}
									else if(stream == 5){
									flag = DMA1_Instant->HISR &(1U<<11);
									DMA1_Instant->HIFCR |= (1U <<11);
									return (flag);
									
									}
									else if(stream == 6){
									flag = DMA1_Instant->HISR &(1U<<21);
									DMA1_Instant->HIFCR |= (1U <<21);
									return (flag);
									
									}
									else{
									flag = DMA1_Instant->HISR &(1U<<27);
									DMA1_Instant->HIFCR |= (1U <<27);
									return (flag);
									}
			
									break;
		case(DMA2):		
									if(stream == 0){
									flag= DMA2_Instant->LISR &(1U<<5) ;
									DMA2_Instant->LIFCR |= (1U <<5);
									return (flag);
									}
									else if(stream == 1){
									flag= DMA2_Instant->LISR &(1U<<11) ;
									DMA2_Instant->LIFCR |= (1U <<11);
									return (flag);
									
									}
									else if(stream == 2){
									flag= DMA2_Instant->LISR &(1U<<21) ;
									DMA2_Instant->LIFCR |= (1U <<21);
									return (flag);
									
									}
									else if(stream == 3){
									flag= DMA2_Instant->LISR &(1U<<27) ;
									DMA2_Instant->LIFCR |= (1U <<27);
									return (flag);
									
									}
									else if(stream == 4){
									flag = DMA2_Instant->HISR &(1U<<5);
									DMA2_Instant->HIFCR |= (1U <<5);
									return (flag);
									
									}
									else if(stream == 5){
									flag = DMA2_Instant->HISR &(1U<<11);
									DMA2_Instant->HIFCR |= (1U <<11);
									return (flag);
									
									}
									else if(stream == 6){
									flag = DMA2_Instant->HISR &(1U<<21);
									DMA2_Instant->HIFCR |= (1U <<21);
									return (flag);
									
									}
									else{
									flag = DMA2_Instant->HISR &(1U<<27);
									DMA2_Instant->HIFCR |= (1U <<27);
									return (flag);
									}
			
									break;

		default: return 0;			break;
		}
	}


