#include"RCC_cnfg.h"
#include"RCC_DEFS.h"
#include"STD_TYPES.h"


/*This file contatins functions protoypes for RCC driver*/


#ifndef	RCC_H_
#define	RCC_H_

/*By default, after a system reset, the HSI oscillator is selected as the system clock.
	When a clock source is used directly or through PLL as the system clock, it is not possible to stop it.	*/

void vRCC_setSysClk(Clk_Src_t clk,	HSE_Src_t hseSrc, PLL_Src_t pllSrc, AHB_PreScaler_t ahb , APB1_PreScaler_t apb1 , APB2_PreScaler_t apb2 );

/*Enabling a peripheral on a selected bus, */
void vRCC_EnPeripheralClk(BUS_t bus , uint16	periph);











#endif