/*
 * SSD_Interface.h
 *
 *  Created on: Sep 4, 2023
 *      Author: WIN10
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

typedef struct
{
	u8 PORT;
	u8 CommanState;
	u8 StartingPin;


}SSD_t;

#define Comman_Cathod 1
#define Comman_Anode  0


#define GPIO_PORTA   0
#define GPIO_PORTB   1

#define GPIO_PIN0    0
#define GPIO_PIN7    7

void SSD_voidInit(SSD_t *Copy_PstructLed);
void SSD_Display(SSD_t *Copy_PstructLed,u8 num);
void SSD_Disable(SSD_t *Copy_PstructLed);





#endif /* HAL_SSD_SSD_INTERFACE_H_ */
