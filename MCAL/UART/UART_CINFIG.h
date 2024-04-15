/*
 * UART_CINFIG.h
 *
 * Created: 2/24/2024 9:14:15 PM
 *  Author: mathe
 */ 


#ifndef UART_CINFIG_H_
#define UART_CINFIG_H_

#define	UART_5BIT_MODE 		5
#define	UART_6BIT_MODE 		6
#define	UART_7BIT_MODE 		7
#define	UART_8BIT_MODE 		8
#define	UART_9BIT_MODE 		9

#define UART_NUM_BIT_MODE   UART_8BIT_MODE

#define	UART_STOP_1BIT  1
#define	UART_STOP_2BIT  2

#define UART_NUM_STOP_BIT  UART_STOP_1BIT

#define	UART_PARITY_DISABLED 0
#define	UART_PARITY_EVEN     1
#define	UART_PARITY_ODD      2

#define UART_PARITY_MODE    UART_PARITY_DISABLED

//Buad for 16M
#define  UART_BAUD_2400  416
#define  UART_BAUD_4800  207
#define  UART_BAUD_9600  103
#define  UART_BAUD_14400  68
#define  UART_BAUD_19200  51
#define  UART_BAUD_28800  34
#define  UART_BAUD_38400  25
#define  UART_BAUD_57600  16
#define  UART_BAUD_76800  12
#define  UART_BAUD_115200  8
#define  UART_BAUD_230400  3
#define  UART_BAUD_250000  3
#define  UART_BAUD_500000  1
#define  UART_BAUD_1000000  0

#define UART_BAUD_RATE  UART_BAUD_9600

#define UART_NOT_RECEIVED 'x'



#endif /* UART_CINFIG_H_ */