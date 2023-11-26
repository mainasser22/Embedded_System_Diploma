/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    CLCD_config.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 ***********************************
 * Author  : Mai Nasser
 *  Layer  : HAL
 *  SWC    : CLCD
 ***********************************
 *
 */

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/***************************************************************************************/

#define CLCD_MODE  4   //or 8


/***************************************************************************************/

#define CLCD_DATA_PORT      DIO_PORTD   // or  DIO_PORTA, DIO_PORTB, DIO_PORTC

/* RS,RW,EN */
#define CLCD_CONTROL_PORT   DIO_PORTC   // or  DIO_PORTA, DIO_PORTB, DIO_PORTD

/***************************************************************************************/

#define CLCD_RS             DIO_PIN2   //or  DIO_PIN0, DIO_PIN1, DIO_PIN3, DIO_PIN4, DIO_PIN5, DIO_PIN6, DIO_PIN7
#define CLCD_RW             DIO_PIN3   //or  DIO_PIN0, DIO_PIN1, DIO_PIN2, DIO_PIN4, DIO_PIN5, DIO_PIN6, DIO_PIN7
#define CLCD_EN             DIO_PIN4   //or  DIO_PIN0, DIO_PIN1, DIO_PIN2, DIO_PIN3, DIO_PIN5, DIO_PIN6, DIO_PIN7

/***************************************************************************************/


#endif /* CLCD_CONFIG_H_ */
