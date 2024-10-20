#include"STD_TYPES.h"

#ifndef GPIO_CNFG_H_
#define	GPIO_CNFG_H_


typedef enum{
	
	GPIOA_G,
	GPIOB_G,
	GPIOC_G,
	GPIOD_G,
	GPIOE_G,
	GPIOH_G
	
	
}PortName;
typedef enum{

	pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7,
	pin8,
	pin9,
	pin10,
	pin11,
	pin12,
	pin13,
	pin14,
	pin15
	
}PinNum;


typedef enum{

	in = 00,
	out = 01,
	af = 10,
	//Analog mode sets the pin as in low power mode, it doesn't mean the Pin is ADC!!!
	analog = 11


}PinMode;

typedef enum{
	/*
	The push-pull mode means the output is either strongly pulled low to VSS, or strongly pulled high to VDD. 
	The open drain mode simply stops driving the high FET,
	so either the pin is strongly pulled low to VSS, or left floating high-Z. 
	
	Depending on internal pull-up resistors or external ones, that is then responsible to pull the data high. If you want high-Z, 
	use open-drain mode so it won't push high, or set the pin as input and it won't push high or pull low.

 Open drain mode is compatible with other items that are open-drain.
 In the case of I2C bus for example, the IO pin must be in open-drain mode, and what is even more handy is the fact that while it is a 3.3V MCU, 
 the open-drain mode allows (some pins, not all) to be pulled up to 5V, to for example allow the 3.3V MCU to talk directly on a 5V I2C bus with other 5V I2C devices.
	
	In communication protcols, the open drain only gets to high state (1) if a pull up resistor is connected  

	*/
	push_pull,
	openDrain
	
}OutputMode;

typedef enum{
	
	low = 00,
	med = 01,
	high =10,
	veryHigh = 11
	
}Output_speed;


typedef enum{
	none = 00,
	up = 01,
	down = 10
	
}Pull_type;


typedef enum{
	
	af0 = 0b0000,
	af1 = 0b0001,
	af2 = 0b0010,
	af3 = 0b0011,
	af4 = 0b0100,
	af5 = 0b0101,
	af6 = 0b0110,
	af7 = 0b0111,
	af8 = 0b1000,
	af9 = 0b1001,  
	af10= 0b1010,
	af11= 0b1011,
	af12= 0b1100,
	af13= 0b1101,
	af14= 0b1110,
	af15= 0b1111
	
	
}AlternateFunctions;





#endif