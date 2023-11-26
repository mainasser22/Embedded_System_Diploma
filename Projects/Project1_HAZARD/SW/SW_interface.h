/*
 * SW.interface.h
 *
 *      Author: Mai Nasser
 *      Layer:HAL
 *      SWC:SWITCH-BUTTON
 */

#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H

// Port Defines
#define  SW_PORTA  0
#define  SW_PORTB  1
#define  SW_PORTC  2
#define  SW_PORTD  3

// PIN Defines
#define SW_PIN0   0
#define SW_PIN1   1
#define SW_PIN2   2
#define SW_PIN3   3
#define SW_PIN4   4
#define SW_PIN5   5
#define SW_PIN6   6
#define SW_PIN7   7

// Switch status
#define SW_PRESSED     1
#define SW_NOT_PRESSED 0

// PULL_State
#define SW_Int_PULL_UP     0
#define SW_Ext_PULL_UP     1
#define SW_Ext_PULL_DOWN   2
#define SW_FLOATING        3

typedef struct{

	u8 Port;
	u8 Pin ;
	u8 Pull_State;

}SW_Type;

void SW_voidInit       ( SW_Type SW_Config );
u8   SW_u8GetPressed   ( SW_Type SW_Config );

#endif
