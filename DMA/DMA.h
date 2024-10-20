#include"DMA_PRIV.h"
#include"DMA_CNFG.h"
#include"RCC.h"

#ifndef DMA_H_
#define	DMA_H_


void vDMA_init(uint8 DMA, uint8 stream, uint8 channel, uint8 direction );

void vDMA_setAddresses(uint8 DMA,uint8 stream ,uint32* src, uint32* dest , uint32 size);

void vDMA_enable(uint8 DMA , uint8 stream);

uint8 u8DMA_trasnferComplete_Clear(uint8 DMA, uint8 stream);


#endif


