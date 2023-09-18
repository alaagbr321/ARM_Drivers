/*
 * DotMatrix_Program.c
 *
 *  Created on: Sep 10, 2023
 *      Author: WIN10
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"
#include "DotMatrix_Interface.h"
#include "DotMatrix_Private.h"
#include "DotMatrix_Config.h"

void DotMatrix_voidInit()
{

	for(u8 i=0;i<8;i++)
	{
		GPIO_voidSetPinMode(GPIO_PORTA,i,GPIO_OUTPUT);
		GPIO_voidSetPinMode(GPIO_PORTB,i,GPIO_OUTPUT);
	}
	DotMatrix_voidDisableCols();
}
static void DotMatrix_voidDisableCols()
{
	GPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN0,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN4,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN5,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN6,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN7,GPIO_HIGH);
}
static void DotMatrix_voidSetRowValue(u8 Copy_u8Value)
{

	GPIO_voidSetPortValue(GPIO_PORTA,Copy_u8Value);

}
void DotMatrix_voidSendData(u8 *Copy_u8Data)
{

	while(1)
		{

			for(u8 i=0; i<8 ;i++)
			{
				DotMatrix_voidDisableCols();
				DotMatrix_voidSetRowValue(Copy_u8Data[i]);
				GPIO_voidSetPinValue(GPIO_PORTB,i,GPIO_LOW);
				SYSTICK_voidDelayMs(3);

			}

		}

}
