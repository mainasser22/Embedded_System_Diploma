/*
 * LED_program.c
 *
 *      Author: Mai Nasser
 *      Layer:HAL
 *      SWC:LED
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../DIO/DIO_interface.h"
#include "LED_interface.h"

void LED_voidInit(LED_Type LED_Config)
{

	DIO_VoidSetPinDirection( LED_Config.Port , LED_Config.Pin , DIO_PIN_OUTPUT);

}

void LED_voidOn(LED_Type LED_Config)
{

	if(LED_Config.Active_State == ACTIVE_HIGH ){

		DIO_VoidSetPinValue(LED_Config.Port ,LED_Config.Pin ,DIO_PIN_HIGH);

	}else if(LED_Config.Active_State == ACTIVE_LOW ){

		DIO_VoidSetPinValue(LED_Config.Port ,LED_Config.Pin ,DIO_PIN_LOW);

	}

}

void LED_voidOff(LED_Type LED_Config)
{

	if(LED_Config.Active_State == ACTIVE_HIGH ){

		DIO_VoidSetPinValue(LED_Config.Port ,LED_Config.Pin ,DIO_PIN_LOW);

	}else if(LED_Config.Active_State == ACTIVE_LOW ){

		DIO_VoidSetPinValue(LED_Config.Port ,LED_Config.Pin ,DIO_PIN_HIGH);

	}

}

void LED_voidToggle( LED_Type LED_Config)
{
	DIO_VoidTogglePinValue( LED_Config.Port , LED_Config.Pin );
}

