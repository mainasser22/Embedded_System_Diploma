/*
 * BIT_MATH.h
 *
 *      Author: Mai Nasser
 *      Layer:LIB
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLR_BIT(reg,bit) reg&=(~(1<<bit))
#define TOG_BIT(reg,bit) reg^=(1<<bit)
#define GET_BIT(reg,bit) (reg&(1<<bit))>>bit
#define IS_BIT_SET(reg,bit) (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit) !((reg&(1<<bit))>>bit)
#define ROR(reg,num) reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num) reg= (reg>>(REGISTER_SIZE-num))|(reg<<(num))


#endif /* LIB_BIT_MATH_H_ */
