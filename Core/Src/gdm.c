/*
 * gdm.c
 *
 *  Created on: Mar 7, 2025
 *      Author: user
 */


#include "gdm.h"
#include "main.h"

enum device_mode current_mode;

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart1;

static void __configureSleepMode(enum device_mode mode){
	/** Initializes the CPU, AHB and APB buses clocks
	  */
	  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	  if (current_mode == ACTIVE){
		  HAL_GPIO_WritePin(BAT_MEAS_GPIO_Port, BAT_MEAS_Pin, 1);
	  } else if (current_mode == IDLE){
		  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
									  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
		  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
		  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV256;
		  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV16;
		  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV16;

		  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
		  {
			Error_Handler();
		  }

		  HAL_GPIO_WritePin(BAT_MEAS_GPIO_Port, BAT_MEAS_Pin, 0);
	  }
}

void GoToMode(enum device_mode mode){
	if (mode == ACTIVE){

		current_mode = ACTIVE;

		__configureSleepMode(current_mode);
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 1);


	} else if (mode == IDLE){
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, 0);

		current_mode = IDLE;

		__configureSleepMode(current_mode);
	}
}

