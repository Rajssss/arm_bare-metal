/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Rajssss@GitHub.com
 * @brief          : Bare-Metal Programme to Control On-Board User LED (LD2) of
 * 					 NEUCLEO-STM32F446RE board Mapped at PORT-A Pin-5.
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdint.h>

void delayOn(uint32_t t_hold) //Delay Routine for LED On State
{
	for(uint32_t i=0; i < t_hold; i++ );

}

void delayOff(uint32_t t_hold) //Delay Routine for LED Off State
{
	for(uint32_t i=0; i < t_hold; i++ );

}


int main(void)
{
	uint32_t *pClkCtrlReg = (uint32_t* )0x40023830;   //Clock control enable Reg address for AHB1 on which GPIOA is connected
	uint32_t *pGPIOAModeReg = (uint32_t* )0x40020000;  //GPIO mode Reg address of GPIOA
	uint32_t *pGPIOAOutDataReg = (uint32_t* )0x40020014;   //GPIO Output Data Reg address

	*pClkCtrlReg |= 0x00000001;  //Enable clock for GPIOA in AHB1 Bus, via Clock control Reg of AHB1 (Step 1)

	//*pGPIOAModeReg &= 0xFFFFF3FF; //Clearing GPIOA pin 5 mode to 00 first (Method 1)
	*pGPIOAModeReg &= ~(3<<10);	   //Clearing GPIOA pin 5 mode to 00 first (Method 2)

	//*pGPIOAModeReg |= 0x00000400; //setting GPIOA mode pin 5 to 01->O/P (Method 1)
	*pGPIOAModeReg |= (1<<10);     //setting GPIOA mode pin 5 to 01->O/P (Method 2)

    while(1)
    {
		*pGPIOAOutDataReg |= 0x0020; //Set GPIOA Pin-5 to HIGH (LD2).
		delayOn(50000);
		*pGPIOAOutDataReg &= 0xFFDF; //Set GPIOA Pin-5 to LOW (LD2).
		delayOff(500000);
    }
}









