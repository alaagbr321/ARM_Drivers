/*
 * STP_Program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: WIN10
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include"../../MCAL/GPIO/GPIO_Interface.h"

#include "STP_Interface.h"
#include "STP_Config.h"
#include "STP_Private.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"


void STP_voidInit()
{
	/* Configure GPIO_PINS */
	GPIO_voidSetPinMode(STP_GPIO_PORT,DS_PIN,GPIO_OUTPUT);
	GPIO_voidSetPinMode(STP_GPIO_PORT,SHCP_PIN,GPIO_OUTPUT);
	GPIO_voidSetPinMode(STP_GPIO_PORT,STCP_PIN,GPIO_OUTPUT);

}
void STP_voidSendData(u8 Copy_u8Data)
{
	for(s8 i=7;i>=0;i--)
	{
		GPIO_voidSetPinValue(STP_GPIO_PORT,DS_PIN,GET_BIT(Copy_u8Data,i));
		GPIO_voidSetPinValue(STP_GPIO_PORT,SHCP_PIN,GPIO_HIGH);
		//SYSTICK_voidDelayMs(1);
		GPIO_voidSetPinValue(STP_GPIO_PORT,SHCP_PIN,GPIO_LOW);
		//SYSTICK_voidDelayMs(1);
	}

	GPIO_voidSetPinValue(STP_GPIO_PORT,STCP_PIN,GPIO_HIGH);
//	SYSTICK_voidDelayMs(1);
	GPIO_voidSetPinValue(STP_GPIO_PORT,STCP_PIN,GPIO_LOW);
//	SYSTICK_voidDelayMs(1);


}
//void STP_voidLatchData();

