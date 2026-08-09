#include <iostream>
#include "environment/maze.h"
#include "sensor/sensor.h"
#include "planning/aStar.h"
#include "robot/robot.h"
#include "control/controlLoop.h"


int main() {
    Maze maze(21,21);
    maze.generate();
    
    Robot robot(maze, {1,1}, {19,19});
    robot.initialize();

    ControlLoop controlLoop(robot, 100);
    controlLoop.start();
    controlLoop.wait();

    maze.printPath(robot.getPath());

    return 0;
}