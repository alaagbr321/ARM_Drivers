/*
 * UART_Program.c
 *
 *  Created on: Sep 16, 2023
 *      Author: WIN10
 */

#include"../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include  "UART_Interface.h"
#include "UART_Config.h"
#include "UART_Private.h"
#include "../GPIO/GPIO_Interface.h"
#include "../GPIO/GPIO_Private.h"

f32 USARTDIV;
u32 fraction;
void UART_voidInit(u8 UART_ID,u32 Copy_u32BaudRate)
{


	switch(UART_ID)
	{


	case UART_1:
		GPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN6,GPIO_Alternate);
		GPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN7,GPIO_Alternate);
		GPIOB->AFRL&=~(0xFF<<24);
		GPIOB->AFRL|=(0x77<<24);
		/*Choose no Start bits,data bits*/
		CLR_BIT(UART1->USART_CR1,M);
		/*Choose no Stop bits*/
		CLR_BIT(UART1->USART_CR1,12);
		CLR_BIT(UART1->USART_CR1,13);
		/*Choose Suitable BaudRate*/

		USARTDIV=((f32)F_CPU/(16*Copy_u32BaudRate));
		fraction=(u32)(16*(USARTDIV-(u32)(USARTDIV)));


		UART1->USART_BRR&=~(0xFFF<<4);
		(UART1->USART_BRR)|=((u32)USARTDIV<<4);
		UART1->USART_BRR&=~(0b1111);
		UART1->USART_BRR|=fraction;

		/*Enable Tx,Rx*/
		SET_BIT(UART1->USART_CR1,TE);
		SET_BIT(UART1->USART_CR1,RE);
		/*Enable UART1*/
		SET_BIT(UART1->USART_CR1,UE);
		break;

	case UART_2:
		GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_Alternate);
		GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_Alternate);
		GPIOA->AFRL&=~(0xFF<<8);
		GPIOA->AFRL|=(0x77<<8);
		/*Choose no Start bits,data bits*/
		CLR_BIT(UART2->USART_CR1,M);
		/*Choose no Stop bits*/
		CLR_BIT(UART2->USART_CR1,12);
		CLR_BIT(UART2->USART_CR1,13);
		/*Choose Suitable BaudRate*/
		USARTDIV=((f32)F_CPU/(16*Copy_u32BaudRate));
		fraction=(u32)(16*(USARTDIV-(u32)(USARTDIV)));
		UART2->USART_BRR&=~(0xFFF<<4);
		(UART2->USART_BRR)|=((u32)USARTDIV<<4);
		UART2->USART_BRR&=~(0b1111);
		UART2->USART_BRR|=fraction;
		/*Enable Tx,Rx*/
		SET_BIT(UART2->USART_CR1,TE);
		SET_BIT(UART2->USART_CR1,RE);
		/*Enable UART1*/
		SET_BIT(UART2->USART_CR1,UE);
		break;

	case UART_6:
		GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN11,GPIO_Alternate);
		GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN12,GPIO_Alternate);
		GPIOA->AFRH&=~(0xFF<<12);
		GPIOA->AFRH|=(0x77<<12);
		/*Choose no Start bits,data bits*/
		CLR_BIT(UART6->USART_CR1,M);
		/*Choose no Stop bits*/
		CLR_BIT(UART6->USART_CR1,12);
		CLR_BIT(UART6->USART_CR1,13);
		/*Choose Suitable BaudRate*/
		USARTDIV=((f32)F_CPU/(16*Copy_u32BaudRate));
		fraction=(u32)(16*(USARTDIV-(u32)(USARTDIV)));
		UART6->USART_BRR&=~(0xFFF<<4);
		(UART6->USART_BRR)|=((u32)USARTDIV<<4);
		UART6->USART_BRR&=~(0b1111);
		UART6->USART_BRR|=fraction;
		/*Enable Tx,Rx*/
		SET_BIT(UART6->USART_CR1,TE);
		SET_BIT(UART6->USART_CR1,RE);
		/*Enable UART1*/
		SET_BIT(UART6->USART_CR1,UE);
		break;


	}



}
void UART_voidSendData(u8 UART_ID,u8 Copy_u8Data)
{
	switch(UART_ID)
	{
	case UART_1:
		while(GET_BIT(UART1->USART_SR,TC)==0);
		UART1->USART_DR=Copy_u8Data;
		break;
	case UART_2:
		while(GET_BIT(UART2->USART_SR,TC)==0);
		UART2->USART_DR=Copy_u8Data;
		break;

	case UART_6:
		while(GET_BIT(UART6->USART_SR,TC)==0);
		UART6->USART_DR=Copy_u8Data;
		break;


	}




}

void UART_voidTransmit(u8 *arr)
{

	u16 timeout=0;
	u8 i=0;
	while(arr[i] != '\0')
	{
		UART1->USART_DR = arr[i];
		while(GET_BIT(UART1->USART_SR,TC)==0)
		{
			timeout++;
			if(timeout == 10000)
			{
				break;
			}
		}
		i++;
	}



}
u8 UART_u8RecieveData(u8 UART_ID)
{
	u8 LocalResult=0;
	u16 timeout=0;
	switch(UART_ID)
	{

	case UART_1:
		while(GET_BIT(UART1->USART_SR,RXNE)==0)
		{

			timeout++;
			if(timeout == 10000)
			{
				LocalResult = 128;
				break;
			}
		}

		 if(LocalResult == 0)
		    {
			 LocalResult= UART1->USART_DR;
		    }
//		 CLR_BIT(UART1->USART_SR,RXNE);

		break;



	case UART_2:
		while(GET_BIT(UART2->USART_SR,RXNE)==0);
		LocalResult= UART2->USART_DR;
		break;


	case UART_6:
		while(GET_BIT(UART6->USART_SR,RXNE)==0);
		LocalResult= UART6->USART_DR;
		break;
	}

	return LocalResult;

}




