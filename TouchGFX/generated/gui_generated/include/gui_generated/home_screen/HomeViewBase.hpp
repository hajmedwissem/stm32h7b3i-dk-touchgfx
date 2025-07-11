/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef HOMEVIEWBASE_HPP
#define HOMEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/home_screen/HomePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class HomeViewBase : public touchgfx::View<HomePresenter>
{
public:
    HomeViewBase();
    virtual ~HomeViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image page_bg;
    touchgfx::ScalableImage FSM_logo;
    touchgfx::ScalableImage university_of_monastir_logo;
    touchgfx::Container PB;
    touchgfx::ImageButtonStyle< touchgfx::ClickButtonTrigger >  Settings_PB;
    touchgfx::ImageButtonStyle< touchgfx::ClickButtonTrigger >  status_PB;
    touchgfx::ImageButtonStyle< touchgfx::ClickButtonTrigger >  about_PB;
    touchgfx::ImageButtonStyle< touchgfx::ClickButtonTrigger >  Alert_PB;
    touchgfx::ImageButtonStyle< touchgfx::ClickButtonTrigger >  Power_Off;
    touchgfx::TextArea home_page;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<HomeViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // HOMEVIEWBASE_HPP
