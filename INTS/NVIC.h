#include"STD_TYPES.h"
#include"NVIC_PRIV.h"
#ifndef NVIC_H_
#define	NVIC_H_

void	vNVIC_EnableInt(uint16 intpt);
void	vNVIC_ClearInt(uint16 intpt);
void	vNVIC_EnablePendingInt(uint16 intpt);
void	vNVIC_ClearPendingInt(uint16 intpt);
uint8	uNVIC_ReadActiveInt(uint16 intpt);
void	vNVIC_SetPriority(uint16 intpt ,uint8 u8priority_cnfg ,uint8 group, uint8 subGroup );

#endif