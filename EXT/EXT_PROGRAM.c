/*
 * EXT_PROGRAM.c
 *
 * Created: 2/3/2024 9:30:35 PM
 *  Author: mathe
 */ 
#include "STD_TYPES.h"
#include "EXT_INT.h"
#include "DIO_INT.h"
#include "BIT_MATH.h"
void EXT0_init(u8 level)
{
	if(level == EXT_LOW_LEVEL)
	{
		CLEAR_BIT(MCUCR,ISC00);
		CLEAR_BIT(MCUCR,ISC01);
	}
	else if(level == EXT_ANY_LOGICAL)
	{
		SET_BIT(MCUCR,ISC00);
		CLEAR_BIT(MCUCR,ISC01);
	}
	else if(level == EXT_FALLING)
	{
		CLEAR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
	}
	else if( level == EXT_RISING)
	{
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01);
		
	}
	//enable INT0
	SET_BIT(GICR, INT0);
	
}




void EXT1_init(u8 level)
{
		if(level == EXT_LOW_LEVEL)
		{
			CLEAR_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
		}
		else if(level == EXT_ANY_LOGICAL)
		{
			SET_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
		}
		else if(level == EXT_FALLING)
		{
			CLEAR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}
		else if( level == EXT_RISING)
		{
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			
		}
		//enable INT1
		SET_BIT(GICR, INT1);
	
}
void EXT2_init(u8 level)
{

				if(level == EXT_FALLING)
				{
					CLEAR_BIT(MCUCSR,ISC2);
				}
				else if( level == EXT_RISING)
				{
					SET_BIT(MCUCSR,ISC2);
					
				}
				//enable INT1
				SET_BIT(GICR, INT2);	
	
}

//pointer to function
void (*INT0_ptr)();

void EXT_setCallbackInt0(void (*ptr)())
{
	//INT0_ptr = APP_func;
	INT0_ptr = ptr;
}



void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	//call func(pointer to function)
	//APP_func();
	INT0_ptr();

}


//pointer to function
void (*INT1_ptr)();

void EXT_setCallbackInt1(void (*ptr)())
{
	//INT2_ptr = APP_func;
	INT1_ptr = ptr;
}



void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	//call func(pointer to function)
	//APP_func();
	INT1_ptr();

}

//pointer to function
void (*INT2_ptr)();

void EXT_setCallbackInt2(void (*ptr)())
{
	//INT2_ptr = APP_func;
	INT2_ptr = ptr;
}



void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	//call func(pointer to function)
	//APP_func();
	INT2_ptr();

}