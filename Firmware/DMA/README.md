# DMA: Direct Memory Access

##### Direct memory access (DMA) is a feature of computer systems that allows certain hardware subsystems to access main system memory (random-access memory) independent of the central processing unit (CPU). Without DMA, when the CPU is using programmed input/output, it is typically fully occupied for the entire duration of the read or write operation, and is thus unavailable to perform other work. With DMA, the CPU first initiates the transfer, then it does other operations while the transfer is in progress, and it finally receives an interrupt from the DMA controller (DMAC) when the operation is done.

#### DMA of STM32F103C8T6 has 7 channels and each peripheral has a dedicated & configurable channel.


#### Pass these values as priority parameter:
```C
#define DMA_Priority_Very_High 3
#define DMA_Priority_High      2
#define DMA_Priority_Medium    1
#define DMA_Priority_Low       0

```


#### USART

```C
void USART1_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
void USART1_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
void USART2_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
void USART2_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
void USART3_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
void USART3_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
```
#### I2C

```C
void I2C1_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
void I2C1_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
void I2C2_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
void I2C2_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
```

#### SPI

```C
void SPI1_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
void SPI1_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
void SPI2_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
void SPI2_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
```

#### ADC

```C
void ADC1_DMA(uint32_t source_address, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority);
```
