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
SSD_Type ssd2= {SSD_COMMON_CATHODE,SSD_PORTD,SSD_PORTD,SSD_PIN0};

int main(void)
{
	SSD_voidInitialDataPort(ssd1);
	SSD_voidInitialDataPort( ssd2 );
	SSD_voidEnable( ssd1 );
	SSD_voidEnable( ssd2 );
	while(1){

			for (u8 i=0; i<10 ;i++ )
			{
				SSD_voidSendNumber(ssd2,i);
				for (u8 j=0 ; j<10 ;j++ )
				{
					SSD_voidSendNumber(ssd1, j);
					_delay_ms(250);
				}
			}
	}

}

