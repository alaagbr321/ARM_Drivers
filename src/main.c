#include "LIB/STD_TYPES.h"
#include"LIB/BIT_MATH.h"
#include "MCAL/RCC/RCC_Interface.h"
#include "MCAL/GPIO/GPIO_Interface.h"
#include "HAL/SSD/SSD_Interface.h"
#include "MCAL/NVIC/NVIC_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/SYSTICK/SYSTICK_Interface.h"
#include "Service/RTOS/RTOS_Interface.h"
#include "HAL/STP/STP_Interface.h"
#include "HAL/SSD/SSD_Private.h"
#include "LIB/song.h"
#include"LIB/Image.h"
#include"HAL/DotMatrix/DotMatrix_Interface.h"
#include "HAL/IR/IR_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "HAL/TFT/TFT_Interface.h"



int main()
{
	/*Initialize RCC*/
	RCC_voidInit();
	SYSTICK_voidInit();
	/*Enable Peripheral Clock*/
	RCC_voidEnablePeripheralClock(RCC_AHB1,RCC_AHB1_GPIOA);
	RCC_voidEnablePeripheralClock(RCC_APB2,RCC_APB2_SPI1);
	GPIO_voidSetPinMode(GPIO_PORTA,2,GPIO_OUTPUT);
	GPIO_voidSetPinMode(GPIO_PORTA,1,GPIO_OUTPUT);
	SPI_voidMasterInit();
	TFT_voidInit();

	TFT_voidDisplayImage(image);





	return 0;


}

