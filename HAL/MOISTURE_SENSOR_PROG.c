/*
 * MOISTURE_SENSOR_PROG.c
 *
 * Created: 4/13/2024 3:02:16 PM
 *  Author: mathe
 */ 
#include "ADC_INT.h"
#include "LCD_INT.h"

u16 READ_MOISTURE()
{
	// moisture sensor read
	return ADC_read(ADC1)*100.0/1024;
	
}
