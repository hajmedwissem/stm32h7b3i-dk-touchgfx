/*
 * water_pump.h
 *
 *  Created on: Apr 18, 2025
 *      Author: USER
 */

#ifndef SRC_DRIVERR_WATER_PUMP_WATER_PUMP_H_
#define SRC_DRIVERR_WATER_PUMP_WATER_PUMP_H_

#include"main.h"


void water_pump_init(void);
void pump_PWM_Start(void);


void set_pump_speed(uint8_t speed);
void  turn_off_pump(void);
void pump_forced_off(void);
void pump_force_on(void);
void pump_in_maneul_mode(void);
void turn_pump_on(void);

#endif /* SRC_DRIVERR_WATER_PUMP_WATER_PUMP_H_ */
