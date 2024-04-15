/*
 * SS_PROG.c
 *
 * Created: 2/10/2024 9:59:07 PM
 *  Author: mathe
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "SS_INT.h"

#include "DIO_INT.h"

#define F_CPU 16000000
#include <util/delay.h>

void SS_init()
{
	DIO_setPinDir(SS_E1, DIO_OUTPUT);
	DIO_setPinDir(SS_E2, DIO_OUTPUT);
	
	DIO_setPinDir(SS_S0 ,DIO_OUTPUT);
	DIO_setPinDir(SS_S1 ,DIO_OUTPUT);
	DIO_setPinDir(SS_S2 ,DIO_OUTPUT);
	DIO_setPinDir(SS_S3 ,DIO_OUTPUT);
}

void SS_setEnable1()
{
	DIO_setPinValue(SS_E1, DIO_HIGH);
}

void SS_setEnable2()
{
	DIO_setPinValue(SS_E2, DIO_HIGH);
}

void SS_setDisable1()
{
	DIO_setPinValue(SS_E1, DIO_LOW);
	
}

void SS_setDisable2()
{
	DIO_setPinValue(SS_E2, DIO_LOW);
	
}

void SS_writeNumber(u8 num)
{
	//enabe1
	SS_setEnable1();
	//disable2
	SS_setDisable2();
	//write num
	u8 s;
	s = num/10;//3
	DIO_setPinValue(SS_S0, GET_BIT(s,0));
	DIO_setPinValue(SS_S1, GET_BIT(s,1));
	DIO_setPinValue(SS_S2, GET_BIT(s,2));
	DIO_setPinValue(SS_S3, GET_BIT(s,3));
	//SS_PORT = SS_PORT | ((num/10)<<4);
	//delay 20 ms
	_delay_ms(20);
	
	//disable1
	SS_setDisable1();
	//enable2
	SS_setEnable2();
	//write num
	//PORTA =PORTA | ((num%10)<<4);
	s = num%10;
	DIO_setPinValue(SS_S0, GET_BIT(s,0));
	DIO_setPinValue(SS_S1, GET_BIT(s,1));
	DIO_setPinValue(SS_S2, GET_BIT(s,2));
	DIO_setPinValue(SS_S3, GET_BIT(s,3));
	//delay 20 ms
	_delay_ms(20);
	
}