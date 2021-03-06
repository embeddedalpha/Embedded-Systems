#ifndef _W25Q128_H_
#define _W25Q128_H_

#include "SPI.h"

#define Write_Enable				0x06
#define Volatile_Write_Enable 		0x50
#define Write_Disable 				0x04
#define Release_Power_Down_ID		0xAB
#define Manufacturer_Device_ID 		0x90
#define JEDEC_ID					0x9f
#define Read_Unique_ID 				0x4b
#define Read_Data					0x03
#define Fast_Read 					0x0b
#define Page_Program 				0x02
#define Sector_Erase_4KB 			0x20
#define Block_Erase_32KB 			0x52
#define Block_Erase_64KB 			0xD8
#define Chip_Erase 					0xC7
#define Read_Status_Register_1		0x05
#define Write_Status_Register_1 	0x01
#define Read_Status_Register_2		0x35
#define Write_Status_Register_2 	0x31
#define Read_Status_Register_3		0x15
#define Write_Status_Register_3 	0x11
#define Read_SFDP_Register			0x5A
#define Erase_Security_Register 	0x44
#define Program_Security_Register 	0x42
#define Read_Security_Register		0x48
#define Global_Block_Lock			0x7E
#define Global_Block_Unlock 		0x98
#define Read_Block_Lock				0x3d
#define Individual_Block_Lock		0x36
#define Individual_Block_UnLock 	0x39
#define Erase_Program_Suspend		0x75
#define Erase_Program_Resume		0x7A
#define Power_Down					0xB9
#define Enter_QPI_Mode				0x38
#define Enable_Reset				0x66
#define Reset_Device				0x99


struct SPI_Master_Parameters W25Q128;

extern uint8_t Memory_Buffer[254];

void W25Q128_Init(void);

/***********************************************************************************/
void W25Q128_Write_Enable(void);
void W25Q128_Write_Disable(void);
uint8_t W25Q128_Read_Data(uint32_t address, uint8_t length);
/***********************************************************************************/

/***********************************************************************************/
void W25Q128_Write_Status_Register(uint8_t reg, uint8_t data);
void W25Q128_Page_Write(int data[256], int length, uint32_t address);
void W25Q128_Write(int data[256], int length, uint32_t address);
/***********************************************************************************/

/***********************************************************************************/
void W25Q128_Erase_64KB_Block(uint32_t address);
void W25Q128_Erase_32KB_Block(uint32_t address);
void W25Q128_Erase_4KB_Sector(uint32_t address);
void W25Q128_Chip_Erase(void);
/***********************************************************************************/

/***********************************************************************************/
void W25Q128_Chip_Erase(void);
void W25Q128_Reset_Device(void);
/***********************************************************************************/

/***********************************************************************************/
uint8_t W25Q128_Read_Status_Register_1(void);
uint8_t W25Q128_Read_Status_Register_2(void);
uint8_t W25Q128_Read_Status_Register_3(void);
/***********************************************************************************/

/***********************************************************************************/
void W25Q128_Global_Block_Sector_Unlock(void);
void W25Q128_Global_Block_Sector_Lock(void);
/***********************************************************************************/

/***********************************************************************************/












#endif
