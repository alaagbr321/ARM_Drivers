/*
 * UART_Private.h
 *
 *  Created on: Sep 16, 2023
 *      Author: WIN10
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define USART1_BASE_ADDRESS          0x40011000
#define USART2_BASE_ADDRESS          0x40004400
#define USART6_BASE_ADDRESS          0x40011400


/* USART_SR BITS */
#define CTS                      9
#define LBD						 8
#define TXE						 7
#define TC						 6
#define RXNE					 5
#define IDLE					 4
#define ORE						 3
#define NF						 2
#define FE						 1
#define PE						 0

/* USART_CR1 BITS */
#define OVER8                    15
#define UE						 13
#define M						 12
#define WAKE				     11
#define PCE					     10
#define PS					     9
#define PEIE					 8
#define TXEIE					 7
#define TCIE			    	 6
#define RXNEIE					 5
#define IDLEIE					 4
#define TE						 3
#define RE						 2
#define RWU						 1
#define SBK						 0











typedef struct
{
	volatile    u32      USART_SR;
	volatile    u32      USART_DR;
	volatile    u32      USART_BRR;
	volatile    u32      USART_CR1;
	volatile    u32      USART_CR2;
	volatile    u32      USART_CR3;
	volatile    u32      USART_GTPR;


}USART_MemMap_t;

#define   UART1         ((volatile USART_MemMap_t*)USART1_BASE_ADDRESS)
#define   UART2			((volatile USART_MemMap_t*)USART2_BASE_ADDRESS)
#define   UART6			((volatile USART_MemMap_t*)USART6_BASE_ADDRESS)




#endif /* MCAL_UART_UART_PRIVATE_H_ */
