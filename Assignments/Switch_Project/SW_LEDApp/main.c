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
#include"SW/SW_interface.h"

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
SW_Type SW[8] = {
		{SW_PORTB, LED_PIN0, SW_Ext_PULL_UP},
		{SW_PORTB, LED_PIN1, SW_Ext_PULL_UP},
		{SW_PORTB, LED_PIN2, SW_Ext_PULL_UP},
		{SW_PORTB, LED_PIN3, SW_Ext_PULL_UP},
		{SW_PORTB, LED_PIN4, SW_Ext_PULL_UP},
		{SW_PORTB, LED_PIN5, SW_Ext_PULL_UP},
		{SW_PORTB, LED_PIN6, SW_Ext_PULL_UP},
		{SW_PORTB, LED_PIN7, SW_Ext_PULL_UP}
};

void FlashingEvery1sec();
void ShiftingLeftEvery250ms();
void ShiftingRightEvery250ms();
void TwoLedsConvergingEvery250ms();
void TwoLedsDivergingEvery250ms();
void PingPongEffectEvery250ms();
void Incrementing_SnakeEffect_Every250();
void TwoLedsConvergeDivergeEvery250ms ();

int main(void){

	for(u8 i=0;i<8;i++)
	{
		LED_voidInit(Leds[i]);
	}

	for(u8 i=0;i<8;i++)
		{
			SW_voidInit    (SW[i]);
		}


	while(1)
	{

		for(u8 i=0;i<8;i++)
		{
			if (SW_u8GetPressed (SW[i])) {
				switch(i){
				case 0:
					FlashingEvery1sec();
					break;
				case 1:
					ShiftingLeftEvery250ms();
					break;
				case 2:
					ShiftingRightEvery250ms();
					break;
				case 3:
					TwoLedsConvergingEvery250ms();
					break;
				case 4:
					TwoLedsDivergingEvery250ms();
					break;
				case 5:
					PingPongEffectEvery250ms();
					break;
				case 6:
					Incrementing_SnakeEffect_Every250();
					break;
				case 7:
					TwoLedsConvergeDivergeEvery250ms ();
					break;

				}
			}
		}

	}

}
void FlashingEvery1sec(){

	for(u8 i=0;i<8;i++)
	{
		LED_voidOn(Leds[i]);
	}
	_delay_ms(1000);
	for(u8 i=0;i<8;i++)
	{
		LED_voidOff(Leds[i]);
	}
	_delay_ms(1000);
}
void ShiftingLeftEvery250ms(){
	for(u8 i=0;i<8;i++)
	{
		LED_voidOn(Leds[i]);
		_delay_ms(250);
		LED_voidOff(Leds[i]);
	}
}

void ShiftingRightEvery250ms(){
	for(u8 i=0;i<8;i++)
	{
		LED_voidOn     (Leds[7 - i]);
		_delay_ms(250);
		LED_voidOff     (Leds[7 - i]);
	}
}

void TwoLedsConvergingEvery250ms(){
	for(u8 i=0;i<4;i++)
	{
		LED_voidOn(Leds[i]);
		LED_voidOn(Leds[7-i]);
		_delay_ms(250);
		LED_voidOff(Leds[i]);
		LED_voidOff(Leds[7-i]);
	}
}

void TwoLedsDivergingEvery250ms(){
	for(u8 i=0;i<4;i++)
	{
		LED_voidOn(Leds[3-i]);
		LED_voidOn(Leds[4+i]);
		_delay_ms(250);
		LED_voidOff(Leds[3-i]);
		LED_voidOff(Leds[4+i]);
	}
}

void PingPongEffectEvery250ms(){
	for(u8 i=0;i<8;i++)
	{
		LED_voidOn(Leds[i]);
		_delay_ms(100);
		LED_voidOff(Leds[i]);
	}
	for(u8 i=0;i<8;i++)
		{
			LED_voidOn     (Leds[7 - i]);
			_delay_ms(100);
			LED_voidOff     (Leds[7 - i]);
		}
	_delay_ms(250);
}


void Incrementing_SnakeEffect_Every250(){
	for(u8 i=0;i<8;i++)
	{
		LED_voidOn(Leds[i]);
		_delay_ms(250);
	}
	for(u8 i=0;i<8;i++)
	{
		LED_voidOff(Leds[i]);
	}
	_delay_ms(250);
}
void TwoLedsConvergeDivergeEvery250ms () {
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
