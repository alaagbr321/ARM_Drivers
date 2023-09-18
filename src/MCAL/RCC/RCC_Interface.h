/*
 * RCC_Interface.h
 *
 *  Created on: Sep 3, 2023
 *      Author: WIN10
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/*RCC Buses*/
#define RCC_APB1    1
#define RCC_APB2    2
#define RCC_AHB1    3
#define RCC_AHB2    4

/*AHB1 Peripherals*/
#define RCC_AHB1_GPIOA          0
#define RCC_AHB1_GPIOB          1
#define RCC_AHB1_GPIOC          2
#define RCC_AHB1_DMA1           21
#define RCC_AHB1_DMA2           22

/*AHB2 Peripherals*/
#define RCC_AHB2_OTGFS          7

/*APB1 Peripherals*/
#define RCC_APB1_TIMER2          0
#define RCC_APB1_TIMER3          1
#define RCC_APB1_TIMER4          2
#define RCC_APB1_TIMER5          3
#define RCC_APB1_WWDG           11
#define RCC_APB1_SPI2			14
#define RCC_APB1_SPI3			15
#define RCC_APB1_USART2			17
#define RCC_APB1_I2C1			21
#define RCC_APB1_I2C2			22
#define RCC_APB1_I2C3			23
#define RCC_APB1_PWR			28


/*APB2 Peripherals*/
#define RCC_APB2_TIMER1          0
#define RCC_APB2_USART1          4
#define RCC_APB2_USART6          5
#define RCC_APB2_ADC1	         8
#define RCC_APB2_SDIO	         11
#define RCC_APB2_SPI1	         12
#define RCC_APB2_SPI4	         13
#define RCC_APB2_SYSCFG	         14
#define RCC_APB2_TIMER9          16
#define RCC_APB2_TIMER10         17
#define RCC_APB2_TIMER11         18

/* Speed Options */
enum
{
	CLK_Full,
	CLK_2=8,
	CLK_4,
	CLK_8,
	CLK_16,
	CLK_128,
	CLK_256,
	CLK_512,

};



void RCC_voidInit   (void);
void RCC_voidEnablePeripheralClock      (   u8 Copy_u8BusId    , u8 Copy_u8PerId    );
void RCC_voidDisablePeripheralClock     (   u8 Copy_u8BusId    , u8 Copy_u8PerId    );
void RCC_voidChangeAHB_Speed();



#endif /* RCC_INTERFACE_H_ */
