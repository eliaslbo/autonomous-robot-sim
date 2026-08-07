#include <iostream>
#include "environment/maze.h"
#include "sensor/sensor.h"

int main() {
    Maze maze(21,21);
    maze.generate();
    maze.printMaze();

    Sensor sensor(maze);
    SensorReading reading = sensor.measure(1,1);
    std::cout << "Up: " << reading.up << std::endl;
    std::cout << "Down: " << reading.down << std::endl;
    std::cout << "Left: " << reading.left << std::endl;
    std::cout << "Right: " << reading.right << std::endl;
    
    return 0;
}