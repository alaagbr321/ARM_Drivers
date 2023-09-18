/*
 * NVIC_Program.c
 *
 *  Created on: Sep 5, 2023
 *      Author: WIN10
 */
#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include  "NVIC_Interface.h"
#include  "NVIC_Config.h"
#include  "NVIC_Private.h"


void NVIC_voidPriorityGroup_Sub_Selection()
{
	/*4 Groups + 4 Sub_Groups*/
	SCB_AIRCR=Group_Selection;

}
void NVIC_voidInterruptEnable(u8 Copy_u8InterruptNum)
{
	NVIC->ISER[Copy_u8InterruptNum/32]=(1<<(Copy_u8InterruptNum%32));
}

u8   NVIC_u8InterruptCheckEnable(u8 Copy_u8InterruptNum)
{
	u8 Local_u8ReturnedValue=255;

	Local_u8ReturnedValue=GET_BIT(NVIC->ISER[Copy_u8InterruptNum/32],(Copy_u8InterruptNum%32));


	return Local_u8ReturnedValue;


}
void NVIC_voidInterruptDisable(u8 Copy_u8InterruptNum)
{
	NVIC->ICER[Copy_u8InterruptNum/32]=(1<<(Copy_u8InterruptNum%32));
}
void NVIC_voidInterruptEnablePending(u8 Copy_u8InterruptNum)
{
	NVIC->ISPR[Copy_u8InterruptNum/32]=(1<<(Copy_u8InterruptNum%32));

}
u8   NVIC_u8InterruptCheckPending(u8 Copy_u8InterruptNum)
{
	u8 Local_u8ReturnedValue=255;

	Local_u8ReturnedValue=GET_BIT(NVIC->ISPR[Copy_u8InterruptNum/32],(Copy_u8InterruptNum%32));

	return Local_u8ReturnedValue;


}
void NVIC_voidInterruptDisablePending(u8 Copy_u8InterruptNum)
{

	NVIC->ICPR[Copy_u8InterruptNum/32]=(1<<(Copy_u8InterruptNum%32));

}
u8   NVIC_u8InterruptCheckFlag(u8 Copy_u8InterruptNum)
{
	u8 Local_u8ReturnedValue=255;

	Local_u8ReturnedValue=GET_BIT(NVIC->IABR[Copy_u8InterruptNum/32],(Copy_u8InterruptNum%32));

	return Local_u8ReturnedValue;

}

//1000
void NVIC_voidInterruptChangePriority(Postion_E Copy_u8InterruptNum,u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority)
{
	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((Group_Selection - 0x05FA0300)/256));
	if(Copy_u8InterruptNum < 0)
		{
			if(Copy_u8InterruptNum == MEMORY_MANAGE || Copy_u8InterruptNum == BUS_FAULT || Copy_u8InterruptNum == USAGE_FAULT)
			{
				Copy_u8InterruptNum += 3 ;
				SCB->SHPR1 = (Local_u8Priority)<< ((8* Copy_u8InterruptNum) +4);
			}
			else if(Copy_u8InterruptNum == SV_CALL)
			{
				Copy_u8InterruptNum +=7 ;
				SCB->SHPR2 = (Local_u8Priority) << ((8 * Copy_u8InterruptNum) + 4 );
			}
			else if ( Copy_u8GroupPriority == PEND_SV)
			{
				Copy_u8InterruptNum += 8 ;
				SCB->SHPR3 = (Local_u8Priority) << ((8*Copy_u8InterruptNum) + 4 );
			}
		}
		else if ( Copy_u8InterruptNum >= 0)
		{
			NVIC->IPR[Copy_u8InterruptNum] = Local_u8Priority << 4 ;
		}

}



