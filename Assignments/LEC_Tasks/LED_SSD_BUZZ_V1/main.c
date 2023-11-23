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
SSD_Type SSD1  = {SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN0};
BUZZ_Type Buzz1 = {BUZZ_PORTD,BUZZ_PIN0,ACTIVE_HIGH};
int main(void)
{
	for(u8 i=0;i<8;i++)
		{
			LED_voidInit(Leds[i]);
		}
	SSD_voidInitialDataPort  ( SSD1 );
	BUZZ_voidInit(Buzz1);

	SSD_voidEnable( SSD1 );

	u8 count=0;

	while(1){

		switch(count)
		{
		case 0:
			BUZZ_voidOff(Buzz1);
			SSD_voidSendNumber(SSD1,0);
			count++;
			_delay_ms(100);
			break;

		case 1:
			SSD_voidSendNumber(SSD1,1);
			LED_voidOn(Leds[0]);
			_delay_ms(100);
			count++;
			break;

		case 2:
			SSD_voidSendNumber(SSD1,2);
			LED_voidOn(Leds[1]);
			_delay_ms(100);
			count++;
			break;
		case 3:
			SSD_voidSendNumber(SSD1,3);
			LED_voidOn(Leds[2]);
			_delay_ms(100);
			count++;
			break;
		case 4:
			SSD_voidSendNumber(SSD1,4);
			LED_voidOn(Leds[3]);
			_delay_ms(100);
			count++;
			break;
		case 5:
			SSD_voidSendNumber(SSD1,5);
			LED_voidOn(Leds[4]);
			count++;
			_delay_ms(100);
			break;

		case 6:
			SSD_voidSendNumber(SSD1,6);
			LED_voidOn(Leds[5]);
			_delay_ms(100);
			count++;
			break;

		case 7:
			SSD_voidSendNumber(SSD1,7);
			LED_voidOn(Leds[6]);
			_delay_ms(100);
			count++;
			break;

		case 8:
			SSD_voidSendNumber(SSD1,8);
			LED_voidOn(Leds[7]);
			BUZZ_voidOn(Buzz1);
			_delay_ms(100);
			count=0;
			for(u8 i=0;i<8;i++)
			{
				LED_voidOff(Leds[i]);
			}
			break;
		}

	}

}

