/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/status_screen/StatusViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

StatusViewBase::StatusViewBase() :
    flexButtonCallback(this, &StatusViewBase::flexButtonCallbackHandler),
    sliderValueChangedCallback(this, &StatusViewBase::sliderValueChangedCallbackHandler)
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    status_Cont.setPosition(0, 0, 480, 272);
    status_Cont.setScrollbarsColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    status_Cont.setScrollbarsAlpha(255);
    page_bg.setBitmap(touchgfx::Bitmap(BITMAP_GRAPH_BG_ID));
    page_bg.setPosition(0, 0, 480, 690);
    page_bg.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);
    status_Cont.add(page_bg);

    CO2_cont.setPosition(18, 415, 441, 264);
	co2_bg.setPosition(-11, 43, 405, 224);
	co2_bg.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
	co2_bg.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	co2_bg.setBorderSize(1);
    CO2_cont.add(co2_bg);

    co2_graph.setPosition(5, 43, 389, 224);
	co2_graph.setScale(1);
	co2_graph.setGraphRangeX(0, 100);
	co2_graph.setGraphAreaMargin(10, 28, 19, 22);
	co2_graph.setGraphAreaPadding(2, 6, 0, 6);
	co2_graph.setGraphRangeY(0, 1500);
	co2_graphMajorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
	co2_graphMajorYAxisGrid.setInterval(20);
	co2_graphMajorYAxisGrid.setLineWidth(1);
	co2_graphMajorYAxisGrid.setScale(1);
	co2_graph.addGraphElement(co2_graphMajorYAxisGrid);

	co2_graphMajorXAxisLabel.setInterval(20);
	co2_graphMajorXAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_STUE));
	co2_graphMajorXAxisLabel.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	co2_graphMajorXAxisLabel.setScale(1);
	co2_graph.addBottomElement(co2_graphMajorXAxisLabel);

	co2_graphMajorYAxisLabel.setInterval(20);
	co2_graphMajorYAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_0ZFD));
	co2_graphMajorYAxisLabel.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
	co2_graphMajorYAxisLabel.setScale(1);
	co2_graph.addLeftElement(co2_graphMajorYAxisLabel);

	co2_graphLine1Painter.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
	co2_graphLine1.setPainter(co2_graphLine1Painter);
	co2_graphLine1.setLineWidth(2);
	co2_graph.addGraphElement(co2_graphLine1);

    CO2_cont.add(co2_graph);

    co2_slider.setXY(407, 66);
    co2_slider.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_INDICATORS_SLIDER3_VERTICAL_ROUND_NOB_ID));
    co2_slider.setupVerticalSlider(7, 3, 0, 0, 125);
    co2_slider.setValueRange(0, 1500);
    co2_slider.setValue(100);
    co2_slider.setNewValueCallback(sliderValueChangedCallback);
    CO2_cont.add(co2_slider);

    co2_title.setXY(16, 13);
    co2_title.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    co2_title.setLinespacing(0);
    co2_title.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XTAW));
    CO2_cont.add(co2_title);

    status_Cont.add(CO2_cont);

    humd_cont.setPosition(0, 70, 480, 307);
    humdit_bg.setPosition(15, 58, 389, 224);
    humdit_bg.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    humdit_bg.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    humdit_bg.setBorderSize(1);
    humd_cont.add(humdit_bg);

    humd_graph.setPosition(17, 64, 389, 224);
    humd_graph.setScale(1);
    humd_graph.setGraphRangeX(0, 100);
    humd_graph.setGraphAreaMargin(10, 28, 19, 22);
    humd_graph.setGraphAreaPadding(2, 6, 0, 6);
    humd_graph.setGraphRangeY(0, 100);
    humd_graphMajorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    humd_graphMajorYAxisGrid.setInterval(20);
    humd_graphMajorYAxisGrid.setLineWidth(1);
    humd_graphMajorYAxisGrid.setScale(1);
    humd_graph.addGraphElement(humd_graphMajorYAxisGrid);

    humd_graphMajorXAxisLabel.setInterval(20);
    humd_graphMajorXAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_8XT4));
    humd_graphMajorXAxisLabel.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    humd_graphMajorXAxisLabel.setScale(1);
    humd_graph.addBottomElement(humd_graphMajorXAxisLabel);

    humd_graphMajorYAxisLabel.setInterval(20);
    humd_graphMajorYAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_26OJ));
    humd_graphMajorYAxisLabel.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    humd_graphMajorYAxisLabel.setScale(1);
    humd_graph.addLeftElement(humd_graphMajorYAxisLabel);

    humd_graphLine1Painter.setColor(touchgfx::Color::getColorFromRGB(20, 151, 197));
    humd_graphLine1.setPainter(humd_graphLine1Painter);
    humd_graphLine1.setLineWidth(2);
    humd_graph.addGraphElement(humd_graphLine1);

    humd_cont.add(humd_graph);

    hum_graph_title.setXY(23, 27);
    hum_graph_title.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    hum_graph_title.setLinespacing(0);
    hum_graph_title.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GMX6));
    humd_cont.add(hum_graph_title);

    textArea1.setXY(273, 38);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8RLC));
    humd_cont.add(textArea1);

    hum_slider.setXY(425, 95);
    hum_slider.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_INDICATORS_SLIDER3_VERTICAL_ROUND_NOB_ID));
    hum_slider.setupVerticalSlider(7, 3, 0, 0, 125);
    hum_slider.setValueRange(0, 100);
    hum_slider.setValue(50);
    hum_slider.setNewValueCallback(sliderValueChangedCallback);
    humd_cont.add(hum_slider);

    status_Cont.add(humd_cont);

    monotoring_page.setXY(128, 8);
    monotoring_page.setColor(touchgfx::Color::getColorFromRGB(19, 41, 209));
    monotoring_page.setLinespacing(0);
    monotoring_page.setTypedText(touchgfx::TypedText(T___SINGLEUSE_T0E1));
    status_Cont.add(monotoring_page);

    back_pb.setBitmaps(Bitmap(BITMAP_UNDO_ID), Bitmap(BITMAP_UNDO_ID));
    back_pb.setBitmapXY(0, 0);
    back_pb.setAction(flexButtonCallback);
    back_pb.setPosition(18, 16, 33, 33);
    status_Cont.add(back_pb);

    add(status_Cont);
}

StatusViewBase::~StatusViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void StatusViewBase::setupScreen()
{

}

void StatusViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &back_pb)
    {
        //back_action
        //When back_pb clicked change screen to Home
        //Go to Home with screen transition towards East
        application().gotoHomeScreenSlideTransitionEast();
    }
}

void StatusViewBase::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &hum_slider)
    {
        //sliderValueChanged
        //When hum_slider value changed call virtual function
        //Call sliderValueChanged
        sliderValueChanged(value);
    }
    if (&src == &co2_slider)
    {
        //co2sliderchange
        //When co2_slider value changed call virtual function
        //Call co2sliderchange
        co2sliderchange(value);
    }
}
