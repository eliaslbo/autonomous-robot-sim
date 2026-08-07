#include "sensor.h"
#include <vector>


Sensor::Sensor(const Maze& maze) : maze(maze) {

}

int Sensor::openCellCounter(int y, int x, int dy, int dx, int dirCount){
    int new_y = y + dy;
    int new_x = x + dx;
    if (!maze.isWall(new_y, new_x)) {
        dirCount += 1;
        return openCellCounter(new_y, new_x, dy, dx, dirCount);
    } else{
        return dirCount;
    }
}


SensorReading Sensor::measure(int y, int x){
    SensorReading readings;
    std::vector<std::pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < directions.size(); i ++){
        int dy = directions[i].first;
        int dx = directions[i].second;
        int dirCount = 0;
        dirCount = openCellCounter(y, x, dy, dx, dirCount);
        if (i == 0){
            readings.up = dirCount;
        } else if (i == 1){
            readings.down = dirCount;
        } else if (i == 2){
            readings.left = dirCount;
        } else{
            readings.right = dirCount;
        }      
    }
    return readings;
}
