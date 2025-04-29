# EV Range Estimator and Mission Simulator

This project simulates an Electric Vehicle (EV) range prediction and mission execution system using fake CAN messages.

It demonstrates:
- Battery percentage and speed generation
- Non-linear battery consumption based on simulated cargo weight
- Decoding CAN messages into readable format
- Logging every step into a log file

---

## Technologies Used 
- **C++11**
- **CMake** (build system)
- **Ninja** (build tool)
- **Git & GitHub** (version control)
- **Bash Terminal** (for commands)

---

## Project Structure

| Folder        | Description |
| :---          | :--- |
| `/src`        | C++ source files |
| `/include`    | Header files |
| `/build`      | Build artifacts (ignored by Git) |
| `/logs`       | Log outputs (generated automatically) |

---

## How to Setup and Run

### 1. Clone the Repository

```bash
git clone git@github.com:GuzinGunduz/ev-range-predictor.git
cd ev-range-predictor


### 2. Install Requirements
## You must have installed:

g++ (C++ compiler) 

cmake 

ninja 

git 

## If you don't have them,  ## install: Windows (via MSYS2), Linux (apt install cmake g++ ninja-build)

### What Happens When you Run it ? 
Example 1: 

EV Range Estimator Simulator Starting...
Estimated Driving Range: 112.5km
Battery CAN Message: ID: 288 | DLC: 1 | DATA: 94
Decoded: Battery Level = 94%
Generated Speed CAN Message: ID: 304 | DLC: 1 | DATA: 63
Decoded: Speed = 63 km/h
Simulated Cargo Weight: 7.69 tons

--- Mission Simulation Summary ---
Route distance: 100 km
Simulated speed: 40 km/h
Estimated time to arrival: 2.50 hours
Battery level after trip: 61.3%


example2: from logged into /logs/log.txt file.
EV simulator started.
Estimated range : 112 km
Battery CAN Message: ID: 288 | DLC: 1 | DATA: 67 
Decoded: Battery Level = 67%
Generated Speed CAN Message: ID: 304 | DLC: 1 | DATA: 41 
Decoded: Speed = 41 km/h
Simulated Cargo Weight: 15.030428 tons
**************************
Mission Simulation Summary
Route distance: 100.000000 km
Simulated speed: 4 km/h
ETA: 1500 min
Battery after trip: 26%


## Future Improvements (Optional Ideas)
Multi-byte CAN message support (more realistic)
Route maps and weather impact simulation
Unit tests with GoogleTest framework
CI/CD pipeline with GitHub Actions

## This project is structured to reflect a professional embedded systems simulation project for electric vehicle range prediction and mission execution.