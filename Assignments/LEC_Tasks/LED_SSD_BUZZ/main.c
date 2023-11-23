/*
 * main.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Nasser
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include<util/delay.h>

#include "DIO/DIO_interface.h"
#include "SSD/SSD_interface.h"
#include "LED/LED_interface.h"
#include "BUZZ/BUZZ_interface.h"

SSD_Type SSD = {SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN0};
LED_Type LEDS[8] = {{LED_PORTA,LED_PIN0,ACTIVE_HIGH},{LED_PORTA,LED_PIN1,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN2,ACTIVE_HIGH},{LED_PORTA,LED_PIN3,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN4,ACTIVE_HIGH},{LED_PORTA,LED_PIN5,ACTIVE_HIGH},
		{LED_PORTA,LED_PIN6,ACTIVE_HIGH},{LED_PORTA,LED_PIN7,ACTIVE_HIGH}};
BUZZ_Type BUZZ = {BUZZ_PORTD,BUZZ_PIN0,ACTIVE_HIGH};

void main ()
{
	SSD_voidInitialDataPort(SSD);
	SSD_voidEnable(SSD);
	for (int i=0 ; i<8 ; i++)
	{
		LED_voidInit(LEDS[i]);
	}
	BUZZ_voidInit(BUZZ);


	while(1)
	{

		for (u8 i=0 ; i<9 ; i++)
		{
			if (i==0)
			{
				for (u8 j=0 ; j<8 ; j++)
				{
					LED_voidOff(LEDS[j]);
				}
				BUZZ_voidOff(BUZZ);
				SSD_voidSendNumber(SSD,i);
				_delay_ms(100);
				continue;
			}

			LED_voidOn(LEDS[i-1]);
			SSD_voidSendNumber(SSD,i);
			if (i==8)
			{
				BUZZ_voidOn(BUZZ);
			}
			_delay_ms(100);
		}
	}
}
