#include <gui/standby_screen/standbyView.hpp>


#include "../settings/Settings.h"
#include "../BSP/water_pump_mangement/water_pimp_mangement.h"
#include "../BSP/fun_mangement/fun_mangement.h"

standbyView::standbyView()
{

}

void standbyView::setupScreen()
{
    standbyViewBase::setupScreen();
    pump_poweroff();
    fun_forced_en_off();

}

void standbyView::tearDownScreen()
{
    standbyViewBase::tearDownScreen();
}
