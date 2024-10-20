//o configure the 23 lines as interrupt sources, use the following procedure:
//• Configure the mask bits of the 23 interrupt lines (EXTI_IMR)
//• Configure the Trigger selection bits of the interrupt lines (EXTI_RTSR and EXTI_FTSR)
//• Configure the enable and mask bits that control the NVIC IRQ channel mapped to the
//external interrupt controller (EXTI) so that an interrupt coming from one of the 23 lines
//can be correctly acknowledged.
#include"STD_TYPES.h"
#include"EXTI_PRIV.h"
#include"GPIO_cnfg.h"



void vEXTI_Enable(PortName port, uint8 extline_pin);
void vEXTI_SelectTrigger(uint8 extline, uint8 trigger);
void vEXTI_SoftwareInt( uint8 extline);
uint8 uEXTI_ReadPending( uint8 pinNum);
void vEXTI_ClearPending( uint8 pinNum);