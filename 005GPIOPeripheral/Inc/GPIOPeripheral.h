/*
 * GPIOPeripheral.h
 *
 * Description: STM32 GPIO Peripheral API.
 *
 *  Created on: Apr 25, 2020
 *      Author: Rajssss@GitHub.com
 */

#ifndef GPIOPERIPHERAL_H_
#define GPIOPERIPHERAL_H_

#include<stdint.h>


//Clock Control Register for GPIO Peripherals
/*************************************************
 *GPIOx_EN: IO port X clock enable
 *0: IO port H clock disabled
 *1: IO port H clock enabled
 *
 *OTGHSULPIEN: USB OTG HSULPI clock enable
 *0: IO port H clock disabled
 *1: IO port H clock enabled
 *
 *OTGHSEN: USB OTG HS clock enable
 *0: IO port H clock disabled
 *1: IO port H clock enabled
 *
 *DMA2EN: DMA2 clock enable
 *0: IO port H clock disabled
 *1: IO port H clock enabled
 *
 *DMA1EN: DMA1 clock enable
 *0: IO port H clock disabled
 *1: IO port H clock enabled
 *
 *BKPSRAMEN: Backup SRAM interface clock enable
 *0: IO port H clock disabled
 *1: IO port H clock enabled
 *
 *CRCEN: CRC clock enable
 *0: IO port H clock disabled
 *1: IO port H clock enabled
 *
 *RESERVED_x: Reserved, must be kept at reset value.
 *
 *************************************************
 */
typedef struct
{
	uint32_t 	GPIOA_EN    	:1;
	uint32_t 	GPIOB_EN    	:1;
	uint32_t 	GPIOC_EN    	:1;
	uint32_t 	GPIOD_EN   	    :1;
	uint32_t 	GPIOE_EN    	:1;
	uint32_t 	GPIOF_EN    	:1;
	uint32_t 	GPIOG_EN    	:1;
	uint32_t 	GPIOH_EN    	:1;
	uint32_t 	RESERVED_1  	:4;
	uint32_t 	CRC_EN      	:1;
	uint32_t 	RESERVED_2  	:5;
	uint32_t 	BKPSRAM_EN  	:1;
	uint32_t 	DMA1_EN     	:1;
	uint32_t 	DMA2_EN     	:1;
	uint32_t 	RESERVED_3  	:6;
	uint32_t 	OTGHS_EN    	:1;
	uint32_t 	OTGHSULPI_EN    :1;
	uint32_t 	RESERVED_4    	:1;

}RCC_AHB1ENR_t;

RCC_AHB1ENR_t *pGPIOx_Clk_Ctrl_Reg = (RCC_AHB1ENR_t* ) (0x40023800 + 0x30);



//GPIOx Mode Selection Register, where x= Name of the port
/*********************************************************
 *These bits are written to configure the I/O direction mode.
 *00: Input (reset state)
 *01: General purpose output mode
 *10: Alternate function mode
 *11: Analog mode
 *********************************************************
 */
typedef struct{
	uint32_t 	PIN_0    		:2;
	uint32_t 	PIN_1    		:2;
	uint32_t 	PIN_2    		:2;
	uint32_t 	PIN_3    		:2;
	uint32_t 	PIN_4    		:2;
	uint32_t 	PIN_5    		:2;
	uint32_t 	PIN_6    		:2;
	uint32_t 	PIN_7    		:2;
	uint32_t 	PIN_8    		:2;
	uint32_t 	PIN_9    		:2;
	uint32_t 	PIN_10    		:2;
	uint32_t 	PIN_11   		:2;
	uint32_t 	PIN_12   		:2;
	uint32_t 	PIN_13   		:2;
	uint32_t 	PIN_14   		:2;
	uint32_t 	PIN_15   		:2;

}GPIOx_MODER_t;



