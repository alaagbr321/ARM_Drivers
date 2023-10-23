/*
 * IR_Program.c
 *
 *  Created on: Sep 15, 2023
 *      Author: WIN10
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"


#include "IR_Interface.h"
#include"IR_Private.h"
#include"IR_Config.h"




volatile u8 Global_u32Counter=0;
volatile u8 FrameFlag=0;
extern volatile u8 data=0;

volatile u32 Frame[40]={0};



extern void GetFrame()
{

	if(FrameFlag==0)
	{
		SYSTICK_voidSetInterval_single(100000,VoidApp);
		FrameFlag=1;
	}else
	{
		Frame[Global_u32Counter]=MSTK_u32GetElapsedTime();
		SYSTICK_voidSetInterval_single(100000,VoidApp);
		Global_u32Counter++;

	}

}
void VoidApp(void (*PTF)(void))
{
	for(u8 counter=0; counter<8 ; counter++)
	{
		if( (Frame[17+counter] >= 3000) && (Frame[17+counter] < 4000) )
		{
			SET_BIT(data, counter);
		}
		else
		{
			CLR_BIT(data, counter);
		}
	}
	PTF();
	for(u8 i=0;i<40;i++)
	{
		Frame[i] = 0;
	}

	FrameFlag = 0;
	Global_u32Counter=0;

}

