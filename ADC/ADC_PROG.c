/*
 * ADC_PROG.c
 *
 * Created: 2/9/2024 8:59:11 PM
 *  Author: mathe
 */ 
#include "ADC_INT.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
void ADC_init()
{
	//select ref voltage(AVCC)
	CLEAR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);
	
	//select prescaler
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	//enable
	SET_BIT(ADCSRA,ADEN);
}

u16 ADC_read(u8 channel)//return digital
{
	//select ch
	if(channel == ADC0)
	{
		CLEAR_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	else if(channel==ADC1)
	{
		SET_BIT(ADMUX,MUX0);
		CLEAR_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);	
	}
	else if(channel==ADC2)
	{
		CLEAR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLEAR_BIT(ADMUX,MUX2);
		CLEAR_BIT(ADMUX,MUX3);
		CLEAR_BIT(ADMUX,MUX4);
	}
	//start conv
	SET_BIT(ADCSRA,ADSC);
	
	//check if finish
	while(GET_BIT(ADCSRA,ADSC) == 1);
	
	//read result 
	return ADCLH;
}

f32 ADC_convertAnalog(u16 digitalValue)//return analog
{
	return digitalValue*(5.0/1024.0);
}