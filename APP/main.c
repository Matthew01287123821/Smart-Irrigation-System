/*
 * GRADUATION_PROJECT.c
 *
 * Created: 3/22/2024 11:16:31 AM
 * Author : mathe
 */ 

#include "STD_TYPES.h"
#include "DIO_INT.h"
#include "BIT_MATH.h"
#define F_CPU 16000000
#include <util/delay.h>
#include "EXT_INT.h"
#include "TIMER0_INT.h"
#include "LCD_INT.h"
#include "GI_INT.h"
#include "ADC_INT.h"
#include "MOISTURE_SENSOR_INT.h"
#include "ULTRASONIC_INT.h"
#include "ON_OFF_BUTTON_INT.h"
#include "Irrigation_Pump_INT.h"
#include "TankFilling_motor.h"


u8 ON_FLAG=0;                               // FLAG FOR THE ON_OFF BUTTON INTERRUPT
u16 distance=0;                              // DISTANCE MEASURED BY THE ULTRASONIC SENSOR
u32 ovf_count=0;                              // OVERFLOW COUNTER TO CALCULATE TIME OF THE ECHO SIGNAL OF ULTRASONIC
f32 ticktime=(256.0/16000000.0)*1000;           // TICK TIME CALCULATION = NUMBER OF TICKS * ONE TICK TIME


void ON_OFFBUTTON_ISR()                     // EXTERNAL INTERRUPT 1 FUNCTION FOR THE ON_OFF BUTTON
{
	if(ON_FLAG==0)
	{
		ON_FLAG=1;
		
	}
	else if(ON_FLAG==1)
	{
		ON_FLAG=0;
		TIMER0_stop();
		Turn_off_FillingMotor();
		Turn_off_IrrigationPump();
		LCD_clearDis();
		
	}
	
}

void ovf_T0_ISR ()                      // TIMER 0 OVERFLOW INTERRUPT FUNCTION
{
	ovf_count++;
	
}

void ultrasonic_ISR()                   // EXTERNAL INTERRUPT 0 FUNCTION FOR THE START & STOP OF TIMER 0 WHEN RECEIVING THE ECHO SIGNAL OF ULTRASONIC 
{
    static u8 flag=1;                     
	if(flag==1)                          //FLAG=1 ON THE RISING EDGE OF THE ECHO PULSE 
	{
		ovf_count=0;                       //SETTING OVERFLOW COUNTER TO START FROM 0
		TIMER0_setPreload(0);                       //SETTING TIMER TO START FROM 0
		TIMER0_start(TIMER0_CLK_DIV_256);            // STARTING TIMER WITH PRESCALER 256
	}
	else if (flag==0)                                                  //FLAG=0 ON THE falling EDGE OF THE ECHO PULSE
	{
		TIMER0_stop();                                                // STOP TIMER TO MEASURE DISTANCE 
		u32 overallticks = (ovf_count*256+TIMER0_readTimer());        // CALCULATION OF THE OVERALL TICKS OF THE TIMER 
		distance = (overallticks*ticktime)*17;                        // DISTANCE CALCULATION
	}
	flag=!flag;
}
int main(void)
{
    
	
	GI_enable();            // GLOBAL INTERRUPT ENABLE
	LCD_init();              // LCD INITAIALIZATION
	ADC_init();                 // ADC INITAIALIZATION
	Ultrasonic_init();            // ULTRASONIC INITAIALIZATION
	ON_OFF_init();                  // ON_OFF BUTTON INITAIALIZATION
	FillingMotor_init();             // FILLING WATER MOTOR INITAIALIZATION
	IrrigationPump_init();              // IRRIGATION PUMP INITAIALIZATION
	
	
	EXT1_init(EXT_RISING);                  // EXTERNAL INTERRUPT 1 INITAIALIZATION
    EXT0_init(EXT_ANY_LOGICAL);               // EXTERNAL INTERRUPT 0 INITAIALIZATION
	EXT_setCallbackInt1(ON_OFFBUTTON_ISR);       // EXTERNAL INTERRUPT 1 SETCALLBACK FUNCTION
	EXT_setCallbackInt0(ultrasonic_ISR);             // EXTERNAL INTERRUPT 0 SETCALLBACK FUNCTION
	 
	TIMER0_initNormalMode();                          // TIMER 0 INITAIALIZATION
	TIMER0_setCallback(ovf_T0_ISR);                      // TIMER 0 INTERRUPT SETCALLBACK FUNCTION
	
	
		
 	
    while (1) 
    {
		while(ON_FLAG!=1);                       //CHECK IF THE ON_OFF BUTTON IS PRESSED OR NOT TO START OR STOP THE SYSTEM
		UltrasonicReadDistance();                // SEND TRIGGER PULSE FROM THE ULTRASONIC SENSOR TO MEASURE LEVEL OF WATER
		LCD_goto(1,1);                          // WRITE ON THE FIRST LINE OF LCD
		LCD_writeStr("LEVEL = ");                
		LCD_writeNum(distance);
		LCD_writeStr("cm ");

		if(distance>100)                      // IF THE DISTANCE BETWEEN THE SENSOR AND THE LEVEL OF WATER IN THE TANK IS MORE THAN 100 CM :
		{
			Turn_on_FillingMotor();             // TURN ON FILLING MOTOR
		}
		else if(distance<50)                  // IF THE DISTANCE BETWEEN THE SENSOR AND THE LEVEL OF WATER IN THE TANK IS LESS THAN 50 CM :
		{
			Turn_off_FillingMotor();           // TURN OFF FILLING MOTOR
		}
		LCD_goto(1,2);                         // WRITE ON THE SECOND LINE OF LCD
		LCD_writeStr("Moisture is ");
		LCD_writeNum(READ_MOISTURE());          // READ THE ANALONGUE VALUE OF THE MOISTURE MEASURED BY MOISTURE SENSORE AFTER CONVERSION BY ADC
		LCD_writeStr("% ");
		if(READ_MOISTURE()<=20)                  // IF THE MOISTURE VALUE LESS THAN OR EQUAL TO 20% :
		{
			Turn_on_IrrigationPump();             // TURN ON IRRIGATION PUMP 
		}
		else if(READ_MOISTURE()>=90)              // IF THE MOISTURE VALUE MORE THAN OR EQUAL TO 90% :
		{
			Turn_off_IrrigationPump();             // TURN OFF IRRIGATION PUMP 
		}
		_delay_ms(500);
			
				

    }
}

