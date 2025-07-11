/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/settings_screen/settingsViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "../settings/Settings.h"
#include "../BSP/fun_mangement/fun_mangement.h"
#include "../BSP/water_pump_mangement/water_pimp_mangement.h"

extern Settings_t local_settings ;

settingsViewBase::settingsViewBase() :
    flexButtonCallback(this, &settingsViewBase::flexButtonCallbackHandler),
    buttonCallback(this, &settingsViewBase::buttonCallbackHandler),
    sliderValueChangedCallback(this, &settingsViewBase::sliderValueChangedCallbackHandler)
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    settings_Cont.setPosition(0, 2, 480, 272);
    settings_Cont.setScrollbarsColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    settings_Cont.setScrollbarsAlpha(255);
    page_bg.setBitmap(touchgfx::Bitmap(BITMAP_GRAPH_BG_ID));
    page_bg.setPosition(0, 0, 480, 353);
    page_bg.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);
    settings_Cont.add(page_bg);

    auto_settings_container.setPosition(8, 155, 472, 162);
    CO2_slider.setXY(263, 81);
    CO2_slider.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER_VERTICAL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_FIL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_INDICATORS_SLIDER3_VERTICAL_ROUND_NOB_ID));
    CO2_slider.setupHorizontalSlider(16, 15, 0, 0, 169);
    CO2_slider.setValueRange(0, 2000);
    CO2_slider.setValue(0);
    CO2_slider.setNewValueCallback(sliderValueChangedCallback);
    auto_settings_container.add(CO2_slider);

    humidity_slider.setXY(3, 81);
    humidity_slider.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER_VERTICAL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_FIL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_INDICATORS_SLIDER3_VERTICAL_ROUND_NOB_ID));
    humidity_slider.setupHorizontalSlider(16, 10, 0, 0, 169);
    humidity_slider.setValueRange(0, 100);
    humidity_slider.setValue(0);
    humidity_slider.setNewValueCallback(sliderValueChangedCallback);
    auto_settings_container.add(humidity_slider);

    CO2_threshold.setXY(263, 54);
    CO2_threshold.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    CO2_threshold.setLinespacing(0);
    CO2_threshold.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W7GQ));
    auto_settings_container.add(CO2_threshold);

    humidity_threshold.setXY(10, 54);
    humidity_threshold.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    humidity_threshold.setLinespacing(0);
    humidity_threshold.setTypedText(touchgfx::TypedText(T___SINGLEUSE_O4WV));
    auto_settings_container.add(humidity_threshold);

    auto_settings.setXY(164, 11);
    auto_settings.setColor(touchgfx::Color::getColorFromRGB(69, 71, 87));
    auto_settings.setLinespacing(0);
    auto_settings.setTypedText(touchgfx::TypedText(T___SINGLEUSE_EKCY));
    auto_settings_container.add(auto_settings);

    hum_val_display.setPosition(161, 50, 41, 35);
    hum_val_display.setColor(touchgfx::Color::getColorFromRGB(171, 31, 31));
    hum_val_display.setLinespacing(0);
    Unicode::snprintf(hum_val_displayBuffer, HUM_VAL_DISPLAY_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_K2BQ).getText());
    hum_val_display.setWildcard(hum_val_displayBuffer);
    hum_val_display.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZQAJ));
    auto_settings_container.add(hum_val_display);

    co2_val_display.setPosition(371, 50, 95, 31);
    co2_val_display.setColor(touchgfx::Color::getColorFromRGB(166, 25, 25));
    co2_val_display.setLinespacing(0);
    Unicode::snprintf(co2_val_displayBuffer, CO2_VAL_DISPLAY_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_G56W).getText());
    co2_val_display.setWildcard(co2_val_displayBuffer);
    co2_val_display.setTypedText(touchgfx::TypedText(T___SINGLEUSE_B8M7));
    auto_settings_container.add(co2_val_display);

    settings_Cont.add(auto_settings_container);

    auto_text.setXY(308, 90);
    auto_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    auto_text.setLinespacing(0);
    auto_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3NZG));
    settings_Cont.add(auto_text);

    back_pb.setBitmaps(Bitmap(BITMAP_UNDO_ID), Bitmap(BITMAP_UNDO_ID));
    back_pb.setBitmapXY(0, 0);
    back_pb.setAction(flexButtonCallback);
    back_pb.setPosition(18, 16, 33, 33);
    settings_Cont.add(back_pb);

    manuel_text.setXY(72, 90);
    manuel_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    manuel_text.setLinespacing(0);
    manuel_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YBK6));
    settings_Cont.add(manuel_text);

    line1.setPosition(-1, 136, 481, 15);
    line1Painter.setColor(touchgfx::Color::getColorFromRGB(62, 151, 214));
    line1.setPainter(line1Painter);
    line1.setStart(5.0f, 6.7f);
    line1.setEnd(477.3f, 6.8f);
    line1.setLineWidth(10);
    line1.setLineEndingStyle(touchgfx::Line::SQUARE_CAP_ENDING);
    settings_Cont.add(line1);

    manuel_settings_container.setPosition(2, 151, 478, 202);
    manuel_settings_container.setVisible(false);
    pump_settings_cont.setPosition(-3, 91, 254, 97);
    pump_settings_cont.setVisible(false);
    pump_control_slider.setXY(9, 26);
    pump_control_slider.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER_VERTICAL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_FIL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_INDICATORS_SLIDER3_VERTICAL_ROUND_NOB_ID));
    pump_control_slider.setupHorizontalSlider(16, 14, 0, 0, 169);
    pump_control_slider.setValueRange(0, 100);
    pump_control_slider.setValue(0);
    pump_control_slider.setNewValueCallback(sliderValueChangedCallback);
    pump_settings_cont.add(pump_control_slider);

    pump_val_display.setPosition(42, 0, 104, 28);
    pump_val_display.setColor(touchgfx::Color::getColorFromRGB(222, 4, 4));
    pump_val_display.setLinespacing(0);
    Unicode::snprintf(pump_val_displayBuffer, PUMP_VAL_DISPLAY_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_SUBR).getText());
    pump_val_display.setWildcard(pump_val_displayBuffer);
    pump_val_display.setTypedText(touchgfx::TypedText(T___SINGLEUSE_84XL));
    pump_settings_cont.add(pump_val_display);

    manuel_settings_container.add(pump_settings_cont);

    fun_settings_cont.setPosition(262, 91, 216, 97);
    fun_settings_cont.setVisible(false);
    fun_control_slider.setXY(0, 33);
    fun_control_slider.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER_VERTICAL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_FIL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_INDICATORS_SLIDER3_VERTICAL_ROUND_NOB_ID));
    fun_control_slider.setupHorizontalSlider(16, 13, 0, 0, 169);
    fun_control_slider.setValueRange(0, 100);
    fun_control_slider.setValue(0);
    fun_control_slider.setNewValueCallback(sliderValueChangedCallback);
    fun_settings_cont.add(fun_control_slider);

    fun_val_display.setPosition(54, 0, 104, 28);
    fun_val_display.setColor(touchgfx::Color::getColorFromRGB(222, 4, 4));
    fun_val_display.setLinespacing(0);
    Unicode::snprintf(fun_val_displayBuffer, FUN_VAL_DISPLAY_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_JVRD).getText());
    fun_val_display.setWildcard(fun_val_displayBuffer);
    fun_val_display.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IVJU));
    fun_settings_cont.add(fun_val_display);

    manuel_settings_container.add(fun_settings_cont);

    fun_Button.setXY(358, 54);
    fun_Button.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_TOGGLEBUTTON_SMALL_ROUND_SMALL_OFF_DARK_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_TOGGLEBUTTON_SMALL_ROUND_SMALL_ON_ACTION_ID));
    fun_Button.setAction(buttonCallback);
    manuel_settings_container.add(fun_Button);

    pump_Button.setXY(121, 54);
    pump_Button.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_TOGGLEBUTTON_SMALL_ROUND_SMALL_OFF_DARK_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_TOGGLEBUTTON_SMALL_ROUND_SMALL_ON_ACTION_ID));
    pump_Button.setAction(buttonCallback);
    manuel_settings_container.add(pump_Button);

    pump_control.setXY(6, 60);
    pump_control.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    pump_control.setLinespacing(0);
    pump_control.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JO1F));
    manuel_settings_container.add(pump_control);

    fun_control.setXY(262, 60);
    fun_control.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    fun_control.setLinespacing(0);
    fun_control.setTypedText(touchgfx::TypedText(T___SINGLEUSE_C8HC));
    manuel_settings_container.add(fun_control);

    manuel_settings.setXY(164, 10);
    manuel_settings.setColor(touchgfx::Color::getColorFromRGB(69, 71, 87));
    manuel_settings.setLinespacing(0);
    manuel_settings.setTypedText(touchgfx::TypedText(T___SINGLEUSE_EY1U));
    manuel_settings_container.add(manuel_settings);

    settings_Cont.add(manuel_settings_container);

    auto_manuel_pb.setXY(175, 76);
    auto_manuel_pb.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_TOGGLEBUTTON_MEDIUM_ROUND_ON_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_TOGGLEBUTTON_MEDIUM_ROUND_OFF_LIGHT_ID));
    auto_manuel_pb.setAction(buttonCallback);
    settings_Cont.add(auto_manuel_pb);

    settings_page.setXY(175, 11);
    settings_page.setColor(touchgfx::Color::getColorFromRGB(19, 41, 209));
    settings_page.setLinespacing(0);
    settings_page.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Z4I5));
    settings_Cont.add(settings_page);

    add(settings_Cont);
}

