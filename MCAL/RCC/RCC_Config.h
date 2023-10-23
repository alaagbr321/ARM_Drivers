/*
 * RCC_Config.h
 *
 *  Created on: Sep 3, 2023
 *      Author: WIN10
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

#define ENABLE   1
#define DISABLE  0

#define RCC_HSI 	1
#define RCC_HSE 	2
#define RCC_PLL		3


/*Options
 * 1-RCC_HSI
 * 2-RCC_HSE
 * 3-RCC_PLL
 */
#define RCC_ClockSource_Select   RCC_HSE


/*Options :
 * 1-ENABLE
 * 2-DISABLE
 */
#define RCC_HSI_ENABLE     DISABLE
#define RCC_HSE_ENABLE	   ENABLE
#define RCC_PLL_ENABLE     DISABLE


/*Options
 * 1-CLK_Full
 * 2-CLK_2
 * 3-CLK_4
 * 4-CLK_8
 * 5-CLK_16
 * 6-CLK_64
 * 7-CLK_128
 * 8-CLK_256
 * 9-CLK_512
 */

#define AHB_Speed   CLK_2





#endif /* RCC_CONFIG_H_ */
