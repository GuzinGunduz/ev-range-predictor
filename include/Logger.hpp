#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <fstream>   // Needed to write to a file
#include <string>    // Needed for std::string

// This class creates a log file and writes text messages into it.
class Logger {
public:
    // This function sets up the file. It runs when we create a Logger object.
    Logger();

    // This function writes a message (a line of text) into the file.
    void logMessage(std::string message);

    // This function closes the file. It runs automatically when the Logger is destroyed.
    ~Logger(); //it is the opposite of constructor //Runs when object is destroyed

private:
    std::ofstream logFile;  // This is the object that connects to the file
};

#endif


