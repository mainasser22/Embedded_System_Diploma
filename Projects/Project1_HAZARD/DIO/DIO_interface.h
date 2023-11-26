/*
 * DIO_interface.h
 *
 *      Author: Mai Nasser
 *      Layer:MCAL
 *      SWC:DIO/GPIO
 */

#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_

// PIN Directions
#define  DIO_PIN_OUTPUT 1
#define  DIO_PIN_INPUT 0

// PIN Value
#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW	 0

// PORT Directions
#define DIO_PORT_OUTPUT		0xFF
#define DIO_PORT_INPUT		0

// PORT Value
#define DIO_PORT_HIGH 		0xFF
#define DIO_PORT_LOW  		0

// Port Defines
#define  DIO_PORTA  0
#define  DIO_PORTB  1
#define  DIO_PORTC  2
#define  DIO_PORTD  3

// PIN Defines
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

//Pull UP
#define PUD   2

//IO Pins
void DIO_VoidSetPinDirection(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Direction);
void DIO_VoidSetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Value);
void DIO_VoidTogglePinValue(u8 Copy_u8PORT,u8 Copy_u8PIN);
u8   DIO_VoidGetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN);

//IO Ports
void DIO_VoidSetPortDirection(u8 Copy_u8PORT,u8 Copy_u8Direction);
void DIO_VoidSetPortValue(u8 Copy_u8PORT,u8 Copy_u8Value);
void DIO_VoidTogglePortValue(u8 Copy_u8PORT);
u8   DIO_VoidGetPortValue(u8 Copy_u8PORT);

//Low Nibbles = Least Pins [0:3]
void DIO_voidWriteLowNibbles(u8 Copy_u8PORT,u8 Copy_u8value);
//High Nibbles = Most Pins [4:7]
void DIO_voidWriteHighNibbles(u8 Copy_u8PORT,u8 Copy_u8value);


#endif /* DIO_DIO_INTERFACE_H_ */
