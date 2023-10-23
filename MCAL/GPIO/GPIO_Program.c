/*
 * GPIO_Program.c
 *
 *  Created on: Sep 4, 2023
 *      Author: WIN10
 */
#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"


void GPIO_voidSetPinMode(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8PinMode)
{
	u8 Local_u8Location=(Copy_u8Pin*2);

	switch(Copy_u8PinMode)
	{
	case GPIO_INPUT:
		switch(Copy_u8PortID)
		{
		case GPIO_PORTA:

			CLR_BIT(GPIOA->MODDER,Local_u8Location);
			CLR_BIT(GPIOA->MODDER,(Local_u8Location+1));
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->MODDER,Local_u8Location);
			CLR_BIT(GPIOB->MODDER,(Local_u8Location+1));
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->MODDER,Local_u8Location);
			CLR_BIT(GPIOC->MODDER,(Local_u8Location+1));
			break;
		}
		break;


		case GPIO_OUTPUT:
			switch(Copy_u8PortID)
			{
			case GPIO_PORTA:

				SET_BIT(GPIOA->MODDER,Local_u8Location);
				CLR_BIT(GPIOA->MODDER,(Local_u8Location+1));
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB->MODDER,Local_u8Location);
				CLR_BIT(GPIOB->MODDER,(Local_u8Location+1));
				break;
			case GPIO_PORTC:
				SET_BIT(GPIOC->MODDER,Local_u8Location);
				CLR_BIT(GPIOC->MODDER,(Local_u8Location+1));
				break;
			}
			break;


			case GPIO_Alternate:
				switch(Copy_u8PortID)
				{
				case GPIO_PORTA:

					CLR_BIT(GPIOA->MODDER,Local_u8Location);
					SET_BIT(GPIOA->MODDER,(Local_u8Location+1));
					break;
				case GPIO_PORTB:
					CLR_BIT(GPIOB->MODDER,Local_u8Location);
					SET_BIT(GPIOB->MODDER,(Local_u8Location+1));
					break;
				case GPIO_PORTC:
					CLR_BIT(GPIOC->MODDER,Local_u8Location);
					SET_BIT(GPIOC->MODDER,(Local_u8Location+1));
					break;
				}
				break;

				case GPIO_ANALOG:
					switch(Copy_u8PortID)
					{
					case GPIO_PORTA:

						SET_BIT(GPIOA->MODDER,Local_u8Location);
						SET_BIT(GPIOA->MODDER,(Local_u8Location+1));
						break;
					case GPIO_PORTB:
						SET_BIT(GPIOB->MODDER,Local_u8Location);
						SET_BIT(GPIOB->MODDER,(Local_u8Location+1));
						break;
					case GPIO_PORTC:
						SET_BIT(GPIOC->MODDER,Local_u8Location);
						SET_BIT(GPIOC->MODDER,(Local_u8Location+1));
						break;
					}
					break;
	}


}
void GPIO_voidSetPinValue(u8 Copy_u8PortID , u8 Copy_u8Pin ,u8 Copy_u8PinValue)
{
	switch(Copy_u8PinValue)
	{
	case GPIO_HIGH:
		switch(Copy_u8PortID)
		{
		case GPIO_PORTA:
			GPIOA->BSRR=1<<Copy_u8Pin;
			break;
		case GPIO_PORTB:
			GPIOB->BSRR=1<<Copy_u8Pin;
			break;
		case GPIO_PORTC:
			GPIOC->BSRR=1<<Copy_u8Pin;
			break;
		}
		break;
		case GPIO_LOW:
			switch(Copy_u8PortID)
			{
			case GPIO_PORTA:
				GPIOA->BSRR=1<<(Copy_u8Pin+16);
				break;
			case GPIO_PORTB:
				GPIOB->BSRR=1<<(Copy_u8Pin+16);
				break;
			case GPIO_PORTC:
				GPIOC->BSRR=1<<(Copy_u8Pin+16);
				break;
			}
			break;
	}

}
u8  GPIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8Pin)
{
	u8 Local_u8Holder=255;
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		Local_u8Holder=GET_BIT(GPIOA->IDR,Copy_u8Pin);
		break;
	case GPIO_PORTB:
		Local_u8Holder=GET_BIT(GPIOB->IDR,Copy_u8Pin);
		break;
	case GPIO_PORTC:
		Local_u8Holder=GET_BIT(GPIOC->IDR,Copy_u8Pin);
		break;
	}
	return Local_u8Holder;

}

