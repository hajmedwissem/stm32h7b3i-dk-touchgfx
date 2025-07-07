/*
 * fun.c
 *
 *  Created on: Apr 18, 2025
 *      Author: USER
 */
#include "main.h"
#include "fun.h"
#include <stdbool.h>
#include "../../settings/Settings.h"

static bool fun_pwm_stoped = false;
static bool fun_forced_offvar = 	false;

static TIM_HandleTypeDef htim12;

static void fun_TIM1_Init(void);
static uint16_t map_percentage_to_pwm2(uint8_t percent);
static void fun_pwm_out(uint16_t val);



#define fun_MAX_PERCENT  80

static void fun_TIM1_Init(void)
{
	 /* USER CODE BEGIN TIM12_Init 0 */

	  /* USER CODE END TIM12_Init 0 */

	  TIM_MasterConfigTypeDef sMasterConfig = {0};
	  TIM_OC_InitTypeDef sConfigOC = {0};

	  /* USER CODE BEGIN TIM12_Init 1 */

	  /* USER CODE END TIM12_Init 1 */
	  htim12.Instance = TIM12;
	  htim12.Init.Prescaler = 0;
	  htim12.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim12.Init.Period = 65535;
	  htim12.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  htim12.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	  if (HAL_TIM_PWM_Init(&htim12) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim12, &sMasterConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = 0;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  if (HAL_TIM_PWM_ConfigChannel(&htim12, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  /* USER CODE BEGIN TIM12_Init 2 */

	  /* USER CODE END TIM12_Init 2 */
	  HAL_TIM_MspPostInit(&htim12);



}



void fun_init(void)
{

	fun_TIM1_Init();
	fun_pwm_stoped = false;
	fun_forced_offvar = false;
	set_fun_speed(0);
	fun_PWM_Start();


}

void fun_PWM_Start(void)
{
	//if((!get_user_mode_selected()&&(!fun_forced_offvar)) || (get_user_mode_selected() && (!fun_forced_offvar) && (!fun_pwm_stoped))){
	if(!fun_forced_offvar){
		HAL_TIM_PWM_Start(&htim12, TIM_CHANNEL_2);
		fun_pwm_stoped = false;
	}

//	}


}



static void fun_pwm_out(uint16_t val){

	__HAL_TIM_SET_COMPARE(&htim12,TIM_CHANNEL_2,val);
}



void set_fun_speed(uint8_t speed){
	if(!fun_forced_offvar){
		uint16_t pwm_value = map_percentage_to_pwm2(speed);
		fun_PWM_Start();
		fun_pwm_out(pwm_value);
	}

}

static uint16_t map_percentage_to_pwm2(uint8_t percent)
{
	 if (percent > fun_MAX_PERCENT)
		percent = fun_MAX_PERCENT; // Limit max speed
	return (uint16_t)((percent * 65535) / 100);
}


void  turn_off_fun(void){
	set_fun_speed(0);
//	HAL_TIM_PWM_Stop(&htim12, TIM_CHANNEL_2);
	fun_pwm_stoped = true;
}



void fun_forced_off(void){
	fun_forced_offvar = true;
	HAL_TIM_PWM_Stop(&htim12, TIM_CHANNEL_2);
	//turn_off_fun();

}


void fun_force_on(void){
	fun_forced_offvar = false;
	fun_PWM_Start();
}

void turn_fun_on(void){
	fun_pwm_stoped = false;
}

void fun_in_maneul_mode(void){
	//fun_pwm_stoped = false;
}
