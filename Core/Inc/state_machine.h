/*
 * state_machine.h
 *
 *  Created on: Dec 28, 2020
 *      Author: yildi
 */

#ifndef INC_STATE_MACHINE_H_
#define INC_STATE_MACHINE_H_

#include "main.h"
#include "stdint.h"

/*
 *  "flags" ve "states" enumları "state_machine.c" dosyasındaki fonsiyonlar için
 *  kullanılacak olan durumları tanımlayan global değişkenlerdir.
 */

enum flags{
	START,
	STOP
};

enum states{
	TURN_ON,
	INIT_COMPLETE,
	START_PENDING,
	START_RAMP_ENDED,
	STOP_PENDING,
	STOP_RAMP_ENDED,
	STOP_PROCESS_ENDED,
	FAULT_EVENT,
	FAULT_RESET
};

void run_state_machine();
uint8_t init();
uint8_t idle();
uint8_t start_ramp();
uint8_t run();
uint8_t stop_ramp();
uint8_t stop();
uint8_t fault();

#endif /* INC_STATE_MACHINE_H_ */


