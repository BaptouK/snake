#include <chrono>
#include <iostream>
#include <conio.h>
#include <thread>
#include <random>
#include "Snake.h"


std::pair<int,int> randomCoord(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return std::make_pair(dist(gen), dist(gen));
}

std::pair<int,int> createApple(Snake& snake,size_t taille_tableau) {
    auto snake_coords = snake.getCoord();
    std::pair<int,int> a ;
    std::cout << taille_tableau << std::endl;
    do {
        a = randomCoord(1 , taille_tableau-2);
    } while (std::find(snake_coords.begin(), snake_coords.end(), a) != snake_coords.end());

    return  a;

};


int main() {
    char input = 'a';

    constexpr size_t taille_tableau = 20;
    std::array<std::array<char, taille_tableau>, taille_tableau> array{};

    Snake snake;
    std::pair<int,int> apple= createApple(snake,taille_tableau);

    while (input != 'e') {
        auto tab_snake = snake.getCoord();

        for (auto i = 0; i < taille_tableau; i++) {
            // Opération sur les lignes
            if (i==0 || i==taille_tableau-1) {
                array[i].fill('#');
            }else {
                array[i].fill(' ');
            }
            array[apple.first][apple.second] = 'A';
            for (auto j = 0; j < taille_tableau; j++) {
                if (j==0 || j==taille_tableau-1) {
                    array[i][j] = '#';
                }
                for (auto k=0;k<tab_snake.size();k++) {
                    if (k==0) { // C'est la tete du serpent
                        array[tab_snake[k].first][tab_snake[k].second] = 'X';
                    }else {
                        array[tab_snake[k].first][tab_snake[k].second] = 'o';
                    }
                }
            }
        }


        std::string affichage;
        for (auto ligne : array) {
            for (auto colonne :ligne) {
                affichage += colonne;
            }
            affichage += "\n";
        }
        std::cout << affichage << std::endl;

        if (_kbhit()) {
            input = _getch();
            std::cout << "Touche : " << input << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        if (input == 'z') {
            snake.setDirection("up");
        }else if (input == 'q') {
            snake.setDirection("left");
        }else if (input == 's') {
            snake.setDirection("down");
        }else if (input == 'd') {
            snake.setDirection("right");
        }

        if (snake.getHead() == apple) {
            snake.updateCoord(true);

            apple = createApple(snake,taille_tableau);

        }else {
            snake.updateCoord(false);
        }

        system("cls");
        for (auto i = 1; i < snake.getCoord().size(); i++) {
            if (snake.getHead()==snake.getCoord()[i]) {
                input='e';
            }
        }

        if (array[snake.getHead().first][snake.getHead().second] == '#') {
            //std::cout <<snake.getHead().first << " " << snake.getHead().second << std::endl;
            input='e';
        }
    }

    std::cout << "Bien joue, ton score est de : "<< snake.getCoord().size() <<std::endl;
    return 0;
}
