/*
 * BUZZ_interface.h
 *
 *      Author: Mai Nasser
 *      Layer:HAL
 *      SWC:BUZZ
 */

#ifndef HAL_BUZZ_BUZZ_INTERFACE_H_
#define HAL_BUZZ_BUZZ_INTERFACE_H_

// Port Defines
#define  BUZZ_PORTA  0
#define  BUZZ_PORTB  1
#define  BUZZ_PORTC  2
#define  BUZZ_PORTD  3


// PIN Defines
#define BUZZ_PIN0   0
#define BUZZ_PIN1   1
#define BUZZ_PIN2   2
#define BUZZ_PIN3   3
#define BUZZ_PIN4   4
#define BUZZ_PIN5   5
#define BUZZ_PIN6   6
#define BUZZ_PIN7   7

// PIN Status
#define ACTIVE_HIGH    1
#define ACTIVE_LOW     0

typedef struct{

	u8 Port         ;
	u8 Pin          ;
	u8 Active_State ;

}BUZZ_Type;


void BUZZ_voidInit (BUZZ_Type BUZZ_Config);

void BUZZ_voidOn   (BUZZ_Type BUZZ_Config);

void BUZZ_voidOff  (BUZZ_Type BUZZ_Config);

void BUZZ_voidToggle (BUZZ_Type BUZZ_Config);


#endif /* HAL_BUZZ_BUZZ_INTERFACE_H_ */
