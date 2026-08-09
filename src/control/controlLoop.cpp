#include "controlLoop.h"
#include <chrono>


ControlLoop::ControlLoop(Robot& robot, int intervalMs) : robot(robot){
    this->intervalMs = intervalMs;
    running = false;
}

void ControlLoop::start(){
    running = true;
    thread = std::thread(&ControlLoop::run, this);
}


void ControlLoop::stop(){
    running = false;
    if (thread.joinable()){
        thread.join();
    }
}

void ControlLoop::run(){
    while(running && !robot.hasReachedGoal()){
        robot.move();
        std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs));
    }
    running = false;
}

void ControlLoop::wait(){
    if (thread.joinable()){
        thread.join();
    }
}