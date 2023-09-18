/*
 * NVIC_Interface.h
 *
 *  Created on: Sep 4, 2023
 *      Author: WIN10
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

typedef enum {
    WWDG                = 0 ,
    EXTI16              = 1 ,
    EXTI21              = 2 ,
    EXTI22              = 3 ,
    FLASH               = 4 ,
    RCC                 = 5 ,
    EXTI0               = 6 ,
    EXTI1               = 7 ,
    EXTI2               = 8 ,
    EXTI3               = 9 ,
    EXTI4               = 10,
    DMA1_STREAM0        = 11,
    DMA1_STREAM1        = 12,
    DMA1_STREAM2        = 13,
    DMA1_STREAM3        = 14,
    DMA1_STREAM4        = 15,
    DMA1_STREAM5        = 16,
    DMA1_STREAM6        = 17,
    ADC                 = 18,
    EXTI9_5              = 23,
    TIM1_BRK_TIM9       = 24,
    TIM1_UP_TIM10       = 25,
    TIM1_TRG_COM_TIM11  = 26,
    TIM1_CC             = 27,
    TIM2                = 28,
    TIM3                = 29,
    TIM4                = 30,
    I2C1_EV             = 31,
    I2C1_ER             = 32,
    I2C2_EV             = 33,
    I2C2_ER             = 34,
    SPI1                = 35,
    SPI2                = 36,
    USART1              = 37,
    USART2              = 38,
    EXTI15_10           = 40,
    EXTI17              = 41,
    EXTI18              = 42,
    DMA1_STREAM7        = 47,
    SDIO                = 49,
    TIM5                = 50,
    SPI3                = 51,
    DMA2_STREAM0        = 56,
    DMA2_STREAM1        = 57,
    DMA2_STREAM2        = 58,
    DMA2_STREAM3        = 59,
    DMA2_STREAM4        = 60,
    OTG_FS              = 67,
    DMA2_STREAM5        = 68,
    DMA2_STREAM6        = 69,
    DMA2_STREAM7        = 70,
    USART6              = 71,
    I2C3_EV             = 72,
    I2C3_ER             = 73,
    FPU                 = 81,
    SPI4                = 84,
}Postion_E;

//typedef enum{
//    GROUP_PRIORITY_0_SUB_PRIORITY_0 = 0b0000,
//    GROUP_PRIORITY_0_SUB_PRIORITY_1 = 0b0001,
//    GROUP_PRIORITY_0_SUB_PRIORITY_2 = 0b0010,
//    GROUP_PRIORITY_0_SUB_PRIORITY_3 = 0b0011,
//    GROUP_PRIORITY_1_SUB_PRIORITY_0 = 0b0100,
//    GROUP_PRIORITY_1_SUB_PRIORITY_1 = 0b0101,
//    GROUP_PRIORITY_1_SUB_PRIORITY_2 = 0b0110,
//    GROUP_PRIORITY_1_SUB_PRIORITY_3 = 0b0111,
//    GROUP_PRIORITY_2_SUB_PRIORITY_0 = 0b1000,
//    GROUP_PRIORITY_2_SUB_PRIORITY_1 = 0b1001,
//    GROUP_PRIORITY_2_SUB_PRIORITY_2 = 0b1010,
//    GROUP_PRIORITY_2_SUB_PRIORITY_3 = 0b1011,
//    GROUP_PRIORITY_3_SUB_PRIORITY_0 = 0b1100,
//    GROUP_PRIORITY_3_SUB_PRIORITY_1 = 0b1101,
//    GROUP_PRIORITY_3_SUB_PRIORITY_2 = 0b1110,
//    GROUP_PRIORITY_3_SUB_PRIORITY_3 = 0b1111,
//}GROUB_4_SUBGROUP_4;

#define PEND_SV	-6
#define SYSTICK	-5
//////////
#define SV_CALL	-4
//////////////
#define MEMORY_MANAGE	-3
#define BUS_FAULT		-2
#define USAGE_FAULT		-1



void NVIC_voidPriorityGroup_Sub_Selection();
void NVIC_voidInterruptEnable(u8 Copy_u8InterruptNum);
u8   NVIC_u8InterruptCheckEnable(u8 Copy_u8InterruptNum);
void NVIC_voidInterruptDisable(u8 Copy_u8InterruptNum);
void NVIC_voidInterruptEnablePending(u8 Copy_u8InterruptNum);
u8   NVIC_u8InterruptCheckPending(u8 Copy_u8InterruptNum);
void NVIC_voidInterruptDisablePending(u8 Copy_u8InterruptNum);
u8   NVIC_u8InterruptCheckFlag(u8 Copy_u8InterruptNum);

/*  Priority Options:0--->15     */
void NVIC_voidInterruptChangePriority(Postion_E Copy_u8InterruptNum,u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority);


#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
