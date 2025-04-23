#include <iostream>                  // For printing messages to the console
#include "CanMessage.hpp"           // Contains our custom CAN message class
#include "RangeCalculator.hpp"      // Calculates how far the car can go
#include "Logger.hpp"               // Handles writing logs to a file
#include "CanMessageGenerator.hpp"  // Creates fake battery CAN messages with random values

int main() {
    std::cout << "EV Range Estimator Simulator Starting..." << std::endl;

    // Step 1: Create the logger so we can save events to log.txt
    Logger logger;
    logger.logMessage("---------------------------------------------------");
    logger.logMessage("EV simulator started.");

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
    CanMessage speedMessage = generator.GenerateSpeedMessage();

    // Step 5: Print the raw CAN message format (ID, DLC, data bytes)
    std::string batteryText = message.toText();
    std::cout << "Battery CAN Message: " << batteryText << std::endl;
    logger.logMessage("Battery CAN Message: " + batteryText);

    //Decode battery
    std::string decodedBattery = message.decode();
    std::cout << "Decoded: " << decodedBattery << std::endl;
    logger.logMessage("Decoded: " + decodedBattery);
    //Speed 
    std::string speedText = speedMessage.toText();
    std::cout << "Generated Speed CAN Message: " << speedText << std::endl;
    logger.logMessage("Generated Speed CAN Message: " + speedText);
    //Decode Speed
    std::string decodedSpeed = speedMessage.decode();
    std::cout << "Decoded: " << decodedSpeed << std::endl;
    logger.logMessage("Decoded: " + decodedSpeed);

    

    return 0;
}