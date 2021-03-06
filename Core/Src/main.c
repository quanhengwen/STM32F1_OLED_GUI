
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"

/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"
#include "menu_ui.h"
#include "rtc_ui.h"
#include "rotary_encorder.h"
#include "text.h"
#include "menuL1_item.h"
#include "iwdgtask.h"
#include "rand_task.h"
#include "uart.h"
#include "decode_command.h"
#include "main_ui_page.h"
#include "rtc.h"
#include "delay.h"
#include "24cxx.h"
#include "config.h"

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
IWDG_HandleTypeDef hiwdg;

RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi2;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
/*START_TASK==========================================*/
#define START_TASK_PRIORITY   				CONFIG_START_TASK_PRIORITY  		// Task Priority
#define START_TASK_STACK_SIZE 				CONFIG_START_TASK_STACK_SIZE		// Task Stack Size
TaskHandle_t StartTaskHandler;						// Task Handler
void START_task(void *pvParameters);				// Task Fuction


/*GPIO_TASK==========================================*/
#define GPIO_TASK_PRIORITY   				CONFIG_GPIO_TASK_PRIORITY  		// Task Priority
#define GPIO_TASK_STACK_SIZE 				CONFIG_GPIO_TASK_STACK_SIZE		// Task Stack Size
TaskHandle_t GPIOTaskHandler;						// Task Handler
void GPIO_task(void *pvParameters);					// Task Fuction

/*TASK_LIST_TASK==========================================*/
#define LIST_TASK_PRIORITY   				CONFIG_LIST_TASK_PRIORITY  		// Task Priority
#define LIST_TASK_STACK_SIZE				CONFIG_LIST_TASK_STACK_SIZE		// Task Stack Size
TaskHandle_t LISTTaskHandler;						// Task Handler
void LIST_task(void *pvParameters);					// Task Fuction


/*Event Group ==========================================*/
EventGroupHandle_t EventGroupHandler;





/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI2_Init(void);
static void MX_TIM2_Init(void);
static void MX_RTC_Init(void);
static void MX_IWDG_Init(void);
static void MX_USART1_UART_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
extern uint16_t gram[64][64];
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

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
  MX_SPI2_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  DWT_Delay_Init();
 // AT24CXX_Init();
 // AT24CXX_Check();
  MY_RTC_Init();
  OLED_Init();
  mainMenuInit();
  xTaskCreate((TaskFunction_t  )(START_task),         	//Task Function
			  (const char*     ) "START_task",		    //Task Name
			  (uint16_t        ) START_TASK_STACK_SIZE,  //Task Stack Size
			  (void *          ) NULL,				   //Task Fuction Parameter
			  (UBaseType_t     ) START_TASK_PRIORITY,    //Task Priority
			  (TaskHandle_t*    ) &StartTaskHandler);	   //Task Handler
  vTaskStartScheduler();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
  /* USER CODE END WHILE */

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

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE
                              |RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* IWDG init function */
