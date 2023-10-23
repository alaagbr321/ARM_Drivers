/*
 * GPIO_Interface.h
 *
 *  Created on: Sep 4, 2023
 *      Author: WIN10
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_


/*GPIO Ports*/
#define GPIO_PORTA			 0
#define GPIO_PORTB           1
#define GPIO_PORTC           2

/*GPIO Modes*/
#define GPIO_INPUT      0
#define GPIO_OUTPUT     1
#define GPIO_Alternate  2
#define GPIO_ANALOG     3

/*GPIO INPUT/OUTPUT Modes*/
#define GPIO_NoPullUp_NoPullDown   0
#define GPIO_PullUp				   1
#define GPIO_PullDown			   2

/*GPIO Alternative Modes*/
#define AF_System					0
#define TIM1_TIM2					1
#define TIM3_TIM5					2
#define TIM9_TIM11					3
#define I2C1_I2C3					4




/*GPIO OUTPUT Types*/
#define GPIO_OUTPUT_PUSH_PULL    0
#define GPIO_OUTPUT_OPEN_DRAIN    1

/*GPIO OUTPUT SPEED*/
#define LowSpeed       0
#define MediumSpeed    1
#define HighSpeed      2
#define VeryHighSpeed  3









#define GPIO_HIGH       1
#define GPIO_LOW        0

#define GPIO_PORT_INPUT  0x00000000
#define GPIO_PORT_OUTPUT 0xFFFFFFFF

#define GPIO_PORT_LOW  0x00000000
#define GPIO_PORT_HIGH 0xFFFFFFFF

/*GPIO PINS*/
#define GPIO_PIN0     0
#define GPIO_PIN1     1
#define GPIO_PIN2     2
#define GPIO_PIN3     3
#define GPIO_PIN4     4
#define GPIO_PIN5     5
#define GPIO_PIN6     6
#define GPIO_PIN7     7
#define GPIO_PIN8     8
#define GPIO_PIN9     9
#define GPIO_PIN10    10
#define GPIO_PIN11    11
#define GPIO_PIN12    12
#define GPIO_PIN13    13
#define GPIO_PIN14    14
#define GPIO_PIN15    15









void GPIO_voidSetPinMode(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8PinMode);
void GPIO_voidSetPinValue(u8 Copy_u8PortID , u8 Copy_u8Pin ,u8 Copy_u8PinValue);
void GPIO_voidSetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue);
u8  GPIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8Pin);
void GPIO_voidPUPDMode(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8PinMode);
void GPIO_voidSetPinOutputType(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8OutPutPinType);
void GPIO_voidSetPinOutputSpeed(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8OutPutPinSpeed);
void GPIO_voidSetPortConfigLock(u8 Copy_u8PortID,u32 Copy_LockConfig);
void GPIO_voidSetPinAF(u8 Copy_u8PortID  , u8 Copy_u8Pin ,u8 Copy_u8AFPinMode);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
