/*
 * hum_manager.c
 *
 *  Created on: Apr 25, 2025
 *      Author: USER
 */


#include "../../drivers/hum_drv/hum_drv.h"
#include "main.h"
#include "hum_manager.h"

#include "cmsis_os2.h"
#include <stdio.h>
#include <string.h>

#include "../../settings/Settings.h"
#include "../water_pump_mangement/water_pimp_mangement.h"

#define Hum_queue_max_size 		30


struct{
	uint8_t data[Hum_queue_max_size];
	uint8_t indexFirst;
	uint8_t size;
}hum_queue;





void humidity_task_init(void){


	hum_queue.indexFirst =0;
	hum_queue.size = 0;
	memset(hum_queue.data,0,Hum_queue_max_size);

}





static void humidity_task(void* parm);
static void add_hum_to_queue(uint8_t hum);

float Vwet=0.0f;
float Vdry=3.3f;



/* Definitions for humedity_task */
osThreadId_t humedity_taskHandle;
/* Creation des attributs de la tâche */
const osThreadAttr_t humedity_task_attributes = {
	.name = "humedity_task",
	.stack_size = 128 * 4,
	.priority = (osPriority_t) osPriorityNormal4,
};



void start_humidity_task(void)
{
	    /* Creation de la tâche */
	    humedity_taskHandle = osThreadNew(humidity_task, NULL, &humedity_task_attributes);
}




static void humidity_task(void* parm)
{
	for(;;)
	{

		float tension=((float)read_humidity_sensor()/65535.0f)*3.3f;
		uint8_t humidity = (uint8_t)((1.0f - ((tension - Vwet) / (Vdry - Vwet))) * 100.0f);
	//	printf("humidity = %d  \n",humidity);
		add_hum_to_queue(humidity);

		if (get_user_mode_selected()) {
			// user select auto mode
			// change pump speed automatically
			control_pump_with_humidity(humidity);
		}
		osDelay(1);


	}
}




static void add_hum_to_queue(uint8_t hum){
	uint8_t index =0;

	if(hum_queue.size < (Hum_queue_max_size-1)){
		// there is a space in queue
		index = (hum_queue.indexFirst+hum_queue.size)%Hum_queue_max_size;
		hum_queue.data[index] = hum;
		hum_queue.size++;
	}else{
		//there is no space in queue
		hum_queue.data[0]= hum;
		hum_queue.indexFirst =0;
		hum_queue.size=0;
	}
}


uint8_t get_humdity_from_queue(void){

	uint8_t val = 0;

	if(hum_queue.size != 0){
		val = hum_queue.data[hum_queue.indexFirst];
		hum_queue.indexFirst = (hum_queue.indexFirst + 1)%Hum_queue_max_size;
		hum_queue.size --;
	}
	return val;
}
