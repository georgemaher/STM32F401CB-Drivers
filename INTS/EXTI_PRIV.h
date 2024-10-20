#include"STD_TYPES.h"
#ifndef EXTI_PRIV_H_
#define	EXTI_PRIV_H_

typedef struct{

volatile	uint32	EXTI_IMR;
volatile	uint32	EXTI_EMR;
volatile	uint32	EXTI_RTSR;
volatile	uint32	EXTI_FTSR;
volatile	uint32	EXTI_SWIER;
volatile	uint32	EXTI_PR;

}EXTI_Struct;

typedef struct{
volatile	uint32	MEMRMP;
volatile	uint32	PMC;
volatile	uint32	EXTICR1;
volatile	uint32	EXTICR2;
volatile	uint32	EXTICR3;
volatile	uint32	EXTICR4;
volatile	uint32	CMPCR;

}SYS_CFG_Struct;
	

#define	EXTI_REGS					((EXTI_Struct* )0x40013C00)

#define SYS_CFG_REGS			((SYS_CFG_Struct*)0x40013800)

#define TRIGGER_FALLING	0
#define TRIGGER_RISING	1

#endif