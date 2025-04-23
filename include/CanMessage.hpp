#ifndef CANMESSAGE_HPP
#define CANMESSAGE_HPP

#include <string>     // For using std::string
#include <vector>     // For using std::vector
#include <cstdint>
// represents a fake CAN message
class CanMessage {
public:
    int id;                       // CAN message ID (e.g. 0x120)
    int dlc;                      // Data Length Code: how many data bytes
    std::vector<uint8_t> data;         //  byte-level data

    // Constructor: creates a new CAN message
    CanMessage(int input_id, int input_dlc, std::vector<uint8_t> input_data) {
        id = input_id; // 0x120 canid
        dlc = input_dlc; // number of byte 
        data = input_data;
    }

    // Converts the message to a readable text format
    std::string toText() {
        std::string text = "ID: " + std::to_string(id);
        text += " | DLC: " + std::to_string(dlc); 
        text += " | DATA: ";
        for (int byte : data) {
            text += std::to_string(byte) + " ";
        }
        return text;
    }
    // Decodes data based on known CAN message ID
    std::string decode() {
        if (id == 0x120 && data.size() >= 1) {
            return "Battery Level = " + std::to_string(data[0]) + "%";
        }
        else if (id == 0x130 && data.size() >= 1) {
            return "Speed = " + std::to_string(data[0]) + " km/h";
        }
        return "Unknown message or unsupported ID";
    }
};

#endif // CANMESSAGE_HPP

