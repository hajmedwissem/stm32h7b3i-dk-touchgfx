/*
 * co2_sensor_mangement.h
 *
 *  Created on: Apr 18, 2025
 *      Author: USER
 */

#ifndef SRC_BSP_CO2_SENSOR_MANGEMENT_CO2_SENSOR_MANGEMENT_H_
#define SRC_BSP_CO2_SENSOR_MANGEMENT_CO2_SENSOR_MANGEMENT_H_

#include "main.h"

void co2_task_init(void);

void start_co2_task(void);


#ifdef __cplusplus
extern "C" {
#endif

float_t get_co2_from_queue(void);


#ifdef __cplusplus
}
#endif

#endif /* SRC_BSP_CO2_SENSOR_MANGEMENT_CO2_SENSOR_MANGEMENT_H_ */
