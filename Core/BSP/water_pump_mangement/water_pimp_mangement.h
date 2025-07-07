/*
 * water_pimp_mangement.h
 *
 *  Created on: Apr 18, 2025
 *      Author: USER
 */

#ifndef SRC_BSP_WATER_PUMP_MANGEMENT_WATER_PIMP_MANGEMENT_H_
#define SRC_BSP_WATER_PUMP_MANGEMENT_WATER_PIMP_MANGEMENT_H_

#include <stdint.h>


void control_pump_with_humidity(uint8_t hum);

#ifdef __cplusplus
extern "C" {
#endif

void control_pump_from_UI(uint8_t val);
void pump_poweroff(void);
void pump_forced_on(void);
void set_pump_in_manuel_mode(void);

#ifdef __cplusplus
}
#endif

#endif /* SRC_BSP_WATER_PUMP_MANGEMENT_WATER_PIMP_MANGEMENT_H_ */