static void MX_IWDG_Init(void)
{

  hiwdg.Instance = IWDG;
  hiwdg.Init.Prescaler = IWDG_PRESCALER_32;
  hiwdg.Init.Reload = 2500;
  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* RTC init function */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime;
  RTC_DateTypeDef DateToUpdate;

  /* USER CODE BEGIN RTC_Init 1 */
  if(HAL_RTCEx_BKUPRead(&hrtc,RTC_BKP_DR1)!= 0x32F1){
	  //both rtc battery power and system power diconnect
	  //backup valude will be clear to zero
	  HAL_RTCEx_BKUPWrite(&hrtc,RTC_BKP_DR1,0x32F1);
  }
  else{
	   hrtc.Instance = RTC;
	   hrtc.Init.AsynchPrediv = RTC_AUTO_1_SECOND;
	   hrtc.Init.OutPut = RTC_OUTPUTSOURCE_NONE;
	   if (HAL_RTC_Init(&hrtc) != HAL_OK)
	   {
	     _Error_Handler(__FILE__, __LINE__);
	   }
	  return;
  }
  /* USER CODE END RTC_Init 1 */

    /**Initialize RTC Only 
    */
  hrtc.Instance = RTC;
  hrtc.Init.AsynchPrediv = RTC_AUTO_1_SECOND;
  hrtc.Init.OutPut = RTC_OUTPUTSOURCE_NONE;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initialize RTC and set the Time and Date 
    */
  sTime.Hours = 0x18;
  sTime.Minutes = 0x30;
  sTime.Seconds = 0x30;

  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  DateToUpdate.WeekDay = RTC_WEEKDAY_WEDNESDAY;
  DateToUpdate.Month = RTC_MONTH_AUGUST;
  DateToUpdate.Date = 0x22;
  DateToUpdate.Year = 0x18;

  if (HAL_RTC_SetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BCD) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* SPI2 init function */
static void MX_SPI2_Init(void)
{

  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_1LINE;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi2.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* TIM2 init function */
static void MX_TIM2_Init(void)
{

  TIM_Encoder_InitTypeDef sConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 3;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 65535;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 10;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 10;
  if (HAL_TIM_Encoder_Init(&htim2, &sConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/* USART1 init function */
static void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 38400;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED1_Pin|LED2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SPI_CS_Pin|OLED_RST_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, I2C_SDL_Pin|I2C_SDA_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED1_Pin LED2_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : ROTARY_SW_Pin */
  GPIO_InitStruct.Pin = ROTARY_SW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(ROTARY_SW_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI_CS_Pin */
  GPIO_InitStruct.Pin = SPI_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(SPI_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : OLED_RST_Pin I2C_SDL_Pin I2C_SDA_Pin */
  GPIO_InitStruct.Pin = OLED_RST_Pin|I2C_SDL_Pin|I2C_SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : OLED_DC_Pin */
  GPIO_InitStruct.Pin = OLED_DC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(OLED_DC_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void START_task(void *pvParameters){
	taskENTER_CRITICAL();
	EventGroupHandler = xEventGroupCreate(); //create event group
	//rotary encoder button task
	xTaskCreate((TaskFunction_t  )(Button_task),         	//Task Function
				(const char*     ) "Button_task",		    //Task Name
				(uint16_t        ) BUTTON_TASK_STACK_SIZE, 	//Task Stack Size
				(void *          ) NULL,				    //Task Fuction Parameter
				(UBaseType_t     ) BUTTON_TASK_PRIORITY, 	//Task Priority
				(TaskHandle_t*    ) &ButtonTaskHandler);	    //Task Handler
	//MAIN UI task
	xTaskCreate((TaskFunction_t  )(main_ui_task),         	  	//Task Function
				(const char*     ) "main task",		      	//Task Name
				(uint16_t        ) MAIN_UI_PAGE_TASK_STACK_SIZE, 	//Task Stack Size
				(void *          ) NULL,				    //Task Fuction Parameter
				(UBaseType_t     ) MAIN_UI_PAGE_TASK_PRIORITY, 		//Task Priority
				(TaskHandle_t*    ) &mainUITaskHandler);	    //Task Handler
	//uart task
	xTaskCreate((TaskFunction_t  )(uart_task),              //Task Function
				(const char*     ) "uart_task",		      	//Task Name
				(uint16_t        ) UART_TASK_STACK_SIZE, 	//Task Stack Size
				(void *          ) NULL,			        //Task Fuction Parameter
				(UBaseType_t     ) UART_TASK_PRIORITY, 		//Task Priority
				(TaskHandle_t*    ) &uartTaskHandler);	    //Task Handler

	//decode command task
	xTaskCreate((TaskFunction_t  )(decode_command_task),    //Task Function
				(const char*     ) "decode_task",		    //Task Name
				(uint16_t        ) DECODE_TASK_STACK_SIZE, 	//Task Stack Size
				(void *          ) NULL,				    //Task Fuction Parameter
				(UBaseType_t     ) DECODE_TASK_PRIORITY, 		//Task Priority
				(TaskHandle_t*    ) &decodeTaskHandler);	    //Task Handler

	//gpio blink task
	xTaskCreate((TaskFunction_t  )(GPIO_task),         	  	//Task Function
				(const char*     ) "GPIO_task",		      	//Task Name
				(uint16_t        ) GPIO_TASK_STACK_SIZE, 	//Task Stack Size
				(void *          ) NULL,				    //Task Fuction Parameter
				(UBaseType_t     ) GPIO_TASK_PRIORITY, 		//Task Priority
				(TaskHandle_t*    ) &GPIOTaskHandler);	    //Task Handler

	//independent watch dog task
	xTaskCreate((TaskFunction_t  )(iwdg_Task),         	  	//Task Function
				(const char*     ) "iwdg_Task",		      	//Task Name
				(uint16_t        ) IWDG_TASK_STACK_SIZE, 	//Task Stack Size
				(void *          ) NULL,				    //Task Fuction Parameter
				(UBaseType_t     ) IWDG_TASK_PRIORITY, 		//Task Priority
				(TaskHandle_t    ) &iwdgTaskHandler);	    //Task Handler

#if DEBUG
	//堆疊統計任務
	xTaskCreate((TaskFunction_t  )(LIST_task),         	  	//Task Function
				(const char*     ) "LIST_task",		      	//Task Name
				(uint16_t        ) LIST_TASK_STACK_SIZE, 	//Task Stack Size
				(void *          ) NULL,				    //Task Fuction Parameter
				(UBaseType_t     ) LIST_TASK_PRIORITY, 		//Task Priority
				(TaskHandle_t    ) &LISTTaskHandler);	    //Task Handler
#endif
	vTaskDelete(StartTaskHandler);
	taskEXIT_CRITICAL();
}
void GPIO_task(void *pvParameters){
	while(1){
#if DEBUG

#endif
		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		vTaskDelay(1000/portTICK_PERIOD_MS);
		HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
		vTaskDelay(2000/portTICK_PERIOD_MS);

	}

}


void LIST_task(void *pvParameters)
{
	char info[800];
	while(1)
	{
		vTaskList(info);
		printf("%s\r\n",info);
		printf("Free Heap size = %d\r\n",xPortGetFreeHeapSize());
		vTaskDelay(10000);
	}
}

void vApplicationMallocFailedHook( void ) {
#if DEBUG
	printf("vApplicationMallocFailedHook: Malloc failed \n");
#endif
	while(1);
}
void vApplicationStackOverflowHook( TaskHandle_t xTask, signed char *pcTaskName ) {
#if DEBUG
	printf("vApplicationStackOverflowHook:====================\n");
	printf("StackOverflow: on Task = %s\n",pcTaskName);
	printf("Suspend Task : %s\n",pcTaskName);
#endif
	//vTaskSuspend(xTask);
	while(1);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
#if DEBUG
	printf(" Error_Handler:====================================\n");
	printf(" Error cause on %s file, line number = %d\n",file,line);
#endif
	while (1) {
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
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
	 tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
