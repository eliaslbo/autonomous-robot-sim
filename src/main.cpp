#include <iostream>
#include "environment/maze.h"
#include "sensor/sensor.h"
#include "planning/aStar.h"
#include "robot/robot.h"


int main() {
    Maze maze(21,21);
    maze.generate();
    
    Robot robot(maze, {1,1}, {19,19});
    robot.initialize();
    while (!robot.hasReachedGoal()){
        robot.move();
        std::cout << "(" << robot.getPosition().first << ", " << robot.getPosition().second << ")" << std::endl;
    }
  
    std::vector<std::pair<int,int>> path = robot.getPath();
    maze.printPath(path);

    return 0;
}