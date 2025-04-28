#ifndef CANMESSAGEGENERATOR_HPP
#define CANMESSAGEGENERATOR_HPP

#include "CanMessage.hpp" //I'm using existing CanMessage class
#include <random>

//This class creates fake CAN Messages with random Battery values
class CanMessageGenerator {
public: 
    //Constructor
    CanMessageGenerator();
    
    //Generate CAN Message with random Battery percentage%
    CanMessage GenerateBatteryMessage();
    CanMessage GenerateSpeedMessage();
    // random cargo weight (in tons)
    float GenerateCargoWeight();

private: //Only works in this class, main.cpp is not reach this class// like access specifier, bu bir erisim belirleyicidir.
    
    std::default_random_engine engine;
    std::uniform_int_distribution<int> batteryDist; // we should define random 0-100 batter number in .cpp file not .hpp 
};

#endif



