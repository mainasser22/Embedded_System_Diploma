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

#include"util/delay.h"

SSD_Type ssd1= {SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN0};

int main(void)
{
	SSD_voidInitialDataPort(ssd1);
	SSD_voidEnable(ssd1);
	while(1){
		for (u8 i=0 ; i<10 ;i++ )
		{
			SSD_voidSendNumber( ssd1, i );
			_delay_ms(250);
		}

		for (u8 i=0 ; i<10 ;i++ )
		{
			SSD_voidSendNumber( ssd1, 9-i );
			_delay_ms(250);
		}
	}

}

