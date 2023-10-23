/*
 * EXTI_Program.c
 *
 *  Created on: Sep 5, 2023
 *      Author: WIN10
 */

#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include  "EXTI_Interface.h"
#include "EXTI_Config.h"
#include "EXTI_Private.h"


static void (*PF_Notification[16]) (void) ={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
void  EXTI_voidInit(u8 Copy_InterruptId,u8 Copy_u8IntSenseControl)
{
	SET_BIT(EXTI->IMR,Copy_InterruptId);
	switch(Copy_u8IntSenseControl)
	{
	case EXTI_FallingEdge:

		SET_BIT(EXTI->FTSR,Copy_InterruptId);
		break;

	case EXTI_RisingEdge:
		SET_BIT(EXTI->RTSR,Copy_InterruptId);

		break;

	case EXTI_OnChange:
		SET_BIT(EXTI->RTSR,Copy_InterruptId);
		SET_BIT(EXTI->FTSR,Copy_InterruptId);
		break;
	}


}

void EXTI_voidConfigEXTI(u8 Copy_InterruptId , u8 PortID)
{
	SYSCFG->EXTICR[Copy_InterruptId/4]&=~(0b1111<<((Copy_InterruptId%4)*4));
	SYSCFG->EXTICR[Copy_InterruptId/4]|=(PortID<<((Copy_InterruptId%4)*4));

}
void  EXTI_voidSetCallBack(u8 Copy_InterruptId,void (*PF)(void))
{

	switch(Copy_InterruptId)
	{

	case EXTI_0:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_0]=PF;
		}
		break;
	case EXTI_1:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_1]=PF;
		}
		break;
	case EXTI_2:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_2]=PF;
		}
		break;

	case EXTI_3:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_3]=PF;
		}
		break;
	case EXTI_4:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_4]=PF;
		}
		break;
	case EXTI_5:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_5]=PF;
		}
		break;
	case EXTI_6:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_6]=PF;
		}
		break;
	case EXTI_7:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_7]=PF;
		}
		break;
	case EXTI_8:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_8]=PF;
		}
		break;
	case EXTI_9:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_9]=PF;
		}
		break;
	case EXTI_10:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_10]=PF;
		}
		break;
	case EXTI_11:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_11]=PF;
		}
		break;
	case EXTI_12:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_12]=PF;
		}
		break;
	case EXTI_13:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_13]=PF;
		}
		break;

	case EXTI_14:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_14]=PF;
		}
		break;


	case EXTI_15:
		if(PF!=NULL)
		{
			PF_Notification[EXTI_15]=PF;
		}
		break;
	}


}


void EXTI0_IRQHandler(void)
{

	if(PF_Notification[0]!=NULL)
	{

		PF_Notification[0]();
		SET_BIT(EXTI->PR,0);

	}
}

void EXTI1_IRQHandler(void)
{

	if(PF_Notification[1]!=NULL)
	{

		PF_Notification[1]();
		SET_BIT(EXTI->PR,1);

	}
}


void EXTI2_IRQHandler(void)
{


	if(PF_Notification[2]!=NULL)
	{

		PF_Notification[2]();
		SET_BIT(EXTI->PR,2);

	}
}


void EXTI3_IRQHandler(void)
{

	if(PF_Notification[3]!=NULL)
	{

		PF_Notification[3]();
		SET_BIT(EXTI->PR,3);
	}
}



void EXTI4_IRQHandler(void)
{

	if(PF_Notification[4]!=NULL)
	{

		PF_Notification[4]();
		SET_BIT(EXTI->PR,4);

	}
}



void EXTI9_5_IRQHandler(void)
{

	for(u8 i=5 ;i<=9 ;i++)
	{
		if(PF_Notification[i]!=NULL && GET_BIT(EXTI->PR,i))
			{

				PF_Notification[i]();
				SET_BIT(EXTI->PR,i);
			}
	}



}


void EXTI15_10_IRQHandler(void)
{

	for(u8 i=10 ;i<=15 ;i++)
	{
		if(PF_Notification[i]!=NULL && GET_BIT(EXTI->PR,i))
			{

				PF_Notification[i]();
				SET_BIT(EXTI->PR,i);
			}
	}
}

