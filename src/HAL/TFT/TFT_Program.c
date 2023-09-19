/*
 * TFT_Program.c
 *
 *  Created on: Sep 19, 2023
 *      Author: WIN10
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/GPIO/GPIO_Interface.h"
#include"../../MCAL/GPIO/GPIO_Private.h"
#include"../../MCAL/SYSTICK/SYSTICK_Interface.h"
#include"../../MCAL/SPI/SPI_Interface.h"
#include"TFT_Interface.h"
#include"TFT_Private.h"
#include"TFT_Config.h"

void TFT_voidInit()
{


	/*Reset Pulse*/
	GPIO_voidSetPinValue(GPIO_PORTA,TFT_RST_PIN,GPIO_HIGH);
	SYSTICK_voidDelayMs(100);
	GPIO_voidSetPinValue(GPIO_PORTA,TFT_RST_PIN,GPIO_LOW);
	SYSTICK_voidDelayMs(10);
	GPIO_voidSetPinValue(GPIO_PORTA,TFT_RST_PIN,GPIO_HIGH);
	SYSTICK_voidDelayMs(100);
	GPIO_voidSetPinValue(GPIO_PORTA,TFT_RST_PIN,GPIO_LOW);
	SYSTICK_voidDelayMs(100);
	GPIO_voidSetPinValue(GPIO_PORTA,TFT_RST_PIN,GPIO_HIGH);
	SYSTICK_voidDelayMs(120000);

	/*Sleep OUT*/
	TFT_SendCommand(0x11);

	/*wait 150 ms*/
	SYSTICK_voidDelayMs(150000);

	/* COLOR mode */
	TFT_SendCommand(0x3A);
	TFT_SendData(0x05);//RGB565

	/* display on */
	TFT_SendCommand(0x29);

}

static void TFT_SendCommand(u8 Copy_u8Command)
{
	GPIO_voidSetPinValue(GPIO_PORTA,TFT_A0_PIN,GPIO_LOW);

	SPI_voidSendReceiveData(Copy_u8Command);

}
static void TFT_SendData(u8 Copy_u8Data)
{
	GPIO_voidSetPinValue(GPIO_PORTA,TFT_A0_PIN,GPIO_HIGH);

	SPI_voidSendReceiveData(Copy_u8Data);
}
void TFT_voidDisplayImage(const u16 *ImagePtr)
{
	u8 data;
	u16 counter;
	/* set x address */
	TFT_SendCommand(0x2A);
	TFT_SendData(0);
	TFT_SendData(0);
	TFT_SendData(0);
	TFT_SendData(127);

	/* set y address */
	TFT_SendCommand(0x2B);
	TFT_SendData(0);
	TFT_SendData(0);
	TFT_SendData(0);
	TFT_SendData(159);

	/* RAM write */
	TFT_SendCommand(0x2C);

	for(counter=0; counter<20480; counter++)
	{
		data = ImagePtr[counter] >>8;
		TFT_SendData(data);

		data = ImagePtr[counter] & 0xFF; // for low part
		TFT_SendData(data);
	}



}
