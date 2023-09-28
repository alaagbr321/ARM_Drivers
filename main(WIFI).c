
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
#include "MCAL/UART/UART_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "HAL/ESP/ESP_Interface.h"




int main()
{
	/*Initialize RCC*/
	RCC_voidInit();
	SYSTICK_voidInit();
	/*Enable Peripheral Clock*/
	RCC_voidEnablePeripheralClock(RCC_AHB1,RCC_AHB1_GPIOA);
	RCC_voidEnablePeripheralClock(RCC_AHB1,RCC_AHB1_GPIOB);
	RCC_voidEnablePeripheralClock(RCC_APB2,RCC_APB2_SYSCFG);
	RCC_voidEnablePeripheralClock(RCC_APB2,RCC_APB2_USART1);

GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN8,GPIO_OUTPUT);
GPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_OUTPUT);
UART_voidInit(UART_1,115200);
ESP_voidInit();
ESP_voidConnectToNetWork();
u8 Local_u8Var;


	while(1)
	{
//		ESP_voidConnectToServer();
		Local_u8Var=ESP_u8GetData();

//		Local_u8Var=UART_u8RecieveData(UART_1);
//		UART_voidSendData(UART_1,Local_u8Var);
		if(Local_u8Var=='1')
		{
			GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN8,GPIO_HIGH);
		}else if(Local_u8Var=='0')
		{
			GPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN8,GPIO_LOW);
		}


	}
	return 0;


}


