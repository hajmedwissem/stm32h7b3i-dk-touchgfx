/*
 * fun_mangement.h
 *
 *  Created on: Apr 18, 2025
 *      Author: USER
 */

#ifndef SRC_BSP_FUN_MANGEMENT_FUN_MANGEMENT_H_
#define SRC_BSP_FUN_MANGEMENT_FUN_MANGEMENT_H_



void control_fun_with_co2(uint16_t val);




#ifdef __cplusplus
extern "C" {
#endif



void control_fun_from_UI(uint8_t val);
void fun_forced_en_off(void);
void fun_forced_on(void);
void set_fun_in_manuel_mode(void);

#ifdef __cplusplus
}
#endif


#endif /* SRC_BSP_FUN_MANGEMENT_FUN_MANGEMENT_H_ */
