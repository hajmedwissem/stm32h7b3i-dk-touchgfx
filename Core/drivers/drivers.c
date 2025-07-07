/*
 * drivers.c
 *
 *  Created on: Apr 25, 2025
 *      Author: USER
 */
#include "main.h"
#include "hum_drv/hum_drv.h"
#include "drivers.h"
#include "co2_drv/co2_sensor.h"
#include "water_pump/water_pump.h"
#include "fun/fun.h"


void init_all_drivers(void){


	

	humidity_sensor_init();
	co2_sensor_init();

	water_pump_init();
	fun_init();


}
