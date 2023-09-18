/*
 * SYSTICK_Config.h
 *
 *  Created on: Sep 6, 2023
 *      Author: WIN10
 */

#ifndef MCAL_SYSTICK_SYSTICK_CONFIG_H_
#define MCAL_SYSTICK_SYSTICK_CONFIG_H_
/*Options
 * 1-AHB_8
 * 2-AHB_Full
 */
#define CLK_Source  AHB_8

/*Options
 * 1-SYSTICK_Exception
 * 2-SYSTICK_NoException
 */
#define SYSTICK_ExceptionStatus     SYSTICK_Exception

#define AHB_Speed     25000000



#endif /* MCAL_SYSTICK_SYSTICK_CONFIG_H_ */
