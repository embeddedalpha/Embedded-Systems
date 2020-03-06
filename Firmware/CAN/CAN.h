/*
*********************************************************************************************************************************
@file:    CAN.H
@author:  Kunal Salvi
@version: V3.05.0
@date:    29/2/2020
@brief:   CAN Header File. 
          This file contains the prototype of functions in CAN.c file.
          By calling various "Init" functions, the user can configure 
          the CAN Hardware Peripheral in any of the permitted modes. 
					
@attention: This file aims at providing the user an abrstraction layer to the CAN peripheral
            and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
            In case of failure of code/product due to third party tampering, the author will not be
            responsible. This code is published under MIT License.
	
*********************************************************************************************************************************	
*/


#ifndef _CAN_H_
#define _CAN_H_

#include "stm32f10x.h"

struct CAN_Standard_Frame{
    uint16_t id;
    uint8_t  data[8];
    
}
//

struct CAN_Extended_Frame{
    uint16_ id;
    uint32 extended_id;
    uint8_t data[8];
}
//


#define CAN_BitRate_1000_kbps   1000
#define CAN_BitRate_500_kbps    500
#define CAN_BitRate_250_kbps    250
#define CAN_BitRate_125_kbps    125
#define CAN_BitRate_100_kbps    100
#define CAN_BitRate_75_kbps     75
#define CAN_BitRate_50_kbps     50
#define CAN_BitRate_20_kbps     20
#define CAN_BitRate_10_kbps     10

/***************************************** Initialization Mode *****************************************************************
//@function: The function sets up the CAN controller in Initialization mode.
//@param: none
//@return: Returns 1 if Initialization is successful
********************************************************************************************************************************/

int CAN_Initialization_Mode();

/***************************************** Normal Mode *************************************************************************
//@function: The function sets up the CAN controller in Normal mode.
//@param: none
//@return: Returns 1 if Normalization is successful
********************************************************************************************************************************/

int CAN_Normal_Mode();

/***************************************** Sleep Mode *************************************************************************
//@function: The function sets up the CAN controller in Sleep mode.
//@param: none
//@return: Returns 1 if controller is in sleep mode
********************************************************************************************************************************/

int CAN_Sleep_Mode();

/***************************************** CAN Bitrate *************************************************************************
//@function: The function sets up the bitrate for CAN bus
//@param: 
//       baudrate           CAN_BitRate_1000_kbps   1000     [Defined in CAN.h]
//                          CAN_BitRate_500_kbps    500
//                          CAN_BitRate_250_kbps    250
//                          CAN_BitRate_125_kbps    125
//                          CAN_BitRate_100_kbps    100
//                          CAN_BitRate_75_kbps     75
//                          CAN_BitRate_50_kbps     50
//                          CAN_BitRate_10_kbps     10
//@return: none
********************************************************************************************************************************/

void CAN_Bitrate(int baudrate);

/***************************************** CAN Test Mode *************************************************************************
//@function: The function sets up the bitrate for CAN bus
//@param: 
//       mode               0     ->    Silent Mode     
//                          1     ->    Loop Back Mode
//                          2     ->    Silent Loop Back Mode
//@return: none
********************************************************************************************************************************/

void CAN_Test_Mode_Setup(int mode);


/***************************************** CAN Trasnmmit Data *************************************************************************
//@function: The function transmitts data onto the CAN bus by filling the appropriate buffers
//@param: 
//       mailbox_no               0     ->    Mailbox 0     
//                                1     ->    Mailbox 1
//                                2     ->    Mailbox 2
//       standard_id              Any 11 bit id
//       extended_id              Any 18 bit id
//       dlc                      from 0 to 8
//       data[]                   Array of data to be transmitted
//       priority                 0     ->    Message driven by id of message
//                                1     ->    Message driven by request order
//@return: Returns 1 when data is transmitted.
********************************************************************************************************************************/

int CAN_Transmit_Data_Frame(int mailbox_no, int standard_id, int extended_id, int dlc, int data[], int priority);

#endif
