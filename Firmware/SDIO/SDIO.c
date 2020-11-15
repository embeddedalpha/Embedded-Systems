#include "SDIO.h"



void SDIO_1_Bit_Init(uint32_t data_length)
{
	RCC ->AHBENR |= RCC_AHBENR_SDIOEN;
	
  GPIO_Setup(GPIOD,2,ALTERNATE_PUSH_PULL_OUTPUT); //CMD
  GPIO_Setup(GPIOC,12,ALTERNATE_PUSH_PULL_OUTPUT); //CLK
	GPIO_Setup(GPIOC,8,ALTERNATE_PUSH_PULL_OUTPUT); //D0
	
	//CLOCK CONFIGURATION
	SDIO ->CLKCR &= (uint16_t)~SDIO_CLKCR_WIDBUS; //SDIO_DO USED
	SDIO ->CLKCR |= 18<<0; //400KHZ DURING INITIALIZATION
	SDIO ->CLKCR |= SDIO_CLKCR_CLKEN; //ENABLE CLOCK
	
	SDIO->DLEN = data_length;
	
}
	//
void SDIO_4_Bit_Init(uint32_t data_length)
{
	RCC ->AHBENR |= RCC_AHBENR_SDIOEN;
	
  GPIO_Setup(GPIOD,2,ALTERNATE_PUSH_PULL_OUTPUT); //CMD
  GPIO_Setup(GPIOC,12,ALTERNATE_PUSH_PULL_OUTPUT); //CLK
	GPIO_Setup(GPIOC,8,ALTERNATE_PUSH_PULL_OUTPUT); //D0
  GPIO_Setup(GPIOC,9,ALTERNATE_PUSH_PULL_OUTPUT); //D1
	GPIO_Setup(GPIOC,10,ALTERNATE_PUSH_PULL_OUTPUT); //D2
  GPIO_Setup(GPIOC,11,ALTERNATE_PUSH_PULL_OUTPUT); //D3
	
	SDIO ->CLKCR &= SDIO_CLKCR_WIDBUS_0; //SDIO_D[0:3] USED
	
	SDIO->DLEN = data_length;
}
	//


void SDIO_Power_ON(void)
{
	SDIO -> POWER |= SDIO_POWER_PWRCTRL;
}
//

void SDIO_Power_OFF(void)
{
SDIO -> POWER &= (uint16_t)~SDIO_POWER_PWRCTRL;
	SDIO->CLKCR |= SDIO_CLKCR_PWRSAV;
}
//

void SDIO_Send_Command(uint32_t command)
{
	SDIO->ARG = command;
}
//

uint8_t SDIO_Read_CMD_Response_(void)
{
	return (uint8_t)SDIO->RESPCMD;
}
//

uint32_t SDIO_Read_Response_1(void)
{
	return SDIO->RESP1;
}
//

uint32_t SDIO_Read_Response_2(void)
{
	return SDIO->RESP2;
}
//
uint32_t SDIO_Read_Response_3(void)
{
	return SDIO->RESP3;
}
//
uint32_t SDIO_Read_Response_4(void)
{
	return SDIO->RESP4;
}
//

