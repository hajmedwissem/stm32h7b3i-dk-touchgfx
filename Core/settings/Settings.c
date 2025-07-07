/*
 * Settings.c
 *
 *  Created on: Apr 27, 2025
 *      Author: wisse
 */




#include "Settings.h"
#include <string.h>
#include <stdbool.h>
#include "stm32h7b3i_discovery.h"
#include "stm32h7xx_hal_flash_ex.h"
#include "stm32_hal_legacy.h"



Settings_t activeSettings ;




// Initialize default settings
static Settings_t default_setting = {
    .validat_key = key,                // Initialize the 'validat_key' field
    .config = {                         // Initialize the 'config' field (union)
        .bits = {
            .auto_manuel = 1,           // Initialize 'auto_manuel' bit in 'bits'
            .pump_control = 0,         // Initialize 'pump_control' bit in 'bits'
            .fun_control = 0,          // Initialize 'fun_control' bit in 'bits'
        },
    },
    .pump_speed = 0,                   // Initialize 'pump_speed'
    .fun_speed = 0,                    // Initialize 'fun_speed'
    .hum_threshold = 50,               // Initialize 'hum_threshold'
    .co2_threshold = 250,              // Initialize 'co2_threshold'
};



void load_settings_from_flash(void){

	const Settings_t *storedSettings = (const Settings_t *)Settings_address;

	if (storedSettings->validat_key == key)
	{
	    // Settings are valid, load them into activeSettings
	    memcpy(&activeSettings, storedSettings, sizeof(Settings_t));
	}
	    else
	    {
	        // Settings are invalid, load defaults and save them
	        memcpy(&activeSettings, &default_setting, sizeof(Settings_t));
	        save_settings(activeSettings);
	    }
}





void get_settings(Settings_t *settings){


	memmove(settings,&activeSettings, sizeof(Settings_t));
}



void save_settings(Settings_t newSettings){


  HAL_FLASH_Unlock();

	FLASH_EraseInitTypeDef eraseInit;
	uint32_t pageError = 0;

	eraseInit.TypeErase = FLASH_TYPEERASE_SECTORS;
	eraseInit.Banks = FLASH_BANK_2;
	eraseInit.Sector = FLASH_SECTOR_127;  // Check this based on your memory layout
	eraseInit.NbSectors = 4;
	eraseInit.VoltageRange = 0x00000001;
	uint32_t address = Settings_address ;
	 const uint32_t *pData = (const uint32_t *)&newSettings;
	if (HAL_FLASHEx_Erase(&eraseInit, &pageError) == HAL_OK)
	{

		 // Data to be written (32-bit aligned)

		    // Write 32-bit chunks to the flash memory
		 for (uint32_t i = 0; i < (sizeof(Settings_t) + 15) / 16; i++) // round up
		    {
		        HAL_StatusTypeDef status = HAL_FLASH_Program(
		            FLASH_TYPEPROGRAM_FLASHWORD,
		            address,
		            (uint32_t)(pData + i * 4) // 4 words (16 bytes)
		        );

		        if (status != HAL_OK) {
		            HAL_FLASH_Lock();
		            return;
		        }

		        // Wait for operation to complete
		        status = FLASH_WaitForLastOperation(5000, FLASH_BANK_2);
		        if (status != HAL_OK) {
		            HAL_FLASH_Lock();
		            return;
		        }

		        address += 16; // Move 16 bytes forward
		    }
	}
	memmove(&activeSettings,&newSettings,sizeof(Settings_t));

	HAL_FLASH_Lock();
}




bool get_user_mode_selected(void){
	return activeSettings.config.bits.auto_manuel;
}



uint8_t get_hum_thr(void){
	return activeSettings.hum_threshold;
}

uint16_t get_co2_thr(void){
	return activeSettings.co2_threshold;
}
