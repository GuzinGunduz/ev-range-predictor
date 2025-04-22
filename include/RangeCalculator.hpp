#ifndef RANGE_CALCULATOR_HPP
#define RANGE_CALCULATOR_HPP

//this class will simulate Ev range estimation based on incoming CAN data
class RangeCalculator {
public: 
    //Contructor
    RangeCalculator();

    // Set battery percentage (fake input from Can Message)
    void setBatteryPercentage( int percentage);

    //Estimatre driving range based on battery percentage
    float estimateRange() const;

private:
    int batteryPercentage; //Internal veriable to store battery level

};
#endif // RANGE_CALCULATOR_HPP
// endif means: birden fazla kez cagirmasain diye. 
//Birden fazla kez tanimlamaya calisir bu da hata verir. 

