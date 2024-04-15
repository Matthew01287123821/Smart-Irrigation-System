/*
 * BIT_MATH.h
 *
 * Created: 2/2/2024 7:17:12 PM
 *  Author: mathe
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(x,bitNumber)   x=x|(1<<bitNumber)

#define CLEAR_BIT(x,bitNumber) x=x&(~(1<<bitNumber))

#define TOGGLE(x,bitNumber)		x=x^(1<<bitNumber)

#define GET_BIT(x,bitNumber)	((x>>bitNumber)&1)






#endif /* BIT_MATH_H_ */