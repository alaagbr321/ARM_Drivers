/*
 * RTOS_Program.c
 *
 *  Created on: Sep 10, 2023
 *      Author: WIN10
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"
#include "RTOS_Interface.h"
#include "RTOS_Config.h"
#include "RTOS_Private.h"
#include"../../MCAL/GPIO/GPIO_Interface.h"


RTOS_Task   RTOS_TaskArr[RTOS_Max_Priority]={0};
RTOS_Task   EmptyTask={0};

void RTOS_voidStartOS(u32 Copy_u32Ticks)
{
	SYSTICK_voidSetInterval_periodic(Copy_u32Ticks,RTOS_voidStartScheduler);

}

u8 RTOS_voidCreatTask(u8 Copy_u8Priority	,	u8 Copy_u8Periodicity	,u8 Copy_u8FirstDelay , void (*LPF)(void))
{
	u8 Local_u8ErrorState=0;

	if((RTOS_TaskArr[Copy_u8Priority].PTF==0) && (Copy_u8Priority<RTOS_Max_Priority))
	{
		RTOS_TaskArr[Copy_u8Priority].FirstDelay=Copy_u8FirstDelay;
		RTOS_TaskArr[Copy_u8Priority].Periodicity=Copy_u8Periodicity;
		RTOS_TaskArr[Copy_u8Priority].PTF=LPF;
		RTOS_TaskArr[Copy_u8Priority].TaskState=Ready;
	}else
	{
		Local_u8ErrorState=1;

	}
	return Local_u8ErrorState;
}

void RTOS_voidStartScheduler()
{

	for(u8 Local_u8Counter=0;Local_u8Counter<RTOS_Max_Priority;Local_u8Counter++)
	{
		if((RTOS_TaskArr[Local_u8Counter].PTF!=0) && (RTOS_TaskArr[Local_u8Counter].TaskState==Ready))
		{
			if(RTOS_TaskArr[Local_u8Counter].FirstDelay==0 )
			{
				RTOS_TaskArr[Local_u8Counter].PTF();
				RTOS_TaskArr[Local_u8Counter].FirstDelay=RTOS_TaskArr[Local_u8Counter].Periodicity-1;
			}else
			{

				RTOS_TaskArr[Local_u8Counter].FirstDelay--;
			}
		}
	}
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	if((RTOS_TaskArr[Copy_u8Priority].PTF!=0))
	{
		RTOS_TaskArr[Copy_u8Priority]=EmptyTask;
	}

}
void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	if((RTOS_TaskArr[Copy_u8Priority].PTF!=0))
		{
			RTOS_TaskArr[Copy_u8Priority].TaskState=Suspended;
		}
}
void RTOS_voidResumeTask(u8 Copy_u8Priority)
{
	if((RTOS_TaskArr[Copy_u8Priority].PTF!=0))
			{
				RTOS_TaskArr[Copy_u8Priority].TaskState=Ready;
			}
}
