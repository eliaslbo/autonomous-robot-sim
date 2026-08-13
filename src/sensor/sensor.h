#pragma once
#include <vector>
#include "../environment/maze.h"

struct SensorReading {
    int up;
    int down;
    int left;
    int right;
};


class Sensor {
    public:
        Sensor(const Maze& maze);
        SensorReading measure(int y, int x);
    private:
        const Maze& maze;
        int openCellCounter(int y, int x, int dy, int dx, int dirCount);
};  

