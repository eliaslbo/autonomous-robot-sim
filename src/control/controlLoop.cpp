#include "controlLoop.h"
#include <chrono>
#include <string>


ControlLoop::ControlLoop(Robot& robot, const Maze& maze, int intervalMs, const std::string& host, int port) 
    : robot(robot), maze(maze) {
    this->intervalMs = intervalMs;
    this->host = host;
    this->port = port;
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
    std::string mazeString = maze.toString();

    Socket socket(host, port);
    socket.sendData(mazeString);
    std::string pos = robot.positionToString();
    socket.sendData(pos);

    std::this_thread::sleep_for(std::chrono::seconds(5));  // wait 5 seconds

    while(running && !robot.hasReachedGoal()){
        robot.move();
        std::string pos = robot.positionToString();
        socket.sendData(pos);
        std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs));
    }
    socket.close();
    running = false;
}

void ControlLoop::wait(){
    if (thread.joinable()){
        thread.join();
    }
}