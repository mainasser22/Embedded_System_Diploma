/*
 * BUZZ_program.c
 *
 *      Author: Mai Nasser
 *      Layer:HAL
 *      SWC:BUZZ
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"
#include "BUZZ_interface.h"

void BUZZ_voidInit(BUZZ_Type BUZZ_Config)
{

	DIO_VoidSetPinDirection( BUZZ_Config.Port , BUZZ_Config.Pin , DIO_PIN_OUTPUT);

}

void BUZZ_voidOn(BUZZ_Type BUZZ_Config)
{

	if(BUZZ_Config.Active_State == ACTIVE_HIGH ){

		DIO_VoidSetPinValue(BUZZ_Config.Port ,BUZZ_Config.Pin ,DIO_PIN_HIGH);

	}else if(BUZZ_Config.Active_State == ACTIVE_LOW ){

		DIO_VoidSetPinValue(BUZZ_Config.Port ,BUZZ_Config.Pin ,DIO_PIN_LOW);

	}

}

void BUZZ_voidOff(BUZZ_Type BUZZ_Config)
{

	if(BUZZ_Config.Active_State == ACTIVE_HIGH ){

		DIO_VoidSetPinValue(BUZZ_Config.Port ,BUZZ_Config.Pin ,DIO_PIN_LOW);

	}else if(BUZZ_Config.Active_State == ACTIVE_LOW ){

		DIO_VoidSetPinValue(BUZZ_Config.Port ,BUZZ_Config.Pin ,DIO_PIN_HIGH);

	}

}

void BUZZ_voidToggle( BUZZ_Type BUZZ_Config)
{
	DIO_VoidTogglePinValue( BUZZ_Config.Port , BUZZ_Config.Pin );
}

