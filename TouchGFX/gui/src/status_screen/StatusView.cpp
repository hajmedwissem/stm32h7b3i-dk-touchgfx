#include <gui/status_screen/StatusView.hpp>
#include <math.h>
#include <stdlib.h>

#include <stdint.h>
#include "../BSP/hum_manager/hum_manager.h"
#include "../BSP/co2_sensor_mangement/co2_sensor_mangement.h"

//static uint32_t seed = 12345;  // Initialize with a nonzero seed
//
//void srand_custom(uint32_t new_seed) {
//    seed = new_seed;
//}
//
//uint32_t getRandomValue() {
//    seed = (1664525 * seed + 1013904223) % 0xFFFFFFFF;  // LCG formula
//    return seed % 101;  // Limit to 0-100
//}

StatusView::StatusView()
{

}

void StatusView::setupScreen()
{
    StatusViewBase::setupScreen();
    // Initialize graph range with default slider value at start up
    sliderValueChanged(hum_slider.getValue());
    co2sliderchange(co2_slider.getValue());
}

void StatusView::tearDownScreen()
{
    StatusViewBase::tearDownScreen();
}

void StatusView::sliderValueChanged(int value){

	 // Adjust the Y-axis max value according to the slider value
	humd_graph.setGraphRangeY(0, value);
	humd_graph.invalidate();

	    // Adjust the interval of the labels/grid lines on the Y-axis
	    // to match the new range.
	    if (value > 199)
	    {
	    	humd_graphMajorYAxisLabel.setInterval(50);
	    	humd_graphMajorYAxisGrid.setInterval(50);
	    }
	    else if (value > 100)
	    {
	    	humd_graphMajorYAxisLabel.setInterval(20);
	    	humd_graphMajorYAxisGrid.setInterval(20);
	    }
	    else
	    {
	    	humd_graphMajorYAxisLabel.setInterval(10);
	    	humd_graphMajorYAxisGrid.setInterval(10);
	    }

	    humd_graphMajorYAxisLabel.invalidate();
	    humd_graphMajorYAxisGrid.invalidate();
}

void StatusView::co2sliderchange(int value){
	 // Adjust the Y-axis max value according to the slider value
	co2_graph.setGraphRangeY(0, value);
	co2_graph.invalidate();

		// Adjust the interval of the labels/grid lines on the Y-axis
		// to match the new range.
		if (value > 199)
		{
			co2_graphMajorYAxisLabel.setInterval(250);
			co2_graphMajorYAxisGrid.setInterval(250);
		}
		else if (value > 100)
		{
			co2_graphMajorYAxisLabel.setInterval(20);
			co2_graphMajorYAxisGrid.setInterval(20);
		}
		else
		{
			co2_graphMajorYAxisLabel.setInterval(10);
			co2_graphMajorYAxisGrid.setInterval(10);
		}

		co2_graphMajorYAxisLabel.invalidate();
		co2_graphMajorYAxisGrid.invalidate();
}

void StatusView::handleTickEvent()
{
    tickCounter++;

    // Insert each second tick
    if (tickCounter % 2 == 0)
    {
      //  float yMax = humd_graph.getGraphRangeYMaxAsFloat();
    	 humd_graph.addDataPoint(get_humdity_from_queue());
    	 co2_graph.addDataPoint(get_co2_from_queue());
        // Insert "random" points along a sine wave
//
//        humd_graph.addDataPoint((int)getRandomValue());
//        co2_graph.addDataPoint((int)getRandomValue());
    }
}
