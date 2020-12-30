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

extern uint16_t adc_buffer[5],adc[5];
extern uint16_t duty,speed,pot;
extern uint8_t hall_input,dir;

extern ADC_HandleTypeDef hadc;
extern DMA_HandleTypeDef hdma_adc;
extern TIM_HandleTypeDef htim1;
extern UART_HandleTypeDef huart1;

/*
 *  "flags" ve "states" enumları "state_machine.c" dosyasındaki fonsiyonlar için
 *  kullanılacak olan durumları tanımlayan global değişkenlerdir.
 */

enum flags{
	_IDLE,
	_START,
	_STOP,
	_FAULT
};

enum states{
	INIT,
	IDLE,
	START_RAMP,
	RUN,
	STOP_RAMP,
	STOP,
	SWITCH_DIR,
	FAULT
};

enum events{
	TURN_ON,
	INIT_COMPLETE,
	START_REQUEST,
	START_RAMP_ENDED,
	STOP_REQUEST,
	STOP_RAMP_ENDED,
	STOP_PROCESS_ENDED,
	DIR_REQUEST,
	DIR_SWITCHED,
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


