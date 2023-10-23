/*
 * RTOS_Private.h
 *
 *  Created on: Sep 10, 2023
 *      Author: WIN10
 */

#ifndef SERVICE_RTOS_RTOS_PRIVATE_H_
#define SERVICE_RTOS_RTOS_PRIVATE_H_



typedef struct
{
	void (*PTF)(void);
	u8 Periodicity;
	u8 FirstDelay;
	u8 TaskState;
}RTOS_Task;





#endif /* SERVICE_RTOS_RTOS_PRIVATE_H_ */
