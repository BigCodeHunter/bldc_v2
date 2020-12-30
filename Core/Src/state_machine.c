/*
 * state_machine.c
 *
 *  Created on: Dec 28, 2020
 *      Author: yildi
 */

#include "state_machine.h"
#include "main.h"
#include "stdint.h"

enum states event=TURN_ON;
enum flags flag=STOP;

uint8_t init(){

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);

	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,0);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_2,0);
	__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_3,0);

	HAL_ADC_Start_DMA(&hadc, (uint32_t*)adc_buffer, 5);

	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_6, GPIO_PIN_RESET); // OverCurrent comparator threshold=100mV , 20A
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET); // 3FG function disabled

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);  // OverCurrent protection enabled, (OC_SEL)

	GPIOB->ODR &= 0x01FF;  // PB13-14-15 turned off

	return INIT_COMPLETE;

}

uint8_t idle();

uint8_t start_ramp();

uint8_t run();

void run_state_machine(){

	switch(event){

		case TURN_ON:{
			event=init();
			break;
			}

		case INIT_COMPLETE:{
			event=idle();
			break;
		}

		case START_REQUEST:{
			event=start_ramp();
			break;
		}

		case START_RAMP_ENDED:{
			event=run();
			break;
		}

		case STOP_REQUEST:{
			event=stop_ramp();
			break;
		}

		case STOP_RAMP_ENDED:{
			event=stop();
			break;
			}

		case STOP_PROCESS_ENDED:{
			event=idle();
			break;
		}

		case DIR_REQUEST:{
			event=stop_ramp();
			break;
		}

	}

}

