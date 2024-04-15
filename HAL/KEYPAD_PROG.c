/*
 * KEYPAD_PROG.c
 *
 * Created: 02/02/2024 06:34:23 PM
 *  Author: AMIT
 */ 

#include "KEYPAD_INT.h"

void KEYPAD_init()
{
	DIO_setPinDir(KEYPAD_ROW0, DIO_INPUT);
	DIO_setPinDir(KEYPAD_ROW1, DIO_INPUT);
	DIO_setPinDir(KEYPAD_ROW2, DIO_INPUT);
	DIO_setPinDir(KEYPAD_ROW3, DIO_INPUT);
	
	DIO_setPinPullUp(KEYPAD_ROW0);
	DIO_setPinPullUp(KEYPAD_ROW1);
	DIO_setPinPullUp(KEYPAD_ROW2);
	DIO_setPinPullUp(KEYPAD_ROW3);
	
	DIO_setPinDir(KEYPAD_COL0, DIO_OUTPUT);
	DIO_setPinDir(KEYPAD_COL1, DIO_OUTPUT);
	DIO_setPinDir(KEYPAD_COL2, DIO_OUTPUT);
	DIO_setPinDir(KEYPAD_COL3, DIO_OUTPUT);
	
}

u8 KEYPAD_read()
{
	
	DIO_setPinValue(KEYPAD_COL0, DIO_LOW);
	DIO_setPinValue(KEYPAD_COL1, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL2, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL3, DIO_HIGH);
	
	if(DIO_readPinValue(KEYPAD_ROW0) == DIO_LOW)
	{
		return KEYPAD_ROW0_COL0;
	}
	else if(DIO_readPinValue(KEYPAD_ROW1) == DIO_LOW)
	{
		return KEYPAD_ROW1_COL0;
	}
	else if(DIO_readPinValue(KEYPAD_ROW2) == DIO_LOW)
	{
		return KEYPAD_ROW2_COL0;
	}
	else if(DIO_readPinValue(KEYPAD_ROW3) == DIO_LOW)
	{
		return KEYPAD_ROW3_COL0;
	}
	
	
	
	
	
	DIO_setPinValue(KEYPAD_COL0, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL1, DIO_LOW);
	DIO_setPinValue(KEYPAD_COL2, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL3, DIO_HIGH);
	
	if(DIO_readPinValue(KEYPAD_ROW0) == DIO_LOW)
	{
		return KEYPAD_ROW0_COL1;
	}
	else if(DIO_readPinValue(KEYPAD_ROW1) == DIO_LOW)
	{
		return KEYPAD_ROW1_COL1;
	}
	else if(DIO_readPinValue(KEYPAD_ROW2) == DIO_LOW)
	{
		return KEYPAD_ROW2_COL1;
	}
	else if(DIO_readPinValue(KEYPAD_ROW3) == DIO_LOW)
	{
		return KEYPAD_ROW3_COL1;
	}
	
	
	
	DIO_setPinValue(KEYPAD_COL0, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL1, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL2, DIO_LOW);
	DIO_setPinValue(KEYPAD_COL3, DIO_HIGH);
	
	if(DIO_readPinValue(KEYPAD_ROW0) == DIO_LOW)
	{
		return KEYPAD_ROW0_COL2;
	}
	else if(DIO_readPinValue(KEYPAD_ROW1) == DIO_LOW)
	{
		return KEYPAD_ROW1_COL2;
	}
	else if(DIO_readPinValue(KEYPAD_ROW2) == DIO_LOW)
	{
		return KEYPAD_ROW2_COL2;
	}
	else if(DIO_readPinValue(KEYPAD_ROW3) == DIO_LOW)
	{
		return KEYPAD_ROW3_COL2;
	}
	
	
	DIO_setPinValue(KEYPAD_COL0, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL1, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL2, DIO_HIGH);
	DIO_setPinValue(KEYPAD_COL3, DIO_LOW);
	
	if(DIO_readPinValue(KEYPAD_ROW0) == DIO_LOW)
	{
		return KEYPAD_ROW0_COL3;
	}
	else if(DIO_readPinValue(KEYPAD_ROW1) == DIO_LOW)
	{
		return KEYPAD_ROW1_COL3;
	}
	else if(DIO_readPinValue(KEYPAD_ROW2) == DIO_LOW)
	{
		return KEYPAD_ROW2_COL3;
	}
	else if(DIO_readPinValue(KEYPAD_ROW3) == DIO_LOW)
	{
		return KEYPAD_ROW3_COL3;
	}
	
	return KEYPAD_UNPRESSED;
	
}