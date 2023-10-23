/*
 * RTOS_Interface.h
 *
 *  Created on: Sep 10, 2023
 *      Author: WIN10
 */

#ifndef SERVICE_RTOS_RTOS_INTERFACE_H_
#define SERVICE_RTOS_RTOS_INTERFACE_H_

typedef enum
{
	Ready,
	Suspended,
}Task_State;

void RTOS_voidStartOS(u32 Copy_u32Ticks);
void RTOS_voidStartScheduler();
u8 RTOS_voidCreatTask(u8 Copy_u8Priority	,	u8 Copy_u8Periodicity	,u8 Copy_u8FirstDelay , void (*LPF)(void));
void RTOS_voidDeleteTask(u8 Copy_u8Priority);
void RTOS_voidSuspendTask(u8 Copy_u8Priority);
void RTOS_voidResumeTask(u8 Copy_u8Priority);





#endif /* SERVICE_RTOS_RTOS_INTERFACE_H_ */
