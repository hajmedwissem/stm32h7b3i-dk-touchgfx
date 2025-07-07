#ifndef STANDBYPRESENTER_HPP
#define STANDBYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class standbyView;

class standbyPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    standbyPresenter(standbyView& v);

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

    virtual ~standbyPresenter() {}

private:
    standbyPresenter();

    standbyView& view;
};

#endif // STANDBYPRESENTER_HPP
