#include <iostream>
#include "environment/maze.h"

int main() {
    Maze maze(21,21);
    maze.generate();
    maze.printMaze();
    return 0;
}