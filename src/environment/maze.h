#pragma once
#include <vector>
#include <string>

class Maze {
    public:
        Maze(int height, int width);
        void printMaze();
        bool isWall(int y, int x) const;
        void generate();
        void printPath(const std::vector<std::pair<int,int>>& path) const;
        std::string toString() const;
        int getHeight() const;
        int getWidth() const;
    private:
        std::vector<std::vector<int>> grid;
        int width;
        int height;
        void carve (int x, int y);
};