#pragma once
#include <vector>
#include "../environment/maze.h"
#include "../environment/discoveredMaze.h"

struct SensorReading {
    int up;
    int down;
    int left;
    int right;
};


class Sensor {
    public:
        Sensor(const Maze& maze, std::pair<int,int> startPos);
        SensorReading measure(int y, int x);
        void updateMap(std::pair<int,int> pos);
        const DiscoveredMap& getDiscoveredMap() const;
    private:
        const Maze& maze;
        int openCellCounter(int y, int x, int dy, int dx, int dirCount);
        DiscoveredMap discoveredMap;

};  

