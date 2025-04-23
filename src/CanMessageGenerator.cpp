#include "CanMessageGenerator.hpp"
#include "CanMessage.hpp" 
#include <chrono>
#include <vector> // we need to use std::vector

//Constructor- Initiliza battery distribution 0-100
CanMessageGenerator::CanMessageGenerator()
    : engine(std::chrono::system_clock::now().time_since_epoch().count()), //Seed with current time
      batteryDist(0, 100)
{
    // engine now uses a time-based seed
}

//This function creates CanMessage with random battery% as a data
CanMessage CanMessageGenerator::GenerateBatteryMessage() {
    int battery = batteryDist(engine); //Generate random 0-100 number

    //Build Can message with ID 0x120 and 1 data byte (battery)
    uint8_t batteryByte = static_cast<uint8_t>(battery); // Convert int to 1- Byte format

    std::vector<uint8_t> data;
    data.push_back(batteryByte);

    // Return the complete CAN message (ID: 0x120)
    return CanMessage(0x120, data.size(), data);
}
    // Create a fake CAN message with a random speed
CanMessage CanMessageGenerator::GenerateSpeedMessage() {
    // Set speed range from 0 to 120 km/h
    std::uniform_int_distribution<int> speedDist(0, 120);
    int speed = speedDist(engine); // Generate random speed

    // Convert to byte format (1 byte)
    uint8_t speedByte = static_cast<uint8_t>(speed);
    std::vector<uint8_t> data;
    data.push_back(speedByte);

    // Return a CAN message with ID 0x130 (used for speed messages)
    return CanMessage(0x130, data.size(), data);
}
