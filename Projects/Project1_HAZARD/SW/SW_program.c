/*
 * SW.program.h
 *
 *      Author: Mai Nasser
 *      Layer:HAL
 *      SWC:SWITCH-BUTTON
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../DIO/DIO_interface.h"

#include "../SW/SW_config.h"
#include "../SW/SW_interface.h"
#include "../SW/SW_private.h"

void SW_voidInit(SW_Type SW_Config){

	DIO_VoidSetPinDirection( SW_Config.Port , SW_Config.Pin , DIO_PIN_INPUT );

	if( SW_Config.Pull_State == SW_Int_PULL_UP ){

		DIO_VoidSetPinValue( SW_Config.Port , SW_Config.Pin , DIO_PIN_HIGH  );

	}

}
u8   SW_u8GetPressed   ( SW_Type SW_Config ){

	u8 LOC_u8Result = SW_NOT_PRESSED ;
		u8 PIN_u8PinVal = SW_NOT_PRESSED ;

		if ( (SW_Config.Pull_State == SW_Int_PULL_UP) || (SW_Config.Pull_State == SW_Ext_PULL_UP) )
		{
			 PIN_u8PinVal= DIO_VoidGetPinValue( SW_Config.Port , SW_Config.Pin);

			if ( PIN_u8PinVal==0)
			{
				LOC_u8Result = SW_PRESSED ;
			}
			else if ( PIN_u8PinVal==1)
			{
				LOC_u8Result = SW_NOT_PRESSED ;
			}

		}
		else if (SW_Config.Pull_State == SW_Ext_PULL_DOWN)
		{
			 PIN_u8PinVal=DIO_VoidGetPinValue( SW_Config.Port , SW_Config.Pin);

			if ( PIN_u8PinVal==0)
			{
				LOC_u8Result = SW_NOT_PRESSED ;
			}
			else if ( PIN_u8PinVal==1)
			{
				LOC_u8Result = SW_PRESSED ;
			}
		}

		return LOC_u8Result ;
}

