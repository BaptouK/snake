
#include "Snake.h"
#include <utility>

Snake::Snake() {
    snake.push_back(std::pair(7,5));
    snake.push_back(std::pair(6,5));
    snake.push_back(std::pair(5,5));
};

Snake::~Snake() {};

std::deque<std::pair<int, int>> Snake::getCoord() const {
    return this->snake;
};

void Snake::updateCoord(bool eat_apple) {    if (!eat_apple) {
        this->snake.pop_back();
    }
    if (direction == "up") {
        snake.push_front(std::pair<int, int>(snake[0].first-1,snake[0].second));
    }else if (direction == "down") {
        snake.push_front(std::pair<int, int>(snake[0].first+1,snake[0].second));
    }else if (direction == "left") {
        snake.push_front(std::pair<int, int>(snake[0].first,snake[0].second-1));
    }else if (direction == "right") {
        snake.push_front(std::pair<int, int>(snake[0].first,snake[0].second+1));
    }
};

std::string Snake::getDirection() const {
    return this->direction;
};
void Snake::setDirection(std::string input) {
    if ((input == "up" && direction!="down") || (input == "down" && direction!="up")
        || (input == "left" && direction!="right")|| (input == "right" && direction!="left")) {
        this->direction = input;
    }
};

std::pair<int,int> Snake::getHead()const {
    return this->snake.front();
};