settingsViewBase::~settingsViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void settingsViewBase::setupScreen()
{

}

void settingsViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &back_pb)
    {
        //back_action
        //When back_pb clicked change screen to Home
        //Go to Home with screen transition towards East
        application().gotoHomeScreenSlideTransitionEast();
    }
}

void settingsViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &auto_manuel_pb)
    {
    	if (auto_manuel_pb.getState()) {

    		local_settings.config.bits.auto_manuel = 0;
		   display_auto_setting(false);
		   display_manuel_setting(true);
	   }else{
		   local_settings.config.bits.auto_manuel = 1;
		   display_manuel_setting(false);
		   display_auto_setting(true);

	   }

    }
    if (&src == &pump_Button)
    {
    	local_settings.config.bits.pump_control = pump_Button.getState();
    	display_pump_settings(pump_Button.getState());
    }
    if (&src == &fun_Button)
    {
    	local_settings.config.bits.fun_control = fun_Button.getState();
    	display_fun_settings(fun_Button.getState());
    }

    save_settings(local_settings);
}

void settingsViewBase::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &humidity_slider)
    {
        //hum_Slider_action
        //When humidity_slider value changed call virtual function
        //Call hum_funct
        hum_funct(value);
        local_settings.hum_threshold = value;
    }
    if (&src == &CO2_slider)
    {
        //co2_Slider_action
        //When CO2_slider value changed call virtual function
        //Call co2_func
        co2_func(value);
        local_settings.co2_threshold = value;
    }
    if (&src == &pump_control_slider)
    {
        //manuelPumpSliderchange
        //When pump_control_slider value changed call virtual function
        //Call pump_manuel_func
        pump_manuel_func(value);
        local_settings.pump_speed = value;
    }
    if (&src == &fun_control_slider)
    {
        //manuelFunSliderChange
        //When fun_control_slider value changed call virtual function
        //Call fun_manuel_func
        fun_manuel_func(value);
        local_settings.fun_speed = value;
    }

    save_settings(local_settings);
}


void settingsViewBase::display_manuel_setting(bool show){
	manuel_settings_container.setVisible(show);
	manuel_settings_container.invalidate();
	pump_control_slider.setValue(0);
	fun_control_slider.setValue(0);

	Unicode::snprintf(pump_val_displayBuffer, PUMP_VAL_DISPLAY_SIZE, "%d",0);
	pump_val_display.invalidate();

	Unicode::snprintf(fun_val_displayBuffer, FUN_VAL_DISPLAY_SIZE, "%d", 0);
	fun_val_display.invalidate();

	control_fun_from_UI(0);
	control_pump_from_UI(0);
}

void settingsViewBase::display_auto_setting(bool show){
	auto_settings_container.setVisible(show);
	auto_settings_container.invalidate();
}

void settingsViewBase::display_pump_settings(bool show){
	pump_settings_cont.setVisible(show);
	pump_settings_cont.invalidate();
}
void settingsViewBase::display_fun_settings(bool show){
	fun_settings_cont.setVisible(show);
	fun_settings_cont.invalidate();
}
