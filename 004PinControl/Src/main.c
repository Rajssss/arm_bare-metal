/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Rajssss@GitHub.com
 * @brief          : Bare-Metal Program for GPIO Digital Read/Input.
 * 					 This Program controls the On-board LED and a user LED on
 * 					 GIPO PA1 based on the status of GPIO PA0.
 ******************************************************************************
 */


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdint.h>
#define GPIOA0Stat (uint8_t volatile const)(*pGPIOAInDataReg & 0x01) //Extracts the LSB of GPIOA I/P Data Reg ie GPIOA pin-0 status

int main(void)
{
	uint32_t volatile *const pClkCtrlReg       =  (uint32_t* ) (0x40023800 + 0x30);  //Clock control enable Reg address for AHB1 on which GPIOA is connected
	uint32_t volatile *const pGPIOAModeReg     =  (uint32_t* ) (0x40020000 + 0x00);  //GPIOA mode Reg address
	uint32_t volatile *const pGPIOAOutDataReg  =  (uint32_t* ) (0x40020000 + 0x14);  //GPIOA Output Data Reg address
	uint32_t volatile *const pGPIOAInDataReg   =  (uint32_t* ) (0x40020000 + 0x10);  //GPIOA Input Data Reg address

	*pClkCtrlReg    |=  (0x00000001);  //Enable clock for GPIOA in AHB1 Bus, via Clock control Reg of AHB1
	*pGPIOAModeReg  &=  ~(3<<10);      //Clearing GPIOA pin 5 (LD2) mode to 00 first
	*pGPIOAModeReg  |=  (1<<10);       //Setting GPIOA pin 5 mode to 01->O/P
	*pGPIOAModeReg  &=  ~(0x0F);       //Clearing GPIOA pin 0 and 1 to 00 (INPUT) mode
	*pGPIOAModeReg  |=  (1<<2);        //Setting GPIOA pin 1 mode to 01->O/P


	while(1)
	{
		if(GPIOA0Stat)                      //If GPIO PA0 is HIGH
		{
			*pGPIOAOutDataReg |= (1<<5);    //Set GPIOA pin-5 HIGH
			*pGPIOAOutDataReg |= (1<<1);    //Set GPIOA pin-1 HIGH
		}
		else								//Else
		{
			*pGPIOAOutDataReg &= ~(1<<5);   //Set GPIOA pin-5 LOW
			*pGPIOAOutDataReg &= ~(1<<1);   //Set GPIOA pin-1 LOW
		}
	}
}
