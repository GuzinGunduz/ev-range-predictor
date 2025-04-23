#include "CanMessageGenerator.hpp"
#include "CanMessage.hpp" 
#include <vector> // we need to use std::vector

//Constructor- Initiliza battery distribution 0-100
CanMessageGenerator:: CanMessageGenerator()
//Member initilizer list 
//Bu sınıfın constructor’ında,sınıfın içindeki bir değişkeni constructor gövdesine girmeden önce başlatmak istiyoruz.
    :batteryDist(0, 100) // Initilizer list- //Note: ınıfın private: bölümünde tanımlanmıştı in .hpp de
{
 // engine is auto-seeded using system clock by default
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

