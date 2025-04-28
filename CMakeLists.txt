cmake_minimum_required(VERSION 3.10)

project(EVRangePredictor)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(EVRangePredictor
    src/main.cpp
    src/RangeCalculator.cpp
    src/Logger.cpp
    src/CanMessageGenerator.cpp
    src/MissionSimulator.cpp

)
