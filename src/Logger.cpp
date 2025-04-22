#include "Logger.hpp"
#include <iostream>  // For optional debug messages

// Constructor - opens the log file
Logger::Logger() {
    logFile.open("log.txt", std::ios::app);  // Open file in append mode
    if (!logFile.is_open()) {
        std::cerr << "Error: Could not open log.txt for writing." << std::endl;
    }
}

// Function to write a message to the file
void Logger::logMessage(std::string message) {
    if (logFile.is_open()) {
        logFile << message << std::endl;
    }
}

// Destructor - closes the file
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
