/*
 * TIMER1_PROG.c
 *
 * Created: 2/17/2024 9:10:58 PM
 *  Author: mathe
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_INT.h"
#include "LCD_INT.h"
void TIMER1_initNormalMode()
{
	//SELECT NORMAL MODE
	CLEAR_BIT(TCCR1A,COM1A0);
	CLEAR_BIT(TCCR1A,COM1A1);
	CLEAR_BIT(TCCR1A,COM1B0);
	CLEAR_BIT(TCCR1A,COM1B1);
	CLEAR_BIT(TCCR1A,WGM10);
	CLEAR_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1B,WGM12);
	CLEAR_BIT(TCCR1B,WGM13);	
	
	//SELECT INPUT CAPTURE SELECT TO RISING EDGE
	CLEAR_BIT(TCCR1B,ICES1);
	
	//Enable Interrupt(overflow)	
	SET_BIT(TIMSK,TOIE1);
	
    //Enable Interrupt(INPUT CAPTURE)
	SET_BIT(TIMSK,TICIE1);


}

void TIMER1_start(u8 prescaler)
{
	if(prescaler==TIMER1_CLK_DIV_1)
	{
		SET_BIT(TCCR1B,CS10);
		CLEAR_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
		
	}
	else if(prescaler==TIMER1_CLK_DIV_8)
	{
		CLEAR_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
	}
	else if(prescaler==TIMER1_CLK_DIV_64)
	{
		SET_BIT(TCCR1B,CS10);
		SET_BIT(TCCR1B,CS11);
		CLEAR_BIT(TCCR1B,CS12);
	}
	
}

void (*T1CAPTURE_ptr)();


void __vector_6(void) __attribute__((signal,used));
void __vector_6(void)
{
      T1CAPTURE_ptr();	
}

void TIMER1_capturesetCallback( void (*APP_func)() )
{
	T1CAPTURE_ptr = APP_func;
}

void (*T1_ptr)();

//ISR
void __vector_9(void) __attribute__((signal,used));
void __vector_9(void)
{
	//counter of overflows;
	T1_ptr();
}


void TIMER1_setCallback( void (*APP_func)() )
{
	T1_ptr = APP_func;
}

/*void TIMER1_setCallbackCtc( void (*APP_func)() )
{
	T1_ptr = APP_func;
}*/

u16 TIMER1_readTimer()
{ 
	return TCNT1L;
}

void TIMER1_stop()
{
	CLEAR_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
}

/*void TIMER1_initFastPwmMod14()
{
	//force bit
	CLEAR_BIT(TCCR1A,FOC1A);
	
	//select fast PWM mode 14
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	
	#if(TIMER1_PWM_MODE == TIMER1_PWM_NON_INVERTING)
	{
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
	}
	#elif(TIMER1_PWM_MODE == TIMER1_PWM_INVERTING)
	{
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
	}
	#endif
}*/

/*void TIMER1_setDuty(u8 duty)
{
	#if(TIMER1_PWM_MODE == TIMER1_PWM_NON_INVERTING)
	{
		OCR1A = (duty*ICR1/100) -1;
	}
	#elif(TIMER1_PWM_MODE == TIMER1_PWM_INVERTING)
	{
		
	}
	#endif
}*/

/*void TIMER1_setFrequency(u16 pwm_frequency)
{
	//ICR1 = 4999;//-> 50 Hz
	ICR1 = (16000000/(64.0*pwm_frequency))-1;
	
	// select prescaler 64
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);

}*/