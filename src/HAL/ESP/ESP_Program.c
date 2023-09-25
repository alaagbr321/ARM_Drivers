/*
 * ESP_Program.c
 *
 *  Created on: Sep 24, 2023
 *      Author: WIN10
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/UART/UART_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_Interface.h"
#include "ESP_Interface.h"
#include "ESP_Private.h"
#include "ESP_Config.h"


void ESP_voidInit()
{
	u8 Local_u8Var=0;

	while(Local_u8Var!=129)
	{
		UART_voidTransmit("ATE1\r\n");
		Local_u8Var=ESP_voidValidation();
	}
	Local_u8Var=0;
	while(Local_u8Var!=129)
	{
		UART_voidTransmit("AT+CWMODE=1\r\n");
		Local_u8Var=ESP_voidValidation();
	}
}
void ESP_voidConnectToNetWork()
{
	u8 Local_u8Var=0;
	while(Local_u8Var!=129)
	{
		UART_voidTransmit("AT+CWJAP=\"3la2\",\"12345678\"\r\n");
		Local_u8Var=ESP_voidValidation();
	}

}
void ESP_voidConnectToServer()
{
	u8 Local_u8Var=0;
	while(Local_u8Var!=130 &&ESP_voidValidation()!=4)
	{
		UART_voidTransmit("AT+CIPSTART=\"TCP\",\"23.179.32.37\",80\r\n");
		Local_u8Var=ESP_voidValidation();
	}
}
u8  ESP_u8GetData()
{

	u8 data;
	u8 i=0;
	u8 Local_u8Var=0;
	ESP_voidConnectToServer();
	while(Local_u8Var!=129)
	{
		UART_voidTransmit("AT+CIPSEND=40\r\n");
		Local_u8Var=ESP_voidValidation();
	}
	UART_voidTransmit("GET http://alaa.freevar.com/status.txt\r\n");


		data=ESP_voidValidation();

	return data;


}

static u8  ESP_voidValidation()
{
	u8 Local_u8Counter=0;
	u8 Local_u8ReceivedChar=0;
	u8 result=0;
	u8 i=0;

	u8 Local_u8Response[220]={0};

	while(Local_u8Counter < 220)
	{

		Local_u8Response[Local_u8Counter] = UART_u8RecieveData(UART_1);
		Local_u8Counter++;
	}

	for(u8 Local_u8Counter=0; Local_u8Counter<220; Local_u8Counter++)
	{
		if(Local_u8Response[Local_u8Counter] == 'O' && Local_u8Response[Local_u8Counter+1] == 'K')
		{
			result= 129;
			break;
		}else if(Local_u8Response[Local_u8Counter] == 'C' && Local_u8Response[Local_u8Counter+1] == 'O')
		{
			result=130;
			break;
		} else if(Local_u8Response[Local_u8Counter] == 'N' && Local_u8Response[Local_u8Counter+1] == 'D'&& Local_u8Response[Local_u8Counter+3] == 'O')
		{
			i=Local_u8Counter;
			while(Local_u8Response[i]!=':')
			{
				result=Local_u8Response[i+2];
				i++;
			}
			break;
		}
		else
		{
			result= 0;
		}
	}
	return result;
}

