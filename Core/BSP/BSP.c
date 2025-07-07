/*
 * BSP.c
 *
 *  Created on: Apr 25, 2025
 *      Author: USER
 */

#include "main.h"
#include "BSP.h"
#include "hum_manager/hum_manager.h"
#include "co2_sensor_mangement/co2_sensor_mangement.h"
#include "water_pump_mangement/water_pimp_mangement.h"



void BSP_init_tasks(void){
	humidity_task_init();
	co2_task_init();
}



void BSP_start_task(void){
	start_humidity_task();
	start_co2_task();

}