//GPIO port x input data register, where x= Name of the port
/***********************************************************
 * Port input data.These bits are read-only and can be
 * accessed in word mode only. They contain the input value
 * of the corresponding I/O port
 *
 * RESERVED: Reserved, must be kept at reset value.
 ***********************************************************
 */
typedef struct{
	uint32_t 	IDR0    		:1;
	uint32_t 	IDR1    		:1;
	uint32_t 	IDR2    		:1;
	uint32_t 	IDR3    		:1;
	uint32_t 	IDR4    		:1;
	uint32_t 	IDR5    		:1;
	uint32_t 	IDR6    		:1;
	uint32_t 	IDR7    		:1;
	uint32_t 	IDR8    		:1;
	uint32_t 	IDR9    		:1;
	uint32_t 	IDR10    		:1;
	uint32_t 	IDR11   		:1;
	uint32_t 	IDR12    		:1;
	uint32_t 	IDR13    		:1;
	uint32_t 	IDR14   		:1;
	uint32_t 	IDR15    		:1;
	uint32_t 	RESERVED    	:16;

}GPIOx_IDR_t;




//GPIO port x output data register, where x= Name of the port
/***********************************************************
 * Port output data.
 *
 * RESERVED: Reserved, must be kept at reset value.
 ***********************************************************
 */
typedef struct{
	uint32_t 	ODR0    		:1;
	uint32_t 	ODR1    		:1;
	uint32_t 	ODR2    		:1;
	uint32_t 	ODR3    		:1;
	uint32_t 	ODR4    		:1;
	uint32_t 	ODR5    		:1;
	uint32_t 	ODR6    		:1;
	uint32_t 	ODR7    		:1;
	uint32_t 	ODR8    		:1;
	uint32_t 	ODR9    		:1;
	uint32_t 	ODR10    		:1;
	uint32_t 	ODR11   		:1;
	uint32_t 	ODR12    		:1;
	uint32_t 	ODR13    		:1;
	uint32_t 	ODR14   		:1;
	uint32_t 	ODR15    		:1;
	uint32_t 	RESERVED    	:16;

}GPIOx_ODR_t;




//GPIO port x pull-up/pull-down reg, where x= Name of the port
/*************************************************************
 *Port x configuration bits
 *These bits are written to configure the I/O pull-up or pull-down
 *00: No pull-up, pull-down
 *01: Pull-up
 *10: Pull-down
 *11: Reserved
 *************************************************************
 */
typedef struct{
	uint32_t 	PIN_0    		:2;
	uint32_t 	PIN_1    		:2;
	uint32_t 	PIN_2    		:2;
	uint32_t 	PIN_3    		:2;
	uint32_t 	PIN_4    		:2;
	uint32_t 	PIN_5    		:2;
	uint32_t 	PIN_6    		:2;
	uint32_t 	PIN_7    		:2;
	uint32_t 	PIN_8    		:2;
	uint32_t 	PIN_9    		:2;
	uint32_t 	PIN_10    		:2;
	uint32_t 	PIN_11   		:2;
	uint32_t 	PIN_12   		:2;
	uint32_t 	PIN_13   		:2;
	uint32_t 	PIN_14   		:2;
	uint32_t 	PIN_15   		:2;

}GPIOx_PUPDR_t;


//GPIO port x port output type register, where x= Name of the port
/*****************************************************************
 * Port x configuration bits.
 * These bits are written to configure the output type of the I/O
 * port.
 * 0: Output push-pull (reset state)
 * 1: Output open-drain
 *
 * RESERVED: Reserved, must be kept at reset value.
 *****************************************************************
 */
