#ifndef SETTINGSVIEW_HPP
#define SETTINGSVIEW_HPP

#include <gui_generated/settings_screen/settingsViewBase.hpp>
#include <gui/settings_screen/settingsPresenter.hpp>

class settingsView : public settingsViewBase
{
public:
    settingsView();
    virtual ~settingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    virtual void hum_funct(int value);
    virtual void co2_func(int value);
    virtual void pump_manuel_func(int value);
    virtual void fun_manuel_func(int value);
    void set_humidty_threshold(uint8_t value);
    void set_co2_threshold(uint16_t value);
    void set_fun_speed_value(uint8_t value);
    void set_pump_speed_value(uint8_t value);
    void start_auto_settings(void);
    void start_manuel_settings(void);
    void diplay_pump_container(bool visble);
    void diplay_fun_container(bool visble);
};

#endif // SETTINGSVIEW_HPP
