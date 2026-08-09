#include <iostream>
#include "environment/maze.h"
#include "sensor/sensor.h"
#include "planning/aStar.h"
#include "robot/robot.h"
#include "control/controlLoop.h"
#include "network/socket.h"


int main() {
    Maze maze(41,41);
    maze.generate();
    
    Robot robot(maze, {1,1}, {39,39});
    robot.initialize();

    ControlLoop controlLoop(robot, maze, 50, "127.0.0.1", 65432);
    controlLoop.start();
    controlLoop.wait();

    maze.printPath(robot.getPath());

    return 0;
}