/******************************************************************************/
/*                                                                            */
/* !Layer           : Application Abstraction Layer                           */
/*                                                                            */
/* !Component       : MODE                                                    */
/* !Description     : Hazzard Indicator Function module                       */
/*                                                                            */
/* !Module          : MODE                                                    */
/* !Description     : MODE Module interface                                   */
/*                                                                            */
/* !File            : mode_prg.c                                              */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Induction training exercise project                     */
/*                                                                            */
/* !Target          : ATMega32                                                */
/*                                                                            */
/* !Compiler        : AVR GCC Cross Compiler                                  */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Coded by        : Mai Nasser                      !Date : NOV 25, 2023    */
/*                                                                            */
/******************************************************************************/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "SSD/SSD_interface.h"
#include "SW/SW_interface.h"
#include "CLCD/CLCD_interface.h"



#include "mode_int.h"



/******************************************************************************/

/* Global Variables Definition */
MODE_enutModeState MODE_STATE,PRE_STATE;

/*****************************************************************************************/
extern SSD_Type R_SSD ;
extern SSD_Type L_SSD ;

extern SW_Type R_SW ;
extern SW_Type L_SW ;
extern SW_Type H_SW ;
/*****************************************************************************************/

/******************************************************************************/
/*! \Description Helper Functions                                             */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void APP_vidSetMode(MODE_enutModeState enutSetMode)
{
	switch(enutSetMode)
	{
	case IDLE:
		SSD_voidDisable(R_SSD);
		SSD_voidDisable(L_SSD);
		CLCD_voidSendString((u8*)"IDLE Mode");
		break;
	case RIGHT_BLINK:
		SSD_voidDisable(L_SSD);
		SSD_voidEnable(R_SSD);
		SSD_voidSendNumber( R_SSD,0);
		CLCD_voidSendString((u8*)"RIGHT Mode");
		break;
	case HAZZARD_BLINK:
		SSD_voidEnable(L_SSD);
		SSD_voidEnable(R_SSD);
		SSD_voidSendNumber( L_SSD,0);
		SSD_voidSendNumber( R_SSD,0);
		CLCD_voidSendString((u8*)"HAZZARD Mode");
		break;
	case LEFT_BLINK:
		SSD_voidDisable(R_SSD);
		SSD_voidEnable(L_SSD);
		SSD_voidSendNumber( L_SSD,0);
		CLCD_voidSendString((u8*)"LEFT Mode");
		break;

	}

}

/***************************************/
void MODE_vidIdle (void)
{
	/* Set Mode to IDLE */
	APP_vidSetMode(IDLE);
	/* Check the SWs */
	if (SW_u8GetPressed (R_SW))
	{
		MODE_STATE=RIGHT_BLINK;
	}
	else if (SW_u8GetPressed (H_SW))
	{
		MODE_STATE=HAZZARD_BLINK;
		PRE_STATE=IDLE;
	}
	else if (SW_u8GetPressed (L_SW))
	{
		MODE_STATE=LEFT_BLINK;
	}


}
void MODE_vidRightBlink (void)
{
	/* Set Mode to RIGHT_BLINK */

	APP_vidSetMode(RIGHT_BLINK);
	/* Check the SWs */
/*   if (SW_u8GetPressed (R_SW))
	{
		MODE_STATE=RIGHT_BLINK;
	}
	else*/ if (SW_u8GetPressed (H_SW))
	{
		MODE_STATE=HAZZARD_BLINK;
		PRE_STATE=RIGHT_BLINK;
	}
	else if (SW_u8GetPressed (L_SW))
	{
		MODE_STATE=IDLE;
	}
}
void MODE_vidLeftBlink (void)
{
	/* Set Mode to LEFT_BLINK */
	APP_vidSetMode(LEFT_BLINK);
	/* Check the SWs */
	if (SW_u8GetPressed (R_SW))
	{
		MODE_STATE=IDLE;
	}
	else if (SW_u8GetPressed (H_SW))
	{
		MODE_STATE=HAZZARD_BLINK;
		PRE_STATE=LEFT_BLINK;
	}
/*	else if (SW_u8GetPressed (L_SW))
	{
		MODE_STATE=LEFT_BLINK;
	}*/

}
void MODE_vidHazardBlink (void)
{
	/* Set Mode to HAZZARD_BLINK */

	APP_vidSetMode(HAZZARD_BLINK);
	/* Check the SWs */
/*	if (SW_u8GetPressed (R_SW))
	{
		MODE_STATE=HAZZARD_BLINK;
	}
	else */ if (SW_u8GetPressed (H_SW))
	{
		MODE_STATE=PRE_STATE;
	}
/*	else if (SW_u8GetPressed (L_SW))
	{
		MODE_STATE=HAZZARD_BLINK;
	}
*/
}


/*****************************************************************************************/

/******************************************************************************/
/*! \Description Initialize the MODE driver variables                         */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void MODE_vidInit(void)
{
	/* Set Mode to Default (IDLE) */
	APP_vidSetMode(IDLE);
	MODE_STATE=IDLE;
}

/******************************************************************************/
/*! \Description The MODE driver task, should be called periodically.
				 This service update the state of all configured push
                 buttons.                                                     */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void MODE_vidTask(void)
{
	/* Check the global enum then call Mode API According to it */

     switch(MODE_STATE)
	{
	case IDLE:
		MODE_vidIdle ();
		break;
	case RIGHT_BLINK:
		MODE_vidRightBlink ();
		break;
	case HAZZARD_BLINK:
		MODE_vidHazardBlink();
		break;
	case LEFT_BLINK:
		MODE_vidLeftBlink();
		break;

	}
/*

  	if (MODE_STATE == IDLE )
		MODE_vidIdle ();
	else if(MODE_STATE == RIGHT_BLINK)
		MODE_vidRightBlink ();
	else if(MODE_STATE == HAZZARD_BLINK)
		MODE_vidHazardBlink();
	else if(MODE_STATE == LEFT_BLINK)
		MODE_vidLeftBlink();

*/


}

/**********************************************************************************************/