void GPIO_voidPUPDMode(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8PinMode)
{
	u8 Local_u8Location=(Copy_u8Pin*2);
	switch(Copy_u8PinMode)
	{
	case GPIO_NoPullUp_NoPullDown:
		switch(Copy_u8PortID)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA->PUPDR,Local_u8Location);
			CLR_BIT(GPIOA->PUPDR,(Local_u8Location+1));
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->PUPDR,Local_u8Location);
			CLR_BIT(GPIOB->PUPDR,(Local_u8Location+1));
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->PUPDR,Local_u8Location);
			CLR_BIT(GPIOC->PUPDR,(Local_u8Location+1));
			break;
		}

		break;
		case GPIO_PullUp:
			switch(Copy_u8PortID)
			{
			case GPIO_PORTA:
				SET_BIT(GPIOA->PUPDR,Local_u8Location);
				CLR_BIT(GPIOA->PUPDR,(Local_u8Location+1));
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB->PUPDR,Local_u8Location);
				CLR_BIT(GPIOB->PUPDR,(Local_u8Location+1));
				break;
			case GPIO_PORTC:
				SET_BIT(GPIOC->PUPDR,Local_u8Location);
				CLR_BIT(GPIOC->PUPDR,(Local_u8Location+1));
				break;
			}
			break;
			case GPIO_PullDown:
				switch(Copy_u8PortID)
				{
				case GPIO_PORTA:
					CLR_BIT(GPIOA->PUPDR,Local_u8Location);
					SET_BIT(GPIOA->PUPDR,(Local_u8Location+1));
					break;
				case GPIO_PORTB:
					CLR_BIT(GPIOB->PUPDR,Local_u8Location);
					SET_BIT(GPIOB->PUPDR,(Local_u8Location+1));
					break;
				case GPIO_PORTC:
					CLR_BIT(GPIOC->PUPDR,Local_u8Location);
					SET_BIT(GPIOC->PUPDR,(Local_u8Location+1));
					break;
				}
				break;
	}


}

