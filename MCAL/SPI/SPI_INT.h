/*
 * SPI_INT.h
 *
 * Created: 3/1/2024 9:56:12 PM
 *  Author: mathe
 */ 


#ifndef SPI_INT_H_
#define SPI_INT_H_

#define SPCR *(volatile u8*)0x2D
#define SPSR *(volatile u8*)0x2E
#define SPDR *(volatile u8*)0x2F

#define  MASTER_MODE 1
#define  SLAVE_MODE 2

#define MODE_SELECTION SLAVE_MODE


#define  SPE 6
#define  MSTR 4
#define  SPIF 7




void SPI_init();

void SPI_sendData(u8 data);

u8 SPI_receiveData();



#endif /* SPI_INT_H_ */