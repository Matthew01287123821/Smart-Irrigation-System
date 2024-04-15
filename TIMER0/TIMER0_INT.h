/*
 * TIMER0_INT.h
 *
 * Created: 2/10/2024 8:59:46 PM
 *  Author: mathe
 */ 


#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/


/*Timer0 Registers*/
//Timer/Counter Control Register
#define TCCR0 		*((volatile u8*)0x53)
#define FOC0		7
#define WGM00		6
#define COM01		5	
#define COM00		4
#define WGM01		3
#define CS02		2
#define CS01		1
#define CS00		0

//Timer/Counter Register
#define TCNT0 		*((volatile u8*)0x52)

//Output Compare Register
#define OCR0 		*((volatile u8*)0x5C)

//Timer/Counter Interrupt Mask
#define TIMSK 		*((volatile u8*)0x59)
#define OCIE0		1
#define TOIE0		0
////////////////////////////////////////////////////////////////////////

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

#define TIMER0_CLK_DIV_1			0
#define TIMER0_CLK_DIV_8			1
#define TIMER0_CLK_DIV_64			2
#define TIMER0_CLK_DIV_256			3
#define TIMER0_CLK_DIV_1024			4
#define TIMER0_CLK_EXTERNAL_FALLING	5
#define TIMER0_CLK_EXTERNAL_RISING	6

#define PWM_FREQUENCY_62500  0
#define PWM_FREQUENCY_7812   1

#define PWM_INVERTING	  0
#define PWM_NON_INVERTING 1

#define PWM_MODE		  PWM_NON_INVERTING


#define OC0_DISCONNECTED 0
#define OC0_TOGGLE		 1
#define OC0_CLEAR		 2
#define OC0_SET			 3

#define ocPinMode        OC0_DISCONNECTED

void TIMER0_initCtcMode();
void TIMER0_setOcr(u8 num);

void TIMER0_initNormalMode();

void TIMER0_start(u8 prescaler);

void TIMER0_stop();

void TIMER0_setPreload(u8 ticks);

u8 TIMER0_readTimer();

void TIMER0_setCallback( void (*APP_func)() );

void TIMER0_initFastPwm();

void TIMER0_setDuty(u8 duty);

void TIMER0_setFrequency(u8 pwm_frequency);

#endif /* TIMER0_INT_H_ */