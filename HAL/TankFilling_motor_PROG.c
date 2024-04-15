/*
 * TankFilling_motor_PROG.c
 *
 * Created: 4/14/2024 12:25:29 AM
 *  Author: mathe
 */ 
#include "DIO_INT.h"

void FillingMotor_init()
{
	DIO_setPinDir(DIO_PINC0,DIO_OUTPUT);
}


void Turn_on_FillingMotor()
{
	DIO_setPinValue(DIO_PINC0,DIO_HIGH);
}


void Turn_off_FillingMotor()
{
	DIO_setPinValue(DIO_PINC0,DIO_LOW);
}