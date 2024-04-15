/*
 * DIO_PROGRAM.c
 *
 * Created: 26/01/2024 07:42:09 PM
 *  Author: AMIT
 */ 

#include "DIO_INT.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

void DIO_setPinValue(u8 pinNum, u8 level)
{
	//portA
	if(pinNum >= 0 && pinNum<= 7)
	{
		if(level == DIO_HIGH)
		{
			SET_BIT(PORTA, pinNum);
		}
		else if(level == DIO_LOW)
		{
			CLEAR_BIT(PORTA, pinNum);
		}
	}
	//portB
	else if(pinNum >= 8 && pinNum<= 15)
	{
		pinNum = pinNum-8;
		if(level == DIO_HIGH)
		{
			SET_BIT(PORTB, pinNum);
		}
		else if(level == DIO_LOW)
		{
			CLEAR_BIT(PORTB, pinNum);
		}	
	}
	//portC
	else if(pinNum >= 16 && pinNum<= 23)
	{
		pinNum = pinNum-16;
		if(level == DIO_HIGH)
		{
			SET_BIT(PORTC, pinNum);
		}
		else if(level == DIO_LOW)
		{
			CLEAR_BIT(PORTC, pinNum);
		}
	}
	//portD
	else if(pinNum >= 24 && pinNum<= 31)
	{
		pinNum = pinNum-24;
		if(level == DIO_HIGH)
		{
			SET_BIT(PORTD, pinNum);
		}
		else if(level == DIO_LOW)
		{
			CLEAR_BIT(PORTD, pinNum);
		}
	}
}

void DIO_setPinDir(u8 pinNum, u8 state)
{
	//portA
	if(pinNum >= 0 && pinNum<= 7)
	{
		if(state == DIO_OUTPUT)
		{
			SET_BIT(DDRA, pinNum);
		}
		else if(state == DIO_INPUT)
		{
			CLEAR_BIT(DDRA, pinNum);
		}
	}
	//portB
	else if(pinNum >= 8 && pinNum<= 15)
	{
		pinNum = pinNum-8;
		if(state == DIO_HIGH)
		{
			SET_BIT(DDRB, pinNum);
		}
		else if(state == DIO_LOW)
		{
			CLEAR_BIT(DDRB, pinNum);
		}
	}
	//portC
	else if(pinNum >= 16 && pinNum<= 23)
	{
		pinNum = pinNum-16;
		if(state == DIO_HIGH)
		{
			SET_BIT(DDRC, pinNum);
		}
		else if(state == DIO_LOW)
		{
			CLEAR_BIT(DDRC, pinNum);
		}
	}
	//portD
	else if(pinNum >= 24 && pinNum<= 31)
	{
		pinNum = pinNum-24;
		if(state == DIO_HIGH)
		{
			SET_BIT(DDRD, pinNum);
		}
		else if(state == DIO_LOW)
		{
			CLEAR_BIT(DDRD, pinNum);
		}
	}
	
}


u8 DIO_readPinValue(u8 pinNum)
{
	//portA
	if(pinNum >= 0 && pinNum<= 7)
	{
		return GET_BIT(PINA, pinNum);
	}
	//portB
	else if(pinNum >= 8 && pinNum<= 15)
	{
		pinNum = pinNum-8;
		return GET_BIT(PINB, pinNum);
	}
	//portA
	else if(pinNum >= 16 && pinNum<= 23)
	{
		pinNum = pinNum-16;
		return GET_BIT(PINC, pinNum);
	}
	//portA
	else if(pinNum >= 24 && pinNum<= 31)
	{
		pinNum = pinNum-24;
		return GET_BIT(PIND, pinNum);
	}
	
	
}

void DIO_setPinPullUp(u8 pinNum)
{
	DIO_setPinValue(pinNum, DIO_HIGH);	
}


void DIO_togglePin(u8 pinNum)
{
	if(DIO_readPinValue(pinNum) ==DIO_HIGH)
	{
		DIO_setPinValue(pinNum, DIO_LOW);
	}
	else if(DIO_readPinValue(pinNum) ==DIO_LOW)
	{
		DIO_setPinValue(pinNum, DIO_HIGH);
	}
}