#ifndef ALERTVIEW_HPP
#define ALERTVIEW_HPP

#include <gui_generated/alert_screen/AlertViewBase.hpp>
#include <gui/alert_screen/AlertPresenter.hpp>

class AlertView : public AlertViewBase
{
public:
    AlertView();
    virtual ~AlertView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ALERTVIEW_HPP
