/*
 * co2_sensor.c
 *
 *  Created on: Apr 18, 2025
 *      Author: USER
 */
#include "main.h"
#include"co2_sensor.h"
#include"stm32h7xx_hal_adc.h"




static ADC_HandleTypeDef hadc2;



static void co2_ADC2_Init(void);





static void co2_ADC2_Init(void)
{
	/* USER CODE BEGIN ADC2_Init 0 */

	  /* USER CODE END ADC2_Init 0 */

	  ADC_ChannelConfTypeDef sConfig = {0};

	  /* USER CODE BEGIN ADC2_Init 1 */

	  /* USER CODE END ADC2_Init 1 */

	  /** Common config
	  */
	  hadc2.Instance = ADC2;
	  hadc2.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
	  hadc2.Init.Resolution = ADC_RESOLUTION_16B;
	  hadc2.Init.ScanConvMode = ADC_SCAN_DISABLE;
	  hadc2.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	  hadc2.Init.LowPowerAutoWait = DISABLE;
	  hadc2.Init.ContinuousConvMode = DISABLE;
	  hadc2.Init.NbrOfConversion = 1;
	  hadc2.Init.DiscontinuousConvMode = DISABLE;
	  hadc2.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	  hadc2.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	  hadc2.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;
	  hadc2.Init.Overrun = ADC_OVR_DATA_PRESERVED;
	  hadc2.Init.LeftBitShift = ADC_LEFTBITSHIFT_NONE;
	  hadc2.Init.OversamplingMode = DISABLE;
	  if (HAL_ADC_Init(&hadc2) != HAL_OK)
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
	  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  /* USER CODE BEGIN ADC2_Init 2 */

	  /* USER CODE END ADC2_Init 2 */
}

void co2_sensor_init(void)
{

	co2_ADC2_Init();

}



uint16_t read_co2_sensor(void)
{
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 10);
    uint16_t value = HAL_ADC_GetValue(&hadc2);
    return value;

}

