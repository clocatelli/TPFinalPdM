/*=============================================================================
 * Copyright (c) 2020, Cristian Locatelli <cristian.angel.locatelli@gmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE.txt)
 * Date: 2020/12/06
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "FSM_RW.h"
#include "sb_GPIO.h"
#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();
   entryState();
   entryStateButton(TEC1); // @suppress("Symbol is not resolved")
   initSPI();

	delay_t actualizarFSM;
	delayInit(&actualizarFSM, 30);
   // ----- Repeat for ever -------------------------
   while( true ) { // @suppress("Symbol is not resolved")
	    if(delayRead(&actualizarFSM) ){
	    	FSM_State();
	    }
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
