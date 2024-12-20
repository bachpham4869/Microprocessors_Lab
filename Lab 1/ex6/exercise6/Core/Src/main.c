/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void clearAllClock(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
}
void setNumberOnClock(int num){
	if (num==0){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
	}
	if (num==1){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
	}
	if (num==2){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		}
	if (num==3){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
		}
	if (num==4){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		}
	if (num==5){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
		}
	if (num==6){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, RESET);
		}
	if (num==7){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, RESET);
		}
	if (num==8){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, RESET);
		}
	if (num==9){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		}
	if (num==10){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);
		}
	if (num==11){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
		}
}
void clearNumberOnClock(int num){
	if (num==0){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET);
		}
	else if (num==1){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, SET);
		}
	else	if (num==2){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
			}
	else if (num==3){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
			}
	else if (num==4){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
			}
	else if (num==5){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
			}
	else if (num==6){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, SET);
			}
	else if (num==7){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);
			}
	else if (num==8){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET);
			}
	else if (num==9){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
			}
	else	if (num==10){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);
			}
	else	if (num==11){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
			}
}
void displaytime(int hour, int minute, int second){
	int H=hour%12;
	int M=minute/5;
	int S=second/5;
	for(int i=0 ; i<12 ; i++){
		clearNumberOnClock(i);
	}
	 setNumberOnClock(H);
	 setNumberOnClock(M);
	 setNumberOnClock(S);
}
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int counter = 0;
    while(counter <= 12){
  	  HAL_GPIO_WritePin(GPIOB, (1 << (counter + 4)), GPIO_PIN_RESET);
  	  HAL_Delay(250);
  	  HAL_GPIO_WritePin(GPIOB, (1 << (counter + 4)), GPIO_PIN_SET);
  	  counter++;
    }
    int hour = 19;
    int minute = 15;
    int sec = 0;

  while (1)
  {
    /* USER CODE END WHILE */
	  displaytime(hour,minute,sec);
	  	  HAL_Delay(200);
	  	  sec++;
	  	  if(sec>=60){
	  		  sec = 0;
	  		  minute++;
	  	  }
	  	  if(minute>=60){
	  	  	 minute = 0;
	  	  	 hour++;
	  	  }


    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_1_Pin|LED_2_Pin|LED_10_Pin|LED_11_Pin
                          |LED_12_Pin|LED_3_Pin|LED_4_Pin|LED_5_Pin
                          |LED_6_Pin|LED_7_Pin|LED_8_Pin|LED_9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_1_Pin LED_2_Pin LED_10_Pin LED_11_Pin
                           LED_12_Pin LED_3_Pin LED_4_Pin LED_5_Pin
                           LED_6_Pin LED_7_Pin LED_8_Pin LED_9_Pin */
  GPIO_InitStruct.Pin = LED_1_Pin|LED_2_Pin|LED_10_Pin|LED_11_Pin
                          |LED_12_Pin|LED_3_Pin|LED_4_Pin|LED_5_Pin
                          |LED_6_Pin|LED_7_Pin|LED_8_Pin|LED_9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
