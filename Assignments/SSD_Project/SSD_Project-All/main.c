/*
 * main.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Mai Nasser
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include"DIO/DIO_interface.h"
#include "SSD/SSD_interface.h"
#include "SW/SW_interface.h"


#include"util/delay.h"

SSD_Type ssd1= {SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN0};
SSD_Type ssd2= {SSD_COMMON_CATHODE,SSD_PORTD,SSD_PORTD,SSD_PIN0};
SW_Type SW1 = {DIO_PORTB,DIO_PIN0,SW_Int_PULL_UP};

void NUM_09_90();
void NUM_099();
void Move_a_f();
void Click_CountUp0to9();

s8 count=0;

int main(void)
{
	SSD_voidInitialDataPort  ( ssd1 );
	SSD_voidInitialDataPort  ( ssd2 );
	SW_voidInit(SW1);
	SSD_voidEnable( ssd1 );


	while(1){
		Click_CountUp0to9();
	}


}
void NUM_09_90(){
	for (u8 i=0 ; i<10 ;i++ )
	{
		SSD_voidSendNumber( ssd1, i );
		_delay_ms(100);
	}

	for (u8 i=0 ; i<10 ;i++ )
	{
		SSD_voidSendNumber( ssd1, 9-i );
		_delay_ms(100);
	}
}
void NUM_099(){
	SSD_voidEnable( ssd2 );
	for (u8 i=0; i<10 ;i++ )
	{
		SSD_voidSendNumber(ssd2,i);
		for (u8 j=0 ; j<10 ;j++ )
		{
			SSD_voidSendNumber(ssd1, j);
			_delay_ms(100);
		}
	}

}
void Move_a_f()
{
	for (u8 i=0 ; i<6 ;i++ )
	{
		SSD_voidTurnSegment(ssd1, i);
		_delay_ms(30);
	}
}
void Click_CountUp0to9(){
	SSD_voidSendNumber( ssd1,count);
	if(SW_u8GetPressed(SW1)){
		count++;
		if(count>9)
			count=0;
		_delay_ms(30);
	}

}
