
#ifndef SNAKE_H
#define SNAKE_H
#include <utility>
#include <deque>
#include <string>


class Snake {
public:
    Snake();
    ~Snake();

    std::deque<std::pair<int, int>> getCoord() const;
    void updateCoord(bool eat_apple);

    std::string getDirection() const;
    void setDirection(std::string input) ;

    std::pair<int,int> getHead()const;
private:
    std::deque<std::pair<int, int>> snake;
    std::string direction {"down"};
};

#endif
