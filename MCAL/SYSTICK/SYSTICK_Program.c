/*
 * SYSTICK_Program.c
 *
 *  Created on: Sep 6, 2023
 *      Author: WIN10
 */

#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include  "SYSTICK_Interface.h"
#include "SYSTICK_Config.h"
#include "SYSTICK_Private.h"

u32 SYSTICK_Speed;
static void (*GS_SYSTICK_Callback)(void) ;
static u8   G_u8SingleFlag ;
void SYSTICK_voidInit()
{

	/* Configure CTRL Register */
#if CLK_Source ==AHB_8
	CLR_BIT(SYSTICK->CTRL,2);
	SYSTICK_Speed=(AHB_Speed/8);

#elif CLK_Source ==AHB_Full
	SET_BIT(SYSTICK->CTRL,2);
	SYSTICK_Speed=(AHB_Speed);
#endif

#if SYSTICK_ExceptionStatus ==SYSTICK_Exception
	SET_BIT(SYSTICK->CTRL,1);
#elif SYSTICK_ExceptionStatus==SYSTICK_NoException
	CLR_BIT(SYSTICK->CTRL,1);
#endif


}
void SYSTICK_voidStartTimer()
{
	SET_BIT(SYSTICK->CTRL,0);
}
void SYSTICK_voidStopTimer()
{
	CLR_BIT(SYSTICK->CTRL,0);
}

void SYSTICK_voidDelayMs(u32 Copy_u32DelayMs)
{
	/* 1- Load timer with Value */
	SYSTICK->LOAD=(Copy_u32DelayMs*(AHB_Speed/8000000));
	/* 2- reset timer value */
	SYSTICK->Val=0;
	/* 3- Start the timer   */
	SYSTICK_voidStartTimer();
	/* 4-  wait for timer flag to be raised  */
	while(GET_BIT(SYSTICK->CTRL,16)!=1);
	/* 5-  Stop the timer   */
	SYSTICK_voidStopTimer();

}

void SYSTICK_voidSetInterval_single(u32 A_u32Ticks, void (*CallbackFunction)(void))
{
	/* 0- set Callback function */
	GS_SYSTICK_Callback = CallbackFunction ;
	G_u8SingleFlag = 1 ;
	/*	0-	Enable interrupt	*/
	SET_BIT(SYSTICK->CTRL , 1 );
	/* 1- reset timer value */
	SYSTICK->Val = 0 ;
	/* 2- Load timer with Value */
	SYSTICK->LOAD = A_u32Ticks*(AHB_Speed/8000000) ;
	/* 3- Start the timer   */
	SET_BIT(SYSTICK->CTRL, 0);
}

void SYSTICK_voidSetInterval_periodic(u32 A_u32Ticks, void (*CallbackFunction)(void))
{
	/* 0- set Callback function */
	GS_SYSTICK_Callback = CallbackFunction ;
	G_u8SingleFlag = 0 ;
	SET_BIT(SYSTICK->CTRL , 1 );
	/* 1- reset timer value */
	SYSTICK->Val = 0 ;
	/* 2- Load timer with Value */
	SYSTICK->LOAD = A_u32Ticks*(AHB_Speed/8000000) ;
	/* 3- Start the timer   */
	SET_BIT(SYSTICK->CTRL, 0);
}


u32  MSTK_u32GetElapsedTime(void)
{
	return (SYSTICK->LOAD-SYSTICK->Val) ;
}

u32  MSTK_u32GetRemainingTime(void)
{
	return SYSTICK->Val ;
}


void SysTick_Handler(void)
{
	if(GS_SYSTICK_Callback != NULL)
	{
		GS_SYSTICK_Callback();
	}
	if(G_u8SingleFlag)
	{
		G_u8SingleFlag = 0 ;
		/* 5-  Stop the timer   */
		CLR_BIT(SYSTICK->CTRL, 0);
//		SYSTICK_voidSetInterval_single(1000000,)
	}
}

