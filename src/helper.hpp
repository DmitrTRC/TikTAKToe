//
// Created by Dmitry Morozov on 27/4/22.
//

#ifndef TIKTAKTOE_HELPER_HPP
#define TIKTAKTOE_HELPER_HPP

#include <iostream>
#include "Resources.hpp"


void ClearScreen () {
    const int ROWS_TO_CLEAR = 50;
    for (int i = 0; i < ROWS_TO_CLEAR; i++) {
        std::cout << std::endl;
    }
}

void DrawLogo () {

    std::cout << LOGO << std::endl;
}

//TODO: Refactor ART Styles
// Make next banners: GAME OVER, WINNER, DRAW, etc.
void DrawGameOver () {
    std::cout << GAME_OVER << std::endl;
}

void DrawWinner (const std::string &winner) {
    std::cout << std::endl;
    std::cout << WINNER << std::endl;
    std::cout << "Player " << winner << " won ! " << std::endl;
}

void DrawDraw () {
    std::cout << std::endl;
    std::cout << DRAW << std::endl;
}


#endif //TIKTAKTOE_HELPER_HPP

