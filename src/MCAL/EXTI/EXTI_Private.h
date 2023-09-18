/*
 * EXTI_Private.h
 *
 *  Created on: Sep 5, 2023
 *      Author: WIN10
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define EXTI_BASE_ADDRESS       	0x40013C00
#define SYSCFG_BASE_ADDRESS			0x40013800


typedef struct
{
	volatile u32     IMR           ;
	volatile u32     EMR           ;
	volatile u32     RTSR          ;
	volatile u32     FTSR          ;
	volatile u32     SWIER         ;
	volatile u32     PR            ;

}EXTI_MemMap_t;

typedef struct
{
	volatile u32     MEMRMP        ;
	volatile u32     PMC           ;
	volatile u32     EXTICR[4]     ;
	volatile u32     CMPCR         ;
	volatile u16     CMPCR_2       ;

}SYSCFG_MemMap_t;


#define EXTI        ( (volatile EXTI_MemMap_t*) EXTI_BASE_ADDRESS)
#define SYSCFG      ((volatile SYSCFG_MemMap_t*) SYSCFG_BASE_ADDRESS)



#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
