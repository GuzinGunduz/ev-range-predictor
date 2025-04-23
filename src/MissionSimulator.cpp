#include "MissionSimulator.hpp"
#include "Logger.hpp"
#include <iostream>  // For std::cout
#include <iomanip>   // For controlling float precision

// Constructor: initializes with route distance and optional starting battery
MissionSimulator::MissionSimulator(float routeDistanceKm, float startingBatteryPercent)
    : routeDistance(routeDistanceKm),
      batteryLevel(startingBatteryPercent),
      speed(0),
      eta(0)
{}

// Calculate ETA = Distance / Speed
float MissionSimulator::calculateETA(float speed, float distance) {
    if (speed == 0) return 0;  // prevent division by zero
    return distance / speed;
}

// Assume 0.25% battery usage per km driven
float MissionSimulator::calculateBatteryUsed(float distance) {
    return distance * 0.25f;
}

// Run the simulation and display results
void MissionSimulator::runSimulation() {
    // Step 1: Generate random speed
    CanMessage speedMsg = generator.GenerateSpeedMessage();
    speed = speedMsg.data[0];  // Extract speed in km/h

    // Step 2: Calculate estimated time of arrival
    eta = calculateETA(speed, routeDistance);

    // Step 3: Estimate battery usage
    float batteryUsed = calculateBatteryUsed(routeDistance);
    batteryLevel -= batteryUsed;

    // Step 4: Print the summary
    std::cout << "\n--- Mission Simulation Summary ---" << std::endl;
    std::cout << "Route distance: " << routeDistance << " km" << std::endl;
    std::cout << "Simulated speed: " << speed << " km/h" << std::endl;
    std::cout << "Estimated time to arrival: " << std::fixed << std::setprecision(2) << eta << " hours" << std::endl;
    std::cout << "Battery level after trip: " << std::fixed << std::setprecision(1) << batteryLevel << "%" << std::endl;

    Logger logger;

logger.logMessage("**************************");
logger.logMessage("Mission Simulation Summary");
logger.logMessage("Route distance: " + std::to_string(routeDistance) + " km");
logger.logMessage("Simulated speed: " + std::to_string((int)speed) + " km/h");

logger.logMessage("ETA: " + std::to_string((int)(eta * 60)) + " min");
logger.logMessage("Battery after trip: " + std::to_string((int)batteryLevel) + "%");

}
