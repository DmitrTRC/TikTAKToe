//
// Created by Arina on 25.07.2022.
//

#include <iostream>
#include "Board.hpp"
#include "player.hpp"
#include "Human.h"


int HumanPlayer::InputNextMove () {
    int number{0};
    std::cout << "Enter your move number from 1 to 9 : ";
    std::cin >> number;
    return number;
}

int HumanPlayer::engageMove (const Board &board) {
    return InputNextMove ();

}

HumanPlayer::HumanPlayer (const std::string &name) {
    std::cout << "class HumanPlayer constructor is running" << std::endl;
    setName (name);
}