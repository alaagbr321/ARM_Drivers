/*
 * SPI_Interface.h
 *
 *  Created on: Sep 17, 2023
 *      Author: WIN10
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_


void   SPI_voidSlaveInit();
void   SPI_voidMasterInit();
u16   SPI_voidSendReceiveData(u16 Copy_u16Data);
typedef enum
{
	GPIO_SYSTEM,
	GPIO_TIM1_2,
	GPIO_TIM3_5,
	GPIO_TIM9_11,
	GPIO_I2C1_3,
	GPIO_SPI1_4,
	GPIO_SPI3,
	GPIO_USART1_2,
	GPIO_USART6,
	GPIO_I2C2_3,
	GPIO_OTG_FS,
	GPIO_SDIO = 12,
	GPIO_EVENOUT = 15,

}AF_Select_t;




#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
