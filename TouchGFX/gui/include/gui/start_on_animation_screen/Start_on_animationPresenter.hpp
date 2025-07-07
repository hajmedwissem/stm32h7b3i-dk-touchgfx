#ifndef START_ON_ANIMATIONPRESENTER_HPP
#define START_ON_ANIMATIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Start_on_animationView;

class Start_on_animationPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Start_on_animationPresenter(Start_on_animationView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Start_on_animationPresenter() {}

private:
    Start_on_animationPresenter();

    Start_on_animationView& view;
};

#endif // START_ON_ANIMATIONPRESENTER_HPP
