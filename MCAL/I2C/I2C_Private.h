/*
 * I2C_Private.h
 *
 *  Created on: Oct 2, 2023
 *      Author: WIN10
 */

#ifndef MCAL_I2C_I2C_PRIVATE_H_
#define MCAL_I2C_I2C_PRIVATE_H_



#define I2C1_BASE_ADDRESS               0x40005400
#define I2C2_BASE_ADDRESS               0x40005800
#define I2C3_BASE_ADDRESS               0x40005C00




/*CR1 Registers*/
#define PE             0
#define SMBUS          1
#define SMBTYPE        3
#define ENARP          4
#define ENPEC          5
#define ENGC           6
#define NOSTRETCH      7
#define START          8
#define STOP           9
#define ACK            10
#define POS            11
#define PEC            12
#define ALERT          13
#define SWRST          15

/*SR1 Registers*/
#define SB             0
#define ADDR           1
#define BTF            2
#define ADD10          3
#define STOPF          4
#define RxNE           6
#define TxE            7




typedef struct
{
	volatile u32     CR1           ;
	volatile u32     CR2           ;
	volatile u32     OAR1          ;
	volatile u32     OAR2          ;
	volatile u32     DR            ;
	volatile u32     SR1           ;
	volatile u32     SR2           ;
	volatile u32     CCR           ;
	volatile u32     TRISE         ;
	volatile u32     FLTR          ;
}I2C_MemMap_t;

#define I2C1        ( (volatile I2C_MemMap_t*) I2C1_BASE_ADDRESS)
#define I2C2        ( (volatile I2C_MemMap_t*) I2C2_BASE_ADDRESS)
#define I2C3        ( (volatile I2C_MemMap_t*) I2C3_BASE_ADDRESS)












#endif /* MCAL_I2C_I2C_PRIVATE_H_ */
