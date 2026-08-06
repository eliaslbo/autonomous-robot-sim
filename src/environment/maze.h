#pragma once
#include <vector>

class Maze {
    public:
        Maze(int height, int width);
        void printMaze();
        bool isWall(int x, int y);
        void generate();
    private:
        std::vector<std::vector<int>> grid;
        int width;
        int height;
        void carve (int x, int y);
};