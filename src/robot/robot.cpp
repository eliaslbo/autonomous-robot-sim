#include "robot.h"
#include <string>

Robot::Robot(const Maze& maze, std::pair<int,int> start, std::pair<int,int> goal) : maze(maze), sensor(maze), aStar(maze) {
    this->start = start;
    this->goal = goal;
    this->currentStep = 0;
    this->position = start;
}

void Robot::initialize() {
    path = aStar.findPath(start, goal);
}


std::pair<int,int> Robot::getPosition(){
    return position;
}


void Robot::move(){
    currentStep++;
    position = path[currentStep];
}


bool Robot::hasReachedGoal(){
    return position == goal;
}

std::vector<std::pair<int,int>> Robot::getPath(){
    return path;
}

std::string Robot::positionToString() const {
    std::string result = "POS:" + std::to_string(position.first) + "," + std::to_string(position.second);
    return result;
}