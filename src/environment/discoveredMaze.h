#pragma once
#include <vector>
#include <utility>


class DiscoveredMap{
    public:
        DiscoveredMap(int height, int width, std::pair<int,int> pos);
        void addToMap(std::pair<int,int> cell, int type);
        bool isWall(int y, int x) const;
        bool isUnknown(int y, int x) const;
        int getHeight() const;
        int getWidth() const;
    
    private:
        int height;
        int width;
        std::vector<std::vector<int>> grid;
};