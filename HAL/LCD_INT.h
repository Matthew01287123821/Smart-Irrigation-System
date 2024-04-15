/*
 * LCD_INT.h
 *
 * Created: 30/01/2024 06:10:56 PM
 *  Author: AMIT
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_

//Config
// choose 4 or 8
#define LCD_MODE  4

#define LCD_D0    DIO_PINA0
#define LCD_D1    DIO_PINA1
#define LCD_D2    DIO_PINA2
#define LCD_D3    DIO_PINA3

#define LCD_D4    DIO_PINA4
#define LCD_D5    DIO_PINA5
#define LCD_D6    DIO_PINA6
#define LCD_D7    DIO_PINA7

#define LCD_RS	DIO_PINB1
#define LCD_RW	DIO_PINB2
#define LCD_E	DIO_PINB3



//macros
#define LCD_CLEAR_CMD	0b00000001
#define LCD_ENTRY_MODE_CMD 0b00000110

void LCD_init();

void LCD_clearDis();

void LCD_writeChar(u8 data);

void LCD_writeCmd(u8 data);

void LCD_writeStr( u8* str );

void LCD_writeNum(s32 num);

void LCD_goto(u8 x, u8 y);

void LCD_createNewChar(u8* arr);
void LCD_writeNewChar(u8 location);

void LCD_shiftDis();


#endif /* LCD_INT_H_ */