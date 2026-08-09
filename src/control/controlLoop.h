#pragma once
#include "../robot/robot.h"
#include <thread>
#include <atomic>



class ControlLoop {
    public:
        ControlLoop(Robot& robot, int intervalMs);
        void start();
        void stop();
        void wait();

    private:
        Robot robot;
        int intervalMs;
        std::thread thread;
        std::atomic<bool> running;
        void run();
};