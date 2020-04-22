/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Rajssss@GitHub.com
 * @brief          : Bare-Metal Program for GPIO Digital Read/Input
 ******************************************************************************
 */


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdint.h>

int main(void)
{
	uint32_t *pClkCtrlReg = (uint32_t* )0x40023830;   //Clock control enable Reg address for AHB1 on which GPIOA is connected
	uint32_t *pGPIOAModeReg = (uint32_t* )0x40020000;  //GPIO mode Reg address of GPIOA
	uint32_t *pGPIOAOutDataReg = (uint32_t* )0x40020014;   //GPIO Output Data Reg address
	uint32_t *pGPIOAInDataReg = (uint32_t* )0x40020010;   //GPIO Input Data Reg address

	*pClkCtrlReg |= 0x00000001;  //Enable clock for GPIOA in AHB1 Bus, via Clock control Reg of AHB1

	*pGPIOAModeReg &= ~(3<<10); //Clearing GPIOA pin 5 (LD2) mode to 00 first
	*pGPIOAModeReg |= (1<<10); //setting GPIOA pin 5 mode to 01->O/P

	*pGPIOAModeReg &= ~(0x0F); //Clearing GPIOA pin 0 and 1 to 00 (INPUT) mode
	*pGPIOAModeReg |= (1<<2);


	while(1)
	{
		if((*pGPIOAInDataReg & 0x01)) //(*pGPIOAInDataReg & 0x01) extracts the LSB ie GPIOA pin-0
		{
			*pGPIOAOutDataReg |= (1<<5); // Set GPIOA pin-5 HIGH
			*pGPIOAOutDataReg |= (1<<1); // Set GPIOA pin-1 HIGH
		}
		else
		{
			*pGPIOAOutDataReg &= ~(1<<5); // Set GPIOA pin-5 LOW
			*pGPIOAOutDataReg &= ~(1<<1); // Set GPIOA pin-1 LOW
		}
	}
}
