/*
 * water_pump.c
 *
 *  Created on: Apr 18, 2025
 *      Author: USER
 */
#include "main.h"
#include "water_pump.h"
#include <stdbool.h>
#include "../../settings/Settings.h"

static TIM_HandleTypeDef htim8;

static bool water_pump_pwm_stoped = false;
static bool water_forced_offvar	= false;


static void pump_TIM8_Init(void);
static uint16_t map_percentage_to_pwm(uint8_t percent);
static void pwm_out(uint16_t val);

#define PUMP_MAX_PERCENT 80

static void pump_TIM8_Init(void)
{


	 /* USER CODE BEGIN TIM8_Init 0 */

	  /* USER CODE END TIM8_Init 0 */


	  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	  TIM_MasterConfigTypeDef sMasterConfig = {0};
	  TIM_OC_InitTypeDef sConfigOC = {0};
	  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

	  /* USER CODE BEGIN TIM8_Init 1 */

	  /* USER CODE END TIM8_Init 1 */
	  htim8.Instance = TIM8;
	  htim8.Init.Prescaler = 0;
	  htim8.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim8.Init.Period = 65535;
	  htim8.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  htim8.Init.RepetitionCounter = 0;
	  htim8.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	  if (HAL_TIM_Base_Init(&htim8) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	  if (HAL_TIM_ConfigClockSource(&htim8, &sClockSourceConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  if (HAL_TIM_PWM_Init(&htim8) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim8, &sMasterConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = 0;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	  if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
	  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
	  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
	  sBreakDeadTimeConfig.DeadTime = 0;
	  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
	  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
	  sBreakDeadTimeConfig.BreakFilter = 0;
	  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
	  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
	  sBreakDeadTimeConfig.Break2Filter = 0;
	  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
	  if (HAL_TIMEx_ConfigBreakDeadTime(&htim8, &sBreakDeadTimeConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  /* USER CODE BEGIN TIM8_Init 2 */

	  /* USER CODE END TIM8_Init 2 */
	  HAL_TIM_MspPostInit(&htim8);
}


void water_pump_init(void)
{
	pump_TIM8_Init();
	water_pump_pwm_stoped = false;
	 water_forced_offvar = false;
	 set_pump_speed(0);
	 pump_PWM_Start();
}


void pump_PWM_Start(void)
{
//	if( (!get_user_mode_selected()&&(!water_forced_offvar)) || (get_user_mode_selected() && (!water_forced_offvar) && (!water_pump_pwm_stoped))){
	if(!water_forced_offvar){
		HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_3);
		water_pump_pwm_stoped = false;
	}

	//}


}



static void pwm_out(uint16_t val){

	__HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_3,val);

}




void set_pump_speed(uint8_t speed){
	if(!water_forced_offvar){
		uint16_t pwm_value = map_percentage_to_pwm(speed);
		pump_PWM_Start();
		pwm_out(pwm_value);
	}


}


static uint16_t map_percentage_to_pwm(uint8_t percent)
{
	 if (percent > PUMP_MAX_PERCENT)
		percent = PUMP_MAX_PERCENT; // Limit max speed
	return (uint16_t)((percent * 65535) / 100);
}


void  turn_off_pump(void){
	set_pump_speed(0);
	//HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_3);
	water_pump_pwm_stoped = true;
}

void turn_pump_on(void){
	water_pump_pwm_stoped = false;
}


void pump_forced_off(void){
	water_forced_offvar = true;
	HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_3);

	//turn_off_pump();

}



void pump_force_on(void){
	water_forced_offvar = false;
	pump_PWM_Start();

}


void pump_in_maneul_mode(void){
//	water_pump_pwm_stoped = false;;
}
