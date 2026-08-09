# autonomous-robot-sim
A real-time autonomous robot simulator with pathfinding and live visualisation, built in C++ and Python.

How to build and run:
Requirements:
C++17 compiler (g++ 15+)
CMake 3.20+
Python 3.11+
pygame (pip install pygame)

Build:
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .

Run:
Start the Python visualiser first:
python visualiser/main.py

Then run the C++ simulator:
./build/robot_sim.exe
