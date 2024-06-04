
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------
 *------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "main.h"
#include "stm32f4xx_hal_rcc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define Toh  400  // High-level time
#define Tol   850
#define T1h   800
#define T1l   450
/* USER CODE END Includes */
void SystemClock_Config(void);
/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
//void time();
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

extern TIM_HandleTypeDef tim;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/


/* USER CODE BEGIN PFP */

/* USER CODE END PFP */
void delay_ns(uint32_t ns) {
    ns *= (SystemCoreClock / 1000000) / 1000;
    while (ns--) {
        __NOP();
    }
}

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
uint32_t v1=0 ;
 uint32_t ccr=25000;
 char a[9] = "kannankck";
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
  time();
 // time();
  /* USER CODE END SysInit */


 if(HAL_TIM_PWM_Start(&tim, TIM_CHANNEL_1)!=HAL_OK){
  	Error_Handler();
  }

  /* Initialize all configured peripherals */

  /* USER CODE BEGIN 2 */
  //printf("tim\n",v1);
//printf("kck\n%d",ccr);
while(1){
	//HAL_UART_Transmit(huart, pData, Size, Timeout)
	HAL_TIM_PWM_Start(&tim, TIM_CHANNEL_1);
}
  /* USER CODE END 2 */
  int p=1000;
	int b=0;
/*
	while(1){
  while(b<p){

  	b+=1;
  	__HAL_TIM_SET_COMPARE(&tim,TIM_CHANNEL_1,b);
  	HAL_Delay(1);
  }
  while(b>0){
   	b-=1;
   	__HAL_TIM_SET_COMPARE(&tim,TIM_CHANNEL_1,b);
  	HAL_Delay(1);
   }
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  /* USER CODE END 3 */
	}


/**
  * @brief System Clock Configuration
  * @retval None
  */




void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct ;
  RCC_ClkInitTypeDef RCC_ClkInitStruct ;

  /** Configure the main internal regulator output voltage
  */
  //__HAL_RCC_PWR_CLK_ENABLE();
  //__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
 // RCC_OscInitStruct.LSEState = RCC_LSE_ON;
 // RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }

 // HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_LSE, RCC_MCODIV_1);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
/*
void time1(){

	TIM_OC_InitTypeDef pwn;

	tim.Instance = TIM2 ;
	tim.Init.CounterMode = TIM_COUNTERMODE_UP  ;
	tim.Init.Period = 1000-1;
	tim.Init.Prescaler =50;
	  memset(&pwn,0,sizeof(pwn));
	pwn.OCMode =  TIM_OCMODE_PWM1;
	pwn.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwn.Pulse = 1000*0.2;

	if(HAL_TIM_PWM_Init(&tim)!=HAL_OK){
		Error_Handler();
	}

	if(HAL_TIM_PWM_ConfigChannel(&tim, &pwn,TIM_CHANNEL_1 )!=HAL_OK){
		Error_Handler();
	}

}

*/




 void time(){
	TIM_OC_InitTypeDef TIM;
	  memset(&TIM,0,sizeof(TIM));
	tim.Instance = TIM2 ;
	tim.Init.CounterMode = TIM_COUNTERMODE_UP  ;
	tim.Init.Period = 1000-1;
	tim.Init.Prescaler =50-1;
	TIM.OCMode = TIM_OCMODE_PWM1 ;
	TIM.OCPolarity =TIM_OCPOLARITY_HIGH ;
	TIM.Pulse =500;

if(HAL_TIM_PWM_Init(&tim)!=HAL_OK){
	Error_Handler();
}

if(HAL_TIM_PWM_ConfigChannel(&tim, &TIM,TIM_CHANNEL_1 )!=HAL_OK){
	Error_Handler();
}

}

//HAL_TIM_OC_DelayElapsedCallback(htim);
/*
 void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{

// ccr = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
	ccr=ccr+25000;
  __HAL_TIM_SET_COMPARE(htim,TIM_CHANNEL_1,ccr);

}
 void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
 while(c>0){
  v1 =__HAL_TIM_GET_COMPARE(htim,TIM_CHANNEL_1)-v1;
 c--;
  //v2 = __HAL_TIM_GET_COMPARE(htim,TIM_CHANNEL_1);

}
}
*/
void gpio(){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef m;
	m.Pin = GPIO_PIN_1;
	m.Mode = GPIO_MODE_OUTPUT_PP;
	m.Speed  = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&m);
	//kck.Alternate = GPIO_AF1_TIM2;
}




void Error_Handler(void)
{

  __disable_irq();
  while (1)
  {
  }

}

