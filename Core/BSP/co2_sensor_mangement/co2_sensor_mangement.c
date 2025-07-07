/*
 * co2_sensor_mangement.c
 *
 *  Created on: Apr 18, 2025
 *      Author: USER
 */

#include "main.h"
#include "co2_sensor_mangement.h"

#include <string.h>


#include "cmsis_os2.h"
#include "../../drivers/co2_drv/co2_sensor.h"
#include <string.h>
#include "../../settings/Settings.h"
#include "../fun_mangement/fun_mangement.h"

#define co2_queue_max_size 		30
#define RL 10000.0f
#define R0  17494.02f


#define CO2_A 116.6020682f
#define CO2_B -2.769034857f



struct{
	float_t data[co2_queue_max_size];
	uint16_t indexFirst;
	uint16_t size;
}co2_queue;



/* Definitions for co2_task */
osThreadId_t co2_taskHandle;
const osThreadAttr_t co2_task_attributes = {
  .name = "co2_task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal4,
};




static void co2_task(void* parametre);
static void add_co2_to_queue(float_t co2);





void co2_task_init(void){


	co2_queue.indexFirst =0;
	co2_queue.size = 0;
	memset(co2_queue.data,0,sizeof(co2_queue.data));

}






void start_co2_task(void)
{
	    /* Creation de la tâche */
	    co2_taskHandle = osThreadNew(co2_task, NULL, &co2_task_attributes);
}


static void co2_task(void* parametre)
{
	for(;;)
	{
		float voltage=((float)read_co2_sensor()/ 65535.0f)*3.3f;
		float Rs=((3.3f-voltage)/voltage)* RL;
		float ratio= Rs /  R0 ;
		float ppm = CO2_A * powf(ratio, CO2_B);

		add_co2_to_queue(ppm);

		if (get_user_mode_selected()) {
			control_fun_with_co2(ppm);
		}
		osDelay(1);
	}
}




static void add_co2_to_queue(float_t co2){
	uint16_t index =0;

	if(co2_queue.size < (co2_queue_max_size-1)){
		// there is a space in queue
		index = (co2_queue.indexFirst+co2_queue.size)%co2_queue_max_size;
		co2_queue.data[index] = co2;
		co2_queue.size++;
	}else{
		//there is no space in queue
		co2_queue.data[0]= co2;
		co2_queue.indexFirst =0;
		co2_queue.size= 0;
	}
}


float_t get_co2_from_queue(void){

	float_t val = 0;

	if(co2_queue.size != 0){
		val = co2_queue.data[co2_queue.indexFirst];
		co2_queue.indexFirst = (co2_queue.indexFirst + 1)%co2_queue_max_size;
		co2_queue.size --;
	}
	return val;
}







