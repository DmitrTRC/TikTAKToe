//
// Created by Dmitry Morozov on 28/5/22.
//
#include <iostream>

#include "Game.hpp"


Game::Game () {

    std::cout << "class Game constructor is running" << std::endl;

}

Game::~Game () {
    std::cout << "class Game destructor is running" << std::endl;

}

void Game::Start () {
    std::cout << "Game started" << std::endl;
}
