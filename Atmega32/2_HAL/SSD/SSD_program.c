/*
 * SSD_program.c
 *
 *      Author: Mai Nasser
 *      Layer:HAL
 *      SWC:SSD
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

static u8 Local_u8SSDNumbers[10] = SSD_NUMBER_ARR ;


void SSD_voidInitialDataPort  (SSD_Type Copy_structConfig )
{
	DIO_VoidSetPortDirection( Copy_structConfig.DataPort , 0xFF );
}


void SSD_voidSendNumber( SSD_Type Copy_structConfig , u8 Copy_u8Number ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_VoidSetPortValue( Copy_structConfig.DataPort , Local_u8SSDNumbers[ Copy_u8Number ] );

	}else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_VoidSetPortValue( Copy_structConfig.DataPort , ~( Local_u8SSDNumbers[ Copy_u8Number ] ) );

	}

}


void SSD_voidEnable    ( SSD_Type Copy_structConfig ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_VoidSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_HIGH );
		DIO_VoidSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_LOW );

	}else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_VoidSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_HIGH );
		DIO_VoidSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_HIGH );

	}

}


void SSD_voidDisable   ( SSD_Type Copy_structConfig ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_VoidSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_HIGH );
		DIO_VoidSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_HIGH );

	}
	else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_VoidSetPinDirection( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_HIGH );
		DIO_VoidSetPinValue( Copy_structConfig.EnablePort , Copy_structConfig.EnablePin , DIO_PIN_LOW );

	}

}
