/*
 * main.c
 *
 *  Created on: Nov 15, 2023
 *      Author: Mai Nasser
 */
#include"LIB/BIT_MATH.h"
#include"LIB/STD_TYPES.h"

#include"DIO/DIO_interface.h"
#include"LED/LED_interface.h"
#include"util/delay.h"

LED_Type Leds[8]={
		{LED_PORTA,LED_PIN0,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN1,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN2,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN3,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN4,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN5,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN6,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN7,ACTIVE_HIGH},
};

int main(void){

	for(u8 i=0;i<8;i++)
	{
		LED_voidInit(Leds[i]);
	}

	while(1)
	{
		for(u8 i=0;i<4;i++)
				{
					LED_voidOn(Leds[i]);
					LED_voidOn(Leds[7-i]);
					_delay_ms(250);
					LED_voidOff(Leds[i]);
					LED_voidOff(Leds[7-i]);
				}
			for(u8 i=0;i<4;i++)
				{
					LED_voidOn(Leds[3-i]);
					LED_voidOn(Leds[4+i]);
					_delay_ms(250);
					LED_voidOff(Leds[3-i]);
					LED_voidOff(Leds[4+i]);
				}
			_delay_ms(250);
	}

}
