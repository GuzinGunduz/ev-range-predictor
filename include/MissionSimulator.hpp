#ifndef MISSIONSIMULATOR_HPP
#define MISSIONSIMULATOR_HPP

#include "CanMessageGenerator.hpp" // To access the speed generator

// This class simulates a driving mission on a fixed route
class MissionSimulator {
public:
    // Constructor takes total route distance in km (e.g., 100 km)
    MissionSimulator(float routeDistanceKm, float startingBatteryPercent = 100.0f);

    // Runs a simple simulation and prints ETA and battery
    void runSimulation();

private:
    float routeDistance;     // Total route in kilometers
    float batteryLevel;      // Current battery % (0–100)
    float speed;             // Simulated vehicle speed (km/h)
    float eta;               // Estimated time of arrival (in hours)

    CanMessageGenerator generator; // Reuse your speed generator

    // Internal helpers
    float calculateETA(float speed, float distance);
    float calculateBatteryUsed(float distance);
};

#endif
