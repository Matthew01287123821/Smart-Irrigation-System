/*
 * ON_OFF_BUTTON_PROG.c
 *
 * Created: 4/13/2024 5:58:48 PM
 *  Author: mathe
 */ 
#include "BIT_MATH.h"
#include "DIO_INT.h"


void ON_OFF_init()
{
	DIO_setPinDir(DIO_PIND7,DIO_INPUT);
}
