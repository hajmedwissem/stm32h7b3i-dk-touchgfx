/*
 * Settings.h
 *
 *  Created on: Apr 27, 2025
 *      Author: wisse
 */

#ifndef APPLICATION_USER_SETTINGS_SETTINGS_H_
#define APPLICATION_USER_SETTINGS_SETTINGS_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "main.h"
#include <stdint.h>
#include <stdbool.h>


#define Settings_address 0x081FE000
#define key 0x12345678

typedef union {
    uint8_t Val;
    struct __attribute__((packed)) {
        uint8_t auto_manuel:1;
        uint8_t pump_control:1;
        uint8_t fun_control:1;
        uint8_t b3:1;
        uint8_t b4:1;
        uint8_t b5:1;
        uint8_t b6:1;
        uint8_t b7:1;
    } bits;
} bits_config;

typedef struct {
    bits_config config;  // This holds the union, which contains the 'bits' struct
    uint32_t validat_key;
    uint8_t pump_speed;  // Corrected typo
    uint8_t fun_speed;
    uint8_t hum_threshold;  // Corrected typo
    uint16_t co2_threshold;  // Corrected typo
} Settings_t;







void load_settings_from_flash(void);
void get_settings(Settings_t * settings);
void save_settings(Settings_t newSettings);


bool get_user_mode_selected(void);

uint8_t get_hum_thr(void);

uint16_t get_co2_thr(void);




#ifdef __cplusplus
}
#endif


#endif /* APPLICATION_USER_SETTINGS_SETTINGS_H_ */
