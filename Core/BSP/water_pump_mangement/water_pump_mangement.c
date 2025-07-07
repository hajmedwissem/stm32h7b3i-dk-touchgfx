/*
 * water_pump_mangement.c
 *
 *  Created on: Apr 18, 2025
 *      Author: USER
 */



#include "water_pimp_mangement.h"
#include "../../drivers/water_pump/water_pump.h"
#include "../../settings/Settings.h"





void control_pump_with_humidity(uint8_t hum){

	  int16_t delta = (int16_t)hum - (int16_t)get_hum_thr();


	  if (delta < -15)
		  {
			  // Soil is too dry --> high speed proportional to humidity
			  uint8_t pumpSpeed = (uint8_t)((get_hum_thr() - hum) * 5); // Example formula
			  if (pumpSpeed > 100) pumpSpeed = 100; // Limit max speed
			  set_pump_speed(pumpSpeed);
			  turn_pump_on();
			  pump_PWM_Start();
		  }
	  else if (delta >= -15 && delta <= 15)
		 {
			 // In good range --> low continuous speed
			 set_pump_speed(30); // Example: 30% speed
			 //pump_PWM_Start();
		 }

	  else if (delta > 15)
	      {
	          // Soil is wet --> stop pump
		  set_pump_speed(0);
	      }
}


void control_pump_from_UI(uint8_t val){
	 set_pump_speed(val);
     pump_PWM_Start();
}



void pump_poweroff(void){
	pump_forced_off();
}



void pump_forced_on(void){
	pump_force_on();
}


void set_pump_in_manuel_mode(void){
	pump_in_maneul_mode();
}
