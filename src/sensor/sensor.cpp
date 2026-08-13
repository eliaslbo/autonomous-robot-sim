#include "sensor.h"
#include <vector>


Sensor::Sensor(const Maze& maze, std::pair<int,int> startPos)
    : maze(maze), discoveredMap(maze.getHeight(), maze.getWidth(), startPos) {

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

void Sensor::updateMap(std::pair<int,int> pos){
    int y = pos.first;
    int x = pos.second;
    SensorReading readings = measure(pos.first, pos.second);
    std::vector<int> readingsVec = {readings.up, readings.down, readings.left, readings.right};
    std::vector<std::pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int direction = 0;
    for (int dir : readingsVec){
        if (dir == 0) {
            int wallY = y + directions[direction].first;
            int wallX = x + directions[direction].second;
            if (wallY >= 0 && wallX >= 0 && wallY < discoveredMap.getHeight() && wallX < discoveredMap.getWidth()) {
                discoveredMap.addToMap({wallY, wallX}, 1);
            }
        direction++;
        continue;
        }
        for (int i = 0; i < dir ; i++){
            if (i == dir - 1){
                discoveredMap.addToMap({y + directions[direction].first * (i+1), x + directions[direction].second * (i+1)}, 0);
                int wallY = y + directions[direction].first * (dir + 1);
                int wallX = x + directions[direction].second * (dir + 1);
                if (wallY >= 0 && wallX >= 0 && wallY < discoveredMap.getHeight() && wallX < discoveredMap.getWidth()) {
                    discoveredMap.addToMap({wallY, wallX}, 1);
                }
            }else{
                discoveredMap.addToMap({y + directions[direction].first * (i+1), x + directions[direction].second * (i+1)}, 0);
            }
        }
        direction++;
    }
}

const DiscoveredMap& Sensor::getDiscoveredMap() const {return discoveredMap;}