cmake_minimum_required(VERSION 3.20)
project(AutonomousRobotSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(robot_sim
    src/main.cpp
    src/environment/maze.cpp
    src/sensor/sensor.cpp
    src/planning/aStar.cpp
    src/robot/robot.cpp
    src/control/controlLoop.cpp
    src/network/socket.cpp
)

target_link_libraries(robot_sim ws2_32)