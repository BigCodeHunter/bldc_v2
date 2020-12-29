/*
 * state_machine.c
 *
 *  Created on: Dec 28, 2020
 *      Author: yildi
 */

#include "state_machine.h"
#include "main.h"
#include "stdint.h"

enum states state=TURN_ON;
enum flags flag=STOP;

void run_state_machine(){

	switch(state){

	case TURN_ON:{
		state=init();
		break;
		}

	case INIT_COMPLETE:{
		state=idle();
		break;
	}

	case START_PENDING:{
		state=start_ramp();
		break;
	}

	case START_RAMP_ENDED:{
		state=run();
		break;
	}

	case STOP_PENDING:{
		state=stop_ramp();
		break;
	}

	case STOP_RAMP_ENDED:{
		state=stop();
		break;
		}

	case STOP_PROCESS_ENDED:{
		state=idle();
		break;
	}

	case FAULT_EVENT:{
		state=fault();
		break;
		}

	case FAULT_RESET:{
		state=idle();
		break;
		}

	}

}

uint8_t init(){
	__NOP();
	return 0;
}

uint8_t idle(){
	__NOP();
	return 0;
}
