/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define user1_Pin GPIO_PIN_0
#define user1_GPIO_Port GPIOF
#define user2_Pin GPIO_PIN_1
#define user2_GPIO_Port GPIOF
#define hall1_Pin GPIO_PIN_0
#define hall1_GPIO_Port GPIOA
#define hall1_EXTI_IRQn EXTI0_1_IRQn
#define hall2_Pin GPIO_PIN_1
#define hall2_GPIO_Port GPIOA
#define hall2_EXTI_IRQn EXTI0_1_IRQn
#define hall3_Pin GPIO_PIN_2
#define hall3_GPIO_Port GPIOA
#define hall3_EXTI_IRQn EXTI2_3_IRQn
#define ocp_Pin GPIO_PIN_12
#define ocp_GPIO_Port GPIOB
#define l1_Pin GPIO_PIN_13
#define l1_GPIO_Port GPIOB
#define l2_Pin GPIO_PIN_14
#define l2_GPIO_Port GPIOB
#define l3_Pin GPIO_PIN_15
#define l3_GPIO_Port GPIOB
#define h1_Pin GPIO_PIN_8
#define h1_GPIO_Port GPIOA
#define h2_Pin GPIO_PIN_9
#define h2_GPIO_Port GPIOA
#define h3_Pin GPIO_PIN_10
#define h3_GPIO_Port GPIOA
#define oc_sel_Pin GPIO_PIN_11
#define oc_sel_GPIO_Port GPIOA
#define _3fg_hiz_Pin GPIO_PIN_12
#define _3fg_hiz_GPIO_Port GPIOA
#define octh2_Pin GPIO_PIN_6
#define octh2_GPIO_Port GPIOF
#define octh1_Pin GPIO_PIN_7
#define octh1_GPIO_Port GPIOF
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
