/*
 * I2C_PROG.c
 *
 * Created: 3/2/2024 9:07:59 PM
 *  Author: mathe
 */ 
#include "I2C_INT.h"

void I2C_init(enum I2C_mode mode)
{
	if(mode == MASTER)
	{
		
	}
	else if(mode == SLAVE)
	{
		TWAR =  I2C_SLAVE_ADDRESS<<1;
	}
	//enable
	SET_BIT(TWCR, TWEN);
	TWBR = 72;
	
}

void I2C_sendByte(u8 byte, u8 address)
{
	//send start
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//send address
	u8 x = address<<1;
	CLEAR_BIT(x, 0);//write
	TWDR = x;//address_w
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//send data
	TWDR = byte;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//send stop
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
	
}

void I2C_receiveByteACK(u8* byte, u8 address)
{
	//send start
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//send address
	u8 x = address<<1;
	SET_BIT(x, 0);//read
	TWDR = x;//address_r
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//read data
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while( GET_BIT(TWCR,TWINT) ==0 );
	*byte = TWDR;

	
	//send stop
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
	
	
	
}

void I2C_receiveByteNOACK(u8* byte, u8 address)
{
	//send start
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//send address
	u8 x = address<<1;
	SET_BIT(x, 0);//read
	TWDR = x;//address_r
	TWCR = (1<<TWINT) | (1<<TWEN);
	while( GET_BIT(TWCR,TWINT) ==0 );
	
	//read data
	TWCR = (1<<TWINT) | (1<<TWEN) ;
	while( GET_BIT(TWCR,TWINT) ==0 );
	*byte = TWDR;

	
	//send stop
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
	
	
	
}