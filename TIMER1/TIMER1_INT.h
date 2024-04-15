/*
 * TIMER1_INT.h
 *
 * Created: 2/17/2024 9:10:12 PM
 *  Author: mathe
 */ 


#ifndef TIMER1_INT_H_
#define TIMER1_INT_H_

/******************************************
  INCLUDES
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/

#define TIMER1_PWM_INVERTING 	 0
#define TIMER1_PWM_NON_INVERTING 1
#define TIMER1_PWM_MODE 		 TIMER1_PWM_NON_INVERTING


////////////////////////////////////////////////////////////////////////

/*TIMER1 Registers*/
#define TCCR1A				*((volatile u8*)0x4F)
#define WGM10	0
#define WGM11	1
#define FOC1A	3
#define FOC1B	2
#define COM1B0	4
#define COM1B1	5
#define COM1A0	6
#define COM1A1	7

#define TCCR1B				*((volatile u8*)0x4E)
#define CS10	0
#define CS11	1
#define CS12	2
#define WGM12	3
#define WGM13	4
#define ICES1	6
#define ICNC1	7
#define TCNT1L				*((volatile u16*)0x4C)

#define TCNT1H               *((volatile u16*)0x4D)

#define OCR1A				*((volatile u16*)0x4A)

#define OCR1B				*((volatile u16*)0x48)

#define ICR1				*((volatile u16*)0x46)

#define TIMSK				*((volatile u8*)0x59)
#define TOIE1		2
#define OCIE1B		3
#define OCIE1A		4
#define TICIE1		5

#define TIFR				*((volatile u8*)0x58)
#define ICF1          5
#define OCF1A         4
#define OCF1B         3 
#define TOV1          2

///////////////////////////////////////////////////////////////

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/
#define TIMER1_CLK_DIV_1			0
#define TIMER1_CLK_DIV_8			1
#define TIMER1_CLK_DIV_64			2
#define TIMER1_CLK_DIV_256			3
#define TIMER1_CLK_DIV_1024			4
#define TIMER1_CLK_EXTERNAL_FALLING	5
#define TIMER1_CLK_EXTERNAL_RISING	6

//void TIMER1_initFastPwmMod14();
void TIMER1_setDuty(u8 duty);
//void TIMER1_setFrequency(u16 pwm_frequency);
void TIMER1_initNormalMode();
void TIMER1_start(u8 prescaler);
u16 TIMER1_readTimer();
void TIMER1_stop();



void TIMER1_setCallback( void (*APP_func)() );

void TIMER1_capturesetCallback( void (*APP_func)() );


#endif /* TIMER1_INT_H_ */