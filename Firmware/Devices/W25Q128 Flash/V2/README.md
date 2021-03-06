# W25Qx Flash Driver.

#### The driver has the following functions:

``` c
void W25Qx_Init(SPI_TypeDef *SPI);
uint8_t *W25Qx_Read_Block(uint32_t address,uint8_t *data, uint32_t length);
uint8_t W25Qx_Read_Byte(uint32_t address);
void W25Qx_Write_Block(uint32_t address, uint8_t *data, uint32_t length);
void W25Qx_Write_Byte(uint32_t address, uint8_t byte);
void W25Qx_Write_Enable(void);
void W25Qx_Write_Disable(void);
uint8_t W25Qx_Read_Status_Register_1(void);
uint8_t W25Qx_Read_Status_Register_2(void);
void W25Qx_Block_Erase_64KB(uint32_t address);
void W25Qx_Block_Erase_32KB(uint32_t address);
void W25Qx_Block_Erase_4KB(uint32_t address);
void W25Qx_Chip_Erase(void);
void W25Qx_Power_Down(void);
void W25Qx_Memory_Protect(void);
```

#### When W25Qx_Init function is called, pass the SPI instance you want to use. As STM32F103C8T6 has 2 hardware SPI blocks, SPI1 or SPi2 can be passed in the function.

``` c
W25Qx_Init(SPI1);
```

#### To write a single byte at a particular location in the flash memory, call W25Qx_Write_Byte function and pass the 24-bit address, and byte to be stored

``` c
W25Qx_Write_Byte(0xAABBCC, 0x99);
```

#### To read a single byte from a particular location, call W25Qx_Read_Byte function and pass the address from where you want to read the byte

``` c
uint8_t byte = W25Qx_Read_Byte(0xAABBCC);
```

#### To read multiple bytes, most preferably a block or page, call W25Qx_Read_Block and pass the address, the array in which the data will be stored and the length of data to #### be read.

``` c
uint8_t *array;
array = W25Qx_Read_Block(0xAABBCC, 100);
```

#### Write a block of data to a page or sector by calling W25Qx_Write_Block and passing 24-bit address, data array and length of array

``` C
uint8_t array[] = {1,2,3,4,5,6,7,8,9,10};
W25Qx_Write_Block(0xAABBCC, array, 10);
```
