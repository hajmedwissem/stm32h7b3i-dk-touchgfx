/*
 * fun.h
 *
 *  Created on: Apr 18, 2025
 *      Author: USER
 */

#ifndef SRC_DRIVERR_FUN_FUN_H_
#define SRC_DRIVERR_FUN_FUN_H_

#include"main.h"


void fun_init(void);
void fun_PWM_Start(void);


void set_fun_speed(uint8_t speed);
void  turn_off_fun(void);
void fun_forced_off(void);
void fun_force_on(void);
void fun_in_maneul_mode(void);
void turn_fun_on(void);

#endif /* SRC_DRIVERR_FUN_FUN_H_ */
