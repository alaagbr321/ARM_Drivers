/*
 * DotMatrix_Interface.h
 *
 *  Created on: Sep 10, 2023
 *      Author: WIN10
 */

#ifndef HAL_DOTMATRIX_DOTMATRIX_INTERFACE_H_
#define HAL_DOTMATRIX_DOTMATRIX_INTERFACE_H_

//Rows connected on PortA 0-7
//Cols connected on PortB 0-7

#define NumberOfCols     8
#define NumberOfRows     8


void DotMatrix_voidInit();
void DotMatrix_voidSendData(u8 *Copy_u8Data);




#endif /* HAL_DOTMATRIX_DOTMATRIX_INTERFACE_H_ */
