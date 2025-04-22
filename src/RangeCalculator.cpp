#include "RangeCalculator.hpp"
#include <iostream>

// Constructor -sets default battery percentage to %100 
RangeCalculator:: RangeCalculator() {
    batteryPercentage = 100;

}

//Set the battery percentage (e.g., from CAN message)
void RangeCalculator::setBatteryPercentage( int percentage) {
    batteryPercentage = percentage;

}

//Estimate range based on battery percentage
float RangeCalculator::estimateRange() const{
    //Assume each 1% gives about 1.5 km range
    return batteryPercentage * 1.5;
    
}