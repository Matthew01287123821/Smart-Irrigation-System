/*
 * Irrigation_Pump_PROG.c
 *
 * Created: 4/14/2024 12:34:13 AM
 *  Author: mathe
 */ 
#include "DIO_INT.h"

void IrrigationPump_init()
{
	DIO_setPinDir(DIO_PINB7,DIO_OUTPUT);
}


void Turn_on_IrrigationPump()
{
	DIO_setPinValue(DIO_PINB7,DIO_HIGH);
}


void Turn_off_IrrigationPump()
{
	DIO_setPinValue(DIO_PINB7,DIO_LOW);
}