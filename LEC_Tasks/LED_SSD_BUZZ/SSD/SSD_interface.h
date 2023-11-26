/*
 * SSD.interface.h
 *
 *      Author: Mai Nasser
 *      Layer:HAL
 *      SWC:SSD
 */

#ifndef SSD_SSD_INTERFACE_H_
#define SSD_SSD_INTERFACE_H_

#define SSD_COMMON_CATHODE  0
#define SSD_COMMON_ANODE    1

// Port Defines
#define  SSD_PORTA  0
#define  SSD_PORTB  1
#define  SSD_PORTC  2
#define  SSD_PORTD  3

// PIN Defines
#define SSD_PIN0   0
#define SSD_PIN1   1
#define SSD_PIN2   2
#define SSD_PIN3   3
#define SSD_PIN4   4
#define SSD_PIN5   5
#define SSD_PIN6   6
#define SSD_PIN7   7

typedef struct{

	u8 Type       ;
	u8 DataPort   ;
	u8 EnablePort ;
	u8 EnablePin  ;

}SSD_Type;

void SSD_voidInitialDataPort  ( SSD_Type Copy_structConfig );
void SSD_voidEnable           ( SSD_Type Copy_structConfig );
void SSD_voidDisable          ( SSD_Type Copy_structConfig );
void SSD_voidSendNumber       ( SSD_Type Copy_structConfig , u8 Copy_u8Number );
void SSD_voidTurnSegment      ( SSD_Type Copy_structConfig , u8 Copy_u8SegNumber );

#endif /* SSD_SSD_INTERFACE_H_ */
