/*
 * Flash_Program.c
 *
 *  Created on: Sep 25, 2023
 *      Author: WIN10
 */

#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include  "Flash_Interface.h"
#include "Flash_Config.h"
#include "Flash_Private.h"



void Flash_voidEraseSector(u8 Sector_id)
{
	/*Check that no Flash memory operation is ongoing*/
	while(GET_BIT(Flash->SR,16)==1);
	/*Send Key To Unlock flash register*/
	while(GET_BIT(Flash->CR,31)==1)
	{
		Flash->KEYR=KEY1;
		Flash->KEYR=KEY2;
	}
	/*Select Sector To Erase*/
	Flash->CR &=(~(0b1111)<<3);
	Flash->CR |=(Sector_id<<3);

	/*Activate Sector*/
	SET_BIT(Flash->CR,1);

	/*start*/
	SET_BIT(Flash->CR,16);
	while(GET_BIT(Flash->SR,16)==1);
	CLR_BIT(Flash->CR,1);
	SET_BIT(Flash->SR,0);
}
void Flash_voidFlashSector(u32 Copy_u32Address,u16 * Copy_u16Data,u32 Copy_u32NumOfElements)
{
	/*Check that no Flash memory operation is ongoing*/
	while(GET_BIT(Flash->SR,16)==1);
	/*Send Key To Unlock flash register*/
	while(GET_BIT(Flash->CR,31)==1)
	{
		Flash->KEYR=KEY1;
		Flash->KEYR=KEY2;
	}

	/* Select Program size -->16 bit*/
	Flash->CR &=~((0b11)<<8);
	Flash->CR |=((0b01)<<8);

	/*pG=1*/
	SET_BIT(Flash->CR,0);

	for(u32 i=0;i<Copy_u32NumOfElements;i++)
	{

		*((volatile u16*)Copy_u32Address)=Copy_u16Data[i];

		Copy_u32Address+=2;
		while(GET_BIT(Flash->SR,16)==1);
	}

	CLR_BIT(Flash->CR,0);


}


