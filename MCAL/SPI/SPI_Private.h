/*
 * SPI_Private.h
 *
 *  Created on: Sep 17, 2023
 *      Author: WIN10
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define  SPI1_BASE_ADDRESS      0x40013000
#define  SPI2_BASE_ADDRESS      0x40003800
#define  SPI3_BASE_ADDRESS      0x40003C00

/*CR1 Registers*/
#define CPHA       0
#define CPOL       1
#define MSTR       2
#define SPE        6
#define LSBFIRST   7
#define DFF        11


typedef struct
{

volatile  u32   SPI_CR1;
volatile  u32   SPI_CR2;
volatile  u32   SPI_SR;
volatile  u32   SPI_DR;
volatile  u32   SPI_CRCPR;
volatile  u32   SPI_RXCRCR;
volatile  u32   SPI_TXCRCR;
volatile  u32   SPI_I2SCFGR;
volatile  u32   SPI_I2SPR;





}SPI_MemMap_t;


#define SPI1         ((volatile SPI_MemMap_t*)SPI1_BASE_ADDRESS)
#define SPI2         ((volatile SPI_MemMap_t*)SPI2_BASE_ADDRESS)
#define SPI3         ((volatile SPI_MemMap_t*)SPI3_BASE_ADDRESS)




#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
