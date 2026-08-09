#include <iostream>
#include "environment/maze.h"
#include "sensor/sensor.h"
#include "planning/aStar.h"


int main() {
    Maze maze(21,21);
    maze.generate();
    

    Astar Astar(maze);
    std::vector<std::pair<int,int>> path = Astar.findPath({1,1}, {19,19});

    std::cout << "Path length: " << path.size() << std::endl;

    maze.printPath(path);
    

    return 0;
}