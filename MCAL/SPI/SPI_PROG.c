/*
 * SPI_PROG.c
 *
 * Created: 3/1/2024 9:56:29 PM
 *  Author: mathe
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_INT.h"
#include "DIO_INT.h"

void SPI_init()
{
	SET_BIT(SPCR,SPE);
	
	#if(MODE_SELECTION == MASTER_MODE)
		SET_BIT(SPCR,MSTR);
		DIO_setPinDir(DIO_PINB5,DIO_OUTPUT);
		DIO_setPinDir(DIO_PINB7,DIO_OUTPUT);
		DIO_setPinDir(DIO_PINB6,DIO_INPUT);
		DIO_setPinDir(DIO_PINB4,DIO_OUTPUT);

				
    #elif(MODE_SELECTION == SLAVE_MODE)
		CLEAR_BIT(SPCR,MSTR);
		DIO_setPinDir(DIO_PINB5,DIO_INPUT);
		DIO_setPinDir(DIO_PINB7,DIO_INPUT);
		DIO_setPinDir(DIO_PINB6,DIO_OUTPUT);
		DIO_setPinDir(DIO_PINB4,DIO_INPUT);

#endif

}


void SPI_sendData(u8 data)
{
	DIO_setPinValue(DIO_PINB4,DIO_HIGH);
	DIO_setPinValue(DIO_PINB4,DIO_LOW);
	
	SPDR=data;
    while(GET_BIT(SPSR,SPIF)==0);
}


u8 SPI_receiveData()
{
    while(GET_BIT(SPSR,SPIF)==0);
	return SPDR;

}