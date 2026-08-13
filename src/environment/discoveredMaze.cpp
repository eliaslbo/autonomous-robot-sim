#include "discoveredMaze.h"



DiscoveredMap::DiscoveredMap(int height, int width, std::pair<int,int> pos) {
    this->height = height;
    this->width = width;
    this->grid = std::vector<std::vector<int>>(height, std::vector<int>(width, 2));
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (j == 0 || j == width - 1 || i == 0 || i == height - 1){
                grid[i][j] = 1;
            }
        }
    }grid[pos.first][pos.second] = 0;
}

void DiscoveredMap::addToMap(std::pair<int,int> cell, int type){
    grid[cell.first][cell.second] = type;
}

bool DiscoveredMap::isWall(int y, int x) const {
    return grid[y][x] == 1;
}

bool DiscoveredMap::isUnknown(int y, int x) const {
    return grid[y][x] == 2;
}

int DiscoveredMap::getHeight() const{
    return height;
}


int DiscoveredMap::getWidth() const{
    return width;
}