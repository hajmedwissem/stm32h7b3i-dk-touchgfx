/*
 * hum_drv.c
 *
 *  Created on: Apr 25, 2025
 *      Author: USER
 */
#include "main.h"
#include "hum_drv.h"
#include "stm32h7xx_hal_adc.h"


static ADC_HandleTypeDef hadc1;




//static void humidity_GPIO_Init(void);
static void humidity_ADC1_Init(void);





//static void humidity_GPIO_Init(void)
//{
//  GPIO_InitTypeDef GPIO_InitStruct = {0};
///* USER CODE BEGIN MX_GPIO_Init_1 */
///* USER CODE END MX_GPIO_Init_1 */
//
//  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOA_CLK_ENABLE();
//
//  /*Configure GPIO pin : PA1 */
//  GPIO_InitStruct.Pin = GPIO_PIN_1;
//  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
//
///* USER CODE BEGIN MX_GPIO_Init_2 */
///* USER CODE END MX_GPIO_Init_2 */
//}

static void humidity_ADC1_Init(void)
{
	/* USER CODE BEGIN ADC1_Init 0 */

	  /* USER CODE END ADC1_Init 0 */

	  ADC_MultiModeTypeDef multimode = {0};
	  ADC_ChannelConfTypeDef sConfig = {0};

	  /* USER CODE BEGIN ADC1_Init 1 */

	  /* USER CODE END ADC1_Init 1 */

	  /** Common config
	  */
	  hadc1.Instance = ADC1;
	  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
	  hadc1.Init.Resolution = ADC_RESOLUTION_16B;
	  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
	  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	  hadc1.Init.LowPowerAutoWait = DISABLE;
	  hadc1.Init.ContinuousConvMode = DISABLE;
	  hadc1.Init.NbrOfConversion = 1;
	  hadc1.Init.DiscontinuousConvMode = DISABLE;
	  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	  hadc1.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;
	  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
	  hadc1.Init.LeftBitShift = ADC_LEFTBITSHIFT_NONE;
	  hadc1.Init.OversamplingMode = DISABLE;
	  if (HAL_ADC_Init(&hadc1) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  /** Configure the ADC multi-mode
	  */
	  multimode.Mode = ADC_MODE_INDEPENDENT;
	  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  /** Configure Regular Channel
	  */
	  sConfig.Channel = ADC_CHANNEL_0;
	  sConfig.Rank = ADC_REGULAR_RANK_1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_387CYCLES_5;
	  sConfig.SingleDiff = ADC_SINGLE_ENDED;
	  sConfig.OffsetNumber = ADC_OFFSET_NONE;
	  sConfig.Offset = 0;
	  sConfig.OffsetSignedSaturation = DISABLE;
	  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}


void humidity_sensor_init(void)
{
	//humidity_GPIO_Init();
	humidity_ADC1_Init();

}




uint16_t read_humidity_sensor(void)
{

	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1,20);
	  return HAL_ADC_GetValue(&hadc1);

}






