/*
 * RCC_Program.c
 *
 *  Created on: Sep 3, 2023
 *      Author: WIN10
 */
#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include  "RCC_Interface.h"
#include "RCC_Config.h"
#include "RCC_Private.h"


void RCC_voidInit   (void)
{
	/*Enable Clock Security*/
	SET_BIT(RCC->CR , CSSON);
	/* BYPASS Select    */
	/*Not Bypass*/
	CLR_BIT(RCC->CR , HSEBYP);
	/*Select Clock Source*/
#if RCC_ClockSource_Select ==RCC_HSI
	CLR_BIT(RCC->CFGR ,SW0);
	CLR_BIT(RCC->CFGR ,SW1);

#elif RCC_ClockSource_Select ==RCC_HSE
	SET_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);

#elif RCC_ClockSource_Select ==RCC_PLL
	CLR_BIT(RCC->CFGR,SW0);
	SET_BIT(RCC->CFGR,SW1);

#endif
	/*Enable Clock Source*/
#if RCC_HSI_ENABLE   == ENABLE
	SET_BIT(RCC->CR,HSION);

#elif RCC_HSI_ENABLE == DISABLE
	CLR_BIT(RCC->CR,HSION);
#endif
#if RCC_HSE_ENABLE   == ENABLE
	SET_BIT(RCC->CR,HSEON);
#elif RCC_HSE_ENABLE == DISABLE
	CLR_BIT(RCC->CR,HSEON);
#endif
#if RCC_PLL_ENABLE   == ENABLE
	SET_BIT(RCC->CR,PLLON);
#elif RCC_PLL_ENABLE == DISABLE
	CLR_BIT(RCC->CR,PLLON);
#endif




}
void RCC_voidEnablePeripheralClock      (   u8 Copy_u8BusId    , u8 Copy_u8PerId    )
{
	if((Copy_u8BusId<=RCC_AHB2) && (Copy_u8PerId <32))
	{
		switch(Copy_u8BusId)
		{
		case RCC_APB1:
			SET_BIT(RCC->APB1ENR,Copy_u8PerId);

			break;

		case RCC_APB2:
			SET_BIT(RCC->APB2ENR,Copy_u8PerId);
			break;

		case RCC_AHB1:
			SET_BIT(RCC->AHB1ENR,Copy_u8PerId);
			break;

		case RCC_AHB2:
			SET_BIT(RCC->AHB2ENR,Copy_u8PerId);
			break;
		}
	}

}

void RCC_voidDisablePeripheralClock     (   u8 Copy_u8BusId    , u8 Copy_u8PerId    )
{

	if((Copy_u8BusId<=RCC_AHB2) && (Copy_u8PerId <32))
	{
		switch(Copy_u8BusId)
		{
		case RCC_APB1:
			CLR_BIT(RCC->APB1ENR,Copy_u8PerId);


			break;

		case RCC_APB2:
			CLR_BIT(RCC->APB2ENR,Copy_u8PerId);
			break;

		case RCC_AHB1:
			CLR_BIT(RCC->AHB1ENR,Copy_u8PerId);
			break;

		case RCC_AHB2:
			CLR_BIT(RCC->AHB2ENR,Copy_u8PerId);
			break;

		}



	}




}
void RCC_voidChangeAHB_Speed()
{

RCC->CFGR&=~(0b1111<<4);
RCC->CFGR|=(AHB_Speed<<4);

}
