#include "aStar.h"
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

Astar::Astar(const Maze& maze) : maze(maze){

}

std::vector<std::pair<int,int>> Astar::findPath(std::pair<int,int> start, std::pair<int,int> goal) {

    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openList;
    std::vector<std::pair<int,int>> closedList;
    std::vector<Node> visitedNodes;

    Node startNode;
    startNode.position = start;
    startNode.parent = start;
    startNode.g = 0;
    startNode.h = abs(start.first - goal.first) + abs(start.second - goal.second);
    startNode.f = startNode.g + startNode.h;

    openList.push(startNode);

    std::vector<std::pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!openList.empty()){
        Node current = openList.top();
        openList.pop();

        if (current.position == goal){
            //Do this later
        }

        closedList.push_back(current.position);

        for (std::pair<int,int> dir : directions){
            int dy = dir.first;
            int dx = dir.second;
            int y = current.position.first;
            int x = current.position.second;

            std::pair<int,int>neighbourPos = {y + dy, x + dx};

            if (maze.isWall(neighbourPos.first, neighbourPos.second) || std::find(closedList.begin(), closedList.end(), neighbourPos) != closedList.end()){
                continue;
            }else{
                Node neighbour;
                neighbour.position = {current.position.first + dy, current.position.second + dx};
                neighbour.parent = current.position;
                neighbour.g = current.g + 1;
                neighbour.h = abs(goal.first - neighbour.position.first) + abs(goal.second - neighbour.position.second);
                neighbour.f = neighbour.g + neighbour.h;

                openList.push(neighbour);
            }
        }
        
    }
}