/*
 * DIO_program.c
 *
 *      Author: Mai Nasser
 *      Layer:MCAL
 *      SWC:DIO/GPIO
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_VoidSetPinDirection(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Direction)
{
  if(Copy_u8Direction== DIO_PIN_OUTPUT )
  {
	  switch (Copy_u8PORT)
	  {
	    case DIO_PORTB: SET_BIT(DDRB,Copy_u8PIN); break;
	    case DIO_PORTA: SET_BIT(DDRA,Copy_u8PIN); break;
	    case DIO_PORTC: SET_BIT(DDRC,Copy_u8PIN); break;
	    case DIO_PORTD: SET_BIT(DDRD,Copy_u8PIN); break;
	  }
  }
  else if(Copy_u8Direction== DIO_PIN_INPUT)
  {
	  switch (Copy_u8PORT)
	  {
	  	case DIO_PORTB: CLR_BIT(DDRB,Copy_u8PIN); break;
	        case DIO_PORTA: CLR_BIT(DDRA,Copy_u8PIN); break;
	  	case DIO_PORTC: CLR_BIT(DDRC,Copy_u8PIN); break;
	  	case DIO_PORTD: CLR_BIT(DDRD,Copy_u8PIN); break;
	  }
  }
}
void DIO_VoidSetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Value)
{
	if(Copy_u8Value== DIO_PIN_HIGH )
	  {
		  switch (Copy_u8PORT)
		  {
		  	case DIO_PORTB: SET_BIT(PORTB,Copy_u8PIN); break;
		  	case DIO_PORTA: SET_BIT(PORTA,Copy_u8PIN); break;
		        case DIO_PORTC: SET_BIT(PORTC,Copy_u8PIN); break;
		        case DIO_PORTC: SET_BIT(PORTC,Copy_u8PIN); break;
		  	case DIO_PORTD: SET_BIT(PORTD,Copy_u8PIN); break;
		  }
	  }
	  else if(Copy_u8Value== DIO_PIN_LOW)
	  {
		  switch (Copy_u8PORT)
		  {
		  	 case DIO_PORTB: CLR_BIT(PORTB,Copy_u8PIN); break;
		  	 case DIO_PORTA: CLR_BIT(PORTA,Copy_u8PIN); break;
		  	 case DIO_PORTC: CLR_BIT(PORTC,Copy_u8PIN); break;
		  	 case DIO_PORTD: CLR_BIT(PORTD,Copy_u8PIN); break;
		  }
	  }

}

void DIO_VoidTogglePinValue(u8 Copy_u8PORT,u8 Copy_u8PIN)
{
	switch (Copy_u8PORT)
       {
           case DIO_PORTB: TOG_BIT(PORTB,Copy_u8PIN); break;
	   case DIO_PORTA: TOG_BIT(PORTA,Copy_u8PIN); break;
	   case DIO_PORTC: TOG_BIT(PORTC,Copy_u8PIN); break;
	   case DIO_PORTD: TOG_BIT(PORTD,Copy_u8PIN); break;
       }
}

u8 DIO_VoidGetPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN)
{
	u8 PIN_u8Value=0;
	switch (Copy_u8PORT)
	{
	   case DIO_PORTB: PIN_u8Value=GET_BIT(PINB,Copy_u8PIN); break;
	   case DIO_PORTA: PIN_u8Value=GET_BIT(PINA,Copy_u8PIN); break;
	   case DIO_PORTC: PIN_u8Value=GET_BIT(PINC,Copy_u8PIN); break;
	   case DIO_PORTD: PIN_u8Value=GET_BIT(PIND,Copy_u8PIN); break;
        }
	return PIN_u8Value;
}

void DIO_VoidSetPortDirection(u8 Copy_u8PORT,u8 Copy_u8Direction)
{
	switch (Copy_u8PORT)
		{
		   case DIO_PORTB: DDRB=Copy_u8Direction; break;
		   case DIO_PORTA: DDRA=Copy_u8Direction; break;
		   case DIO_PORTC: DDRC=Copy_u8Direction; break;
		   case DIO_PORTD: DDRD=Copy_u8Direction; break;
	        }

}
void DIO_VoidSetPortValue(u8 Copy_u8PORT,u8 Copy_u8Value)
{
	switch (Copy_u8PORT)
	{
	    case DIO_PORTB: PORTB=Copy_u8Value; break;
	    case DIO_PORTA: PORTA=Copy_u8Value; break;
	    case DIO_PORTC: PORTC=Copy_u8Value; break;
	    case DIO_PORTD: PORTD=Copy_u8Value; break;
        }
}
void DIO_VoidTogglePortValue(u8 Copy_u8PORT)
{
	switch (Copy_u8PORT)
	{
	    case DIO_PORTB: PORTB=~PORTB; break;
	    case DIO_PORTA: PORTA=~PORTA; break;
	    case DIO_PORTC: PORTC=~PORTC; break;
	    case DIO_PORTD: PORTD=~PORTD; break;
        }
}
u8   DIO_VoidGetPortValue(u8 Copy_u8PORT)
{
	u8 PIN_u8Value=0;
		switch (Copy_u8PORT)
		{
		   case DIO_PORTB: PIN_u8Value=PINB; break;
		   case DIO_PORTA: PIN_u8Value=PINA; break;
		   case DIO_PORTC: PIN_u8Value=PINC; break;
		   case DIO_PORTD: PIN_u8Value=PIND; break;
	        }
		return PIN_u8Value;
}
