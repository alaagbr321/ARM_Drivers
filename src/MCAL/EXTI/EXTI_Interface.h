/*
 * EXTI_Interface.h
 *
 *  Created on: Sep 5, 2023
 *      Author: WIN10
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


#define EXTI_FallingEdge      0
#define EXTI_RisingEdge       1
#define EXTI_OnChange         2

#define	EXTI_0                 0
#define EXTI_1                 1
#define EXTI_2                 2
#define EXTI_3                 3
#define EXTI_4                 4
#define EXTI_5                 5
#define EXTI_6                 6
#define EXTI_7                 7
#define EXTI_8                 8
#define EXTI_9                 9
#define EXTI_10                10
#define EXTI_11                11
#define EXTI_12                12
#define EXTI_13                13
#define EXTI_14                14
#define EXTI_15                15

#define EXTI_PORTA                 0
#define EXTI_PORTB                 1
#define EXTI_PORTC                 2

void  EXTI_voidInit(u8 Copy_InterruptId,u8 Copy_u8IntSenseControl);

void EXTI_voidConfigEXTI(u8 Copy_InterruptId,u8 PortID);

void  EXTI_voidSetCallBack(u8 Copy_InterruptId,void (*PF)(void));




#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
