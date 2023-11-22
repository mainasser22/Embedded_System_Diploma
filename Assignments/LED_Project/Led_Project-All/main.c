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

	while(1)
	{
		TwoLedsConvergeDivergeEvery250ms ();
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
