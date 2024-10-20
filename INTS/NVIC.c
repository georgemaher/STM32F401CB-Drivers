#include"NVIC.h"


void	vNVIC_EnableInt(uint16 intpt){
	uint16 int2 = 0;
	if (intpt >=0 && intpt <32){
	
		NVIC_ISER0 |= (1U << intpt);
	
	}
	else if(intpt >=32 && intpt <63){
	
		int2 -= 32;
		NVIC_ISER1 |= (1u << int2);
		
	}	
	else if(intpt >=64 && intpt <95){
	
		int2 -=64;
		NVIC_ISER2 |= (1u << int2);
		
	}	


}
void	vNVIC_ClearInt(uint16 intpt){

  uint16 int2 = 0;
	if (intpt >=0 && intpt <32){
	
		NVIC_ICER0 |= (1U << intpt);
	
	}
	else if(intpt >=32 && intpt <63){
	
		int2 -= 32;
		NVIC_ICER1 |= (1u << int2);
		
	}	
	else if(intpt >=64 && intpt <95){
	
		int2 -=64;
		NVIC_ICER2 |= (1u << int2);
		

	}
}
void	vNVIC_EnablePendingInt(uint16 intpt){
  uint16 int2 = 0;
	if (intpt >=0 && intpt <32){
	
		NVIC_ISPR0 |= (1U << intpt);
	
	}
	else if(intpt >=32 && intpt <63){
	
		int2 -= 32;
		NVIC_ISPR1 |= (1u << int2);
		
	}	
	else if(intpt >=64 && intpt <95){
	
		int2 -=64;
		NVIC_ISPR2 |= (1u << int2);
	}

}
void	vNVIC_ClearPendingInt(uint16 intpt){

	uint16 int2 = 0;
	if (intpt >=0 && intpt <32){
	
		NVIC_ICPR0 |= (1U << intpt);
	
	}
	else if(intpt >=32 && intpt <63){
	
		int2 -= 32;
		NVIC_ICPR1 |= (1u << int2);
		
	}	
	else if(intpt >=64 && intpt <95){
	
		int2 -=64;
		NVIC_ICPR2 |= (1u << int2);
	}
}


uint8	uNVIC_ReadActiveInt(uint16 intpt){
	
	uint8 readFlag = 0;
	uint8 int2 = 0;
		if (intpt >=0 && intpt <32){
	
		readFlag = (NVIC_IABR0 &(1U<<intpt));
	
	}
	else if(intpt >=32 && intpt <63){
	
		int2 -= 32;
		readFlag = (NVIC_IABR1 &(1U<<int2));
		
	}	
	else if(intpt >=64 && intpt <95){
	
		int2 -=64;
		readFlag = (NVIC_IABR2 &(1U<<int2));
	}
	return readFlag;
}



void	vNVIC_SetPriority(uint16 intpt ,uint8 u8priority_cnfg ,uint8 group, uint8 subGroup ){
	SCB_AIRCR |= (SCB_AIRCR_VECTKEY <<16);
	
//	int y = (x & (0b111 << 3)) >> 3; // read specific 3 bits.
	switch(u8priority_cnfg){
		
		case PRIORITY_CNFG1:	
		SCB_AIRCR &=~(1U << 10);			//ob0xx		16Groups, 0 SubGroups
		NVIC_IPR[intpt] = (group << 4U);	//  accessing the 8bit in the 32 bit regs
		
		break;
		
		case PRIORITY_CNFG2:					
		SCB_AIRCR = (SCB_AIRCR | (1U << 10)) &~ ((1U << 9) |(1U << 8)); 				//ob100		8Groups, 2 SubGroups
		NVIC_IPR[intpt] = (group << 5U)| (subGroup << 4U);	//  accessing the 8bit in the 32 bit regs

		
		break;
		
		case PRIORITY_CNFG3:					
		SCB_AIRCR |=(1U << 10);				//ob101		4Groups, 4 SubGroups		
    SCB_AIRCR &=~(1U << 9);
		SCB_AIRCR &=~(1U << 8);
		NVIC_IPR[intpt] = (group << 6U)| (subGroup << 4U);
		break;
		
		case PRIORITY_CNFG4:					
		SCB_AIRCR |=(1U << 10);				//ob110		2Groups, 8 SubGroups
		SCB_AIRCR |=(1U << 9);
		SCB_AIRCR &=~(1U << 8);
		NVIC_IPR[intpt] = (group << 7U)| (subGroup << 4U);

		break;
		
		case PRIORITY_CNFG5:						
		SCB_AIRCR |=(1U << 10);				//ob111		0Groups, 16 SubGroups
		SCB_AIRCR |=(1U << 9);
		SCB_AIRCR |=(1U << 8);
		NVIC_IPR[intpt] =  (subGroup << 4U);
		break;
		
		default:												
		break;
	}

}

