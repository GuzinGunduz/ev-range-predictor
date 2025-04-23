#include <iostream>                  // For printing messages to the console
#include "CanMessage.hpp"           // Contains our custom CAN message class
#include "RangeCalculator.hpp"      // Calculates how far the car can go
#include "Logger.hpp"               // Handles writing logs to a file
#include "CanMessageGenerator.hpp"  // Creates fake battery CAN messages with random values

int main() {
    std::cout << "EV Range Estimator Simulator Starting..." << std::endl;

    // Step 1: Create the logger so we can save events to log.txt
    Logger logger;
    logger.logMessage("EV simulator started.");
    logger.logMessage("Battery level: 75%");

    // Step 2: Estimate how far the car can go based on 75% battery
    RangeCalculator calculator;
    calculator.setBatteryPercentage(75);
    float estimatedRange = calculator.estimateRange();

    // Step 3: Show the estimated range on screen and log it
    std::cout << "Estimated Driving Range: " << estimatedRange << "km" << std::endl;
    logger.logMessage("Estimated range : " + std::to_string((int)estimatedRange) + " km");

    // Step 4: Create a fake CAN message that contains a random battery % (0-100)
    CanMessageGenerator generator;
    CanMessage message = generator.GenerateBatteryMessage();

    // Step 5: Print the raw CAN message format (ID, DLC, data bytes)
    std::string canText = message.toText();
    std::cout << "Generated CAN Message: " << canText << std::endl;
    logger.logMessage("Generated CAN Message: " + canText);

    // Step 6: Decode the CAN message to make sense of the data (e.g. battery level = 76%)
    std::string decodedInfo = message.decode();
    std::cout << "Decoded: " << decodedInfo << std::endl;
    logger.logMessage("Decoded: " + decodedInfo);

    return 0;
}

 