#ifndef STANDBYVIEW_HPP
#define STANDBYVIEW_HPP

#include <gui_generated/standby_screen/standbyViewBase.hpp>
#include <gui/standby_screen/standbyPresenter.hpp>

class standbyView : public standbyViewBase
{
public:
    standbyView();
    virtual ~standbyView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // STANDBYVIEW_HPP
