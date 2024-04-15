/*
 * SS_INT.h
 *
 * Created: 2/10/2024 10:00:08 PM
 *  Author: mathe
 */ 


#ifndef SS_INT_H_
#define SS_INT_H_
//Config
#define SS_E1   DIO_PINB2
#define SS_E2   DIO_PINB1

#define SS_S0	DIO_PINA4
#define SS_S1	DIO_PINA5
#define SS_S2	DIO_PINA6
#define SS_S3	DIO_PINA7

//#define SS_PORT PORTA


void SS_init();

void SS_setEnable1();
void SS_setEnable2();

void SS_setDisable1();
void SS_setDisable2();

void SS_writeNumber(u8 num);




#endif /* SS_INT_H_ */