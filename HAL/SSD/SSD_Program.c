/*
 * SSD_Program.c
 *
 *  Created on: Sep 4, 2023
 *      Author: WIN10
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/GPIO/GPIO_Interface.h"
#include"../../MCAL/GPIO/GPIO_Private.h"
#include"SSD_Interface.h"
#include"SSD_Private.h"


void SSD_voidInit(SSD_t *Copy_PstructLed)
{

	for(u8 i=Copy_PstructLed->StartingPin ; i<(Copy_PstructLed->StartingPin+8) ; i++)
	{
		GPIO_voidSetPinMode(Copy_PstructLed->PORT,i,GPIO_OUTPUT);
	}
	switch(Copy_PstructLed->CommanState)
	{
	case Comman_Cathod:
		//set port value to 0
		for(u8 i=Copy_PstructLed->StartingPin ; i<(Copy_PstructLed->StartingPin+8) ; i++)
		{
			GPIO_voidSetPinValue(Copy_PstructLed->PORT,i,GPIO_LOW);
		}
		break;

	case Comman_Anode:
		//set port value to 0xff
		for(u8 i=Copy_PstructLed->StartingPin ; i<(Copy_PstructLed->StartingPin+8) ; i++)
		{
			GPIO_voidSetPinValue(Copy_PstructLed->PORT,i,GPIO_HIGH);
		}
		break;
	}
}

void SSD_Display(SSD_t *Copy_PstructLed,u8 num)
{
	switch(Copy_PstructLed->CommanState)
	{
	case Comman_Cathod:
		switch(Copy_PstructLed->PORT)
		{
		case GPIO_PORTA:
			GPIOA->ODR&=~(255<<(Copy_PstructLed->StartingPin));
			GPIOA->ODR|=(~arr[num]<<(Copy_PstructLed->StartingPin));
			break;

		case GPIO_PORTB:
			GPIOB->ODR&=~(255<<(Copy_PstructLed->StartingPin));
			GPIOB->ODR|=(~arr[num]<<(Copy_PstructLed->StartingPin));
			break;
		}

		break;

		case Comman_Anode:
			switch(Copy_PstructLed->PORT)
			{
			case GPIO_PORTA:
				GPIOA->ODR&=~(255<<(Copy_PstructLed->StartingPin));
				GPIOA->ODR|=(arr[num]<<(Copy_PstructLed->StartingPin));
				break;

			case GPIO_PORTB:
				GPIOB->ODR&=~(255<<(Copy_PstructLed->StartingPin));
				GPIOB->ODR|=(arr[num]<<(Copy_PstructLed->StartingPin));
				break;
			}
			break;
	}

}

