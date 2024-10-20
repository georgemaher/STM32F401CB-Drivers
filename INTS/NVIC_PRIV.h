#ifndef NVIC_PRIV_H_
#define	NVIC_PRIV_H_

/*
NVIC_IPR[0] = *(NVIC_IPR + 0) returns value
so I pass the address and it will be dereferenced 
automatically when calling the array element.
*/

#define	NVIC_IPR		     (	( volatile uint8* )0xE000E400)
#define NVIC_ISER0			 (*( volatile uint32* )0xE000E100 )
#define NVIC_ISER1			 (*( volatile uint32* )0xE000E104 )
#define NVIC_ISER2			 (*( volatile uint32* )0xE000E108 )
#define NVIC_ICER0			 (*( volatile uint32* )0xE000E180 )
#define NVIC_ICER1			 (*( volatile uint32* )0xE000E184 )
#define NVIC_ICER2			 (*( volatile uint32* )0xE000E188 )
#define NVIC_ISPR0			 (*( volatile uint32* )0xE000E200 )
#define NVIC_ISPR1			 (*( volatile uint32* )0xE000E204 )
#define NVIC_ISPR2			 (*( volatile uint32* )0xE000E208 )
#define NVIC_ICPR0			 (*( volatile uint32* )0xE000E280 )
#define NVIC_ICPR1			 (*( volatile uint32* )0xE000E284 )
#define NVIC_ICPR2			 (*( volatile uint32* )0xE000E288 )
																												
#define NVIC_IABR0			 (*( volatile uint32* )0xE000E300 )
#define NVIC_IABR1			 (*( volatile uint32* )0xE000E304 )
#define NVIC_IABR2			 (*( volatile uint32* )0xE000E308 )



#define SCB_BASE_ADDRESS		(uint32*) 0xE000ED00
#define	SCB_AIRCR						( *(volatile uint32*)(SCB_BASE_ADDRESS + 0x0C)	)		
#define	SCB_AIRCR_VECTKEY		0x5FA 
#define	PRIORITY_CNFG1			0		//ob0xx		16Groups, 0 SubGroups
#define	PRIORITY_CNFG2			1		//ob100		8Groups, 2 SubGroups
#define	PRIORITY_CNFG3			2		//ob101		4Groups, 4 SubGroups
#define	PRIORITY_CNFG4			3		//ob110		2Groups, 8 SubGroups
#define	PRIORITY_CNFG5			4		//ob111		0Groups, 16 SubGroups
                                
#endif                          
                                
                                
                                
                               	
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                
                                	
                                