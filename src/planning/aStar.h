#pragma once
#include <utility>
#include <vector>
#include "../environment/maze.h"

struct Node {
    std::pair<int,int> position;
    std::pair<int,int> parent;
    int g;
    int h;
    int f;
};

class Astar {
    public:
        Astar(const Maze& maze);
        std::vector<std::pair<int,int>> findPath(std::pair<int,int> start, std::pair<int,int> goal) const;
    private:
        const Maze& maze;
};