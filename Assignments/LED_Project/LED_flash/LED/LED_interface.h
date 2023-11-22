/*
 * LED_interface.h
 *
 *      Author: Mai Nasser
 *      Layer:HAL
 *      SWC:LED
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

// Port Defines
#define  LED_PORTA  0
#define  LED_PORTB  1
#define  LED_PORTC  2
#define  LED_PORTD  3


// PIN Defines
#define LED_PIN0   0
#define LED_PIN1   1
#define LED_PIN2   2
#define LED_PIN3   3
#define LED_PIN4   4
#define LED_PIN5   5
#define LED_PIN6   6
#define LED_PIN7   7

// PIN Status
#define ACTIVE_HIGH    1
#define ACTIVE_LOW     0

typedef struct{

	u8 Port         ;
	u8 Pin          ;
	u8 Active_State ;

}LED_Type;


void LED_voidInit (LED_Type LED_Config);

void LED_voidOn   (LED_Type LED_Config);

void LED_voidOff  (LED_Type LED_Config);

void LED_voidToggle (LED_Type LED_Config);


#endif /* HAL_LED_LED_INTERFACE_H_ */
