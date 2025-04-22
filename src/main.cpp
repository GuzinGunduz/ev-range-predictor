#include <iostream> //Required for printing to the console
#include "CanMessage.hpp"
#include "RangeCalculator.hpp"


//#include "../include/CanMessage.hpp" // Include the CanMessage class we created
//Note: I dont need to use ../ anymore in the path, since I already told CMakeLists.txt to include
// include/ directory with this line : include_directories(include) So I deleted. 
int main() {
    //Print a message to show that the program has started
    std::cout << "EV Range Estimator Simulator Starting..." << std::endl;

    //Create a fake CAN Message 
    //0x120 is the message ID (in hexadecimal)
    // 3 is the number of data bytes (DLC)
    // The vektor contains the actual data bytes
    CanMessage message(0x120, 3, {34, 89, 200 });

    //Step2:Create a RangeCalculator __cpp_lib_has_unique_object_representations
    RangeCalculator calculator;

    //Step3: Set battery level to fake value (e.g. 75%)
    calculator.setBatteryPercentage(75);

    //Step4: Calculate estimated range
    float estimatedRange = calculator.estimateRange();

    
    //Print the CAN message using the toText() method 
    // std::cout << "Fake CAN Message: " << message.toText() << std::endl;
   
    //Step 5: Print Result
    std::cout <<"Estimated Driving Range: " <<estimatedRange << "km" << std::endl;


    return 0;
}
 