void GPIO_voidSetPinOutputType(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8OutPutPinType)
{
	switch(Copy_u8OutPutPinType)
	{
	case GPIO_OUTPUT_PUSH_PULL:
		switch(Copy_u8PortID)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA->OTYPER,Copy_u8Pin);
			break;

		case GPIO_PORTB:
			CLR_BIT(GPIOB->OTYPER,Copy_u8Pin);
			break;

		case GPIO_PORTC:
			CLR_BIT(GPIOC->OTYPER,Copy_u8Pin);
			break;
		}
		break;

		case GPIO_OUTPUT_OPEN_DRAIN:

			switch(Copy_u8PortID)
			{
			case GPIO_PORTA:
				SET_BIT(GPIOA->OTYPER,Copy_u8Pin);
				break;

			case GPIO_PORTB:
				SET_BIT(GPIOB->OTYPER,Copy_u8Pin);
				break;

			case GPIO_PORTC:
				SET_BIT(GPIOC->OTYPER,Copy_u8Pin);
				break;
			}
			break;



	}

}
void GPIO_voidSetPinOutputSpeed(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8OutPutPinSpeed)
{
	u8 Local_u8Location=(Copy_u8Pin*2);

	switch(Copy_u8OutPutPinSpeed)
	{
	case LowSpeed:
		switch(Copy_u8PortID)
		{
		case GPIO_PORTA:

			CLR_BIT(GPIOA->OSPEEDR,Local_u8Location);
			CLR_BIT(GPIOA->OSPEEDR,(Local_u8Location+1));
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->OSPEEDR,Local_u8Location);
			CLR_BIT(GPIOB->OSPEEDR,(Local_u8Location+1));
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->OSPEEDR,Local_u8Location);
			CLR_BIT(GPIOC->OSPEEDR,(Local_u8Location+1));
			break;
		}
		break;


		case MediumSpeed:
			switch(Copy_u8PortID)
			{
			case GPIO_PORTA:

				SET_BIT(GPIOA->OSPEEDR,Local_u8Location);
				CLR_BIT(GPIOA->OSPEEDR,(Local_u8Location+1));
				break;
			case GPIO_PORTB:
				SET_BIT(GPIOB->OSPEEDR,Local_u8Location);
				CLR_BIT(GPIOB->OSPEEDR,(Local_u8Location+1));
				break;
			case GPIO_PORTC:
				SET_BIT(GPIOC->OSPEEDR,Local_u8Location);
				CLR_BIT(GPIOC->OSPEEDR,(Local_u8Location+1));
				break;
			}
			break;


			case HighSpeed:
				switch(Copy_u8PortID)
				{
				case GPIO_PORTA:

					CLR_BIT(GPIOA->OSPEEDR,Local_u8Location);
					SET_BIT(GPIOA->OSPEEDR,(Local_u8Location+1));
					break;
				case GPIO_PORTB:
					CLR_BIT(GPIOB->OSPEEDR,Local_u8Location);
					SET_BIT(GPIOB->OSPEEDR,(Local_u8Location+1));
					break;
				case GPIO_PORTC:
					CLR_BIT(GPIOC->OSPEEDR,Local_u8Location);
					SET_BIT(GPIOC->OSPEEDR,(Local_u8Location+1));
					break;
				}
				break;

				case VeryHighSpeed:
					switch(Copy_u8PortID)
					{
					case GPIO_PORTA:

						SET_BIT(GPIOA->OSPEEDR,Local_u8Location);
						SET_BIT(GPIOA->OSPEEDR,(Local_u8Location+1));
						break;
					case GPIO_PORTB:
						SET_BIT(GPIOB->OSPEEDR,Local_u8Location);
						SET_BIT(GPIOB->OSPEEDR,(Local_u8Location+1));
						break;
					case GPIO_PORTC:
						SET_BIT(GPIOC->OSPEEDR,Local_u8Location);
						SET_BIT(GPIOC->OSPEEDR,(Local_u8Location+1));
						break;
					}
					break;
	}


}
void GPIO_voidSetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue)
{
	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		GPIOA->ODR=Copy_u8PortValue;
		break;

	case GPIO_PORTB:
		GPIOB->ODR=Copy_u8PortValue;
		break;
	case GPIO_PORTC:
		GPIOC->ODR=Copy_u8PortValue;
		break;
	}

}

void GPIO_voidSetPinAF(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8AFPinMode)
{

	switch(Copy_u8PortID)
	{
	case GPIO_PORTA:
		if(Copy_u8Pin<=7)
		{
			GPIOA->AFRL |= (Copy_u8AFPinMode<<(Copy_u8Pin*4));
		}else
		{
			GPIOA->AFRH |= (Copy_u8AFPinMode<<(Copy_u8Pin*4));
		}

		break;

	case GPIO_PORTB:
		if(Copy_u8Pin<=7)
		{
			GPIOB->AFRL |= (Copy_u8AFPinMode<<(Copy_u8Pin*4));
		}else
		{
			GPIOB->AFRH |= (Copy_u8AFPinMode<<(Copy_u8Pin*4));
		}
		break;
	case GPIO_PORTC:
		if(Copy_u8Pin<=7)
		{
			GPIOC->AFRL |= (Copy_u8AFPinMode<<(Copy_u8Pin*4));
		}else
		{
			GPIOC->AFRH |= (Copy_u8AFPinMode<<(Copy_u8Pin*4));
		}
		break;
	}


}



