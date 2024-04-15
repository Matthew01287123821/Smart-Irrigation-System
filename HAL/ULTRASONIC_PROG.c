/*
 * ULTRASONIC_PROG.c
 *
 * Created: 4/13/2024 4:05:20 PM
 *  Author: mathe
 */
 #include "BIT_MATH.h"
 #include "DIO_INT.h"
 #include <util/delay.h>

void Ultrasonic_init()
{
	DIO_setPinDir(DIO_PINC7,DIO_OUTPUT);
	DIO_setPinDir(DIO_PIND2,DIO_INPUT);	
}

void UltrasonicReadDistance()
{
		    DIO_setPinValue(DIO_PINC7,DIO_HIGH);
			_delay_us(100);
			DIO_setPinValue(DIO_PINC7,DIO_LOW);
}
