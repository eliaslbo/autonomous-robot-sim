#pragma once
#include "../environment/maze.h"
#include "../sensor/sensor.h"
#include "../planning/aStar.h"
#include <vector>
#include <utility>

class Robot{
    public:
        Robot(const Maze& maze, std::pair<int,int> start, std::pair<int,int> goal);
        void initialize();
        std::pair<int,int> getPosition();
        void move();
        bool hasReachedGoal();
        std::vector<std::pair<int,int>> getPath();

    private:
        const Maze& maze;
        Sensor sensor;
        Astar aStar;
        std::vector<std::pair<int,int>> path;
        std::pair<int,int> position;
        std::pair<int,int> start;
        std::pair<int,int> goal;
        int currentStep;
};