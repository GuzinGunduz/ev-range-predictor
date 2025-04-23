#include <iostream>                  // Required for console output
#include "CanMessage.hpp"           // CAN message structure
#include "RangeCalculator.hpp"      // Range estimation logic
#include "Logger.hpp"               // Logging utility
#include "CanMessageGenerator.hpp"  // Fake CAN message generator

int main() {
    std::cout << "EV Range Estimator Simulator Starting..." << std::endl;

    // Step 1: Create logger and write initial info
    Logger logger;
    logger.logMessage("EV simulator started.");
    logger.logMessage("Battery level: 75%");

    // Step 2: Estimate range using fake battery percentage
    RangeCalculator calculator;
    calculator.setBatteryPercentage(75);
    float estimatedRange = calculator.estimateRange();

    // Step 3: Print and log estimated range
    std::cout << "Estimated Driving Range: " << estimatedRange << "km" << std::endl;
    logger.logMessage("Estimated range : " + std::to_string(estimatedRange) + " km");

    // Step 4: Generate a fake CAN message from battery value
    CanMessageGenerator generator;
    CanMessage message = generator.GenerateBatteryMessage();

    // Step 5: Print and log the generated CAN message
    std::string canText = message.toText();
    std::cout << "Generated CAN Message: " << canText << std::endl;
    logger.logMessage("Generated CAN Message: " + canText);

    return 0;
}

 