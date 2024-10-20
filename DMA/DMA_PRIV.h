
#ifndef DMA_PRIV_H_
#define DMA_PRIV_H_
#include"STD_TYPES.h"
typedef struct
{
	volatile uint32 CR;
	volatile uint32 NDTR;
	volatile uint32 PAR;
	volatile uint32 M0AR;
	volatile uint32 M1AR;
	volatile uint32 FCR;
}DMA_Stream_t;

typedef struct
{
	volatile uint32 LISR;
	volatile uint32 HISR;
	volatile uint32 LIFCR;
	volatile uint32 HIFCR;
	DMA_Stream_t StreamID[8];
}DMA_Cfg_t;

#define DMA1_Instant	((volatile DMA_Cfg_t*)0x40026000 )  //Pointer to (struct of type DMA)
#define DMA2_Instant	((volatile DMA_Cfg_t*)0x40026400 )  //Pointer to (struct of type DMA)

#endif