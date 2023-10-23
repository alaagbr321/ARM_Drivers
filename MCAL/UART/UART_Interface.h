/*
 * UART_Interface.h
 *
 *  Created on: Sep 16, 2023
 *      Author: WIN10
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_


#define UART_1       0
#define UART_2       1
#define UART_6       2




void UART_voidInit(u8 UART_ID,u32 Copy_u32BaudRate);
void UART_voidSendData(u8 UART_ID,u8 Copy_u8Data);
u8 UART_u8RecieveData(u8 UART_ID);
void UART_voidTransmit(u8 *arr);
void UART_u8RecieveDataAsync(u8 UART_ID,u8 *ptr);




#endif /* MCAL_UART_UART_INTERFACE_H_ */
