#include <gui/settings_screen/settingsView.hpp>

#include "../settings/Settings.h"
#include "../BSP/water_pump_mangement/water_pimp_mangement.h"
#include "../BSP/fun_mangement/fun_mangement.h"


Settings_t local_settings;

settingsView::settingsView()
{

}

void settingsView::setupScreen()
{
    settingsViewBase::setupScreen();

    get_settings(&local_settings);

    if(local_settings.config.bits.auto_manuel){
    //	auto_manuel_pb.forceState(false);
    	start_auto_settings();
    }else{
    //	auto_manuel_pb.forceState(true);
    	start_manuel_settings();
    }
    auto_manuel_pb.forceState(!local_settings.config.bits.auto_manuel);
    /************************************************
     * steps :
     * 1. read data from focal struct to detarminat is it auto or manuel
     * 2. display auto or manuel
     *
     *
     *
     ***********************************************/


    //toggleButton1.forceState(activeState)
}

void settingsView::tearDownScreen()
{
    settingsViewBase::tearDownScreen();
}


void settingsView::hum_funct(int value){

	Unicode::snprintf(hum_val_displayBuffer, HUM_VAL_DISPLAY_SIZE, "%d",value);
	hum_val_display.invalidate();
}



void settingsView::co2_func(int value){
	Unicode::snprintf(co2_val_displayBuffer, CO2_VAL_DISPLAY_SIZE, "%d",value);
	co2_val_display.invalidate();
}




void settingsView::fun_manuel_func(int value){
	control_fun_from_UI(value);
	 Unicode::snprintf(fun_val_displayBuffer, FUN_VAL_DISPLAY_SIZE, "%d", value);
	 fun_val_display.invalidate();
}



void settingsView::pump_manuel_func(int value){
	control_pump_from_UI(value);
	Unicode::snprintf(pump_val_displayBuffer, PUMP_VAL_DISPLAY_SIZE, "%d",value);
	pump_val_display.invalidate();
}



void settingsView::set_humidty_threshold(uint8_t value){

	// set slider
	humidity_slider.setValue(value);
	humidity_slider.invalidate();
	// value displayed
	Unicode::snprintf(hum_val_displayBuffer, HUM_VAL_DISPLAY_SIZE, "%d",value);
	hum_val_display.invalidate();
}


void settingsView::set_co2_threshold(uint16_t value){

	//slider
	CO2_slider.setValue(value);
	CO2_slider.invalidate();

	// value displayed
	Unicode::snprintf(co2_val_displayBuffer, CO2_VAL_DISPLAY_SIZE, "%d",value);
	co2_val_display.invalidate();

}

void settingsView::set_fun_speed_value(uint8_t value){
	//slider
	fun_control_slider.setValue(value);
	fun_control_slider.invalidate();

	//value dispalyed
	Unicode::snprintf(fun_val_displayBuffer, FUN_VAL_DISPLAY_SIZE, "%d", value);
	fun_val_display.invalidate();

}

void settingsView::set_pump_speed_value(uint8_t value){
	//slider
	pump_control_slider.setValue(value);
	pump_control_slider.invalidate();

	// value displayed
	Unicode::snprintf(pump_val_displayBuffer, PUMP_VAL_DISPLAY_SIZE, "%d",value);
	pump_val_display.invalidate();

}


void settingsView::start_auto_settings(void){

	// here we need to start auto settings
	/***********************************************************
	 *
	 * steps :
	 * 		1. get co2 threshold and humidty threshold from memory
	 * 		2. init all elements of auto settings container
	 * 		3. show the container
	 *
	 **********************************************************/
	local_settings.pump_speed = 0;
	local_settings.fun_speed = 0;
	save_settings(local_settings);


	/*************************************************************
	 *
	 * step 1 : get co2 threshold and humidty threshold from memory
	 *
	 *************************************************************/


	set_humidty_threshold(local_settings.hum_threshold);
	set_co2_threshold(local_settings.co2_threshold);



	/**************************************************************
	 *
	 * step 2 : init all elements of auto settings container
	 *
	 **************************************************************/
//	settingsView::set_co2_threshold(12);
//	settingsView::set_humidty_threshold(12);

	/***************************************************************
	 *
	 * step 3 : show the container
	 *
	 **************************************************************/

	auto_settings_container.setVisible(true);
	auto_settings_container.invalidate();
	manuel_settings_container.setVisible(false);
	manuel_settings_container.invalidate();


}


void settingsView::start_manuel_settings(void){

	// here we need to start manuel settings
	/***********************************************************
	 *
	 * steps :
	 * 		1. get fun and pump speed from memory
	 * 		2. init all elements of manuel settings container
	 * 		3. show the container
	 *
	 **********************************************************/






	diplay_pump_container(local_settings.config.bits.pump_control);
	diplay_fun_container(local_settings.config.bits.fun_control);
	pump_Button.forceState(local_settings.config.bits.pump_control);
	fun_Button.forceState(local_settings.config.bits.fun_control);

	set_pump_in_manuel_mode();
	set_fun_in_manuel_mode();
	control_pump_from_UI(local_settings.pump_speed);
	control_fun_from_UI(local_settings.fun_speed);

	/*************************************************************
	 *
	 * step 1 : get fun and pump speed from memory
	 *
	 *************************************************************/

	set_fun_speed_value(local_settings.fun_speed);
	set_pump_speed_value(local_settings.pump_speed);



	/**************************************************************
	 *
	 * step 2 : init all elements of auto settings container
	 *
	 **************************************************************/
//	settingsView::set_pump_speed_value(12);
//	settingsView::set_fun_speed_value(12);

	/***************************************************************
	 *
	 * step 3 : show the container
	 *
	 **************************************************************/
	manuel_settings_container.setVisible(true);
	manuel_settings_container.invalidate();

	auto_settings_container.setVisible(false);
	auto_settings_container.invalidate();

}



void settingsView::diplay_pump_container(bool visble){
	pump_settings_cont.setVisible(visble);
	pump_settings_cont.invalidate();
}
void settingsView::diplay_fun_container(bool visble){

	fun_settings_cont.setVisible(visble);
	fun_settings_cont.invalidate();
}
