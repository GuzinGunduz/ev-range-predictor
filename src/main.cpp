#include <iostream> //Required for printing to the console
#include "../include/CanMessage.hpp" // Include the CanMessage class we created

int main() {
    //Print a message to show that the program has started
    std::cout << "EV Range Estimator Simulator Starting..." << std::endl;

    //Create a fake CAN Message 
    //0x120 is the message ID (in hexadecimal)
    // 3 is the number of data bytes (DLC)
    // The vektor contains the actual data bytes
    CanMessage message(0x120, 3, {34, 89, 200 });

    //Print the CAN message using the toText() method 
    std::cout << "Fake CAN Message: " << message.toText() << std::endl;
    

    return 0;
}
