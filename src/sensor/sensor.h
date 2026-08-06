#pragma once
#include <vector>
#include "maze.h"

struct SensorReading {
    int up;
    int down;
    int left;
    int right;
};

class Sensor {
    public:
        Sensor(const Maze& maze);
        SensorReading measure(int x, int y);
    private:
        const Maze& maze;
};  