typedef struct{
	uint32_t 	OT0    			:1;
	uint32_t 	OT1		   		:1;
	uint32_t 	OT2    			:1;
	uint32_t 	OT3    			:1;
	uint32_t 	OT4    			:1;
	uint32_t 	OT5    			:1;
	uint32_t 	OT6    			:1;
	uint32_t 	OT7    			:1;
	uint32_t 	OT8    			:1;
	uint32_t 	OT9    			:1;
	uint32_t 	OT10    			:1;
	uint32_t 	OT11   			:1;
	uint32_t 	OT12    		:1;
	uint32_t 	OT13    		:1;
	uint32_t 	OT14   			:1;
	uint32_t 	OT15    		:1;
	uint32_t 	RESERVED    	:16;

}GPIOx_OTYPER_t;



//GPIO port x output speed register, where x= Name of the port
/*************************************************************
 *Port x configuration bits
 *These bits are written by software to configure the output
 *speed.
 *00: Low speed
 *01: Medium speed
 *10: Fast speed
 *11: High speed
 *************************************************************
 */
typedef struct{
	uint32_t 	PIN_0    		:2;
	uint32_t 	PIN_1    		:2;
	uint32_t 	PIN_2    		:2;
	uint32_t 	PIN_3    		:2;
	uint32_t 	PIN_4    		:2;
	uint32_t 	PIN_5    		:2;
	uint32_t 	PIN_6    		:2;
	uint32_t 	PIN_7    		:2;
	uint32_t 	PIN_8    		:2;
	uint32_t 	PIN_9    		:2;
	uint32_t 	PIN_10    		:2;
	uint32_t 	PIN_11   		:2;
	uint32_t 	PIN_12   		:2;
	uint32_t 	PIN_13   		:2;
	uint32_t 	PIN_14   		:2;
	uint32_t 	PIN_15   		:2;

}GPIOx_OSPEEDR_t;



//GPIO port x output speed register, where x= Name of the port
/*************************************************************
 *
 *BS_x: Port x set bit y (y= 0..15).
 * These bits are write-only and can be accessed in word,
 * half-word or byte mode. A read to these bits returns the
 * value 0x0000.
 * 0: No action on the corresponding ODRx bit
 * 1: Sets the corresponding ODRx bit
 *
 *BR_y: Port x reset bit y (y = 0..15).
 * These bits are write-only and can be accessed in word,
 * half-word or byte mode. A read to these bits returns the
 * value 0x0000.
 * 0: No action on the corresponding ODRx bit
 * 1: Resets the corresponding ODRx bit
 *
 *
 *
 * If both BSx and BRx are set, BSx has priority,
 *
 *************************************************************
 */
typedef struct{
	uint32_t 	BS_0    		:2;
	uint32_t 	BS_1    		:2;
	uint32_t 	BS_2    		:2;
	uint32_t 	BS_3    		:2;
	uint32_t 	BS_4    		:2;
	uint32_t 	BS_5    		:2;
	uint32_t 	BS_6	   		:2;
	uint32_t 	BS_7    		:2;
	uint32_t 	BS_8    		:2;
	uint32_t 	BS_9    		:2;
	uint32_t 	BS_10    		:2;
	uint32_t 	BS_11   		:2;
	uint32_t 	BS_12   		:2;
	uint32_t 	BS_13   		:2;
	uint32_t 	BS_14   		:2;
	uint32_t 	BS_15   		:2;
	uint32_t 	BR_0  	 		:2;
	uint32_t 	BR_1   			:2;
	uint32_t 	BR_2 	  		:2;
	uint32_t 	BR_3   			:2;
	uint32_t 	BR_4   	 		:2;
	uint32_t 	BR_5   			:2;
	uint32_t 	BR_6   			:2;
	uint32_t 	BR_7   			:2;
	uint32_t 	BR_8 	  		:2;
	uint32_t 	BR_9   			:2;
	uint32_t 	BR_10   		:2;
	uint32_t 	BR_11   		:2;
	uint32_t 	BR_12   		:2;
	uint32_t 	BR_13   		:2;
	uint32_t 	BR_14   		:2;
	uint32_t 	BR_15  			:2;

}GPIOx_BSRR_t;







#endif /* GPIOPERIPHERAL_H_ */
