/*
 * Flash_Interface.h
 *
 *  Created on: Sep 25, 2023
 *      Author: WIN10
 */

#ifndef MCAL_FLASH_FLASH_INTERFACE_H_
#define MCAL_FLASH_FLASH_INTERFACE_H_

void Flash_voidEraseSector(u8 Sector_id);
void Flash_voidFlashSector(u32 Copy_u32Address,u16 * Copy_u16Data,u32 Copy_u32NumOfElement);




#endif /* MCAL_FLASH_FLASH_INTERFACE_H_ */
