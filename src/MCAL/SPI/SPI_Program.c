/*
 * SPI_Program.c
 *
 *  Created on: Sep 17, 2023
 *      Author: WIN10
 */

#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include  "SPI_Interface.h"
#include "SPI_Config.h"
#include "SPI_Private.h"
#include "../GPIO/GPIO_Interface.h"
#include "../GPIO/GPIO_Private.h"

void   SPI_voidSlaveInit()
{

	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_Alternate);
	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_Alternate);
	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_Alternate);
	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN7,GPIO_Alternate);
	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT);

	GPIOA->AFRL&=~(0xFFFF<<16);
	GPIOA->AFRL|=(0x5555<<16);


	SPI1->SPI_CR1=0x0343;
}
void   SPI_voidMasterInit()
{

	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_Alternate);
	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_Alternate);
	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_Alternate);
	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN7,GPIO_Alternate);
	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT);

	GPIOA->AFRL&=~(0xFFFF<<16);
	GPIOA->AFRL|=(0x5555<<16);


	SPI1->SPI_CR1=0x0347;
}
u16   SPI_voidSendReceiveData(u16 Copy_u16Data)
{

	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);

	SPI1->SPI_DR=Copy_u16Data;
	while(GET_BIT(SPI1->SPI_SR,7)==1);
	return (SPI1->SPI_DR);
	GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
}
