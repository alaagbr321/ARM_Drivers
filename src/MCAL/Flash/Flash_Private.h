/*
 * Flash_Private.h
 *
 *  Created on: Sep 25, 2023
 *      Author: WIN10
 */

#ifndef MCAL_FLASH_FLASH_PRIVATE_H_
#define MCAL_FLASH_FLASH_PRIVATE_H_

#define FlashBaseAddress       0x08000000
#define KEY1                   0x45670123
#define KEY2                   0xCDEF89AB

typedef struct
{
	volatile u32     ACR           ;
	volatile u32     KEYR          ;
	volatile u32     OPTKEYR       ;
	volatile u32     SR            ;
	volatile u32     CR            ;
	volatile u32     OPTCR         ;
}Flash_MemMap_t;

#define Flash        ( (volatile Flash_MemMap_t*) FlashBaseAddress)







#endif /* MCAL_FLASH_FLASH_PRIVATE_H_ */
