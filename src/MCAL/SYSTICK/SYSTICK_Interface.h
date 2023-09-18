/*
 * SYSTICK_Interface.h
 *
 *  Created on: Sep 6, 2023
 *      Author: WIN10
 */

#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_




#define AHB_8        0
#define AHB_Full     1

#define SYSTICK_NoException   0
#define SYSTICK_Exception     1


void SYSTICK_voidInit();
void SYSTICK_voidStartTimer();
void SYSTICK_voidStopTimer();
void SYSTICK_voidDelayMs(u32 Copy_u32DelayMs);
void SYSTICK_voidSetInterval_periodic(u32 A_u32Ticks, void (*CallbackFunction)(void));
void SYSTICK_voidSetInterval_single(u32 A_u32Ticks, void (*CallbackFunction)(void));
u32  MSTK_u32GetElapsedTime(void);




#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
