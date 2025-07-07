#ifndef START_ON_ANIMATIONVIEW_HPP
#define START_ON_ANIMATIONVIEW_HPP

#include <gui_generated/start_on_animation_screen/Start_on_animationViewBase.hpp>
#include <gui/start_on_animation_screen/Start_on_animationPresenter.hpp>

class Start_on_animationView : public Start_on_animationViewBase
{
public:
    Start_on_animationView();
    virtual ~Start_on_animationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // START_ON_ANIMATIONVIEW_HPP
