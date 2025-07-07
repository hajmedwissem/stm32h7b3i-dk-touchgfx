/*
 * hum_manager.h
 *
 *  Created on: Apr 25, 2025
 *      Author: USER
 */

#ifndef APPLICATION_USER_BSP_HUM_MANAGER_HUM_MANAGER_H_
#define APPLICATION_USER_BSP_HUM_MANAGER_HUM_MANAGER_H_

#include "main.h"


void humidity_task_init(void);

void start_humidity_task(void);


#ifdef __cplusplus
extern "C" {
#endif

uint8_t get_humdity_from_queue(void);

#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_USER_BSP_HUM_MANAGER_HUM_MANAGER_H_ */
