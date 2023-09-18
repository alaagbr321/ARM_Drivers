/*
 * SYSTICK_Private.h
 *
 *  Created on: Sep 6, 2023
 *      Author: WIN10
 */

#ifndef MCAL_SYSTICK_SYSTICK_PRIVATE_H_
#define MCAL_SYSTICK_SYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS     0xE000E010



typedef struct
{

	volatile   u32     CTRL  ;
	volatile   u32     LOAD  ;
	volatile   u32     Val   ;
	volatile   u32     CALIB ;

}SYSTICK_MemMap_t;


#define SYSTICK       ((volatile SYSTICK_MemMap_t* )SYSTICK_BASE_ADDRESS)





#endif /* MCAL_SYSTICK_SYSTICK_PRIVATE_H_ */
