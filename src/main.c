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
#include"HAL/DotMatrix/DotMatrix_Interface.h"
#include "HAL/IR/IR_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"



int main()
{
	/*Initialize RCC*/
	RCC_voidInit();
	SYSTICK_voidInit();
	/*Enable Peripheral Clock*/
	RCC_voidEnablePeripheralClock(RCC_AHB1,RCC_AHB1_GPIOA);
	RCC_voidEnablePeripheralClock(RCC_AHB1,RCC_AHB1_GPIOB);
	RCC_voidEnablePeripheralClock(RCC_APB2,RCC_APB2_SYSCFG);
	RCC_voidEnablePeripheralClock(RCC_APB2,RCC_APB2_SPI1);
	GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN8,GPIO_OUTPUT);
	SPI_voidMasterInit();


	u8 data;

	while(1)
	{
		data=SPI_voidSendReceiveData('1');
		if(data=='2')
		{
			GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN8,GPIO_HIGH);
		}

	}
	return 0;


}

