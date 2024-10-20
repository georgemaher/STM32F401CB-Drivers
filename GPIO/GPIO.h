#include"GPIO_cnfg.h"
#include"GPIO_PRIV.h"
#include"STD_TYPES.h"

#ifndef GPIO_H_
#define GPIO_H_


/*
Functions to configure the GPIOs
*/
void	vSetGPIO_mode(PortName port , PinNum pinNum, PinMode pinMode);
void	vSetGPIO_PullType(PortName port , PinNum pin , Pull_type	type); 
void	vSetGPIO_outputType(PortName port , PinNum pin , OutputMode mode);
void	vSetGPIO_outputSpeed(PortName port , PinNum pin , Output_speed  speed);
uint8	uSetGPIO_readPin(PortName port , PinNum pin );
void	vSetGPIO_writePin(PortName port , PinNum pin, uint8 data );
void	vSetGPIO_lockPin(PortName port , PinNum pin );
void	vSetGPIO_alternateFunction(PortName port , PinNum pin , AlternateFunctions af);







#endif