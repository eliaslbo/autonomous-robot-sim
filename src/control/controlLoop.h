#pragma once
#include "../robot/robot.h"
#include <thread>
#include <atomic>
#include "../network/socket.h"
#include <string>
#include "../environment/maze.h"



class ControlLoop {
    public:
        ControlLoop(Robot& robot, const Maze& maze, int intervalMs, const std::string& host, int port);
        void start();
        void stop();
        void wait();

    private:
        Robot robot;
        const Maze& maze;
        int intervalMs;
        std::thread thread;
        std::atomic<bool> running;
        void run();
        std::string host;
        int port;
};