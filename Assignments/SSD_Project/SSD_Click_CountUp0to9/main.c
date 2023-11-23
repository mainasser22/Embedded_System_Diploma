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
SW_Type SW1 = {DIO_PORTB,DIO_PIN0,SW_Int_PULL_UP};

s8 count=0;

int main(void)
{
	SSD_voidInitialDataPort  ( ssd1 );
	SW_voidInit(SW1);
	SSD_voidEnable( ssd1 );


	while(1){
		SSD_voidSendNumber( ssd1,count);
		if(SW_u8GetPressed(SW1)){
			count++;
			if(count>9)
				count=0;
			_delay_ms(30);
		}
	}


}

