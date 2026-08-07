#include "maze.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

Maze::Maze(int height, int width){
    this->height = height;
    this->width = width;
    this->grid = std::vector<std::vector<int>> (height, std::vector<int>(width,1));
}

void Maze::printMaze(){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (grid[i][j] == 1){
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

bool Maze::isWall(int y, int x) const {
    return grid[y][x] == 1;
}

void Maze::generate(){
    grid[1][1] = 0;
    carve(1,1);
}

void Maze::carve(int x, int y){
    std::vector<std::pair<int,int>> directions = {
        {0, -2},  // up
        {0,  2},  // down
        {-2, 0},  // left
        {2,  0}   // right
    };
    // Shuffle the direction vector
    std::shuffle(directions.begin(), directions.end(), std::mt19937{std::random_device{}()}); 

    for (auto [dx, dy] : directions) {
        int nx = x + dx;
        int ny =y + dy;
        if (nx > 0 && ny > 0 && nx < width - 1 && ny < height - 1 && grid[ny][nx] == 1) {
            grid[y + dy/2][x + dx/2] = 0;
            grid[ny][nx] = 0;
            carve(nx, ny);
        }
    }
}