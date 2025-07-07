/*
 * fun_mangement.c
 *
 *  Created on: Apr 18, 2025
 *      Author: USER
 */


#include "main.h"
#include "fun_mangement.h"
#include "../../drivers/fun/fun.h"
#include "../../settings/Settings.h"

#define CO2_MAX_PPM 5000.0f

#define CO2_MIN_PPM 500.0f



void control_fun_with_co2(uint16_t val){

	 if (val < CO2_MIN_PPM) {
		 set_fun_speed(0);
		 turn_off_fun();
	    } else if (val < get_co2_thr() + 20) {
	       set_fun_speed(20);  // Constant low speed in buffer zone

	    } else {
	        float scale = (val - (get_co2_thr() + 20)) / (CO2_MAX_PPM - (get_co2_thr() + 20));
	        if (scale > 1.0f) scale = 1.0f;
	       set_fun_speed(scale * 100.0f);  // 0–100%
	       turn_fun_on();
	    }

}



void control_fun_from_UI(uint8_t val){
	set_fun_speed(val);
	fun_PWM_Start();
}



void fun_forced_en_off(void){
	fun_forced_off();
}


void fun_forced_on(void){
	fun_force_on();
}


void set_fun_in_manuel_mode(void){
	fun_in_maneul_mode();
}
